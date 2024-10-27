/*
* Ian Cluett
* CS210 Project 2
* 10/06/2024
*/
#include <iostream>
#include <string>

#include "investmentCalc.h"

using namespace std;

int main(){
    investmentCalc newInv;

    string userResponse = "";
    bool endLoop = false;

    while (!endLoop) {
        system("cls");
        newInv.userPrompt();
        newInv.displayTables();
        cout << "\n\nWould you like to go again?\nN to quit.";
        cin >> userResponse;
        if (userResponse == "N" || userResponse == "n") {
            endLoop = true;
        }
    }
    return 0;
}
