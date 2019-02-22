//
// Created by Jackson Zhang on 2019-02-20.
//

#include "WelcomeMail.h"

WelcomeMail::WelcomeMail(Outbox &outbox) : outbox(outbox) {

}

void WelcomeMail::send() {
    outbox.send("new@member.com", "Welcome", "Welcome to join us.");
}

