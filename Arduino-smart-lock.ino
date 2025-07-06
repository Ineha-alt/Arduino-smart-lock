#include <Keypad.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 10, A0, A1, A2);


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String input = "";
int attempts = 0;
bool unlocked = false;
bool inMenu = false;
bool resetting = false;
String newPass = "";

void scrollMessage(String message) {
  for (int i = 0; i < message.length() + 16; i++) {
    lcd.clear();
    lcd.setCursor(16 - i, 0);
    lcd.print(message);
    delay(100);
  }
}

void setup() {
  lcd.begin(16, 2);
  scrollMessage("Welcome to Lock System");
  delay(500);
  lcd.clear();
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

void showMenu() {
  lcd.clear();
  lcd.print("1: Date  2:Reset");
  inMenu = true;
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (!unlocked && !resetting) {
      if (key == '#') {
        if (input == password) {
          lcd.clear();
          lcd.print("Access Granted");
          delay(1500);
          unlocked = true;
          input = "";
          showMenu();
        } else {
          lcd.clear();
          lcd.print("Access Denied");
          delay(1500);
          input = "";
          attempts++;
          if (attempts >= 3) {
            lcd.clear();
            lcd.print("LOCKED OUT");
            delay(5000);
            attempts = 0;
            lcd.clear();
            lcd.print("Enter Password:");
            lcd.setCursor(0, 1);
          } else {
            lcd.clear();
            lcd.print("Enter Password:");
            lcd.setCursor(0, 1);
          }
        }
      } else if (key == '*') {
        input = "";
        lcd.clear();
        lcd.print("Enter Password:");
        lcd.setCursor(0, 1);
      } else if (input.length() < 4) {
        input += key;
        lcd.print("*");
      }
    }
    else if (inMenu) {
      if (key == '1') {
        lcd.clear();
        lcd.print("Jul 6, 2025");
        delay(2000);
        showMenu();
      } else if (key == '2') {
        resetting = true;
        inMenu = false;
        newPass = "";
        lcd.clear();
        lcd.print("New Password:");
        lcd.setCursor(0, 1);
      }
    }
    else if (resetting) {
      if (key == '#') {
        if (newPass.length() == 4) {
          password = newPass;
          lcd.clear();
          lcd.print("Password Saved");
          delay(1500);
        } else {
          lcd.clear();
          lcd.print("Invalid Length");
          delay(1500);
        }
        resetting = false;
        unlocked = false;
        lcd.clear();
        lcd.print("Enter Password:");
        lcd.setCursor(0, 1);
      } else if (key == '*') {
        resetting = false;
        unlocked = false;
        lcd.clear();
        lcd.print("Enter Password:");
        lcd.setCursor(0, 1);
      } else if (newPass.length() < 4) {
        newPass += key;
        lcd.print("*");
      }
    }
  }
}
