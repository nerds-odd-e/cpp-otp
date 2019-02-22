//
// Created by Jackson Zhang on 2019-02-20.
//

#include <ctime>
#include "TimeProvider.h"

time_t TimeProvider::now() {
    return time(nullptr);
}
