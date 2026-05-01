#include <iostream>
#include <limits>
#include "Graph.h"
using namespace std;


int main() {
    Graph g;
    int option;

    while (true){
        cout << "USM Friend Finder" << endl;
        cout << "Options: " << endl;
        cout << "1. Add User" << endl;
        cout << "2. Add Friendship" << endl;
        cout << "3. Show Connections" << endl;
        cout << "4. Exit" << endl;
        cout << "" << endl;
        cout << "Enter your choice: " << endl;
        cin >> option;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }

        if (option == 4){
            break;
        }

        else if (option == 1){
            int id;
            string name;

            cout << "Enter user ID: ";
            cin >> id;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid ID. ID must be numerical." << endl;
                continue;
            }

            cin.ignore();
            cout << "\n Enter name: " << endl;
            getline(cin, name);
            cout << "" << endl;
            if(g.addUser(id, name)){
                cout << "User Added" << endl;
            }
            else{
                cout << "Error: User already added" << endl;
            }
        }

        else if (option == 2){
            int id1, id2;
            cout << "Enter first user ID: " << endl;
            cin >> id1;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid ID. ID must be numerical." << endl;
                continue;
            }
            cout << "Enter second user ID: " << endl;
            cin >> id2;

            if (cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid ID. ID must be numerical." << endl;
                continue;
            }

            
        if(g.addFriendship(id1, id2)){
            cout << "Friendship Added" << endl;
        }
        else{
            cout << "Error: Friendship not added" << endl;
        }
        }
        else if (option == 3){
            int id;
            cout << "Enter user ID: " << endl;
            cin >> id;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid ID. ID must be numerical." << endl;
                continue;
            }

            g.printFriends(id);
        }
        else {
           cout << "Choice not Valid. Please choose a valid option" << endl; 
        }
    }
    cout << "Now exiting program" << endl;
    return 0;
}