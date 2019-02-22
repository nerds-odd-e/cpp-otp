//
// Created by Jackson Zhang on 2019-02-20.
//

#include <sstream>
#include "NowString.h"
#include <iomanip>

NowString::NowString(TimeProvider &timeProvider): timeProvider(timeProvider) {

}

string NowString::get() {
    auto t = timeProvider.now();
    ostringstream oss;
    oss << put_time(localtime(&t), "%F %T");
    return oss.str();
}
