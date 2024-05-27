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
   git clone https://github.com/harshiniraj311/arduino-based-medicine-reminder-system.git
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

## Demo
<img src="https://github.com/harshiniraj311/arduino-based-medicine-reminder-system/assets/155360804/1773f13d-1875-4859-b47c-1efac2e93237" alt="medicine reminder" width="400">
<img src="https://github.com/harshiniraj311/arduino-based-medicine-reminder-system/assets/155360804/b4dc13f4-b6dc-40c4-87a4-b81ceb95b114" alt="medicine reminder" width="400">
<img src="https://github.com/harshiniraj311/arduino-based-medicine-reminder-system/assets/155360804/5ce7dfbc-06ca-478c-9be0-afb0cff25bb8" alt="medicine reminder" width="400">
<img src="https://github.com/harshiniraj311/arduino-based-medicine-reminder-system/assets/155360804/3f9776f0-2dc5-4778-8ddb-6f510ffce98f" alt="medicine reminder" width="400">
<img src="https://github.com/harshiniraj311/arduino-based-medicine-reminder-system/assets/155360804/94c210dd-d9a3-44ba-b403-27f0e4179e74" alt="medicine reminder" width="400">


