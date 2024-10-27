/*
* Ian Cluett
* CS210 Project 2
* 10/06/2024
*/
#ifndef INVLESTMENTCALC_H
#define INVLESTMENTCALC_H


class investmentCalc {
    public:
        // set/get Functions for menu prompt
        void setInitialInvestment(double t_initialInvestment);
        void setMonthlyDeposit(double t_monthlyDeposit);
        void setAnnualInterest(double t_annualInterest);
        void setNumYears(int t_numYears);

        double getInitialInvestment();
        double getMonthlyDeposit();
        double getAnnualInterest();
        int getNumYears();

        // Formatted ouput for each year
        void displayTables();

        // Menu loop function
        void userPrompt();

    private:
        // Initialize private variables
        double m_initialInvestment = 0;
        double m_monthlyDeposit = 0;
        double m_annualInterest = 0;

        int m_numYears = 0;

        // Declarations for private functions
        void m_calculateInterestMonthly(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numYears);
        void m_calculateInterest(double t_initialInvestment, double t_annualInterest, int t_numYears);
        void m_tableHeader(bool t_hasMonthlyDeposit);

        
};

#endif