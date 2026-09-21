# Early Diabetic Neuropathy Detection

## Overview

This project focuses on developing a low-cost, portable system for the early
detection of peripheral diabetic neuropathy.

The system combines vibration perception threshold (VPT) testing with
plantar pressure mapping to assess sensory and pressure-related indicators
associated with peripheral neuropathy.

The objective is to develop an affordable screening system suitable for
point-of-care and resource-constrained settings.

---

## Objectives

- Develop a low-cost and portable system for peripheral neuropathy screening.
- Implement vibration perception threshold (VPT) testing.
- Measure plantar pressure distribution using a sensorized insole.
- Integrate the sensing and data-acquisition system using an ESP32.
- Develop a real-time risk-scoring approach based on the acquired measurements.
- Maintain a target system cost below ₹1000.

---

## System Overview

The system consists of two primary assessment methods:

### 1. Vibration Perception Threshold Testing

Vibration stimuli are applied using vibration actuators to assess the user's
ability to perceive vibration.

The response obtained during the test is used as an indicator of sensory
function.

### 2. Plantar Pressure Mapping

A sensorized insole based on Velostat pressure-sensitive material is used
to measure pressure distribution across the foot.

The pressure measurements provide information about the distribution and
variation of plantar loading.

---

## Hardware

The system uses:

- ESP32 microcontroller
- Vibration actuators
- Velostat-based pressure sensors
- Sensorized insole
- Supporting electronic components

The system was designed with a focus on low cost and portability.

---

## Software

The ESP32 is used for data acquisition and control of the sensing system.

The software handles:

- Sensor data acquisition
- Vibration stimulus control
- Processing of acquired measurements
- Risk-score calculation

---

## Risk Assessment

Measurements obtained from the VPT and plantar pressure tests are combined
to provide a real-time risk assessment.

The system is intended as a low-cost screening tool rather than a replacement
for clinical diagnosis.

---

## Results

The developed prototype demonstrates the feasibility of combining vibration
perception testing and plantar pressure mapping into a single low-cost
screening system.

The target system cost is below ₹1000, supporting the potential use of the
system in affordable point-of-care and resource-constrained screening
applications.

---

## Project Achievement

**1st Place: SPARK Innovation Challenge 2026**

The project received first place in the SPARK Innovation Challenge for the
proposed early-detection solution for peripheral neuropathy.

---

## Future Work

Potential future improvements include:

- Improving sensor calibration and repeatability.
- Increasing the spatial resolution of plantar pressure measurements.
- Refining the risk-scoring methodology.
- Improving the mechanical and electronic packaging of the prototype.
- Conducting larger-scale validation studies.
- Comparing measurements with established clinical assessment methods.

---

## Tools and Technologies

- ESP32
- Velostat
- Vibration actuators
- Embedded programming
- Sensor data acquisition
- Plantar pressure mapping
- Vibration perception threshold testing

---

## Project Information

**Project:** Early Diabetic Neuropathy Detection  
**Institution:** Indian Institute of Technology Indore  
**Duration:** August 2025 – November 2025

**Project Guide:** Dr. I. A. Palani
