//
// Created by Jackson Zhang on 2019-02-20.
//

#include <sstream>
#include <iomanip>
#include "NowString.h"

//NowString::NowString(TimeProvider &timeProvider): timeProvider(timeProvider) {
//
//}

NowString::NowString(std::unique_ptr<TimeProvider> timeProvider_ptr): timeProvider_ptr(std::move(timeProvider_ptr)) {}

string NowString::get() {
    auto t = timeProvider_ptr->now();
    ostringstream oss;
    oss << put_time(localtime(&t), "%F %T");
    return oss.str();
}

NowString createNowString() {
    std::unique_ptr<TimeProvider> timeProvider = std::make_unique<TimeProvider>();
    return NowString{std::move(timeProvider)};
}

NowString NowStringFactory::createNowString() {
    std::unique_ptr<TimeProvider> timeProvider = std::make_unique<TimeProvider>();
    return NowString{std::move(timeProvider)};
}
