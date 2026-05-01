#include <iostream>
#include "Graph.h"
using namespace std;

    const std::map<int, User>& Graph::getUsers() const{
        return users;
    }
    const std::map<int, std::vector<int>>& Graph::getAdjList() const{
        return adjList;
    }

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

    //prevent duplicate friendships
    for (int duplicate: adjList[id1]){
        if (duplicate == id2) {
            return false;
        }
    }

    //prevents friendships with self
    if (id1 == id2){
        return false;
    }

    adjList[id1].push_back(id2);
    adjList[id2].push_back(id1);   
	return true;
}

void Graph::printFriends(int id){
    if (users.find(id) == users.end()){
        cout << "User not found \n";
        return;
    }

    cout << "Friends of " << users[id].name
    << ": \n";
    cout << "-----------------------------\n" << endl;

    if (adjList[id].empty()){
        cout << "No connections found.\n" << endl;
        return;
    }

    for (int friendID : adjList[id]){
        cout << users[friendID].name << "(ID: " 
        << friendID << ")" << endl;
    }
}
