#include "phone.h"

#include <iostream>

class Phone {
 public:
};

class Contact {};

class PhoneNumber {
 public:
  PhoneNumber(std::string& phoneNumber) {
    if (checkPhoneNumber(phoneNumber) == ErrorCode::Accept) {
      number_ = phoneNumber;
    } else if (checkPhoneNumber(phoneNumber) == ErrorCode::Length) {
      std::cout << "Incorrect length\n";
    } else if (checkPhoneNumber(phoneNumber) == ErrorCode::NoPlus) {
      std::cout << "Plus\n"; // + should be automaticaly !!!!!!!!!!!!!!!
    }
  }

 private:
  std::string number_{};
  enum class ErrorCode {
    Length,
    NoPlus,
    NoNumber,
    Accept,
  };
  ErrorCode checkPhoneNumber(std::string& phoneNumber) {
    if (phoneNumber.size() != 12) return ErrorCode::Length;
    if (phoneNumber.front() != '+') return ErrorCode::NoPlus;
    for (int i{}; i < phoneNumber.size(); ++i) {
      if (*(phoneNumber.data() + i) < '0' && *(phoneNumber.data() + i) > '9') {
        return ErrorCode::NoNumber;
      }
    }
    return ErrorCode::Accept;
  }
};
