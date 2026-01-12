# PFC-Calculator-C
A C program that calculates the required capacitor's reactive power and capacitance in order to improve the power factor of a load

## Features
- Calculates required **Reactive Power (kVAR)**.
- Calculates required **Capacitance (μF)**.
- Accepts input based on either current **Power Factor** or current **Reactive Power**.
- Validates user inputs to prevent errors (loops until correct input is given).
- Cleans input buffers to avoid menu skipping.

## How to use
1. Compile the `main.c` file using a C compiler (like GCC or via an IDE like Dev-C++).
2. Run the executable.
3. Enter the **Active Power (P)** in kW.
4. Select your known variable (**Current PF** or **Current Q**).
5. Select your target (**Desired PF** or **Desired Q**).
6. Enter grid details (**Voltage**, **Frequency**).
7. Get the result!

## Author
Dimitrios Poulos
