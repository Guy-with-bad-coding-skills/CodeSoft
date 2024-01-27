#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
float addition(int, int);
float subtraction(int, int);
float multiplication(int, int);
float division(int, int);
int main()
{
    system("color F0");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 243);
    string str = "WELCOME TO SIMPLE CALCULATOR USING C++";
    int choice;
    float a, b;
    cout
        << endl
        << endl
        << setw(75) << "=====CODSOFT INTERNSHIP TASK#2=====";
    cout << endl
         << endl
         << setw(40);
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
        Sleep(40);
    }
    cout << endl
         << endl
         << endl
         << setw(75) << "*****ENTER ANY KEY TO CONTINUTE*****";
    cin.get();
    system("cls");
    do
    {
        cout << endl
             << endl
             << setw(75);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        cout
            << "*****SELECT WHAT YOU WANT TO DO*****";
        cout << "\n\t\t\t\t\t1. ADDITION\n\t\t\t\t\t2. SUBTRACTION\n\t\t\t\t\t3. MULTIPLICATION\n\t\t\t\t\t4. DIVISION\n\t\t\t\t\t0. EXIT\n\t\t\t\t\tENTER:";
        cin >> choice;
        if (choice != 0)
        {
            cout << "\t\t\t\t\tEnter The Operands:";
            cin >> a >> b;
        }
        cin.ignore();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
        cout << setw(50);
        switch (choice)
        {
        case 1:
            cout << "RESULT IS:" << addition(a, b) << endl;
            break;
        case 2:
            cout << "RESULT IS:" << subtraction(a, b) << endl;
            break;
        case 3:
            cout << "RESULT IS:" << multiplication(a, b) << endl;
            break;
        case 4:
            cout << "RESULT IS:" << division(a, b) << endl;
            break;
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
            cout << "THANK YOU!";
            exit(1);
        }
        cout << endl
             << setw(75) << "*****ENTER ANY KEY TO CONTINUTE*****";
        cin.get();
        system("cls");
    } while (choice != 0);
}
float addition(int a, int b)
{
    return a + b;
}
float subtraction(int a, int b)
{
    return a - b;
}
float multiplication(int a, int b)
{
    return a * b;
}
float division(int a, int b)
{
    if (b == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
        cout
            << setw(60) << "INVALID" << endl;
        return 0;
    }
    return a / b;
}