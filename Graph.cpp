#include <iostream>
#include <algorithm>
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

//Removes existing User from Graph
bool Graph::removeUser(int id){
    if (users.find(id) == users.end()){
        return false;
   }
   // removes user from all other friend's list
   for (int friendID : adjList[id]){
        auto& vec = adjList[friendID];
        vec.erase(std::remove(vec.begin(), vec.end(), id), vec.end());
    }
    // removes user from data file
    adjList.erase(id);
    users.erase(id);
	return true;
}

//Removes existing Friendship connections from Graph
bool Graph::removeFriendship(int id1, int id2){
    if (users.find(id1) == users.end() || users.find(id2) == users.end()){
        return false;
   }
    auto& list1 = adjList[id1];
    auto& list2 = adjList[id2];


    if (std::find(list1.begin(), list1.end(), id2) == list1.end()){
        return false;
    }

    // remove id1 from id 2 list
    list2.erase(std::remove(list2.begin(), list2.end(), id1), list2.end());
    // remove id2 from id 1 list
    list1.erase(std::remove(list1.begin(), list1.end(), id2), list1.end());

    return true;
}

bool Graph::editUsername(int idNum, std::string userName){
    if (users.find(idNum) == users.end()){
        return false;
   }

   users[idNum].name = userName;
   return true;
}
