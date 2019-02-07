#ifndef CPP_OTP_LOGGER_H
#define CPP_OTP_LOGGER_H

#include <string>
#include <fruit/fruit.h>

using namespace std;

class ILogger {
public:
    virtual void log(string message) = 0;
};

class Logger : public ILogger {

public:
    INJECT(Logger()) = default;
    virtual void log(string message);

};

#endif //CPP_OTP_LOGGER_H
