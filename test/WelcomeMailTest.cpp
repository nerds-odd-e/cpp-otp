//
// Created by Jackson Zhang on 2019-02-20.
//

#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../main/WelcomeMail.h"
#include "MockOutbox.h"

using ::testing::StrEq;

class WelcomeMailTest : public testing::Test {
protected:
    MockOutbox mockOutbox;
    WelcomeMail mail = WelcomeMail(mockOutbox);
};

TEST_F(WelcomeMailTest, Send){
    EXPECT_CALL(mockOutbox, send(StrEq("new@member.com"), StrEq("Welcome"), StrEq("Welcome to join us.")));
    mail.send();
}
