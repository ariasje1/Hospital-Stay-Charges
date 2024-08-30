#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double total_charges(int, double, double, double);
double total_charges(double, double);

int main()
{
    char create_another_bill;
    do
    {
        // Intro
        string stars(70, '*');
        string brackets(32, '=');
        cout << stars << endl << setw(50) << brackets << endl
            << right << setw(50) << "= Welcome to Bay View Hospital =" << endl
            << setw(50) << brackets << endl;
        cout << "Please read through the following prompts to determine patient's info:\n" << endl;
        cout << "Was the patient an in-patient or out-patient?" << endl << stars << endl << endl;

        // Input
        cout << "Please enter the patient's name: ";
        string name;
        cin.ignore(); // Clear the input buffer before using getline
        getline(cin, name);

        cout << "\nPlease make a selection: \n"
            << "1: Inpatient Bill\n"
            << "2: Outpatient Bill\n"
            << "3: Exit Application\n";
        cout << "\nSelection: ";
        int selection;
        const int Inpatient_Bill = 1,
            Outpatient_Bill = 2,
            Exit_Application = 3;
        cin >> selection;
        cout << endl;

        // Choices
        int days_spent_in_hospital = 0;
        double daily_rate = 0.0;
        double hospital_medication_charges = 0.0;
        double charges_for_hospital_services = 0.0;

        if (selection == Inpatient_Bill)
        {
            cout << "Enter the number of days patient " << name << " stayed in the hospital: ";
            cin >> days_spent_in_hospital;
            while (days_spent_in_hospital < 0) {
                cout << "Days cannot be negative. Please enter again: ";
                cin >> days_spent_in_hospital;
            }

            cout << "What is the daily hospital charge: $";
            cin >> daily_rate;
            while (daily_rate < 0) {
                cout << "Daily rate cannot be negative. Please enter again: ";
                cin >> daily_rate;
            }

            cout << "Enter the medication expenses: $";
            cin >> hospital_medication_charges;
            while (hospital_medication_charges < 0) {
                cout << "Medication charges cannot be negative. Please enter again: ";
                cin >> hospital_medication_charges;
            }

            cout << "Enter the charges for services: $";
            cin >> charges_for_hospital_services;
            while (charges_for_hospital_services < 0) {
                cout << "Service charges cannot be negative. Please enter again: ";
                cin >> charges_for_hospital_services;
            }

            // Overload function
            double total_cost = total_charges(days_spent_in_hospital, daily_rate, hospital_medication_charges, charges_for_hospital_services);
            cout << "\nThe total charges for " << name << " are: $" << fixed << setprecision(2) << total_cost << endl;

        }
        else if (selection == Outpatient_Bill)
        {
            cout << "Enter charges for services: $";
            cin >> charges_for_hospital_services;
            while (charges_for_hospital_services < 0) {
                cout << "Service charges cannot be negative. Please enter again: ";
                cin >> charges_for_hospital_services;
            }

            cout << "Enter the medication expenses: $";
            cin >> hospital_medication_charges;
            while (hospital_medication_charges < 0) {
                cout << "Medication charges cannot be negative. Please enter again: ";
                cin >> hospital_medication_charges;
            }

            // Overload function
            double total_cost = total_charges(charges_for_hospital_services, hospital_medication_charges);
            cout << "\nThe total charges for " << name << " are: $" << fixed << setprecision(2) << total_cost << endl;
        }
        else if (selection == Exit_Application)
        {
            // Exit option
            cout << "Exiting the application. Goodbye!\n";
            break; // Exit the loop
        }
        else
        {
            cout << "The valid choices are 1 through 3. Run the program again and select one of those.\n";
        }

        cout << "\nWould you like to create another Hospital Bill for another patient? (y/n): ";
        cin >> create_another_bill;

    } while (create_another_bill == 'Y' || create_another_bill == 'y');

    return 0;
}

double total_charges(int days_spent_in_hospital, double daily_rate, double hospital_medication_charges, double charges_for_hospital_services)
{
    double total_charges = (days_spent_in_hospital * daily_rate) + hospital_medication_charges + charges_for_hospital_services;
    return total_charges;
}

double total_charges(double charges_for_hospital_services, double hospital_medication_charges)
{
    double total_charges = charges_for_hospital_services + hospital_medication_charges;
    return total_charges;
}
