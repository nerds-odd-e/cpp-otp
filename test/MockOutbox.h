//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_MOCKOUTBOX_H
#define CPP_OTP_MOCKOUTBOX_H

#include "gmock/gmock.h"
#include "../main/Outbox.h"

class MockOutbox : public Outbox {
public:
    MOCK_METHOD3(send, void(string, string, string));
};
#endif //CPP_OTP_MOCKOUTBOX_H