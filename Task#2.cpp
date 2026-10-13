
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void registration()
{
    string username;
    string password;

    cout << "\n===== REGISTRATION =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    ifstream checkFile("users.txt");

    string savedUsername;
    string savedPassword;

    while(checkFile >> savedUsername >> savedPassword)
    {
        if(savedUsername == username)
        {
            cout << "Username already exists!" << endl;
            checkFile.close();
            return;
        }
    }

    checkFile.close();

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration successful!" << endl;
}

void login()
{
    string username;
    string password;

    cout << "\n===== LOGIN =====" << endl;

    cout << "Enter the Username: ";
    cin >> username;

    cout << "Enter the Password: ";
    cin >> password;

    ifstream file("users.txt");

    string savedUsername;
    string savedPassword;

    while(file >> savedUsername >> savedPassword)
    {
        if(savedUsername == username && savedPassword == password)
        {
            cout << "Login successful!" << endl;
            file.close();
            return;
        }
    }

    file.close();

    cout << "Invalid username or password!" << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================" << endl;
        cout << "LOGIN & REGISTRATION" << endl;
        cout << "====================" << endl;

        cout << "1. Registration" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter the Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            registration();
        }
        else if(choice == 2)
        {
            login();
        }
        else if(choice == 3)
        {
            cout << "Program ended" << endl;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }

    } while(choice != 3);

    return 0;
}