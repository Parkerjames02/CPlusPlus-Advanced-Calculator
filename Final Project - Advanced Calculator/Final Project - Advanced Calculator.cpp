/*
Parker Haynie
8/19/2022
The Expanded C++ Calculator
*/

// This includes my own header file that I created for this project.
#include "expCalc.h"

// This is the "main()" function. This is the first function that the program looks at.
int main()
{
    // This displays whatever is in the "loginOptions()" function to the command terminal.
    loginOptions();
    // This displays whatever is in the "displayTitle()" function to the command terminal.
    displayTitle();
    // This displays whatever is in the "getName()" function to the command terminal.
    getName();
    // This displays whatever is in the "displayWelcomeMessage()" function to the command terminal.
    displayWelcomeMessage();
    // This displays whatever is in the "enterEquation()" function to the command terminal.
    enterEquation();
    // This displays whatever is in the "displayGoodbyeMessage()" function to the command terminal.
    displayGoodbyeMessage();
    //This line returns the value "0" after main has already ran through everything.
    return 0;
}