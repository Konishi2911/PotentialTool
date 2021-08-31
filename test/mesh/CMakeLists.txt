add_executable(gridTest ${CMAKE_CURRENT_SOURCE_DIR}/grid.cpp)

target_compile_features(gridTest PRIVATE cxx_std_17)
target_link_libraries(gridTest PRIVATE primitive mesh)

add_test(NAME GridTest COMMAND $<TARGET_FILE:gridTest>)
