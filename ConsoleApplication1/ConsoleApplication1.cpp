#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <cstdlib>

using namespace std;

struct myStat {
public:
    vector<string> reg;
    vector<string> usernames = { "Denis", "Misha", "Miroslaw", "Adolf", "Stary" };
    vector<int> positions;
    string login;
    string password;

    myStat() {
        for (int i = 0; i < usernames.size(); ++i) {
            positions.push_back(i + 1);
        }
    }

    void Register() {

        cout << "Redem login: ";
        cin >> login;
        while (login.length() < 4) {
            cout << "Try now" << endl;
            cout << "Redem login: ";
            cin >> login;
        }

        cout << "Redem password: ";
        cin >> password;

        while (password.length() < 8) {
            cout << "Try now" << endl;
            cout << "Redem password: ";
            cin >> password;
        }

        reg.push_back(login);
        reg.push_back(password);

        cout << "Suc!" << endl;
    }

    void Menu() {
        int choice;
        string checkChoice;
        string newName;
        cout << "-------------------" << endl;
        cout << "Welcome! " << endl;
        do {
            cout << "-------------------" << endl;
            cout << " " << endl;
            cout << "Menu:" << endl;
            cout << "1. Your name, password " << endl;
            cout << "2. Homework " << endl;
            cout << "3. Average score" << endl;
            cout << "4. Place in the group" << endl;
            cout << "5. Exit " << endl;
            cout << "Action: ";
            cin >> choice;
            cout << " " << endl;

            switch (choice) {
            case 1:
                for (size_t i = 0; i < reg.size(); i += 2) {
                    cout << "Login: " << reg[i] << "\nPassword: " << reg[i + 1] << endl;
                }

                choice = 0;
                break;

            case 2:

                cout << "Your homework: 1 " << endl;
                cout << "Want to check?";
                cout << ": ";
                cin >> checkChoice;
                if (checkChoice == "Yes" || checkChoice == "yes" || checkChoice == "Y" || checkChoice == "y") {
                    string choice1;
                    cout << "Task: ";
                    cout << "Enter 'Hello World' " << endl;
                    cout << "Ready to perform? " << endl;
                    cout << ": ";
                    cin >> choice1;
                    if (choice1 == "Yes" || choice1 == "yes" || choice1 == "Y" || choice1 == "y") {
                        string fileName;
                        string dz;
                        
                        cout << "Enter file name: ";
                        cin >> fileName;
                        ofstream hw1File(fileName + ".txt");
                        
                        cout << "Enter dz (Hello Word) " << endl;
                        cout << ": ";
                        cin >> dz;
                        
                        hw1File << dz;
                    }
                    else if (choice1 == "No" || choice1 == "no" || choice1 == "N" || choice1 == "n") {
                        cout << "Don't you want to do it? 2 buddy" << endl;
                    }
                    else {
                        cout << "???";
                    }
                }
                else if (checkChoice == "No" || checkChoice == "no" || checkChoice == "N" || checkChoice == "n") {
                    cout << "Ok " << endl;
                }
                else {
                    cout << "???" << endl;
                }
                choice = 0;
                break;
            case 3:
                srand(time(NULL));
                int randomNumber = rand() % 1 + 5;

                cout << "You have: ";
                for (int i = 0; i < randomNumber; i++) {
                    cout << "*";
                }
                choice = 0;
                break;

            case 4:

                cout << "Enter your name: ";
                cin >> newName;

                usernames.push_back(newName);
                positions.push_back(usernames.size());

                cout << "Leaderboard:" << endl;

                for (int i = 0; i < usernames.size(); i++) {
                    cout << "Name: " << usernames[i] << ", pos: " << positions[i] << endl;
                }
                choice = 0;
                break;

            case 5:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Cheto neto" << endl;
            }

        } while (choice != 5);
    }


};


int main()
{
    myStat mystat;

    mystat.Register();
    mystat.Menu();

}