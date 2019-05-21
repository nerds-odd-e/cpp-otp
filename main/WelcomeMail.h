//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_WELCOMEMAIL_H
#define CPP_OTP_WELCOMEMAIL_H


#include "Outbox.h"

class WelcomeMail {

public:
//    WelcomeMail(Outbox &outbox);
    WelcomeMail(std::unique_ptr<Outbox> outbox_ptr);

    void send();

private:
//    Outbox &outbox;
    std::unique_ptr<Outbox> outbox_ptr;
};


#endif //CPP_OTP_WELCOMEMAIL_H
