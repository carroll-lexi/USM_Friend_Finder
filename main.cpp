#include <iostream>
#include <limits>
#include "Graph.h"
using namespace std;


int main() {
    Graph g;
    int option;

    while (true){
        cout << "\nUSM Friend Finder" << endl;
            cout << "-----------------------------\n" << endl;
        cout << "Options: " << endl;
        cout << "1. Add User" << endl;
        cout << "2. Add Friendship" << endl;
        cout << "3. Show Connections" << endl;
        cout << "4. Delete User" << endl;
        cout << "5. Remove Friendship" << endl;
        cout << "6. Edit Username" << endl;
        cout << "7. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cout << "\n";

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }

        if (option == 7){
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
                cout << "Invalid ID. ID must be numerical.\n" << endl;
                continue;
            }

            cin.ignore();
            cout << "\nEnter name: ";
            getline(cin, name);
            cout << "" << endl;
            if(g.addUser(id, name)){
                cout << "User Added" << endl;
            }
            else{
                cout << "Error: User already added\n" << endl;
            }
        }

        else if (option == 2){
            int id1, id2;
            cout << "Enter first user ID: ";
            cin >> id1;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid ID. ID must be numerical.\n" << endl;
                continue;
            }
            cout << "Enter second user ID: ";
            cin >> id2;

            if (cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid ID. ID must be numerical.\n" << endl;
                continue;
            }

            
        if(g.addFriendship(id1, id2)){
            cout << "Friendship Added\n" << endl;
        }
        else{
            cout << "Error: Friendship not added\n" << endl;
        }
        }
        else if (option == 3){
            int id;
            cout << "Enter user ID: ";
            cin >> id;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid ID. ID must be numerical.\n" << endl;
                continue;
            }

            g.printFriends(id);
        }

        else if (option == 4 || option == 5 || option == 6) {
            cout << "Features Under Construction. Please come back to enjoy these features later. In the meantime, enjoy the rest of our applications functions!\n" << endl;
        }

        else {
           cout << "Choice not valid. Please choose a valid option\n" << endl; 
        }
    }
    cout << "Now exiting program" << endl;
    return 0;
}