#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "StubProfileDao.h"
#include "gmock/gmock.h"
#include "StubRsaTokenDao.h"
#include "MockLogger.h"
#include <fruit/fruit.h>

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::StrEq;

fruit::Component<IAuthenticationService> getAuthenticationServiceComponent() {
    return fruit::createComponent()
            .bind<IRsaTokenDao, RsaTokenDao>()
            .bind<ILogger, Logger>()
            .bind<IProfileDao, ProfileDao>()
            .bind<IAuthenticationService, AuthenticationService>();
}

class AuthenticationServiceTest : public testing::Test {
protected:
    NiceMock<StubProfileDao> stubProfileDao;
    NiceMock<StubRsaTokenDao> stubRsaTokenDao;
    MockLogger mockLogger;
    AuthenticationService target = AuthenticationService(&stubProfileDao, &stubRsaTokenDao, &mockLogger);

    void givenPassword(string userName, string password) {
        ON_CALL(stubProfileDao, getPassword(userName)).WillByDefault(Return(password));
    }

    void givenToken(string userName, string token) {
        ON_CALL(stubRsaTokenDao, getRandom(userName)).WillByDefault(Return(token));
    }

};

TEST_F(AuthenticationServiceTest, IsValid) {
    givenPassword("joey", "91");
    givenToken("joey", "000000");

    ASSERT_TRUE(target.isValid("joey", "91000000"));
}

TEST_F(AuthenticationServiceTest, IsNotValid) {
    givenPassword("joey", "91");
    givenToken("joey", "000000");

    EXPECT_CALL(mockLogger, log(StrEq("log in failed")));
    ASSERT_FALSE(target.isValid("joey", "wrong password"));
}

TEST_F(AuthenticationServiceTest, NormalUsage) {
    ConcreteAuthenticationService target;

    ASSERT_FALSE(target.isValid("joey", "91264206"));
}

TEST_F(AuthenticationServiceTest, DI) {
    fruit::Injector<IAuthenticationService> injector(getAuthenticationServiceComponent);
    IAuthenticationService *authenticationService(injector);

    ASSERT_FALSE(authenticationService->isValid("joey", "91264206"));
}

