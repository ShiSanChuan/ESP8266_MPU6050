FIND_PACKAGE( OpenCV REQUIRED ) 

aux_source_directory(. DIR_SRCS)
add_executable(hello ${DIR_SRCS})

TARGET_LINK_LIBRARIES(hello ${OpenCV_LIBS})
