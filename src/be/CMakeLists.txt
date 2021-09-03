file(GLOB_RECURSE POTS_BE_SOURCE_FILES
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	./*.cpp/
)

find_package(Eigen3 REQUIRED)

add_library(boundary_element SHARED ${POTS_BE_SOURCE_FILES})

set_property(TARGET boundary_element PROPERTY CXX_STANDARD 17)

target_link_libraries(boundary_element PRIVATE primitive)
target_include_directories(boundary_element PUBLIC /opt/homebrew/Cellar/eigen/3.4.0/include/eigen3)
