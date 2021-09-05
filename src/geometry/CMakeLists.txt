file(GLOB_RECURSE POTS_GEOM_SOURCE_FILES
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	./*.cpp/
)

add_library(geometry SHARED ${POTS_GEOM_SOURCE_FILES})

set_property(TARGET geometry PROPERTY CXX_STANDARD 17)

target_link_libraries(geometry PRIVATE primitive)
