#include "third_party/catch.hpp"
#include "data_structure/tree/segment_tree.hpp"

TEST_CASE("range sum query", "[segment-tree]") {
    vector<int> ar{-1,-2,0,3,4,5,2,-1};
    
    SegmentTree<int> array(ar);
    
    // enqurire for range sum on original array
    REQUIRE(array.range_sum_query(0,0)==-1);
    REQUIRE(array.range_sum_query(0,1)==-3);
    REQUIRE(array.range_sum_query(0,2)==-3);
    REQUIRE(array.range_sum_query(1,3)==1);
    REQUIRE(array.range_sum_query(7,7)==-1);
    REQUIRE(array.range_sum_query(5,7)==6);
    REQUIRE(array.range_sum_query(0,7)==10);

    // update array
    array.point_update(0,1);
    array.point_update(2,-5);
    array.point_update(3,-4);

    // enqurire for range sum on original array
    REQUIRE(array.range_sum_query(0,0)==1);
    REQUIRE(array.range_sum_query(0,1)==-1);
    REQUIRE(array.range_sum_query(0,2)==-6);
    REQUIRE(array.range_sum_query(1,3)==-11);
    REQUIRE(array.range_sum_query(7,7)==-1);
    REQUIRE(array.range_sum_query(5,7)==6);
    REQUIRE(array.range_sum_query(0,7)==0);
}

TEST_CASE("range product query", "[segment-tree]") {
    vector<int> ar{-1,-2,0,3,4,5,2,-1};
    
    SegmentTree<int> array(ar);
    
    // enqurire for range product 
    REQUIRE(array.range_prod_query(0,0)==-1);
    REQUIRE(array.range_prod_query(0,1)==2);
    REQUIRE(array.range_prod_query(0,2)==0);
    REQUIRE(array.range_prod_query(1,3)==0);
    REQUIRE(array.range_prod_query(7,7)==-1);
    REQUIRE(array.range_prod_query(5,7)==-10);
    REQUIRE(array.range_prod_query(0,7)==0);

    // update array
    array.point_update(2,1);
    
    // enqurire for range product 
    REQUIRE(array.range_prod_query(0,0)==-1);
    REQUIRE(array.range_prod_query(0,1)==2);
    REQUIRE(array.range_prod_query(0,2)==2);
    REQUIRE(array.range_prod_query(1,3)==-6);
    REQUIRE(array.range_prod_query(7,7)==-1);
    REQUIRE(array.range_prod_query(5,7)==-10);
    REQUIRE(array.range_prod_query(0,7)==-240);
}

TEST_CASE("range max query", "[segment-tree]") {
    vector<int> ar{-1,-2,0,3,4,5,2,-1};
    
    SegmentTree<int> array(ar);
    
    // enqurire for range max 
    REQUIRE(array.range_prod_query(0,0)==-1);
    REQUIRE(array.range_prod_query(0,1)==-1);
    REQUIRE(array.range_prod_query(0,2)==0);
    REQUIRE(array.range_prod_query(1,3)==3);
    REQUIRE(array.range_prod_query(7,7)==-1);
    REQUIRE(array.range_prod_query(5,7)==5);
    REQUIRE(array.range_prod_query(0,7)==5);

    // update array
    array.point_update(2,1e5);
    array.point_update(5,-1e5);

    // enqurire for range max 
    REQUIRE(array.range_prod_query(0,0)==-1);
    REQUIRE(array.range_prod_query(0,1)==-1);
    REQUIRE(array.range_prod_query(0,2)==1e5);
    REQUIRE(array.range_prod_query(1,3)==1e5);
    REQUIRE(array.range_prod_query(7,7)==-1);
    REQUIRE(array.range_prod_query(5,7)==2);
    REQUIRE(array.range_prod_query(0,7)==4);
}

TEST_CASE("range min query", "[segment-tree]") {
    vector<int> ar{-1,-2,0,3,4,5,2,-1};
    
    SegmentTree<int> array(ar);
    
    // enqurire for range min 
    REQUIRE(array.range_prod_query(0,0)==-1);
    REQUIRE(array.range_prod_query(0,1)==-2);
    REQUIRE(array.range_prod_query(0,2)==-2);
    REQUIRE(array.range_prod_query(1,3)==-2);
    REQUIRE(array.range_prod_query(7,7)==-1);
    REQUIRE(array.range_prod_query(5,7)==-1);
    REQUIRE(array.range_prod_query(0,7)==-2);

    // update array
    array.point_update(0,-1e5);
    array.point_update(7,1e5);

    // enqurire for range min 
    REQUIRE(array.range_prod_query(0,0)==-1e5);
    REQUIRE(array.range_prod_query(0,1)==-1e5);
    REQUIRE(array.range_prod_query(0,2)==-1e5);
    REQUIRE(array.range_prod_query(1,3)==-2);
    REQUIRE(array.range_prod_query(7,7)==1e5);
    REQUIRE(array.range_prod_query(5,7)==2);
    REQUIRE(array.range_prod_query(0,7)==-1e5);
}



