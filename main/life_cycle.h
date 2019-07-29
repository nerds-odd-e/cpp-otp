//
// Created by Jackson Zhang on 2019-07-26.
//

#ifndef CPP_OTP_MAIN_LIFE_CYCLE_H_
#define CPP_OTP_MAIN_LIFE_CYCLE_H_

#include <iostream>
#include <vector>

class LifeCycle {
 public:
  LifeCycle();
  ~LifeCycle();
  LifeCycle(const LifeCycle& other);
  LifeCycle(LifeCycle&& other) noexcept;
  LifeCycle& operator=(const LifeCycle& other);
  LifeCycle& operator=(LifeCycle&& other) noexcept;
};

void printLifeCycle();

#endif //CPP_OTP_MAIN_LIFE_CYCLE_H_
