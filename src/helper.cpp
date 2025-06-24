#include "helper.h"

#include <iostream>

void callCommand() {
  std::cout << "This is the phone emulator. Please, read Readme.txt before "
               "using it. Thanks for you choosing!\n";
  std::cout << "Available commands: add, call, sms, exit\n";
  std::cout << "Enter a command: ";
  std::cin.ignore();
  std::string command;
  std::getline(std::cin, command);
  enum class Command {
    Add,
    Call,
    Sms,
    Exit,
    Unknown,
  };

  Command cmd{};
  if (command == "add")
    cmd = Command::Add;
  else if (command == "call")
    cmd = Command::Call;
  else if (command == "sms")
    cmd = Command::Sms;
  else if (command == "exit")
    cmd = Command::Exit;
  else
    cmd = Command::Unknown;

  switch (cmd) {
    case Command::Add: {
      break;
    }
    case Command::Call: {
      break;
    }
    case Command::Sms: {
      break;
    }
    case Command::Exit: {
      break;
    }
    case Command::Unknown: {
      break;
    }
    default:
      break;
  }
}