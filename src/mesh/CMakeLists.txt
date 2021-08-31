file(GLOB_RECURSE POTS_MESH_SOURCE_FILES
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	./*.cpp/
)

add_library(mesh SHARED ${POTS_MESH_SOURCE_FILES})

set_property(TARGET mesh PROPERTY CXX_STANDARD 17)

target_link_libraries(mesh PRIVATE primitive)
