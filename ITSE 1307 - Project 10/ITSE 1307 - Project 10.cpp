// Author: Jesus Arias
// GitHub username: ariasje1
// Date: 08/29/2024
// Description: A C++ program that calculates the hospital charges for patients based on their stay and services used. 
// The program allows the user to enter data for either an in-patient or an out-patient. For in-patients, the user enters 
// the number of days spent in the hospital, the daily rate, medication charges, and charges for hospital services. 
// For out-patients, the user enters medication charges and charges for hospital services. The program uses overloaded 
// functions to calculate the total charges for each type of patient and displays the final bill. The user can create 
// multiple bills for different patients and exit the program when done.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function Prototypes
double total_charges(int days_spent_in_hospital, double daily_rate, double hospital_medication_charges, double charges_for_hospital_services);
double total_charges(double charges_for_hospital_services, double hospital_medication_charges);

int main()
{
    char create_another_bill;  // Variable to store user's choice to create another bill

    do
    {
        // Intro - Display welcome message
        string stars(70, '*');      // Creates a line of asterisks for formatting
        string brackets(32, '=');   // Creates a line of equal signs for formatting
        cout << stars << endl << setw(50) << brackets << endl
             << right << setw(50) << "= Welcome to Bay View Hospital =" << endl
             << setw(50) << brackets << endl;
        cout << "Please read through the following prompts to determine patient's info:\n" << endl;
        cout << "Was the patient an in-patient or out-patient?" << endl << stars << endl << endl;

        // Input - Get patient information
        cout << "Please enter the patient's name: ";
        string name;   // Variable to store the patient's name
        cin.ignore();  // Clear the input buffer before using getline
        getline(cin, name);  // Read the entire line of input for the patient's name

        // Display menu for selecting patient type or exiting
        cout << "\nPlease make a selection: \n"
             << "1: Inpatient Bill\n"
             << "2: Outpatient Bill\n"
             << "3: Exit Application\n";
        cout << "\nSelection: ";
        int selection;   // Variable to store user selection
        const int Inpatient_Bill = 1,  // Constant for inpatient option
                  Outpatient_Bill = 2,  // Constant for outpatient option
                  Exit_Application = 3; // Constant for exit option
        cin >> selection;  // Get user selection
        cout << endl;

        // Variables to store billing information
        int days_spent_in_hospital = 0;           // Number of days spent in hospital
        double daily_rate = 0.0;                  // Daily rate for hospital stay
        double hospital_medication_charges = 0.0; // Charges for medication
        double charges_for_hospital_services = 0.0; // Charges for hospital services

        // Inpatient bill calculation
        if (selection == Inpatient_Bill)
        {
            // Get and validate the number of days spent in the hospital
            cout << "Enter the number of days patient " << name << " stayed in the hospital: ";
            cin >> days_spent_in_hospital;
            while (days_spent_in_hospital < 0) {
                cout << "Days cannot be negative. Please enter again: ";
                cin >> days_spent_in_hospital;
            }

            // Get and validate the daily rate
            cout << "What is the daily hospital charge: $";
            cin >> daily_rate;
            while (daily_rate < 0) {
                cout << "Daily rate cannot be negative. Please enter again: ";
                cin >> daily_rate;
            }

            // Get and validate the medication charges
            cout << "Enter the medication expenses: $";
            cin >> hospital_medication_charges;
            while (hospital_medication_charges < 0) {
                cout << "Medication charges cannot be negative. Please enter again: ";
                cin >> hospital_medication_charges;
            }

            // Get and validate the charges for hospital services
            cout << "Enter the charges for services: $";
            cin >> charges_for_hospital_services;
            while (charges_for_hospital_services < 0) {
                cout << "Service charges cannot be negative. Please enter again: ";
                cin >> charges_for_hospital_services;
            }

            // Calculate the total cost using the overloaded function for inpatients
            double total_cost = total_charges(days_spent_in_hospital, daily_rate, hospital_medication_charges, charges_for_hospital_services);
            cout << "\nThe total charges for " << name << " are: $" << fixed << setprecision(2) << total_cost << endl;
        }
        // Outpatient bill calculation
        else if (selection == Outpatient_Bill)
        {
            // Get and validate the charges for hospital services
            cout << "Enter charges for services: $";
            cin >> charges_for_hospital_services;
            while (charges_for_hospital_services < 0) {
                cout << "Service charges cannot be negative. Please enter again: ";
                cin >> charges_for_hospital_services;
            }

            // Get and validate the medication charges
            cout << "Enter the medication expenses: $";
            cin >> hospital_medication_charges;
            while (hospital_medication_charges < 0) {
                cout << "Medication charges cannot be negative. Please enter again: ";
                cin >> hospital_medication_charges;
            }

            // Calculate the total cost using the overloaded function for outpatients
            double total_cost = total_charges(charges_for_hospital_services, hospital_medication_charges);
            cout << "\nThe total charges for " << name << " are: $" << fixed << setprecision(2) << total_cost << endl;
        }
        // Exit the application
        else if (selection == Exit_Application)
        {
            cout << "Exiting the application. Goodbye!\n";
            break; // Exit the loop
        }
        // Handle invalid menu selection
        else
        {
            cout << "The valid choices are 1 through 3. Run the program again and select one of those.\n";
        }

        // Prompt user to create another bill
        cout << "\nWould you like to create another Hospital Bill for another patient? (y/n): ";
        cin >> create_another_bill;

    } while (create_another_bill == 'Y' || create_another_bill == 'y');  // Loop continues if user chooses 'y'

    return 0;
}

/**
 * Function: total_charges
 * -----------------------
 * Calculates the total charges for an in-patient stay.
 *
 * Parameters:
 *   days_spent_in_hospital - Number of days the patient spent in the hospital
 *   daily_rate - Daily rate charged by the hospital
 *   hospital_medication_charges - Charges for medication during the hospital stay
 *   charges_for_hospital_services - Charges for services (lab tests, etc.) during the hospital stay
 *
 * Returns:
 *   The total cost of the in-patient hospital stay.
 */
double total_charges(int days_spent_in_hospital, double daily_rate, double hospital_medication_charges, double charges_for_hospital_services)
{
    double total_charges = (days_spent_in_hospital * daily_rate) + hospital_medication_charges + charges_for_hospital_services;
    return total_charges;
}

/**
 * Function: total_charges
 * -----------------------
 * Calculates the total charges for an out-patient visit.
 *
 * Parameters:
 *   charges_for_hospital_services - Charges for services (lab tests, etc.) during the hospital visit
 *   hospital_medication_charges - Charges for medication during the hospital visit
 *
 * Returns:
 *   The total cost of the out-patient visit.
 */
double total_charges(double charges_for_hospital_services, double hospital_medication_charges)
{
    double total_charges = charges_for_hospital_services + hospital_medication_charges;
    return total_charges;
}
