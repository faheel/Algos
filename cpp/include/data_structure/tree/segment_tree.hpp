/*
    Segment Tree
    ------------
    In computer science, a segment tree, also known as a statistic tree,
    is a tree data structure used for storing information about intervals or segments.
    It allows querying which of the stored elements contain a given point.
    It is a data structure that allows answering range queries
    over an array effectively, while still being flexible enough to allow
    modifying the array. This includes finding sum of consecutive array elements or
    finding the minimum element in such a range.

    Time Complexity
    ---------------
    A segment tree for a set I of n intervals can be built in O(logn + k) time.
    'k' being the number of retrieved intervals or segments.

    Space Complexity
    ----------------
    A segment tree for a set I of n intervals uses O(n logn) storage.

    The following code shows three segment tree operations
    1. construction
    2. sum query
    3. update
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree{

    public:

    // A utility function to get the middle index from corner indices.
    int get_mid(int s, int e) { return s + (e -s)/2; }

    int get_sum_util(int *st, int ss, int se, int qs, int qe, int si){
        // If segment of this node is a part of given range, then return the sum of the segment
        if (qs <= ss && qe >= se)
            return st[si];
    
        // If segment of this node is outside the given range
        if (se < qs || ss > qe)
            return 0;
    
        // If a part of this segment overlaps with the given range
        int mid = get_mid(ss, se);
        return get_sum_util(st, ss, mid, qs, qe, 2*si+1) +
            get_sum_util(st, mid+1, se, qs, qe, 2*si+2);
    }

    void update_value_util(int *st, int ss, int se, int i, int diff, int si){
        // Base Case: If the input index lies outside the range of this segment
        if (i < ss || i > se)
            return;
    
        // If the input index is in range of this node, then update the value of the node and its children
        st[si] = st[si] + diff;
        if (se != ss){
            int mid = get_mid(ss, se);
            update_value_util(st, ss, mid, i, diff, 2*si + 1);
            update_value_util(st, mid+1, se, i, diff, 2*si + 2);
        }
    }

    void update_value(vector<int> arr, int *st, int i, int new_val){
        int n = arr.size();
        // Check for erroneous input index
        if (i < 0 || i > n-1){
            cout<<"Invalid Input";
            return;
        }
    
        // Get the difference between new value and old value
        int diff = new_val - arr[i];
    
        // Update the value in array
        arr[i] = new_val;
    
        // Update the values of nodes in segment tree
        update_value_util(st, 0, n-1, i, diff, 0);
    }

    int get_sum(int *st, vector<int> arr, int query_start, int query_end){
        int n = arr.size();
        // Check for erroneous input values
        if (query_start < 0 || query_end > n-1 || query_start > query_end){
            cout<<"Invalid Input";
            return -1;
        }
    
        return get_sum_util(st, 0, n-1, query_start, query_end, 0);
    }

    int construct_st_util(vector<int> arr, int ss, int se, int *st, int si){
        // If there is one element in array, store it in current node of segment tree and return
        if (ss == se){
            st[si] = arr[ss];
            return arr[ss];
        }
    
        // If there are more than one elements, then recur for left and right subtrees and store the sum of values in this node
        int mid = get_mid(ss, se);
        st[si] = construct_st_util(arr, ss, mid, st, si*2+1) +
                construct_st_util(arr, mid+1, se, st, si*2+2);
        return st[si];
    }

    int *construct_st(vector<int> arr){
        int n = arr.size();
        // Allocate memory for the segment tree
    
        //Height of segment tree
        int x = (int)(ceil(log2(n)));
    
        //Maximum size of segment tree
        int max_size = 2*(int)pow(2, x) - 1;
    
        // Allocate memory
        int *st = new int[max_size];
    
        // Fill the allocated memory st
        construct_st_util(arr, 0, n-1, st, 0);
    
        // Return the constructed segment tree
        return st;
    }

};
