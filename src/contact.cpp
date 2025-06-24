#include "contact.h"

#include <algorithm>  
#include <ranges> // for std::ranges::transform
#include <cctype>     // for std::toupper, std::tolower, std::isalpha
#include <iostream>
#include <string>

#include "phoneNumber.h"

void Contact::set(const std::string& name, const PhoneNumber& phoneNumber) {
  if (!checkName(name)) {
    std::cout << "Incorrect symbol\n";
  } else {
    name_ = name;
    formatName(name_);
    phoneNumber_ = phoneNumber;
  }
}
void Contact::get() {}

bool Contact::checkName(const std::string& name) {
  for (const auto x : name) {
    if (!std::isalpha(static_cast<unsigned char>(x)))
      return false;  // a check for Latin alphabet characters using <cctype>
  }
  return true;
}
void Contact::formatName(std::string& name) {
  name[0] = static_cast<char>(std::toupper(name[0]));
  if (name.size() > 1) {
    std::ranges::transform(name.begin() + 1, name.end(), name.begin() + 1,
                           ::tolower);
  }
}
