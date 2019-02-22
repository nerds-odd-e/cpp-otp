//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_WELCOMEMAIL_H
#define CPP_OTP_WELCOMEMAIL_H


#include "Outbox.h"

class WelcomeMail {

public:
    WelcomeMail(Outbox &outbox);

    void send();

private:
    Outbox &outbox;
};


#endif //CPP_OTP_WELCOMEMAIL_H
