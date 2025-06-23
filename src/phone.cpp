#include "phone.h"

#include <algorithm>  // for std::ranges::transform
#include <cctype>     // for std::toupper, std::tolower, std::isalpha
#include <iostream>
#include <map>

class Phone {
 public:
  void Add() {}
  void Call() {}
  void Sms() {}
  void Exit() {}

 private:
  std::map<PhoneNumber, std::string> contacts_;
};

class Contact {
 public:
  void set(const std::string& name, const PhoneNumber& phoneNumber) {
    if (!checkName(name)) {
      std::cout << "Incorrect symbol\n";
    } else {
      name_ = name;
      name_[0] = static_cast<char>(std::toupper(name_[0]));
      if (name_.size() > 1) {
        std::ranges::transform(name_.begin() + 1, name_.end(),
                               name_.begin() + 1, ::tolower);
      }
    }
    phoneNumber_ = phoneNumber;
  }
  void get() {}

 private:
  std::string name_;
  PhoneNumber phoneNumber_;
  bool checkName(const std::string& name) {
    for (const auto x : name) {
      if (!std::isalpha(static_cast<unsigned char>(x)))
        return false;  // a check for Latin alphabet characters using <cctype>
    }
    return true;
  }
};

class PhoneNumber {
 public:
  PhoneNumber(const std::string& phoneNumber) {
    if (checkPhoneNumber(phoneNumber) == ErrorCode::Length) {
      std::cout << "Incorrect length\n";
    } else if (checkPhoneNumber(phoneNumber) == ErrorCode::NoNumber) {
      std::cout << "Incorrect symbol\n";
    } else
      number_ = "+7" + phoneNumber;
  }

  // Required for using PhoneNumber as a key in std::map (strict weak ordering)
  bool operator<(const PhoneNumber& other) const {
    return number_ < other.number_;
  }

 private:
  std::string number_{};
  enum class ErrorCode {
    Length,
    NoNumber,
    Accept,
  };
  ErrorCode checkPhoneNumber(const std::string& phoneNumber) {
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
};
