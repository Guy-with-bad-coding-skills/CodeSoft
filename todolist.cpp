#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stack>
#include <iomanip>
// Used the concept of Singly Linked List in order to perform this task also used stack that store the task that has been done.
using namespace std;
class tasks
{
public:
    string task;
    tasks *next;
    tasks(string t)
    {
        task = t;
        next = NULL;
    }
};
class list
{
public:
    tasks *head;
    stack<string> s1;
    stack<string> temp;
    list()
    {
        head = NULL;
    }
    void addtask(string t)
    {
        tasks *newtask = new tasks(t);
        if (head == NULL)
        {
            head = newtask;
        }
        else
        {
            tasks *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newtask;
        }
    }
    void deletetask(string t)
    {
        tasks *temp = head;
        tasks *ptr;
        bool flag;
        if (temp == NULL)
        {
            flag = 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
            cout << endl
                 << "\t\t\t\t\t\tSORRY NO TASKS FOUND" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            cout << setw(80) << "-----------------------------------------" << endl;
            cout << endl
                 << setw(75) << "PRESS ENTER KEY TO CONTINUE...";
            cin.get();
            system("cls");
        }
        while (temp != NULL)
        {
            if (temp->task == t)
            {
                flag = 1;
                if (temp == head)
                {
                    s1.push(temp->task);
                    ptr = temp->next;
                    delete temp;
                    head = ptr;
                }
                else
                {
                    s1.push(temp->task);
                    ptr->next = temp->next;
                    delete temp;
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
                cout << endl
                     << "\t\t\t\t\t\tTASK HAS BEEN MARKED DONE" << endl;
            }
            ptr = temp;
            temp = temp->next;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            cout << setw(80) << "-----------------------------------------" << endl;
            cout << endl
                 << setw(75) << "PRESS ENTER KEY TO CONTINUE...";
            cin.get();
            system("cls");
        }
        if (flag != 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
            cout << endl
                 << "\t\t\t\t\t\tSORRY TASK NOT FOUND" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            cout << setw(80) << "-----------------------------------------" << endl;
            cout << endl
                 << setw(75) << "PRESS ENTER KEY TO CONTINUE...";
            cin.get();
            system("cls");
        }
    }
    void display()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
        cout << endl
             << endl;
        tasks *temp = head;
        if (temp == NULL)
        {
            cout
                << setw(69);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
            cout << "SORRY NO TASKS FOUND" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        }
        while (temp != NULL)
        {
            cout << "\t\t\t\t\t" << temp->task << endl;
            temp = temp->next;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        cout << setw(80) << "-----------------------------------------" << endl;
        cout << endl
             << setw(75) << "PRESS ENTER KEY TO CONTINUE...";
        cin.get();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        system("cls");
    }
    void displaydone()
    {
        temp = s1;
        if (temp.empty())
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
            cout << endl
                 << endl
                 << "\t\t\t\t\t\tNO TASK HAS BEEN DONE YET" << endl;
        }
        else
        {
            cout << endl;
            while (!temp.empty())
            {
                cout << setw(50) << temp.top() << endl;
                temp.pop();
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        cout << setw(80) << "-----------------------------------------" << endl;
        cout << endl
             << setw(75) << "PRESS ENTER KEY TO CONTINUE...";
        cin.get();
        system("cls");
    }
};
int main()
{
    int choice;
    string task;
    string str = "TO DO LIST PROJECT USING C++";
    string str1 = "*****DISPLAYING YOUR TASKS*****";
    string str2 = "*****VIEWING RECENTLY DONE TASKS*****";
    string str3 = "TASK HAS BEEN ADDED SUCCESSFULLY";
    string str4 = "THE TASK HAS BEEN MARKED DONE";
    list l1;
    system("color F0");
    cout << endl
         << endl
         << setw(72) << "=====CODSOFT INTERNSHIP TASK#4=====";
    cout << endl
         << endl;
    cout << setw(42);
    for (int i = 0; str[i] != '\0'; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
        cout << str[i];
        Sleep(70);
    }
    cout << endl
         << endl
         << setw(75) << "*****ENTER ANY KEY TO CONTINUTE*****";
    cin.get();
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    do
    {
        system("cls");
        cout << endl
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 243);
        cout << setw(75) << "*****SELECT WHAT YOU WANT TO DO*****" << endl
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
        cout << "\n\t\t\t\t\t1. ADD TASK\n\t\t\t\t\t2. MARK DONE\n\t\t\t\t\t3. DISPLAY TASKS\n\t\t\t\t\t4. VIEW RECENTLY DONE TASKS" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
        cout << "\t\t\t\t\tENTER YOUR CHOICE:";
        cin >> choice;
        cin.ignore();
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        switch (choice)
        {
        case 1:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 247);
            cout << endl
                 << endl
                 << endl
                 << "\t\t\t\t\tENTER THE TASK THAT YOU WANT TO ADD:";
            cin >> task;
            cin.ignore();
            l1.addtask(task);
            cout << endl
                 << setw(45);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
            for (int i = 0; str3[i] != '\0'; i++)
            {
                cout << str3[i];
                Sleep(40);
            }
            Sleep(100);
            system("cls");
            break;
        case 3:
            cout << endl
                 << endl;
            cout << setw(45);
            for (int i = 0; str1[i] != '\0'; i++)
            {
                cout << str1[i];
                Sleep(40);
            }
            l1.display();
            break;
        case 2:
            cout << endl
                 << endl
                 << endl;
            cout << setw(75);
            cout << "ENTER THE TASKS THAT HAS BEEN DONE:";
            cin >> task;
            cin.ignore();
            l1.deletetask(task);
            break;
        case 4:
            cout << endl
                 << endl
                 << endl
                 << setw(42);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
            for (int i = 0; str2[i] != '\0'; i++)
            {
                cout << str2[i];
                Sleep(40);
            }
            l1.displaydone();
            break;
        default:
            cout << "THANKYOU";
        }
    } while (choice != 0);
}