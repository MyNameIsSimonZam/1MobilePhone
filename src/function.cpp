// function.cpp
#include "function.h"

#include <iostream>

#include "contact.h"
#include "phone.h"
#include "phoneNumber.h"

namespace phone_emulator {
void addNewContact(Phone& phone) {
  PhoneNumber phoneNumber{};
  while (true) {
    std::cout << "Enter a number: +7";
    std::string inNumber{};
    std::getline(std::cin, inNumber);
    try {
      phoneNumber = PhoneNumber{inNumber};
      break;
    } catch (const std::invalid_argument& e) {
      std::cout << "Error: Invalid argument" << e.what() << '\n';
    }
  }
  Contact contact{};
  while (true) {
    std::cout << "Enter a name: ";
    std::string inName{};
    std::getline(std::cin, inName);
    try {
      contact.set(inName, phoneNumber);
      break;
    } catch (const std::invalid_argument& e) {
      std::cout << "Error: Invalid argument" << e.what() << '\n';
    }
  }
  phone.set(contact);
}

void show(Phone& phone) {
  // реализовать
}

void printIntro() {
  std::cout << "This is the phone emulator. Please, read Readme.txt before "
               "using it. Thanks for you choosing!\n";
  std::cout << "Available commands: add, call, sms, exit\n";
  std::cout << "Name will be fotmating like this \"Bigfirstsymbol\"\n";
}

Command parseCommand() {
  std::cout << "Enter a command: ";
  std::string command;
  std::getline(std::cin, command);
  phone_emulator::Command cmd{};
  if (command == "add")
    cmd = phone_emulator::Command::Add;
  else if (command == "show")
    cmd = phone_emulator::Command::ShowContacts;
  else if (command == "call")
    cmd = phone_emulator::Command::Call;
  else if (command == "sms")
    cmd = phone_emulator::Command::Sms;
  else if (command == "exit")
    cmd = phone_emulator::Command::Exit;
  else
    cmd = phone_emulator::Command::Unknown;
  return cmd;
}

void executeCommand(phone_emulator::Command& cmd, Phone& phone) {
  switch (cmd) {
    case Command::Add: {
      addNewContact(phone);
      break;
    }
    case Command::ShowContacts: {
      phone.printContacts();
      break;
    }
    case Command::Call: {
      phone.call();
      break;
    }
    case Command::Sms: {
      phone.sms();
      break;
    }
    case Command::Unknown: {
      std::cout << "Error... Unknown command\n";
      break;
    }
    default:
      break;
  }
}
}  // namespace phone_emulator