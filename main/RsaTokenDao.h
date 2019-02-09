#ifndef CPP_OTP_RSATOKENDAO_H
#define CPP_OTP_RSATOKENDAO_H

#include <string>
#include <fruit/fruit.h>

using namespace std;

class RsaTokenDao {

public:
    INJECT(RsaTokenDao()) = default;

    virtual string getRandom(string userName);
};

#endif //CPP_OTP_RSATOKENDAO_H
