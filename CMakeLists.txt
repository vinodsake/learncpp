cmake_minimum_required(VERSION 3.10)

project(learncpp)

file(GLOB SUBDIR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(DIR ${SUBDIR})
	if(IS_DIRECTORY ${DIR})
		if(NOT (${DIR} STREQUAL ".git" OR ${DIR} STREQUAL "_build"))
			message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}")
			file(COPY cmakelist_generator.txt 
				DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}")
			file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/cmakelist_generator.txt 
				${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/CMakeLists.txt)
			add_subdirectory(${DIR})
		endif()
	endif()
endforeach()
