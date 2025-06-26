// main.cpp
#include <iostream>

#include "function.h"
#include "phone.h"

int main() {
  phone_emulator::printIntro();
  Phone phone{};
  while (true) {
    phone_emulator::Command command{phone_emulator::parseCommand()};
    if (command == phone_emulator::Command::Exit) break;
    phone_emulator::executeCommand(command, phone);
  }
  return 0;
}
