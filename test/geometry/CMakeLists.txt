add_executable(segTest ${CMAKE_CURRENT_SOURCE_DIR}/segment_test.cpp)

target_compile_features(segTest PRIVATE cxx_std_17)
target_link_libraries(segTest PRIVATE primitive geometry)


add_executable(polylineTest ${CMAKE_CURRENT_SOURCE_DIR}/polyline_test.cpp)

target_compile_features(polylineTest PRIVATE cxx_std_17)
target_link_libraries(polylineTest PRIVATE primitive geometry)


add_test(NAME GeometrySegmentTest COMMAND $<TARGET_FILE:segTest>)
add_test(NAME GeometryPolylineTest COMMAND $<TARGET_FILE:polylineTest>)
