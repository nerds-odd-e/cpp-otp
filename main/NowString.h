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
//    explicit NowString(TimeProvider& timeProvider);
    explicit NowString(std::unique_ptr<TimeProvider> timeProvider_ptr);

    string get();

private:
//    TimeProvider& timeProvider;
    std::unique_ptr<TimeProvider> timeProvider_ptr;
};

class NowStringFactory {
private:
    TimeProvider timeProvider;

public:
    NowString createNowString();
};

NowString createNowString();

#endif //CPP_OTP_NOWSTRING_H

