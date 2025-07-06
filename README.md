# Arduino Smart Lock 🔒

This is a basic smart lock system made using Arduino, a keypad, a 16x2 LCD screen and the code written in c++.

When the user enters the correct password, it shows "Access Granted". If the wrong password is entered three times, the system locks out for a few seconds. After logging in, you can view the current date or reset the password using menu options.

## Features
- 4-digit password entry
- Password masking with `*`
- LCD feedback messages
- Lockout after 3 wrong attempts
- Option to reset password
- Date display

## Components Used
- Arduino Uno
- 4x4 Keypad
- 16x2 LCD
- Potentiometer
- Breadboard and jumper wires

## Circuit Preview
Check the `circuit.png` for how the setup looks.

## How to Use
1. Upload the `Arduino-smart-lock.ino` file to your Arduino.
2. Open Serial Monitor or just observe the LCD.
3. Enter the default password `1234` using the keypad and # to enter.
4. Use `1` for Date and `2` to Reset the password.

## Notes
- You can change the password in the code or reset it through the menu.
- This was built and tested using Tinkercad.

