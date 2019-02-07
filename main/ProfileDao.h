#ifndef CPP_OTP_PROFILEDAO_H
#define CPP_OTP_PROFILEDAO_H

#include <string>
#include <fruit/fruit.h>

using namespace std;

class IProfileDao {
public:
    virtual string getPassword(string userName) = 0;
};

class ProfileDao : public IProfileDao {

public:
    INJECT(ProfileDao()) = default;

    virtual string getPassword(string userName);
};

#endif //CPP_OTP_PROFILEDAO_H
