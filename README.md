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

## Example Output
Running the program for an industrial load of **100 kW**. The example demonstrates the calculation required to correct the **Power Factor from 0.75 to 0.95** on a 400V/50Hz grid.
The corrections of errors are also shown.
<img width="1151" height="1069" alt="image" src="https://github.com/user-attachments/assets/9a8535c4-eebc-4fe8-897d-667be6fd6292" />

## Author
**Dimitrios Poulos**
* Electrical & Computer Engineering Student
