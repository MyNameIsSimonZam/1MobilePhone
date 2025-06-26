// contact.cpp
#include "contact.h"

#include <algorithm>
#include <cctype>  // for std::toupper, std::tolower, std::isalpha
#include <iostream>
#include <ranges>  // for std::ranges::transform
#include <string>

#include "phoneNumber.h"

void Contact::set(const std::string& name, const PhoneNumber& phoneNumber) {
  if (!checkName(name)) {
    std::cout << "Incorrect symbol\n";
    throw std::invalid_argument("Incorrect symbol");
  } else {
    name_ = name;
    formatName(name_);
    phoneNumber_ = phoneNumber;
  }
}
std::string Contact::getName() const {
  return name_;
}
PhoneNumber Contact::getNumber() const {
  return phoneNumber_;
}

void Contact::show() const {
  std::cout << name_ << " " << phoneNumber_;
}

bool Contact::checkName(const std::string& name) const {
  for (const auto x : name) {
    if (!std::isalpha(static_cast<unsigned char>(x)))
      return false;  // a check for Latin alphabet characters using <cctype>
  }
  return true;
}
void Contact::formatName(std::string& name) {
  if (name.empty()) return;
  name[0] = static_cast<char>(std::toupper(name[0]));
  if (name.size() > 1) {
    std::ranges::transform(name.begin() + 1, name.end(), name.begin() + 1, ::tolower);
  }
}
