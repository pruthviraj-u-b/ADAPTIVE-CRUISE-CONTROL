# Adaptive-Cruise-Control: Intelligent Vehicle Distance Management System

An Arduino-based Adaptive Cruise Control (ACC) system designed to enhance driving safety and comfort. Utilizing an ultrasonic sensor, it dynamically monitors the distance to a leading vehicle. It automatically adjusts throttle or stops the motors to maintain a safe gap, reducing driver workload.

---

## 🧠 System Architecture & Key Features

* **Embedded Intelligence Core:** Uses an Arduino microcontroller to coordinate real-time distance metrics and adjust motor actuation simultaneously.
* **Real-Time Distance Ranging:** Integrates an HC-SR04 ultrasonic sensor to poll target coordinates and establish dynamic feedback zones.
* **Automated Safety Interventions:** Programmed with multi-tier braking thresholds to stop motors immediately when obstacles cross critical safety metrics.
* **Dynamic Speed Optimization:** Adjusts variable PWM drive signals dynamically, keeping safe pacing offsets without needing manual throttle taps.
* **Advanced Driver-Assistance (ADAS) Blueprint:** Serves as a modular, low-cost platform for evaluating autonomous highway spacing, collision-avoidance logic, and smart braking models.

---

## 📈 Validated Performance Results

* **Reliable Spacing Control:** Successfully maintained steady following distances during active field tests, avoiding forward collisions.
* **Low-Latency Brake Triggers:** Validated immediate motor cut-offs ($0\text{ RPM}$) during sudden close-range cut-ins.
* **Smooth Throttle Transitions:** Re-accelerated back up to cruising speeds efficiently once tracking paths cleared, matching expected highway travel metrics.

---

## 🛠️ Tech Stack & Hardware Components

### Software & Analytics
* **Languages:** C++ / C (Embedded)
* **Development Environment:** Arduino IDE
* **Architectural Layout:** Non-blocking distance calculation timers, multi-threshold pulse processing

### Hardware Specifications
* **Microcontroller:** Arduino Uno or Mega Core
* **Ranging Sensor:** HC-SR04 Ultrasonic Transducer
* **Drivetrain Actuators:** Dual DC Geared Motors
* **Power Driver:** H-Bridge Motor Driver Controller
* **Power Architecture:** Regulated DC Battery Pack Assembly

---
