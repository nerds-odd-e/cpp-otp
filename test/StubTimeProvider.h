//
// Created by Jackson Zhang on 2019-02-20.
//

#ifndef CPP_OTP_STUBTIMEPROVIDER_H
#define CPP_OTP_STUBTIMEPROVIDER_H

#include "gmock/gmock.h"
#include "../main/TimeProvider.h"

using namespace std;

class StubTimeProvider : public TimeProvider {
public:
    MOCK_METHOD0(now, time_t());
};

#endif //CPP_OTP_STUBTIMEPROVIDER_H
