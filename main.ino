#include <LiquidCrystal.h>
#include <Wire.h>
#include <RTClib.h>
#include <EEPROM.h>

int pushVal = 0;                           
int val2;
int addr = 0;
RTC_DS3231 rtc;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define getWellsoon 0                                           
#define HELP_SCREEN 1
#define TIME_SCREEN 2

int pushpressed = 0;
const int ledPin = LED_BUILTIN;
int ledState = LOW;
int buzz = 13;

int push1state, push2state, push3state, stopinState = 0;
int push1Flag, push2Flag, Push3Flag = false;
int push1pin = 9;
int push2pin = 8;
int push3pin = 7;
int stopPin = 6;
int screens = 0;
int maxScreen = 2;
bool isScreenChanged = true;

long previousMillis = 0;
long interval = 500;
unsigned long currentMillis;

long previousMillisLCD = 0;
long intervalLCD = 2000;
unsigned long currentMillisLCD;

int buzz8amHH = 8;
int buzz8amMM = 0;
int buzz8amSS = 0;

int buzz2pmHH = 14;
int buzz2pmMM = 0;
int buzz2pmSS = 0;

int buzz8pmHH = 20;
int buzz8pmMM = 0;
int buzz8pmSS = 0;

int nowHr, nowMin, nowSec;

void gwsMessege() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stay Healthy :)");
    lcd.setCursor(0, 1);
    lcd.print("Get Well Soon :)");
}

void helpScreen() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press Buttons");
    lcd.setCursor(0, 1);
    lcd.print("for Reminder...!");
}

void timeScreen() {
    DateTime now = rtc.now();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time:");
    lcd.setCursor(6, 0);
    lcd.print(nowHr = now.hour(), DEC);
    lcd.print(":");
    lcd.print(nowMin = now.minute(), DEC);
    lcd.print(":");
    lcd.print(nowSec = now.second(), DEC);
    lcd.setCursor(0, 1);
    lcd.print("Date: ");
    lcd.print(now.day(), DEC);
    lcd.print("/");
    lcd.print(now.month(), DEC);
    lcd.print("/");
    lcd.print(now.year(), DEC);
}

void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(1,0);
    delay(1000);
    lcd.clear();

    Serial.begin(9600);

    if (!rtc.begin()) {
        lcd.print("Missing RTC");
        delay(1000); 
        while (1);
    } else {
        lcd.print("RTC initialized");
    }

    if (rtc.lostPower()) {
        lcd.print("RTC lost power, lets set the time!");
    }

    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome To");
    lcd.setCursor(0, 1);
    lcd.print("Medicine reminder");
    delay(1000);
    timeScreen();
    delay(5000);

    pinMode(push1pin, INPUT);
    pinMode(push2pin, INPUT);
    pinMode(push3pin, INPUT);
    pinMode(stopPin, INPUT);
    pinMode(ledPin, OUTPUT);
    delay(200);

    Serial.println("initial EEpROM value");
    Serial.println(EEPROM.read(addr));

    val2 = EEPROM.read(addr);

    switch (val2) {
        case 1:
            Serial.println("Set for 1/day");
            push1state = 1;
            push2state = 0;
            push3state = 0;
            pushVal = 1;
            break;
        case 2:
            Serial.println("Set for 2/day");
            push1state = 0;
            push2state = 1;
            push3state = 0;
            pushVal = 2;
            break;
        case 3:
            Serial.println("Set for 3/day");
            push1state = 0;
            push2state = 0;
            push3state = 1;
            pushVal = 3;
            break;
    }
}

void loop() {
    push1();
    push2();
    push3();

    if (pushVal == 1) {
        at8am();
    } else if (pushVal == 2) {
        at8am();
        at8pm();
    } else if (pushVal == 3) {
        at8am();
        at2pm();
        at8pm();
    }

    currentMillisLCD = millis();
    push1state = digitalRead(push1pin);
    push2state = digitalRead(push2pin);
    push3state = digitalRead(push3pin);
    stopinState = digitalRead(stopPin);

    stopPins();
    changeScreen();
}

void push1() {
    if (push1state == 1) {
        push1state = 0;
        push2state = 0;
        push3state = 0;
        EEPROM.write(addr, 1);
        Serial.print("Push1 Written: "); Serial.println(EEPROM.read(addr));
        pushVal = 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Reminder set ");
        lcd.setCursor(0, 1);
        lcd.print("for Once/day !");
        delay(1200);
        lcd.clear();
    }
}

void push2() {
    if (push2state == 1) {
        push2state = 0;
        push1state = 0;
        push3state = 0;
        EEPROM.write(addr, 2);
        Serial.print("Push2 Written: "); Serial.println(EEPROM.read(addr));
        pushVal = 2;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Reminder set ");
        lcd.setCursor(0, 1);
        lcd.print("for Twice/day !");
        delay(1200);
        lcd.clear();
    }
}

void push3() {
    if (push3state == 1) {
        push3state = 0;
        push1state = 0;
        push2state = 0;
        EEPROM.write(addr, 3);
        Serial.print("Push3 Written: "); Serial.println(EEPROM.read(addr));
        pushVal = 3;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Reminder set ");
        lcd.setCursor(0, 1);
        lcd.print("for Thrice/day !");
        delay(1200);
        lcd.clear();
    }
}

void stopPins() {
    if (stopinState == 1) {
        Serial.print("Stop button has been pressed\n");
        stopinState = 0;
        pushpressed = 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Take Medicine");
        lcd.setCursor(0, 1);
        lcd.print("with Warm Water");
        delay(1200);
        lcd.clear();
    }
}

void startBuzz() {
    if (pushpressed == 0) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            Serial.println("Start Buzzing");
            ledState = (ledState == LOW) ? HIGH : LOW;
            digitalWrite(ledPin, ledState);
        }
    } else if (pushpressed == 1) {
        ledState = LOW;
        digitalWrite(ledPin, ledState);
    }
}

void at8am() {
    DateTime now = rtc.now();
    if (now.hour() == buzz8amHH && now.minute() == buzz8amMM && now.second() > buzz8amSS) {
        startBuzz();
    }
}

void at2pm() {
    DateTime now = rtc.now();
    if (now.hour() == buzz2pmHH && now.minute() == buzz2pmMM && now.second() > buzz2pmSS) {
        startBuzz();
    }
}

void at8pm() {
    DateTime now = rtc.now();
    if (now.hour() == buzz8pmHH && now.minute() == buzz8pmMM && now.second() > buzz8pmSS) {
        startBuzz();
    }
}

void changeScreen() {
    if (currentMillisLCD - previousMillisLCD > intervalLCD) {
        previousMillisLCD = currentMillisLCD;
        screens = (screens >= maxScreen) ? 0 : screens + 1;
        isScreenChanged = true;
    }

    if (isScreenChanged) {
        isScreenChanged = false;
        switch (screens) {
            case getWellsoon:
                gwsMessege();
                break;
            case HELP_SCREEN:
                helpScreen();
                break;
            case TIME_SCREEN:
                timeScreen();
                break;
            default:
                break;
        }
    }
}
