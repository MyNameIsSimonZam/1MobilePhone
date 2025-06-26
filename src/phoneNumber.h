// phoneNumber.h
#pragma once

#include <string>

class PhoneNumber {
 public:
  PhoneNumber() = default;
  PhoneNumber(const std::string& phoneNumber);
  friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& number);
  friend bool operator==(const PhoneNumber& lhs, const std::string& rhs);
  friend bool operator==(const std::string& rhs, const PhoneNumber& lhs);

 private:
  std::string number_{};
  enum class ErrorCode {
    Length,
    NoNumber,
    Accept,
  };
  ErrorCode checkPhoneNumber(const std::string& phoneNumber);
};
