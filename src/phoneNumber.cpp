#include "phoneNumber.h"

#include <iostream>
#include <string>

PhoneNumber::PhoneNumber(const std::string& phoneNumber) {
  if (checkPhoneNumber(phoneNumber) == ErrorCode::Length) {
    std::cout << "Incorrect length\n";
  } else if (checkPhoneNumber(phoneNumber) == ErrorCode::NoNumber) {
    std::cout << "Incorrect symbol\n";
  } else
    number_ = "+7" + phoneNumber;
}

PhoneNumber::ErrorCode PhoneNumber::checkPhoneNumber(const std::string& phoneNumber) {
  if (phoneNumber.size() != 10) return ErrorCode::Length;
  for (int i{}; i < phoneNumber.size(); ++i) {
    if (*(phoneNumber.data() + i) < '0' ||
        *(phoneNumber.data() + i) >
            '9') {  // Pointers for learning (date for string only)
      return ErrorCode::NoNumber;
    }
  }
  return ErrorCode::Accept;
}
