#include "third_party/catch.hpp"
#include "data_structure/tree/segment_tree.hpp"

TEST_CASE("Construct a Segment Tree", "[segment-tree]"){
    SegmentTree tree;

    int *st1 = tree.construct_st(vector<int>({1, 3, 5, 7, 9, 11}));
    int *st2 = tree.construct_st(vector<int>({11, 33, 55, 77, 99, 111}));
    int *st3 = tree.construct_st(vector<int>({12, 23, 45, 67, 89, 91}));
    int *st4 = tree.construct_st(vector<int>({13, 32, 54, 76, 98, 19}));

    //Get sum
    tree.get_sum(st1, vector<int>({1, 3, 5, 7, 9, 11}), 1, 3);
    tree.get_sum(st2, vector<int>({11, 33, 55, 77, 99, 111}), 0, 3);
    tree.get_sum(st3, vector<int>({12, 23, 45, 67, 89, 91}), 0, 2);
    tree.get_sum(st4, vector<int>({13, 32, 54, 76, 98, 19}), 1, 2);

    //Update values
    tree.update_value(vector<int>({1, 3, 5, 7, 9, 11}), st1, 0, 10);
    tree.update_value(vector<int>({11, 33, 55, 77, 99, 111}), st1, 1, 20);
    tree.update_value(vector<int>({12, 23, 45, 67, 89, 91}), st1, 2, 30);
    tree.update_value(vector<int>({13, 32, 54, 76, 98, 19}), st1, 3, 40);
    
}
