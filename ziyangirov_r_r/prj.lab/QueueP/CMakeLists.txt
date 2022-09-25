add_library(Queuep Queuep.h Queuep.cpp)

add_executable(Queuep_test Queuep_test.cpp)
target_link_libraries(Queuep_test Queuep)


