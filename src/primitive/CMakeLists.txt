file(GLOB_RECURSE POTS_PRIMITIVES_SOURCE_FILES
	RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	./*.cpp/
)

add_library(primitive SHARED ${POTS_PRIMITIVES_SOURCE_FILES})

set_property(TARGET primitive PROPERTY CXX_STANDARD 17)
