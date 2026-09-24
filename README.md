# Arduino Password System

A simple Arduino-based password system using 3 buttons, LEDs, a buzzer, and an OLED display. The user must enter the correct sequence of buttons to unlock the system.

## How It Works

* The system has 3 buttons with a predefined password sequence.
* The user presses the buttons to enter the password.
* Each pressed button activates its corresponding LED as feedback.
* If the sequence is correct, the green indicator lights up and the OLED displays a success message.
* If the sequence is incorrect, the OLED displays an error message and the user can try again.

## Components

* Arduino
* 3 Push Buttons
* 3 LEDs
* Buzzer
* OLED Display (SSD1306)
* Resistors
* Jumper Wires
