#pragma once

#include <vector>

#include "contact.h"

class Phone {
 public:
  void Add(const Contact& contact);
  void Call();
  void Sms();
  void Exit();

 private:
  std::vector<Contact> contacts_{};
};