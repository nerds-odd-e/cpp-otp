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
    NiceMock<StubTimeProvider> stubTimeProvider;
    NowString nowString = NowString{stubTimeProvider};

    void givenCurrentTime(string time){
        struct tm tm;
        time_t t;
        strptime(time.c_str(), "%F %T", &tm);
        tm.tm_isdst = -1;
        t = mktime(&tm);
        ON_CALL(stubTimeProvider, now()).WillByDefault(Return(t));
    }
};

TEST_F(NowStringTest, ShowCurrentTime) {
    givenCurrentTime("2019-01-20 18:30:45");
    ASSERT_EQ(nowString.get(), "2019-01-20 18:30:45");
}
