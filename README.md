# Arduino Traffic Lights Project 🚦

## Table of Contents
1. [Project Overview](#project-overview)
2. [Materials and Components](#materials-and-components)
3. [System Design](#system-design)
   - [3.1 Sensor Overview](#sensor-overview)
   - [3.2 Sensor Characteristics](#sensor-characteristics)
4. [Circuit Diagram](#circuit-diagram)
5. [Code Explanation](#code-explanation)
7. [Conclusion](#conclusion)

---

## Project Overview
This project was part of my Year 12 Computer Science course to investigate control systems. I chose to design a traffic light system using an Arduino Uno and an ultrasonic distance sensor to record and account for pedestrians, when controlling the lights, to reduce congestion and improve traffic.


## Materials and Components
- **Sensors**
  - 1 x HC-SR04 Ultrasonic Distance Sensor
- **Lights**
   - 2 x Red LED
   - 1 x Yellow LED
   - 2 x Green LED
- **Connections**
  - 16 x Jumper Wire
  - 2 x Breadboard
- **Controller**
  - Arduino Uno
- **Resistors**
  - 5 x 1KΩ Resistor for voltage division

### Photo of the circuit from TinkerCAD
<img width="1113" alt="Screenshot 2024-11-14 at 19 17 19" src="https://github.com/user-attachments/assets/51102b68-3a75-4bb0-8dcc-2b651e600371">


## System Design

### Sensor Overview
The HC-SR04 ultrasonic sensor measures distance by emitting an ultrasonic sound wave and calculating the time taken for the echo to return. This is used to detect pedestrains approaching a crosswalk, by checking for interruptions of the echo signal within a specified range, indicating the precense of people incoming. This triggers a change in the traffic lights, turning it red for cars and prioritising pedestrians, giving them the green light, ensuring safety and efficiency.

### Sensor Characteristics
- **Type**
  - Digital: the output is a pulse duration that corresponds to the distance detected
  - Active: it actively sends out an ultrasonic pulse and listens for the echo
- **Valid range of voltages in/out**
  - Input Voltage: Recommended input voltage is 5V.
  - Logic Levels: Trigger and Echo pins operate between 0V (LOW) and 5V (HIGH)
- **Range and accuracy**
  - The distance measurement range is approximately 2 cm to 400 cm within a 30 degree cone, and is accurate to the nearest 0.3cm
- **Operating Frequency**
   - Operates at an ultrasonic frequency of 40 kHz, which allowing for high-resolution distance measurements and is beyond human hearing
- **Power Consumption**
  - Typically consumes around 15 mA when active, making it power-efficient and suitable for battery-operated projects
- **Limitations**
  - Object Interference: Objects that don’t reflect sound well, including soft surface and clothing, may not produce a strong echo, leading to inaccurate readings
  - Environmental Conditions: extreme weather or wind may affect readings, since it's used outdoors

### Circuit Diagram
A comprehensive circuit diagram is provided below to show the complete wiring for this project, the details of how each component is connected to the Arduino. [Download the pdf version](https://github.com/user-attachments/files/17757295/Traffic.Lights.Project.pdf)

![Traffic Lights Project-1](https://github.com/user-attachments/assets/299257a1-dcf0-4712-998f-1c18ab525742)


### Code Explanation
The code is designed to manage pedestrian and car traffic at a crosswalk based on the proximity of a person approaching. A function is used to trigger the ultrasonic sensor to emit sound pulses, it measures the time taken for the echo to return and calculates the distance to any detected object. The distance is outputted to the Serial Monitor for debugging. The code continuously checks if the distance to an object (a pedestrian) is within a set threshold (30 cm for prototype purposes). If an object is detected, the car light turns yellow and then red, while the pedestrian light turns green, allowing them to cross. The pedestrian light remains green as long as someone is within range. Once no object is detected, there is a 6-second wait loop to ensure that all pedestrians are able to pass and to be able to detect any newly arriving ones. Afterwards, the lights simply reset, turning the car light back to green and the pedestrian light to red. The program repeats this cycle, checking continuously for pedestrians and adjusting the lights accordingly, ensuring a responsive system that provides safety, by making adjustments based on real-time distance data from the ultrasonic sensor.

[Link to the code](https://github.com/TadasVilcinskas/Arduino-TrafficLights/blob/main/system_code.ino/)

### Conclusion
This traffic lights project successfully demonstrates a simple, yet effective control system. By using the HC-SR04 ultrasonic distance sensor, the system detects pedestrians approaching the crossing and dynamically adjusts the traffic lights, prioritizing pedestrian movement while managing car traffic effectively. With additional refinements, it has the potential to be a practical model, not only showcasing the applications of automation in traffic management, but also emphasizing the potential of microcontroller-based solutions in addressing real-world problems.
