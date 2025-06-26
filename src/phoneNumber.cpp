// phoneNumber.cpp
#include "phoneNumber.h"

#include <iostream>
#include <string>

PhoneNumber::PhoneNumber(const std::string& phoneNumber) {
  if (checkPhoneNumber(phoneNumber) == ErrorCode::Length) {
    std::cout << "Incorrect length\n";
    throw std::invalid_argument("Incorrect length");
  } else if (checkPhoneNumber(phoneNumber) == ErrorCode::NoNumber) {
    std::cout << "Incorrect symbol\n";
    throw std::invalid_argument("Incorrect length");
  } else
    number_ = "+7" + phoneNumber;
}

std::ostream& operator<<(std::ostream& os, const PhoneNumber& number) {
  os << number.number_;
  return os;
}

bool operator==(const PhoneNumber& lhs, const std::string& rhs) {
  return lhs.number_ == rhs;
}
bool operator==(const std::string& rhs, const PhoneNumber& lhs) {
  return lhs.number_ == rhs;
}

PhoneNumber::ErrorCode PhoneNumber::checkPhoneNumber(const std::string& phoneNumber) {
  if (phoneNumber.size() != 10) return ErrorCode::Length;
  for (int i{}; i < phoneNumber.size(); ++i) {
    if (*(phoneNumber.data() + i) < '0' ||
        *(phoneNumber.data() + i) > '9') {  // Pointers for learning (date for string only)
      return ErrorCode::NoNumber;
    }
  }
  return ErrorCode::Accept;
}
