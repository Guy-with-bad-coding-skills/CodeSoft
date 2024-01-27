#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
bool tictactoe(char[][3], int, int, char);
void printgrid(char[][3]);
bool checkwinner(char[][3], char);
int main()
{
    string str1 = "----------TIC TAC TOE MULTIPLAYER GAME USING C++----------";
    system("color F0");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    cout << endl
         << setw(74) << "=====CODSOFT INTERNSHIP TASK#3=====";
    cout << endl
         << endl;
    cout << setw(30);
    for (int i = 0; str1[i] != '\0'; i++)
    {
        cout << str1[i];
        Sleep(40);
    }
    cout << endl
         << endl
         << setw(95) << "INSTRUCTION: USER NEEDS TO ENTER THE COORDINATES VALUE LIKE (0,1) etc.";
    cout << endl
         << endl
         << setw(75) << "*****ENTER ANY KEY TO CONTINUTE*****";
    cin.get();
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    cout << endl;
    char grid[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    int a1, a2;
    for (int i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            do
            {
                cout << endl
                     << setw(55) << "Enter Player 1 choice(x):";
                cin >> a1 >> a2;
                if (tictactoe(grid, a1, a2, 'x'))
                {
                    printgrid(grid);
                    if (checkwinner(grid, 'x'))
                    {
                        exit(1);
                    }

                    break;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
                    cout << setw(44) << "INVALID CHOICE" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                }
            } while (!tictactoe(grid, a1, a2, 'x'));
        }
        else
        {
            do
            {
                cout << setw(55) << "Enter Player 2 choice(o):";
                cin >> a1 >> a2;
                if (tictactoe(grid, a1, a2, 'o'))
                {
                    printgrid(grid);
                    if (checkwinner(grid, 'o'))
                    {
                        exit(1);
                    }
                    break;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
                    cout << setw(44) << "INVALID CHOICE" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                }
            } while (!tictactoe(grid, a1, a2, 'o'));
        }
    }
    cout << "The Game Has Been Drawn" << endl;
}
void printgrid(char grid[][3])
{
    cout << setw(45);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            cout << "|";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
            cout << grid[i][j];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            cout << "|";
        }
        cout << endl
             << setw(45);
    }
}
bool tictactoe(char grid[][3], int i, int j, char x)
{
    if (i >= 3 || j >= 3 || i < 0 || j < 0 || grid[i][j] != '-')
    {
        return false;
    }
    else
    {
        grid[i][j] = x;
        return true;
    }
}
bool checkwinner(char grid[][3], char x)
{
    char a, b, c;
    for (int k = 0; k < 3; k++)
    {
        a = grid[k][0];
        b = grid[k][1];
        c = grid[k][2];
        if (a == b && b == c && a == c && a != '-' && b != '-' && c != '-')
        {
            if (x == 'x')
            {
                cout << "Player 1 Has Won The Game" << endl;
                return true;
            }
            else
            {
                cout << "Player 2 Has Won The Game" << endl;
                return true;
            }
        }
    }
    for (int k = 0; k < 3; k++)
    {
        a = grid[0][k];
        b = grid[1][k];
        c = grid[2][k];
        if (a == b && b == c && a == c && a != '-' && b != '-' && c != '-')
        {
            if (x == 'x')
            {
                cout << "Player 1 Has Won The Game" << endl;
                return true;
            }
            else
            {
                cout << "Player 2 Has Won The Game" << endl;
                return true;
            }
        }
    }
    a = grid[0][0];
    b = grid[1][1];
    c = grid[2][2];
    if (a == b && b == c && a == c && a != '-' && b != '-' && c != '-')
    {
        if (x == 'x')
        {
            cout << "Player 1 Has Won The Game" << endl;
            return true;
        }
        else
        {
            cout << "Player 2 Has Won The Game" << endl;
            return true;
        }
    }
    a = grid[0][2];
    b = grid[1][1];
    c = grid[2][0];
    if (a == b && b == c && a == c && a != '-' && b != '-' && c != '-')
    {
        if (x == 'x')
        {
            cout << "Player 1 Has Won The Game" << endl;
            return true;
        }
        else
        {
            cout << "Player 2 Has Won The Game" << endl;
            return true;
        }
    }

    return false;
}
