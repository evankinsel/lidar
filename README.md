# ESP32-Based LiDAR Scanner

**2D & 3D Desktop Scanning System**

> **WORK IN PROGRESS**

A desktop LiDAR scanning system built around an **ESP32**, **Adafruit time-of-flight distance sensors**, and stepper motors.

The project is being developed from the firmware up, with the goal of creating a complete 2D and 3D scanning system capable of collecting spatial measurements and generating a 3D point cloud.

## Current Development

The project is currently focused on the **ESP32 firmware and scanning logic**.

### Firmware

* Sensor interfacing and distance measurement
* Distance data processing
* Stepper motor control
* Angular positioning
* 2D scanning logic
* Initial 3D scanning framework
* Serial communication and measurement output

The current firmware is being developed and tested before integrating the physical scanning hardware.

## Development Roadmap

### Stage 1: Firmware

**Current**

Develop and validate the ESP32 firmware responsible for:

* Sensor measurements
* Motor positioning
* Scan sequencing
* Measurement timing
* Angular tracking
* Serial data output

### Stage 2: 2D Scanner

**Next**

Integrate the first physical scanning system and produce a 2D profile by combining:

**Distance + Angular Position**

This stage will establish the basic scanning and coordinate system used by the larger system.

### Stage 3: 3D Scanner

**Planned**

Expand the system to two axes of motion to collect measurements across a 3D space.

The scanner will combine:

**Distance + Horizontal Angle + Vertical Angle**

to generate spatial coordinates for each measurement.

### Stage 4: Data Processing

**Planned**

Develop the computer-side processing pipeline to:

* Receive ESP32 measurement data
* Organize scan data
* Convert measurements into Cartesian coordinates
* Filter and process measurements
* Generate point cloud data

### Stage 5: Visualization

**Planned**

Create a 3D visualization system for viewing and analyzing the resulting point cloud.

## Hardware

Planned system components include:

* ESP32
* Adafruit time-of-flight distance sensor(s)
* Stepper motors
* Stepper motor drivers
* Turntable / scanning mechanism
* 3D printed mechanical components

## Software

* Arduino / ESP32 firmware
* Python
* NumPy
* 3D visualization tools

## Final Goal

Build a complete desktop 3D scanning system from the ground up, combining embedded systems, sensing, electromechanical control, coordinate transformations, data processing, and 3D visualization.

The project will progress from firmware development to a functional 2D scanner and ultimately a full 3D point cloud system.
