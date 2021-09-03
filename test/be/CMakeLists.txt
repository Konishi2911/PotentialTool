add_executable(vSegTest ${CMAKE_CURRENT_SOURCE_DIR}/vortex_segment_test.cpp)

target_compile_features(vSegTest PRIVATE cxx_std_17)
target_link_libraries(vSegTest PRIVATE primitive boundary_element)

add_test(NAME VortexSegmentTest COMMAND $<TARGET_FILE:vSegTest>)
