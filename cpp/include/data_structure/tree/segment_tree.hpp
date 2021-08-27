/*
    Segment Tree
    ------------------
    A Segment Tree is a data structure that allows answering range queries over an array effectively, 
    while still being flexible enough to allow modifying the array. This includes :
        >finding the sum of consecutive array elements a[l…r], 
        >finding the product of array elements a[l…r],         
        >finding the minimum element in range a[l...r], 
        >finding the maximum element in range a[l...r] 
    which can be answered in O(logn) time per query. 
    Between answering such queries the Segment Tree allows modifying the array by replacing one element.
*/

#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include<vector>
#include<string>

using namespace std;

const int INF = INT_MAX;

template<typename T> 
class SegmentTree {
    
    T *rng_mx_seg,  // stores segment tree which answers the range max queries
    *rng_mn_seg,    // stores segment tree which answers the range min queries
    *rng_sum_seg,   // stores segment tree which answers the range sum queries
    *rng_prod_seg;  // stores segment tree which answers the range product queries
    int size;       // to store size of the segment tree

    /*
        Helper function to contruct segment trees

        Algorithm
        ---------------
        It is convenient to describe this operation recursively in the other direction, i.e., from the root vertex to the leaf vertices. 
        The construction procedure, if called on a non-leaf vertex, does the following:
            1.recursively construct the values of the two child vertices
            2.merge the computed values of these children.
        We start the construction at the root vertex and assign their values as it is, and hence, we are able to compute the entire segment tree.

        Time complexity
        ---------------
        O(N), where N is the size of array

        Space complexity
        ----------------
        O(N), where N is the size of array
    */
    void buildTree(vector<T> &ar,int n, int low, int high) {
        if(low==high) {
            rng_mn_seg[n]=ar[low];
            rng_mx_seg[n]=ar[low];
            rng_sum_seg[n]=ar[low];
            rng_prod_seg[n]=ar[low];
            return;
        }
        int mid = (low+high)/2;
        build(ar,2*n+1,low,mid);
        build(ar,2*n+2,mid+1,high);
        rng_sum_seg[n] = rng_sum_seg[2*n+1] + rng_sum_seg[2*n+2];
        rng_prod_seg[n] = rng_prod_seg[2*n+1] * rng_prod_seg[2*n+2];
        rng_mx_seg[n] = max(rng_mx_seg[2*n+1],rng_mx_seg[2*n+2]);
        rng_mn_seg[n] = min(rng_mn_seg[2*n+1],rng_mn_seg[2*n+2]);
    }
    
    public :

        /*
        contructor which takes original array as parameter & contructs an initial segment tree out of the original array

        Time complexity
        ---------------
        O(N), where N is the size of array

        Space complexity
        ----------------
        O(N), where N is the size of array
        */
        SegmentTree(vector<T> a) {
            size = a.size();
            rng_sum_seg=new T[4*size];
            rng_prod_seg=new T[4*size];
            rng_mx_seg=new T[4*size];
            rng_mn_seg=new T[4*size];
            build(a,0,0,size-1);
        }    

        /*
        Member function to handle point update query.
        update the value present at index "id"(0-based) with "val"

        Algorithm
        ---------------
        Now we want to modify a specific element in the array, let's say we want to do the assignment a[i]=x. 
        And we have to rebuild the Segment Tree, such that it correspond to the new, modified array.
        Each level of a Segment Tree forms a partition of the array. Therefore an element a[i] only contributes 
        to one segment from each level. Thus only O(logn) vertices need to be updated.It is easy to see, that 
        the update request can be implemented using a recursive function. The function gets passed the current 
        tree vertex, and it recursively calls itself with one of the two child vertices (the one that contains 
        a[i] in its segment), and after that recomputes its sum value, similar how it is done in the build method 
        (that is as the sum of its two children).

        Time complexity
        ---------------
        O(LogN), where N is the size of array

        Space complexity
        ----------------
        O(LogN), where N is the size of array
        */
        void point_update(int id,T val,int low=0,int high=INF, int n=0) {
            if(high==INF) high=size-1;
            if(low>high) return;
            if(low==high) {
                rng_sum_seg[n]=val; 
                rng_mx_seg[n]=val; 
                rng_mn_seg[n]=val; 
                rng_prod_seg[n]=val; 
                return;
            }
            int mid=(low+high)/2;
            if(mid>=id) point_update(id,val,low,mid,2*n+1);
            else point_update(id,val,mid+1,high,2*n+2);
            rng_sum_seg[n]=rng_sum_seg[2*n+1]+rng_sum_seg[2*n+2];
            rng_prod_seg[n]=rng_prod_seg[2*n+1]*rng_prod_seg[2*n+2];
            rng_mx_seg[n]=max(rng_mx_seg[2*n+1],rng_mx_seg[2*n+2]);
            rng_mn_seg[n]=min(rng_mn_seg[2*n+1],rng_mn_seg[2*n+2]);
        }
        
        /*
        Member function to handle range sum query as:
        range_sum_query(l,r) returns a[l]+a[l+1]...a[r] where a is the original array

        Algorithm
        ---------------
        T range_sum_query(node, l, r) {
            if the range of the node is within l and r
                 return value in the node
            else if the range of the node is completely outside l and r
                 return 0
            else
             return range_sum_query(node's left child, l, r) + 
                    range_sum_query(node's right child, l, r)
        }

        Time complexity
        ---------------
        O(LogN), where N is the size of array

        Space complexity
        ----------------
        O(LogN), where N is the size of array
        */
        T range_sum_query(int rl, int rr, int low=0, int high=INF, int id=0) {
            if(low>high) return 0;
            if(high==INF) high=size-1;
            // complete overlap
            if(rl<=low && rr>=high) return rng_sum_seg[id];
            // no overlap
            if(rl>high || rr<low) return 0;
            int mid=(low+high)/2;
            return range_sum_query(rl,rr,low,mid,2*id+1) + range_sum_query(rl,rr,mid+1,high,2*id+2);
        }

        /*
        Member function to handle range prod query as:
        range_prod_query(l,r) returns a[l]*a[l+1]...a[r] where a is the original array

        Algorithm
        ---------------
        T range_prod_query(node, l, r) {
            if the range of the node is within l and r
                 return value in the node
            else if the range of the node is completely outside l and r
                 return 1
            else
             return range_prod_query(node's left child, l, r) * 
                    range_prod_query(node's right child, l, r)
        }

        Time complexity
        ---------------
        O(LogN), where N is the size of array

        Space complexity
        ----------------
        O(LogN), where N is the size of array
        */
        T range_prod_query(int rl, int rr, int low=0, int high=INF, int id=0) {
            if(low>high) return 1;
            if(high==INF) high=size-1;
            // complete overlap
            if(rl<=low && rr>=high) return rng_prod_seg[id];
            // no overlap
            if(rl>high || rr<low) return 1;
            int mid=(low+high)/2;
            return range_prod_query(rl,rr,low,mid,2*id+1) * range_prod_query(rl,rr,mid+1,high,2*id+2);
        }

        /*
        Member function to handle range max query as:
        range_max_query(l,r) returns max(a[l],a[l+1]...,a[r]) where a is the original array

        Algorithm
        ---------------
        T range_max_query(node, l, r) {
            if the range of the node is within l and r
                 return value in the node
            else if the range of the node is completely outside l and r
                 return 1
            else
             return max(range_max_query(node's left child, l, r),range_max_query(node's right child, l, r))
        }

        Time complexity
        ---------------
        O(LogN), where N is the size of array

        Space complexity
        ----------------
        O(LogN), where N is the size of array
        */
        T range_max_query(int rl, int rr, int low=0, int high=INF, int id=0) {
            if(low>high) return -INF;
            if(high==INF) high=size-1;
            // complete overlap
            if(rl<=low && rr>=high) return rng_mx_seg[id];
            // no overlap
            if(rl>high || rr<low) return -INF;
            int mid=(low+high)/2;
            return max(range_max_query(rl,rr,low,mid,2*id+1),range_max_query(rl,rr,mid+1,high,2*id+2));
        }

        /*
        Member function to handle range min query as:
        range_min_query(l,r) returns min(a[l],a[l+1]...,a[r]) where a is the original array

        Algorithm
        ---------------
        T range_min_query(node, l, r) {
            if the range of the node is within l and r
                 return value in the node
            else if the range of the node is completely outside l and r
                 return 1
            else
             return min(range_min_query(node's left child, l, r),range_min_query(node's right child, l, r))
        }

        Time complexity
        ---------------
        O(LogN), where N is the size of array

        Space complexity
        ----------------
        O(LogN), where N is the size of array
        */
        T range_min_query(int rl, int rr, int low=0, int high=INF, int id=0) {
            if(low>high) return INF;
            if(high==INF) high=size-1;
            // complete overlap
            if(rl<=low && rr>=high) return rng_mx_seg[id];
            // no overlap
            if(rl>high || rr<low) return INF;
            int mid=(low+high)/2;
            return min(range_min_query(rl,rr,low,mid,2*id+1),range_min_query(rl,rr,mid+1,high,2*id+2));
        }
 
        ~SegmentTree() {
            delete[] rng_sum_seg;
            delete[] rng_prod_seg;
            delete[] rng_mx_seg;
            delete[] rng_mn_seg;
        }
};

#endif // SEGMENT_TREE_HPP