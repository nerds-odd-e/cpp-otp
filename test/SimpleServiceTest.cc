#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"

class SimpleServiceTest : public testing::Test {

};

void Logger::log(string message) {
    std::cout << "logger defined in test" << std::endl;
}

TEST_F(SimpleServiceTest, doSomething) {
    SimpleServiceWithLocalVar sut;

    sut.doSomething();
}
