set(tBTreeLib "frame")

add_library(${tBTreeLib} STATIC src/btree.cpp)
target_include_directories(${tBTreeLib} PUBLIC pub_include)
target_include_directories(${tBTreeLib} PUBLIC prt_include)
target_link_libraries(${tBTreeLib} PUBLIC )
target_compile_features(${tBTreeLib} PUBLIC cxx_std_23)