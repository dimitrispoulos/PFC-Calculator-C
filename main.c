/*
	Project: Power Factor Correction (PFC) Calculator
	Description: Calculates the required capacitor's reactive power (kVAr) and capacitance (uF) in order to improve the power factor of a load
	Author: Dimitrios Poulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265359    // Definition of PI constant

int main()
{
	// Variable declaration
	int input1, input2;    // Menu selection variables
	double P;    // Active Power in kW
	double currentQ, desiredQ, capacitorQ, capacitorQVAr;    // currentQ: Current Reactive Power (kVAr), desiredQ: Target Reactive Power (kVAr), capacitorQ: Capacitor's Reactive Power which must be provided (kVAr), capacitorQVAr: The former Reactive Power in VAr
	double currentPF, desiredPF;    // currentPF: Current Power Factor, desiredPF: Target Power Factor
	double phi1, phi2;    // phi1: Current Phase angle (in radians), phi2: Target Phase angle (in radians)
	double voltage;    // Voltage (V)
	double frequency;    // Frequency (Hz)
	double capacitanceF, capacitanceuF;    // capacitanceF: Capacitor's Capacitance (Farads), capacitanceuF: The former Capacitance in microFarads (uF)
	
	
	printf("=== POWER FACTOR CORRECTION (PFC) CALCULATOR ===\n\n\n");
	// Input of Active Power (P)
	do
	{
		printf("Enter Active Power (P) in kW: ");
		scanf("%lf", &P);    // Use of 'lf' because due to double variables
		if(P < 0)
		{
			printf("Error! Active Power cannot be a negative number. Please try again\n");
		}
	} while(P < 0);
	
	
	// Choice of the known variable
	do
	{
		printf("\n1) I know the current Power Factor (cosphi1)\n");
		printf("2) I know the current Reactive Power (currentQ)\n");
		printf("Please enter your choice (1 or 2): ");
		scanf("%d", &input1);
		if(input1 != 1 && input1 != 2)
		{
			printf("Invalid choice! Please enter 1 or 2.\n");
		}	
	} while(input1 != 1 && input1 != 2);
	
	// Known variable is Power Factor (PF)
	if(input1 == 1)
	{
		// Input of current Power Factor (PF)
		do
		{
			printf("\nEnter current Power Factor-PF (number between 0 and 1): ");
			scanf("%lf", &currentPF);
			if(currentPF<=0 || currentPF>1)
			{
				printf("Error! Power Factor must be between 0 and 1 (or 1). Please try again\n");
			}
		} while(currentPF<=0 || currentPF>1);
		
		phi1 = acos(currentPF);    // Calculation of the current phase angle
		currentQ = P*tan(phi1);    // Calculation of the current Reactive Power
		printf("-> Calculated Current Q: %.2f kVAR\n\n", currentQ);
		
		
		// Choice of the target variable
		do
		{
			printf("1) I want to input desired PF\n");
			printf("2) I want to input desired Q\n");
			printf("Please enter your choice (1 or 2): ");
			scanf("%d", &input2);
			if(input2 != 1 && input2 != 2)
			{
				printf("Invalid choice! Please enter 1 or 2.\n\n");
			}
		} while(input2 != 1 && input2 != 2);
		
		// Target variable is Power Factor (PF)
		if(input2 == 1)
		{
			// Input of desired Power Factor (PF)
			do
			{
				printf("\nEnter desired Power Factor-PF (must be > %.4f): ", currentPF);
				scanf("%lf", &desiredPF);
				if(desiredPF<=currentPF || desiredPF>1)
				{
					printf("Error! Desired Power Factor must be between 0 and current Power Factor. Please try again\n");
				}
			} while(desiredPF<=currentPF || desiredPF>1);
			
			phi2 = acos(desiredPF);    // Calculation of the target phase angle
			desiredQ = P*tan(phi2);    // Calculation of the target Reactive Power
		}
		
		// Target variable is Reactive Power (Q)
		else if(input2 == 2)
		{
			// Input of desired Reactive Power (Q)
			do
			{
				printf("\nEnter desired Reactive Power (Q) in kVAr (must be < %.2f): ", currentQ);
				scanf("%lf", &desiredQ);
				if(desiredQ>=currentQ || desiredQ<0)
				{
					printf("Error! Desired Reactive Power must be smaller than current Reactive Power. Please try again\n");
				}
			} while(desiredQ>=currentQ || desiredQ<0);
			
			phi2 = atan(desiredQ/P);    // Calculation of the target phase angle
			desiredPF = cos(phi2);    // Calculation of the target Power Factor
		}
	}
	
	
	
	// Known variable is Reactive Power (Q)
	else if(input1 == 2)
	{
		// Input of current Reactive Power (Q)
		do
		{
			printf("\nEnter current Reactive Power (Q) in kVAR: ");
			scanf("%lf", &currentQ);
			if(currentQ < 0)
			{
				printf("Error! Reactive Power cannot be a negative number. Please try again\n");
			}
		} while(currentQ < 0);
		
		phi1 = atan(currentQ/P);    // Calculation of current phase angle
		currentPF = cos(phi1);    // Calculation of the current Reactive Power
		printf("-> Calculated Current PF: %.4f\n\n", currentPF);
		
		
		// Choice of the target variable
		do
		{
			printf("1) I want to input desired PF\n");
			printf("2) I want to input desired Q\n");
			printf("Please enter your choice (1 or 2): ");
			scanf("%d", &input2);
			if(input2 != 1 && input2 != 2)
			{
				printf("Invalid choice! Please enter 1 or 2.\n\n");
			}
		} while(input2 != 1 && input2 != 2);
		
		// Target variable is Power Factor (PF)
		if(input2 == 1)
		{
			// Input of desired Power Factor (PF)
			do
			{
				printf("Enter desired Power Factor-PF (must be > %.4f): ", currentPF);
				scanf("%lf", &desiredPF);
				if(desiredPF<=currentPF || desiredPF>1)
				{
					printf("Error! Desired Power Factor must be between 0 and current Power Factor. Please try again\n");
				}
			} while(desiredPF<=currentPF || desiredPF>1);
			
			phi2 = acos(desiredPF);    // Calculation of the target phase angle
			desiredQ = tan(phi2)*P;    // Calculation of the current Reactive Power
		}
		
		// Target variable is Reactive Power (Q)
		else if(input2 == 2)
		{
			// Input of desired Reactive Power (Q)
			do
			{
				printf("Enter desired Q in kVAr (must be < %.2f): ", currentQ);
				scanf("%lf", &desiredQ);
				if(desiredQ>=currentQ || desiredQ<0)
				{
					printf("Error! Desired Reactive Power must be smaller than current Reactive Power.\n");
				}
			} while(desiredQ>=currentQ || desiredQ<0);
			
			phi2 = atan(desiredQ/P);    // Calculation of the target phase angle
			desiredPF = cos(phi2);    // Calculation of the target Power Factor
		}
		
		else
		{
			printf("Invalid Main Choice. Exiting.\n");
			return 1;
		}
	}
	
	else
	{
		printf("Invalid Main Choice. Exiting.\n");
		return 1;
	}
	
	
	capacitorQ = currentQ - desiredQ;    // Calculation of required capacitor's Reactive Power
	
	
	// Input of Voltage (Volts)
	do
	{
		printf("\nEnter Voltage (V): ");
		scanf("%lf", &voltage);
		if(voltage <= 0)
		{
			printf("Error! Voltage must be a positive number\n");
		}
	} while(voltage <= 0);
	
	// Input of Frequency (Hz)
	do
	{
		printf("Enter Frequency (Hz): ");
		scanf("%lf", &frequency);
		if(frequency <= 0)
		{
			printf("Error! Frequency must be a positive number\n");
		}
	} while(frequency <= 0);
	
	
	
	capacitorQVAr = capacitorQ*1000;    // Conversion of capacitor's Reactive Power from kVAr to VAr
	
	capacitanceF = capacitorQVAr/(2*pi*frequency*voltage*voltage);    // Calculation of Capacitance in Farads. Formula: C = Qc / (2 * pi * f * V^2)
	
	capacitanceuF = capacitanceF*1000000;    // Conversion of capacitance from F to uF
	
	
	
	printf("\n\n\n================ RESULTS ================\n");
	printf("Initial State: PF=%.4f | Q=%.2f kVAR\n", currentPF, currentQ);
	printf("Desired State:  PF=%.4f | Q=%.2f kVAR\n", desiredPF, desiredQ);
	printf("-----------------------------------------\n");
	printf("REQUIRED CAPACITOR'S REACTIVE POWER: %.2f kVAR\n", capacitorQ);
	printf("REQUIRED CAPACITANCE: %.2f uF\n", capacitanceuF);
	printf("=========================================\n");
	
	
	// Program Ending
	system("PAUSE");
	
	return 0;
}
