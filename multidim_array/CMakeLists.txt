set( LINK_LIBS  
)

set( INCLUDES
	${CMAKE_INCLUDE_SOURCE_DIR}/include
 )

get_filename_component(TARGET_LIB ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB TARGET_SRCS "*.c" "*.cpp" "*.cc")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${TARGET_LIB} ${TARGET_SRCS})
target_include_directories(${TARGET_LIB} PUBLIC ${INCLUDES})
target_link_libraries(${TARGET_LIB} ${LINK_LIBS})


