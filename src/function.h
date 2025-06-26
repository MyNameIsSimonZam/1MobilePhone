// function.h
#pragma once

#include "phone.h"

namespace phone_emulator {
enum class Command { Add, Call, Sms, Exit, Unknown, ShowContacts };

void printIntro();
Command parseCommand();
void executeCommand(phone_emulator::Command& cmd, Phone& phone);
void addNewContact(Phone& phone);
void call(Phone& phone);
void sms(Phone& phone);
void show(Phone& phone);
}  // namespace phone_emulator