//
// Created by Jackson Zhang on 2019-02-20.
//

#include <sstream>
#include <iomanip>
#include "NowString.h"

NowString::NowString(TimeProvider &timeProvider): timeProvider(timeProvider) {

}

string NowString::get() {
    auto t = timeProvider.now();
    ostringstream oss;
    oss << put_time(localtime(&t), "%F %T");
    return oss.str();
}

NowString createNowString() {
    TimeProvider&& timeProvider = TimeProvider{};
    return NowString{timeProvider};
}

NowString NowStringFactory::createNowString() {
    return NowString{timeProvider};
}
