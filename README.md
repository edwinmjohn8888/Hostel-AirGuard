# Hostel AirGuard

### ESP32-Based Hostel Ventilation Alert Prototype

## Problem
In hostel rooms, students often gather together while the doors and windows are closed and the AC is running. This can reduce fresh-air ventilation and allow CO₂ to build up.

I chose this problem after discussing it with a hostel student who was concerned about ventilation in crowded rooms.

## Solution
Hostel AirGuard is an ESP32-based prototype that demonstrates a CO₂-based ventilation alert system.

It uses simulated CO₂ readings to control LED indicators, a buzzer, and ventilation suggestions.

## Features
- Green LED: Below 1000 ppm
- Yellow LED: 1000–1499 ppm
- Red LED and buzzer: 1500 ppm and above
- Ventilation suggestions displayed in the Serial Monitor
- Automatic and manual simulation modes

## Simulation Modes

**Automatic Mode:** CO₂ values increase and decrease automatically between 700 and 2000 ppm.

**Manual Mode:** A potentiometer connected to GPIO 34 allows the user to adjust simulated CO₂ values between approximately 400 and 2000 ppm.

The mode is selected by changing the `manualMode` variable in the code.

## Components
- ESP32 microcontroller
- Green, yellow, and red LEDs
- Three 220Ω resistors
- Buzzer
- Potentiometer

## Circuit Connections
| Component | ESP32 Pin |
|---|---|
| Green LED | GPIO 4 |
| Yellow LED | GPIO 5 |
| Red LED | GPIO 2 |
| Buzzer | GPIO 18 |
| Potentiometer SIG | GPIO 34 |

The potentiometer is also connected to 3V3 and GND.

## Simulation
[Run Hostel AirGuard on Wokwi](https://wokwi.com/projects/479386702869052417)

## Limitations
The current prototype does not measure real CO₂ levels. Both modes use simulated values, and the warning thresholds are illustrative rather than universal safety limits.

## Future Improvements
- Add an SCD40/SCD41 sensor for real CO₂ measurements.
- Add an OLED display for live readings.
- Introduce a physical button for switching modes.
- Add data logging and mobile notifications.
