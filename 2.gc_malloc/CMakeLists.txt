# 设置头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
# 设置源文件搜索路径
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRCS)
# 添加源文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
# 添加测试源文件目录为所有后缀名为.c的源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/test TEST_SRCS)

# 添加lib库搜索路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 设置目标文件名
set(TARGET_NAME "2.gc_malloc")
# 设置目标lib
set(TARGET_LIB "gc_malloc")
# 生成目标文件
add_executable(${TARGET_NAME} ${SRCS} ${TEST_SRCS})
# 添加链接库
target_link_libraries(${TARGET_NAME} malloc)

# 生成目标库
add_library(${TARGET_LIB} ${SRCS})
target_link_libraries(${TARGET_LIB} malloc)

# 将生成的目标文件移动到与src目录同级的out目录下
set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")
# 将生成的目标lib文件移动到与src目录同级的out目录下
set_target_properties(${TARGET_LIB} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")

