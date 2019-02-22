//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_NOWSTRING_H
#define CPP_OTP_NOWSTRING_H

#include <string>
#include "TimeProvider.h"

using namespace std;

class NowString {

public:
    explicit NowString(TimeProvider &timeProvider);

    string get();

private:
    TimeProvider &timeProvider;
};


#endif //CPP_OTP_NOWSTRING_H
