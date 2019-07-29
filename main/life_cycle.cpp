//
// Created by Jackson Zhang on 2019-07-26.
//

#include "life_cycle.h"
#include <iostream>

LifeCycle::LifeCycle() {
  std::cout << "Constructor" << std::endl;
}
LifeCycle::~LifeCycle() {
  std::cout << "Destructor" << std::endl;
}
LifeCycle::LifeCycle(const LifeCycle &other) {
  std::cout << "Copy Constructor" << std::endl;
}
LifeCycle::LifeCycle(LifeCycle &&other) noexcept {
  std::cout << "Move Constructor" << std::endl;
}
LifeCycle &LifeCycle::operator=(const LifeCycle &other) {
  std::cout << "Copy Assignment" << std::endl;
  return *this = LifeCycle(other);
}
LifeCycle &LifeCycle::operator=(LifeCycle &&other) noexcept {
  std::cout << "Move Assignment" << std::endl;
  return *this;
}
void printLifeCycle() {
  LifeCycle c1;
  LifeCycle c2;
  LifeCycle c3;

  std::cout << "---------------" << std::endl;

  LifeCycle cs[] = {c1, c2, c3};
  std::cout << cs << std::endl;

  std::cout << "---------------" << std::endl;

  std::vector<LifeCycle> clist = {c1, c2, c3};

  std::cout << "---------------" << std::endl;

  std::vector<LifeCycle> vs[] = {clist};

  std::cout << "---------------" << std::endl;
}
