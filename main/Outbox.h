//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_OUTBOX_H
#define CPP_OTP_OUTBOX_H

#include <string>

using namespace std;

class Outbox {

public:
    virtual void send(string receiver, string title, string content);

};


#endif //CPP_OTP_OUTBOX_H
