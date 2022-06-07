cmake_minimum_required(VERSION 3.19)
project(test_analyze_homework)

set(CMAKE_CXX_STANDARD  17)

# 该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名
aux_source_directory(. SOURCE_FILES)

add_executable(${PROJECT_NAME}  test_analyze_homework.cpp ${SOURCE_FILES} )