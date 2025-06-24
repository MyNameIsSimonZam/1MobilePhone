#include "phone.h"

#include "contact.h"

void Phone::Add(const Contact& contact) { contacts_.push_back(contact); }
void Phone::Call() {}
void Phone::Sms() {}
void Phone::Exit() {}
