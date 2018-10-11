set(GTEST_SHUFFLE 1)

add_executable(
    libtest
    main.cpp
    Transpose_Test.cpp
    MatrixProduct_Test.cpp
)

target_include_directories(libtest PUBLIC ../vendor/googletest/googletest/include
                                         ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(libtest gtest MatrixfuncShareLib )
