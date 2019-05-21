//
// Created by Jackson Zhang on 2019-02-20.
//

#include "WelcomeMail.h"

//WelcomeMail::WelcomeMail(Outbox &outbox) : outbox(outbox) {
//
//}

void WelcomeMail::send() {
    outbox_ptr->send("new@member.com", "Welcome", "Welcome to join us.");
}

WelcomeMail::WelcomeMail(std::unique_ptr<Outbox> outbox_ptr): outbox_ptr(std::move(outbox_ptr)) {

}

