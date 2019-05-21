//
// Created by Jackson Zhang on 2019-02-20.
//

#include <gtest/gtest.h>
#include "../main/NowString.h"
#include "gmock/gmock.h"
#include "StubTimeProvider.h"
#include "time.h"

using ::testing::NiceMock;
using ::testing::Return;

class NowStringTest: public testing::Test {
protected:
    std::unique_ptr<NiceMock<StubTimeProvider>> stubTimeProvider = std::make_unique<NiceMock<StubTimeProvider>>();
//    NowString nowString = NowString{std::move(stubTimeProvider)};
//
    void givenCurrentTime(string time){
        struct tm tm;
        time_t t;
        strptime(time.c_str(), "%F %T", &tm);
        tm.tm_isdst = -1;
        t = mktime(&tm);
        ON_CALL(*stubTimeProvider, now()).WillByDefault(Return(t));
    }
};

TEST_F(NowStringTest, ShowCurrentTime) {
//    std::unique_ptr<NiceMock<StubTimeProvider>> stubTimeProvider = std::make_unique<NiceMock<StubTimeProvider>>();
//
//    string time = "2019-01-20 18:30:45";
//    struct tm tm;
//    time_t t;
//    strptime(time.c_str(), "%F %T", &tm);
//    tm.tm_isdst = -1;
//    t = mktime(&tm);
//    ON_CALL(*stubTimeProvider, now()).WillByDefault(Return(t));

    givenCurrentTime("2019-01-20 18:30:45");
    NowString nowString = NowString{std::move(stubTimeProvider)};
    ASSERT_EQ(nowString.get(), "2019-01-20 18:30:45");
}
