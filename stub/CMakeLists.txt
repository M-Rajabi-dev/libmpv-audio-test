cmake_minimum_required(VERSION 3.10)
project(libass C)

add_library(ass STATIC ass_stub.c)

target_include_directories(ass PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS ass ARCHIVE DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ass DESTINATION include)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/libass.pc DESTINATION lib/pkgconfig)
