# Medicine Reminder Using Arduino Uno

## Description
This Arduino project is a medicine reminder system that uses an LCD and a buzzer to alert users to take their medication at set times daily.

## Features
- **Three Daily Reminders:** Alerts at 8 AM, 2 PM, and 8 PM.
- **LCD Display:** Shows the current time, date, and reminder messages.
- **Buzzer Alert:** Notifies users when it's time to take their medication.
- **Button Interface:** Set the reminder frequency (once, twice, or thrice a day) using push buttons.
- **EEPROM Storage:** Retains reminder settings even after power cycles.
- **Stop Button:** Stops the buzzer alert when the reminder is acknowledged.

## Components Used
- **Arduino Uno**
- **16x2 LCD Display**
- **RTC DS3231 Module**
- **Buzzer**
- **Push Buttons**
- **10K Resistor**

## Circuit Diagram
- **LCD Connections:**
  - RS pin to digital pin 12
  - Enable pin to digital pin 11
  - D4 pin to digital pin 5
  - D5 pin to digital pin 4
  - D6 pin to digital pin 3
  - D7 pin to digital pin 2
  - R/W pin to ground
  - VSS pin to ground
  - VCC pin to 5V
- **10K Resistor:**
  - Ends to +5V and ground
  - Wiper to LCD VO pin (pin 3)

## Installation
1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/medicine-reminder-arduino.git
   ```
2. **Connect the components as per the circuit diagram.**
3. **Upload the provided code to the Arduino Uno.**

## Usage
- **Set Reminder Frequency:** Use push buttons to set reminders for once, twice, or thrice a day.
- **Acknowledge Reminder:** Press the stop button to stop the buzzer when the reminder goes off.

## Code
The code is available in the `main.ino` file in this repository.

## License
This project is licensed under the MIT License.

