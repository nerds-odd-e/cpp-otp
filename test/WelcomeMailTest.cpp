//
// Created by Jackson Zhang on 2019-02-20.
//

#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../main/WelcomeMail.h"
#include "MockOutbox.h"

using ::testing::StrEq;

class WelcomeMailTest : public testing::Test {
//protected:
//    std::unique_ptr<MockOutbox> mockOutbox = std::make_unique<MockOutbox>();
//    WelcomeMail mail = WelcomeMail(std::move(mockOutbox));
};

TEST_F(WelcomeMailTest, Send){
    MockOutbox mockOutbox;
    Mail mailSent;
    EXPECT_CALL(mockOutbox, send(StrEq("new@member.com"), StrEq("Welcome"), StrEq("Welcome to join us."), testing::_)).WillOnce(testing::SaveArg<3>(&mailSent));
    WelcomeMail mail = WelcomeMail(mockOutbox);
    mail.send();
    EXPECT_EQ("new@member.com", mailSent.to);
}
