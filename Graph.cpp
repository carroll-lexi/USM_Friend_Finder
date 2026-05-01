#include <iostream>
#include "Graph.h"
using namespace std;

//Adds new User to Graph
bool Graph::addUser(int id, string name){
    if (users.count(id)){
        return false;
   }
    users[id] = {id, name};
    adjList[id] = {};
	return true;
}

//Adds new Friendship connection to Graph
bool Graph::addFriendship(int id1, int id2){
    if (users.find(id1) == users.end() || users.find(id2) == users.end()){
        return false;
   }

    adjList[id1].push_back(id2);
    adjList[id2].push_back(id1);   
	return true;
}

void Graph::printFriends(int id){
    if (adjList.find(id) == adjList.end()){
        cout << "User not found /n";
        return;
    }
    else{
        cout << "Friends of " << users[id].name << ": " << endl;
        for (int friendID : adjList[id]){
            cout << users[friendID].name << "(ID: " << friendID << ")" << endl;
        }
    }
}
