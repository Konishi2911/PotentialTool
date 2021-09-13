add_executable(vSegTest ${CMAKE_CURRENT_SOURCE_DIR}/vortex_segment_test.cpp)

target_compile_features(vSegTest PRIVATE cxx_std_17)
target_link_libraries(
	vSegTest PRIVATE 
	primitive boundary_element
	GTest::GTest GTest::Main
)

gtest_discover_tests(vSegTest)


add_executable(patchTest ${CMAKE_CURRENT_SOURCE_DIR}/patch.cpp)

target_compile_features(patchTest PRIVATE cxx_std_17)
target_link_libraries(
	patchTest PRIVATE 
	primitive geometry mesh boundary_element
	GTest::GTest GTest::Main
)

gtest_discover_tests(patchTest)
