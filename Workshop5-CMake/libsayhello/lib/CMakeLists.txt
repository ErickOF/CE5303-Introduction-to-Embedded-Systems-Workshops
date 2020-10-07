#add include to directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

#set the proper macros
set(LIBRARY_NAME sayhello)
set(SRC_FILES say.c)
set(INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/say.h)

#add the library
add_library(${LIBRARY_NAME} SHARED ${SRC_FILES} ${INCLUDE_FILES})

#installing the library
install (TARGETS ${LIBRARY_NAME} DESTINATION lib)
install (FILES ${INCLUDE_FILES} DESTINATION include)