//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_OUTBOX_H
#define CPP_OTP_OUTBOX_H

#include <string>

using namespace std;

class Mail
{
 public:
  string to;
};

class Outbox {

public:
    virtual ~Outbox() = default;
    virtual void send(string receiver, string title, string content, const Mail& mail) const;

};


#endif //CPP_OTP_OUTBOX_H
