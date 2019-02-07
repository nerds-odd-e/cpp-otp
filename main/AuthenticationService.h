#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include <string>
#include "ProfileDao.h"
#include "RsaTokenDao.h"
#include "Logger.h"
#include <fruit/fruit.h>

using namespace std;

class IAuthenticationService {
public:
    virtual bool isValid(string userName, string password) = 0;
};

class AuthenticationService : public IAuthenticationService {

public:
    INJECT(AuthenticationService(IProfileDao* profileDao, IRsaTokenDao* rsaTokenDao, ILogger* logger));

    virtual bool isValid(string userName, string password);

private:
    IProfileDao* profileDao;
    IRsaTokenDao* rsaTokenDao;
    ILogger* logger;
};

class ConcreteAuthenticationService : public AuthenticationService {
public:
    ConcreteAuthenticationService() : AuthenticationService(&profileDao, &rsaTokenDao, &logger) { }

private:
    ProfileDao profileDao;
    RsaTokenDao rsaTokenDao;
    Logger logger;
};


#endif //CPP_OTP_AUTHENTICATIONSERVICE_H
