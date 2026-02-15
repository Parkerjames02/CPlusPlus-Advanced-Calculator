/*
Parker Haynie
8/19/2022
Source File For Expanded C++ Calculator
*/

// This is the header file that contains all of the functions like "cout" and "cin".
#include <iostream>
// This is the header file that has the nexessary information to include the input and output related functions.
#include <stdio.h>
// This is the header file that has all of the information for all input and output related functions.
#include <stdlib.h>
// This is the header that tells the program to use a variable that has a type std::string. 
#include <string>
// This includes my own header file that I created for this project.
#include "expCalc.h"
// This tells the program to look at the standard namespace for everything that is not declared.
using namespace std;

// This initializes the char variable "loginOption".
char loginOption;
// This initializes the string variable "name".
string name;
// This initializes the int variables "a" and "b".
int a, b;
// This initializes the int pointer variables "p1" and "p2".
int *p1, *p2;
// This initializes the int variable "choice".
int choice;
// This initializes the char variable "again" and sets it equal to "Y".
char again = 'Y';

// This is the "loginSystem" class. It is the parent class to "userLogin" and "guestLogin".
// The "userLogin" and "guestLogin" classes inherit the "usernameEntered" variable and the "passwordEntered" variable.
class loginSystem
{
    // This line declares the string variable "usernameEntered" and the string variable "passwordEntered"
    // and puts them within the protected encapsulation.
protected:

    string usernameEntered;
    string passwordEntered;
};

// This is the "userLogin" class. It is the child class to "loginSystem". An object is made from
// this class if the user is a registered user.
class userLogin : public loginSystem
{
    // Everything underneath this line is under the encapsulation of public.
public:

    // This is the function that allows the registered user to login.
    void login()
    {
        cout << "\nPlease enter your login info." << endl;
        cout << "-----------------------------" << endl;
        cout << "Username:";
        // This line allows the user to enter their username.
        cin >> usernameEntered;

        // This if else statement is for if the user enters the correct username.
        if (usernameEntered == username)
        {
            cout << "Password:";
            // This line allows the user to enter their password.
            cin >> passwordEntered;

            // This if else statement is for if the user enters the correct password.
            if (passwordEntered == password)
            {
                cout << "\nYou have successfully logged in as a user and you now have access to the program." << endl;
                cout << "---------------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "\nThe password that you entered was incorrect. Please restart the program." << endl;
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            cout << "\nThe username that you entered was incorrect. Please restart the program." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // This line declares the string variable "username" and the string variable "password"
    // and puts them within the private encapsulation. It also sets it equal to my specific entries.
private:

    string username = "admin";
    string password = "123abc";
};

// This is the "guestLogin" class. It is the child class to "loginSystem". An object is made from
// this class if the user is a guest.
class guestLogin : public loginSystem
{
    // Everything underneath this line is under the encapsulation of public.
public:

    // This is the function that allows the guest to login.
    void login()
    {
        cout << "\nPlease make an account now." << endl;
        cout << "---------------------------" << endl;
        cout << "Username:";
        // This line allows the user to enter their username.
        cin >> usernameEntered;
        cout << "Password:";
        // This line allows the user to enter their password.
        cin >> passwordEntered;
        cout << "\nYou have successfully logged in as a guest and you now have access to the program." << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }

    // This line declares the string variable "username" and the string variable "password"
    // and puts them within the private encapsulation.
private:

    string username;
    string password;
};

// This is a void function that asks the user if they are a registered user or a guest.
// If they are a registered user then they will have to login with a certain username and password.
// If they are a guest then they are asked to make a account (their username and password entries don't matter).
void loginOptions()
{
    cout << "Are you a registered user or a guest?" << endl;
    cout << "(Enter 'r' for registered user and 'g' for guest)" << endl;
    // This line allows the user to enter their login option.
    cin >> loginOption;
    // This if/else if/else statement is used to let the user choose if they are a registered user or a guest.
    if (loginOption == 'r' || loginOption == 'R')
    {
        // This line creates an object from the class "userLogin".
        userLogin userLogObj;
        // This line takes the object created from the class and uses the "login()" function to let the user login.
        userLogObj.login();
    }
    else if (loginOption == 'g' || loginOption == 'G')
    {
        // This line creates an object from the class "guestLogin".
        guestLogin guestLogObj;
        // This line takes the object created from the class and uses the "login()" function to let the user login.
        guestLogObj.login();
    }
    else
    {
        cout << "\nThat is an invalid choice. Please restart the program." << endl;
        exit(EXIT_FAILURE);
    }
}

// This is a void function that displays the title of the program.
void displayTitle()
{
    cout << "\n             <-[The Expanded C++ Calculator]->" << endl;
}

// This is a string function that asks the user for their name and then returns that name.
string getName()
{
    cout << "\nPlease enter the name that you would like to be addressed by." << endl;
    // This line allows the user to enter their name.
    cin >> name;
    // This line returns the name after it is entered.
    return name;
}

// This is a void function that displays the welcome message. It explains what the program is.
// It also refers to the user as the name that was entered previously.
void displayWelcomeMessage()
{
    cout << "\nHello, " << name << ", and welcome to the Expanded C++ Calculator. With this" << endl;
    cout << "calculator you will be able to add, subtract, multiply, and divide any" << endl;
    cout << "two numbers. Go ahead and enter the equation that you would like the" << endl;
    cout << "answer to." << endl;
}

// This is a void function that will take the equation that was entered by the user and then it will
// show you the answer to that equation. The user has the option to add, subtract, multiply and divide.
void enterEquation()
{
    // This is a while loop that allows the user to enter another equation if they want to.
    while (again == 'y' || again == 'Y')
    {
        p1 = &a;
        p2 = &b;
        cout << "\nGo ahead and select the type of equation you want answered." << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "[1] Addition" << endl;
        cout << "[2] Subtraction" << endl;
        cout << "[3] Multiplication" << endl;
        cout << "[4] Division" << endl;
        cout << "\nPlease enter numbers 1-4 to chose the type of equation." << endl;
        // This line allows the user to make a choice on what type of equation that they want the answer to.
        cin >> choice;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Enter the first number of the equation." << endl;
        // This line allows the user to enter the first number of the equation.
        cin >> a;
        cout << "Enter the second number of the equation." << endl;
        // This line allows the user to enter the second number of the equation.
        cin >> b;

        // This determines what is displayed depending on the type of equation that is chosen by the user.
        switch (choice)
        {
            // This case only occurs if the user decides on addition.
        case 1:
            cout << "-----------------------------------------" << endl;
            cout << *p1 << " + " << *p2 << " = " << *p1 + *p2 << endl;
            cout << "\nWould you like to try another equation?" << endl;
            cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
            // This line allows the user to make the decision of entering another equation.
            cin >> again;
            break;
            // This case only occurs if the user decides on subtraction.
        case 2:
            cout << "-----------------------------------------" << endl;
            cout << *p1 << " - " << *p2 << " = " << *p1 - *p2 << endl;
            cout << "\nWould you like to try another equation?" << endl;
            cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
            // This line allows the user to make the decision of entering another equation.
            cin >> again;
            break;
            // This case only occurs if the user decides on multiplication.
        case 3:
            cout << "----------------------------------------" << endl;
            cout << *p1 << " * " << *p2 << " = " << *p1 * *p2 << endl;
            cout << "\nWould you like to try another equation?" << endl;
            cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
            // This line allows the user to make the decision of entering another equation.
            cin >> again;
            break;
            // This case only occurs if the user decides on division.
        case 4:
            // This if statement only outputs the answer if you don't devide by zero.
            if (*p2 == 0)
            {
                cout << "---------------------------------" << endl;
                cout << "You can not divide a number by 0." << endl;
                cout << "\nWould you like to try another equation?" << endl;
                cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
                // This line allows the user to make the decision of entering another equation.
                cin >> again;
            }
            else if (*p2 != 0)
            {
                cout << "----------------------------------------" << endl;
                cout << *p1 << " / " << *p2 << " = " << *p1 / (float)*p2 << endl;
                cout << "\nWould you like to try another equation?" << endl;
                cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
                // This line allows the user to make the decision of entering another equation.
                cin >> again;
            }
            break;
        default:
            cout << "-----------------------------------------------------" << endl;
            cout << "That is an invalid choice. Please restart the program." << endl;
            exit(EXIT_FAILURE);
        }
    }
}

// This is a void function that displays the goodbye message if the user is done using the program.
void displayGoodbyeMessage()
{
    cout << "\nThank you for using my calculator program!" << endl;
}