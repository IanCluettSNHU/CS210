/*
* Ian Cluett
* CS210 Project 2
* 10/06/2024
*/

#include <iostream>
#include <string>
#include <iomanip>

#include "investmentCalc.h"

using namespace std;

// Setters for menu loop
void investmentCalc::setInitialInvestment(double t_initialInvestment){m_initialInvestment = t_initialInvestment;}
void investmentCalc::setMonthlyDeposit(double t_monthlyDeposit){m_monthlyDeposit = t_monthlyDeposit;}
void investmentCalc::setAnnualInterest(double t_annualInterest){m_annualInterest = t_annualInterest;}
void investmentCalc::setNumYears(int t_numYears){m_numYears = t_numYears;}
// Getters for calculations
double investmentCalc::getInitialInvestment(){return m_initialInvestment;}
double investmentCalc::getMonthlyDeposit(){return m_monthlyDeposit;}
double investmentCalc::getAnnualInterest(){return m_annualInterest;}
int investmentCalc::getNumYears(){return m_numYears;}

void investmentCalc::userPrompt(){
    // Initialize input values
    bool notValid = true; //check for input validation
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    // Menu Header
    cout << setfill('=') << setw(34) << '\n';
    cout << "========= Enter Values: =========\n";

    // Prompt user for each required aspect, then set the internal variables
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    // Check to make sure the input is valid
    while (notValid) {
        if (initialInvestment < 0) {
            cout << "Please enter a number greater than or equal to 0: ";
            cin.clear(); // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cin >> initialInvestment;
        }
        else {
            investmentCalc::setInitialInvestment(initialInvestment);
            notValid = false;
        }
    }
    //cout << "entered: $" << investmentCalc::getInitialInvestment() << '\n';

    notValid = true;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    while (notValid) {
        if (monthlyDeposit < 0) {
            cout << "Please enter a number greater than or equal to 0: ";
            cin.clear(); // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cin >> monthlyDeposit;
        }
        else {
            investmentCalc::setMonthlyDeposit(monthlyDeposit);
            notValid = false;
        }
    }
    //cout << "entered: $" << investmentCalc::getMonthlyDeposit() << '\n';

    notValid = true;
    cout << "Annual Interest Rate: %";
    cin >> annualInterest;
    while (notValid) {
        if (annualInterest < 0) {
            cout << "Please enter a number greater than or equal to 0: ";
            cin.clear(); // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cin >> annualInterest;
        }
        else {
            investmentCalc::setAnnualInterest(annualInterest);
            notValid = false;
        }
    }
    //cout << "entered: %" << investmentCalc::getAnnualInterest() << '\n';

    notValid = true;
    cout << "Number of years: ";
    cin >> numYears;
    while (notValid) {
        if (numYears <= 0) {
            cout << "Please enter a number greater than 0: ";
            cin.clear(); // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cin >> numYears;
        }
        else {
            investmentCalc::setNumYears(numYears);
            notValid = false;
        }
    }
    //cout << "entered: %" << investmentCalc::getNumYears() << '\n';

}

void investmentCalc::displayTables() {
    // Output the calculations in a formatted "table"
    bool t_hasMonthlyDeposit = false;
    m_tableHeader(t_hasMonthlyDeposit);
    m_calculateInterest(getInitialInvestment(), getAnnualInterest(), getNumYears());

    t_hasMonthlyDeposit = true;
    m_tableHeader(t_hasMonthlyDeposit);
    m_calculateInterestMonthly(getInitialInvestment(), getMonthlyDeposit(), getAnnualInterest(), getNumYears());

    cout << "+" << setw(65) << setfill('-') << "+\n";

}

void investmentCalc::m_calculateInterestMonthly(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numYears){
    // Function to calculate and output interest with monthly deposit
    double runningTotal = t_initialInvestment;
    double interestCurrent = 0.00;
    double interestTotal = 0.00;

    cout << fixed << setprecision(2) << setfill(' ') << right;



    for (int i = 1; i <= t_numYears; ++i) {
        //calculate and output the monthly interest and running balance
        for (int j = 0; j < 12; ++j) {
            interestCurrent = (runningTotal + t_monthlyDeposit) * ((t_annualInterest / 100) / 12);
            runningTotal += interestCurrent + t_monthlyDeposit;
            interestTotal += interestCurrent;
        }

        // output the results
        cout << showbase << "|" << setw(5) << i;
        cout << setw(25) << runningTotal;
        cout << setw(32) << interestTotal << " |" << endl;
    }
}

void investmentCalc::m_calculateInterest(double t_initialInvestment, double t_annualInterest, int t_numYears){
    // function to calculate and output interest without monthly deposit
    double runningTotal = t_initialInvestment;
    double interestTotal = 0.00;

    cout << fixed << setprecision(2) << setfill(' ');

    for (int i = 1; i <= t_numYears; ++i) {
        interestTotal = runningTotal * (t_annualInterest / 100);
        runningTotal += interestTotal;

        // output the results
        cout << showbase << "|" << setw(5) << i;
        cout << setw(25) << runningTotal;
        cout << setw(32) << interestTotal << " |" << endl;
    }

}

void investmentCalc::m_tableHeader(bool t_hasMonthlyDeposit){
    cout << "+" << setw(65) << setfill('-') << "+\n";
    // Branch depending on whether or not it contains monthly deposits
    if(!t_hasMonthlyDeposit){
        cout << "|   Balance and Interest Without Additional Monthly Deposits    |\n";
    } else {
        cout << "|     Balance and Interest With Additional Monthly Deposits     |\n";
    }
    cout << "+" << setw(65) << setfill('=') << "+\n";
    cout << "| Year     Year End Balance ($)    Year End Interest Earned ($) |\n";
    cout << "+" << setw(65) << setfill('-') << "+\n";

}