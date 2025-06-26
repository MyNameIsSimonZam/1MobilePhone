// contact.h
#pragma once
#include <string>

#include "phoneNumber.h"

class Contact {
 public:
  Contact() = default;
  void set(const std::string& name, const PhoneNumber& phoneNumber);
  std::string getName() const;
  PhoneNumber getNumber() const;
  void show() const;

 private:
  std::string name_;
  PhoneNumber phoneNumber_;
  bool checkName(const std::string& name) const;
  void formatName(std::string& name);
};
