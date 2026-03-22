# Arduino-Based Parking Assistance System
This was my first hands-on project with the Arduino ecosystem. I designed a Parking Assistance System that provides real-time feedback to a driver using ultrasonic sensing, visual signals, and auditory alerts. The project focuses on creating distinct safety zones to prevent collisions during low-speed maneuvers.
Logic & Detection Zones
The system is programmed to react differently based on the distance between the sensor and an obstacle:
Safe zone > 25 cm
Warning Zone 10-25 cm
Danger zone < 10 cm
Error 0 cm

## Hardware Configuration (Wiring)

To keep the design clean and efficient, I utilized a common ground rail on the breadboard. This reduced the number of jumper wires and improved the overall circuit organization.

Ultrasonic Sensor: Trig -> Pin 9 | Echo -> Pin 10 | VCC -> 5V

Buzzer: Pin 8

Bi-Color LED: Red -> Pin 6 | Green -> Pin 7

Ground: All components connected to a shared GND row.

## Development Process

My approach was to understand each component individually before integrating them into a single system. I tested the sensor, buzzer, and LED separately to verify their behavior.
I designed the system's logic and architecture, then collaborated with Gemini AI to structure the final code. This "Human-in-the-loop" design process allowed me to focus on the hardware constraints while ensuring the software logic met my specific requirements.

## Key Takeaways

-Breadboard Architecture: I overcame initial frustrations by learning how breadboard rails are connected internally. Mastering the power and ground rails was a "turning point" for my circuit design.

-Iterative Testing: Testing components in isolation saved significant debugging time during the final assembly.

-Technical Intuition: This project built my confidence in basic electrical wiring and the fundamentals of Arduino programming.

