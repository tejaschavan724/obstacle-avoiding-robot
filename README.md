<h1 align="center">🤖 Obstacle Avoiding Robot (Arduino Project)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Arduino-blue?style=flat-square">
  <img src="https://img.shields.io/badge/Hardware-Ultrasonic%20Sensor%2C%20Servo%2C%20DC%20Motors-green?style=flat-square">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=flat-square">
</p>

<p align="center">
  A self-navigating robot that avoids obstacles using an ultrasonic sensor and servo motor.<br>
  Built with Arduino Uno and designed for intelligent movement and real-time decision-making.
</p>

---

## 🚀 Overview

This project showcases an **autonomous robot** capable of navigating around obstacles by sensing the environment with an **ultrasonic sensor** mounted on a **servo motor**.  
When the robot detects an obstacle within a specified range, it evaluates the surroundings and chooses the most optimal path — left or right — to avoid the object.

---

## 🧠 Key Features

- 📏 Real-time distance measurement using **HC-SR04**
- 🔄 Rotating head with servo motor for 3-way scanning (Left, Center, Right)
- 🔁 Loop-based movement logic for continuous operation
- 💡 Smart decision-making based on obstacle distance
- 🔌 Controlled using **L298N motor driver**

---

## 🛠 Hardware Components

| Component               | Quantity | Function                            |
|------------------------|----------|-------------------------------------|
| Arduino Uno            | 1        | Microcontroller                     |
| HC-SR04 Sensor         | 1        | Distance measurement                |
| SG90 Servo Motor       | 1        | Rotates ultrasonic sensor           |
| L298N Motor Driver     | 1        | Controls direction of DC motors     |
| DC Motors              | 2        | Robot movement                      |
| Robot Chassis + Wheels| 1 set    | Physical base                       |
| Battery Pack           | 1        | Powers motors and Arduino           |

---

## 📁 Folder Structure

