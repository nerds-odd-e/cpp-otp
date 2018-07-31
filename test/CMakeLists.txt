set(Test_SRCS sample_unittest.cc)

add_executable(cpp_otp_test ${Test_SRCS})
target_link_libraries(cpp_otp_test gtest gtest_main core)
