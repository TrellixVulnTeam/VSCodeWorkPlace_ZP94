#指定最小cmake版本
cmake_minimum_required(VERSION 3.0.0)
project(C_DataStructure VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    main.c
    DataStructure/List/SeqList/SeqList.c
    DataStructure/List/LinkList/LinkList.c
    DataStructure/Stack/SeqStack/SeqStack.c
    DataStructure/Stack/LinkStack/LinkStack.c
    DataStructure/Queue/LinkQueue/LinkQueue.c
    DataStructure/Queue/SeqQueue/SeqQueue.c
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
