#include <iostream>
#include <limits>
#include "Graph.h"
#include "FileIO.h"
using namespace std;


int main() {
    Graph g;
    int option;

    while (true){
        cout << "\nUSM Friend Finder" << endl;
            cout << "-----------------------------\n" << endl;
        cout << "Options: " << endl;
        cout << "1.  Add User" << endl;
        cout << "2.  Add Friendship" << endl;
        cout << "3.  Show Connections" << endl;
        cout << "4.  Save Data" << endl;
        cout << "5.  Load Data" << endl;
        cout << "6.  Delete User" << endl;
        cout << "7.  Remove Friendship" << endl;
        cout << "8.  Edit Username" << endl;
        cout << "9.  Find Connections Between Users" << endl;
        cout << "10. Display All Users" << endl;
        cout << "11. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cout << "\n";

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }

        if (option == 11){
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
            cout << "\nFriendship Added\n" << endl;
        }
        else{
            cout << "\nError: Friendship not added\n" << endl;
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

        else if (option == 4){
            saveToFile(g, "data.txt");
            cout << "Data saved successfully\n";
        }

        else if (option == 5){
            loadFromFile(g, "data.txt");
            cout << "Data loaded successfully\n";
        }

        else if (option == 6){
            int id;
            cout << "Enter user ID: ";
            cin >> id;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid ID. ID must be numerical.\n" << endl;
                continue;
            }

            cout << "" << endl;
            if(g.removeUser(id)){
                cout << "User Removed" << endl;
            }
            else{
                cout << "Error: User not found\n" << endl;
            }
        }
        else if (option == 7){
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

            
        if(g.removeFriendship(id1, id2)){
            cout << "\nFriendship Removed\n" << endl;
        }
        else{
            cout << "\nError: Friendship not removed\n" << endl;
        }
        }
        else if (option == 8) {
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

            if(g.editUsername(id, name)){
                cout << "Username Updated" << endl;
            }
            else{
                cout << "Error: User not found\n" << endl;
            }
        }

        else if (option == 9){
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

        cout << "\n";
        g.findConnection(id1,id2);
        cout << "\n";
        }

        else if (option == 10){
            cout << "\n";
            g.printAllUsers();
            cout << "\n";
        }

        else {
           cout << "Choice not valid. Please choose a valid option\n" << endl; 
        }
    }
    cout << "Now exiting program" << endl;
    return 0;
}