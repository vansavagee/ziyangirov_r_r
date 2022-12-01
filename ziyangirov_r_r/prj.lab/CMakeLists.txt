add_subdirectory(matplotplusplus)
add_executable(btest_test btest_test.cpp)
target_link_libraries(btest_test PUBLIC matplot)
set_property (TARGET btest_test
  PROPERTY
    CXX_STANDARD 20
)