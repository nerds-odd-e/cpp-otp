//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_TIMEPROVIDER_H
#define CPP_OTP_TIMEPROVIDER_H


class TimeProvider {
public:
    virtual time_t now();
};


#endif //CPP_OTP_TIMEPROVIDER_H
