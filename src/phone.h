// phone.h
#pragma once

#include <vector>

#include "contact.h"

class Phone {
 public:
  Phone() = default;
  void set(const Contact& contact);
  void get();
  void call();
  void sms();

 private:
  std::vector<Contact> contacts_{};
};