# Task 2: Mobile Phone Simulation Program

## Description

Implement a simple program that simulates the basic functionality of a mobile phone.

Features include:
- Making phone calls
- Sending SMS messages
- Managing a contact list

The mobile phone and individual contact entries must be implemented using **classes**.  
Phone numbers must follow the format: `+7 <10 digits>`

---

## User Interaction

The user interacts with the program via the following commands:

- `add` — Adds a new contact to the address book.  
  Prompts the user to enter both the name and phone number.

- `call` — Prompts the user to enter a contact name or phone number.  
  Simulates a call by printing `CALL <number>` to the console.

- `sms` — Prompts the user to enter a name or number, then a message.  
  Simulates sending a text message by printing `SMS <number>: <message>` to the console.

- `exit` — Terminates the program.

---

## Tips

- You may implement the **PhoneNumber** as a separate class.
- Validate phone numbers to match the required format: `+7XXXXXXXXXX`