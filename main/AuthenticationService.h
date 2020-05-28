#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include <string>
#include "ProfileDao.h"
#include "RsaTokenDao.h"
#include "Logger.h"
#include <fruit/fruit.h>

using namespace std;

class SimpleServiceWithLocalVar {
public:
    void doSomething();
};

class AuthenticationService {

public:
    INJECT(AuthenticationService(ProfileDao& profileDao, RsaTokenDao& rsaTokenDao, Logger& logger));

    virtual bool isValid(string userName, string password);

private:
    ProfileDao& profileDao;
    RsaTokenDao& rsaTokenDao;
    Logger& logger;
};

class ConcreteAuthenticationService : public AuthenticationService {
public:
    ConcreteAuthenticationService() : AuthenticationService(profileDao, rsaTokenDao, logger) { }

private:
    ProfileDao profileDao;
    RsaTokenDao rsaTokenDao;
    Logger logger;
};


#endif //CPP_OTP_AUTHENTICATIONSERVICE_H
