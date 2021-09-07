add_executable(domainTest ${CMAKE_CURRENT_SOURCE_DIR}/domain.cpp)

target_compile_features(domainTest PRIVATE cxx_std_17)
target_link_libraries(domainTest PRIVATE primitive mesh geometry)

add_test(NAME DomainTest COMMAND $<TARGET_FILE:domainTest>)


add_executable(lDiscretizerTest ${CMAKE_CURRENT_SOURCE_DIR}/linear_discretizer.cpp)

target_compile_features(lDiscretizerTest PRIVATE cxx_std_17)
target_link_libraries(
	lDiscretizerTest PRIVATE 
	primitive mesh geometry
	GTest::GTest GTest::Main	
)

gtest_discover_tests(lDiscretizerTest)
