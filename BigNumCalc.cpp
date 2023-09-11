#include "BigNumCalc.h"

#include <iostream>
#include <list>
#include <string>

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
  std::list<int> nums;
  for (int i = 0; i < numString.length(); i++) {
    nums.push_back((numString[i] - '0'));
  }
  return nums;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  // check which number is bigger
  if (num1.size() < num2.size()) {
    while (num1.size() < num2.size()) {
      num1.push_front(0);
    }
  } else {
    while (num2.size() < num1.size()) {
      num2.push_front(0);
    }
  }

  std::list<int> result;
  int rem = 0;
  for (int i = num1.size() - 1; i >= 0; i--) {
    // get element 1
    auto e1 = std::next(num1.begin(), i);

    // get element 2
    auto e2 = std::next(num2.begin(), i);

    // add elements
    int add = *e1 + *e2 + rem;

    // do rem
    if (add >= 10) {
      rem = 1;
      add = add - 10;
    } else {
      rem = 0;
    }

    // push add value to front of result
    if (i == 0) {
      result.push_front(add);
      if (rem != 0) {
        result.push_front(rem);
      }
    } else {
      result.push_front(add);
    }
  }
  return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> temp;
  std::list<int> result;
  // check which number is bigger
  if (num1.size() < num2.size()) {
    while (num1.size() < num2.size()) {
      num1.push_front(0);
    }
  } else {
    while (num2.size() < num1.size()) {
      num2.push_front(0);
    }
  }

  for (int i = num2.size() - 1; i >= 0; i--) {
    // get element 1
    auto e1 = std::next(num1.begin(), i);

    // get element 2
    auto e2 = std::next(num2.begin(), i);

    if (*e2 > *e1) {
      *e1 = *e1 + 10;
      auto ch = std::next(num1.begin(), i - 1);
      *ch = *ch - 1;
    }

    int sub = *e1 - *e2;
    temp.push_front(sub);
  }

  int check = 0;
  for (int i = 0; i < temp.size(); i++) {
    auto ch = std::next(temp.begin(), i);
    if ((check == 0) && (*ch > 0)) {
      check = 1;
    }

    if (check > 0) {
      result.push_back(*ch);
    }
  }

  return result;
};

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int rem = 0;

  for (int i = num1.size() - 1; i >= 0; i--) {
    // get element 1
    auto e1 = std::next(num1.begin(), i);
    // get element 2
    auto e2 = std::next(num2.begin(), 0);

    int mul = (*e1 * *e2) + rem;

    std::string mu;

    if (mul >= 10) {
      mu = std::to_string(mul);
      rem = (mu[0] - '0');
      mul = (mu[1] - '0');
    } else {
      rem = 0;
    }

    // push add value to front of result
    if (i == 0) {
      result.push_front(mul);
      if (rem != 0) {
        result.push_front(rem);
      }
    } else {
      result.push_front(mul);
    }
  }

  return result;
};