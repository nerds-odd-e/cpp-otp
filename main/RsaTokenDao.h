#ifndef CPP_OTP_RSATOKENDAO_H
#define CPP_OTP_RSATOKENDAO_H

#include <string>
#include <fruit/fruit.h>

using namespace std;

class IRsaTokenDao {
public:
    virtual string getRandom(string userName) = 0;
};

class RsaTokenDao : public IRsaTokenDao {

public:
    INJECT(RsaTokenDao()) = default;

    virtual string getRandom(string userName);
};

#endif //CPP_OTP_RSATOKENDAO_H
