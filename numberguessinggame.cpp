#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <iomanip>
// Used the concept of recursion and the base case will be true when user input is matched with the random number generated by computer.
void randomnumber(int, int);
using namespace std;
int main()
{
     int num;
     system("color 1");
     string str = "WELCOME TO RANDOM NUMBER GUESSING GAME USING C++";
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
     cout << endl
          << endl
          << endl
          << setw(80);
     cout << "==========CODSOFT INTERNSHIP TASK#1==========";
     cout << endl
          << endl
          << endl
          << setw(35);

     for (int i = 0; str[i] != '\0'; i++)
     {
          cout << str[i];
          Sleep(40);
     }
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
     cout << endl
          << endl
          << endl
          << setw(75) << "*****ENTER ANY KEY TO CONTINUTE*****";
     cin.get();
     system("cls");
     system("color F0");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
     cout << endl
          << endl
          << endl
          << setw(70);
     cout << "GUESS A NUMBER RANGING FROM 0 to 100:";
     cin >> num;
     int random = rand() % (100 - 1) + 1;
     randomnumber(num, random);
}
void randomnumber(int num, int random)
{
     if (random == num)
     {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
          cout << endl
               << setw(70) << "CONGRATULATIONS YOU GUESSED THE NUMBER";
          return;
     }
     if (num < random)
     {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
          cout << endl

               << setw(72) << "THE GUESSES NUMBER IS TOO LOW TRY AGAIN" << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
          cout << endl
               << setw(70) << "GUESS A NUMBER RANGING FROM 0 to 100:";
          cin >> num;
     }
     else
     {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
          cout << endl
               << setw(73) << "THE GUESSES NUMBER IS TOO HIGH TRY AGAIN" << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
          cout << endl
               << setw(70) << "GUESS A NUMBER RANGING FROM 0 to 100:";
          cin >> num;
     }
     randomnumber(num, random); // recursion
}
