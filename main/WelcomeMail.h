//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_WELCOMEMAIL_H
#define CPP_OTP_WELCOMEMAIL_H


#include "Outbox.h"

class WelcomeMail {

public:
    explicit WelcomeMail(Outbox& outbox);
//    WelcomeMail(std::unique_ptr<Outbox> outbox_ptr);

    void send();

private:
    const Outbox& outbox;
//    std::unique_ptr<Outbox> outbox_ptr;
};

//class ConcreteWelcomeMail: public WelcomeMail {
// public:
//  ConcreteWelcomeMail();
// private:
//  Outbox outbox;
//};


#endif //CPP_OTP_WELCOMEMAIL_H
