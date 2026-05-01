#include <iostream>
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

        if (option == 4){
            break;
        }

        else if (option == 1){
            int id;
            string name;
            cout << "Enter user ID: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;

            if(g.addUser(id, name)){
                cout << "User Added";
            }
            else{
                cout << "Error: User already added";
            }
        }

        else if (option == 2){
            int id1, id2;
            cout << "Enter first user ID: ";
            cin >> id1;
            cout << "Enter second user ID: ";
            cin >> id2;

            
        if(g.addFriendship(id1, id2)){
            cout << "Friendship Added";
        }
        else{
            cout << "Error: Friendship not added";
        }
        }
        else if (option == 3){
            int id;
            cout << "Enter user ID: ";
            cin >> id;

            g.printFriends(id);
        }
        else {
           cout << "Choice not Valid. Please choose a valid Option" << endl; 
        }
    }
    cout << "Now exiting program";
    return 0;
}