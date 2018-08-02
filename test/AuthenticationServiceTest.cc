#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "StubProfileDao.h"
#include "gmock/gmock.h"
#include "StubRsaTokenDao.h"

using ::testing::NiceMock;
using ::testing::Return;

namespace {

    TEST(AuthenticationService, IsValid) {
        NiceMock<StubProfileDao> stubProfileDao;
        ON_CALL(stubProfileDao, getPassword("joey")).WillByDefault(Return("91"));
        NiceMock<StubRsaTokenDao> stubRsaTokenDao;
        ON_CALL(stubRsaTokenDao, getRandom("joey")).WillByDefault(Return("000000"));
        AuthenticationService target(stubProfileDao, stubRsaTokenDao);

        bool actual = target.isValid("joey", "91000000");

        ASSERT_TRUE(actual);
    }

}