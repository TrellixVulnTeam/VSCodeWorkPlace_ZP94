#指定最小cmake版本
cmake_minimum_required(VERSION 3.0.0)
project(C_DataStructure VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    main.c
    DataStructure/List/seqList/seqList.c
    DataStructure/List/LinkList/linkList.c
)

#生成的可执行文件
add_executable(main ${SOURCES})

target_include_directories(main
    PRIVATE
        ${PROJECT_SOURCE_DIR}/DataStructure/List/seqList/
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
