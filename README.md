# ITSE 1307 - Project 10

Hospital Stay Charges Program

This C++ program computes and displays the charges for a patient's hospital stay. The program allows the user to enter information for both in-patient and out-patient cases and calculates the total charges accordingly. It makes use of function overloading to handle different sets of data for in-patients and out-patients.

Program Overview
Features
User Input:

The user is asked if the patient was admitted as an in-patient or an out-patient.
If the patient was an in-patient, the program prompts for the following information:
Number of days spent in the hospital.
Daily rate of the hospital stay.
Hospital medication charges.
Charges for hospital services (e.g., lab tests).
If the patient was an out-patient, the program prompts for the following information:
Charges for hospital services (e.g., lab tests).
Hospital medication charges.
Function Overloading:

Two overloaded functions are used to calculate the total charges:
One function accepts arguments for in-patient data.
Another function accepts arguments for out-patient data.
Both functions return the total charges.
Loop for Multiple Calculations:

After calculating and displaying the charges, the program asks the user if they would like to perform another calculation.
The program continues to run until the user chooses to quit.
Input Validation:

The program ensures that no negative numbers are entered for any data fields.
