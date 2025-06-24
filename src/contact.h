#pragma once
#include <string>

#include "phoneNumber.h"

class Contact {
 public:
  void set(const std::string& name, const PhoneNumber& phoneNumber);
  void get();

 private:
  std::string name_;
  PhoneNumber phoneNumber_;
  bool checkName(const std::string& name);
  void formatName(std::string& name);
};
