// phone.cpp
#include "phone.h"

#include <iostream>

#include "contact.h"

void Phone::set(const Contact& contact) {
  contacts_.push_back(contact);
}
void Phone::get() {
  std::cout << "Size: " << contacts_.size() << "\n";
  for (const auto x : contacts_) {
    x.show();
    std::cout << "\n";
  }
}
void Phone::call() {
  std::cout << "Enter the phone name or phone number: ";
  std::string request;
  std::getline(std::cin, request);
  for (const auto x : contacts_) {
    if (request == x.getName() || request == x.getNumber()) {
      std::cout << "CALL <";
      x.show();
      std::cout << "> \n";
      return;
    }
  }
  std::cout << "This name or phone number is missing \n";
}
void Phone::sms() {
  std::cout << "Enter the phone name or phone number: ";
  std::string request;
  std::string message;
  std::getline(std::cin, request);
  for (const auto x : contacts_) {
    if (request == x.getName() || request == x.getNumber()) {
      std::cout << "SMS <";
      x.show();
      std::cout << ">: ";
      std::getline(std::cin, message);
      return;
    }
  }
  std::cout << "This name or phone number is missing \n";
}
