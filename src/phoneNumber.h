#pragma once

#include <string>

class PhoneNumber {
 public:
  PhoneNumber(const std::string& phoneNumber);

 private:
  std::string number_{};
  enum class ErrorCode {
    Length,
    NoNumber,
    Accept,
  };
  ErrorCode checkPhoneNumber(const std::string& phoneNumber);
};
