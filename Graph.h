#ifndef graph_h
#define graph_h

#include <map>
#include <vector>
#include "User.h"

class Graph {
private:
    std::map<int, User> users;
    std::map<int, std::vector<int>> adjList;

public:
    const std::map<int, User>& getUsers() const;
    const std::map<int, std::vector<int>>& getAdjList() const;

    std::string removeSpacesFromName(std::string name);
    bool addUser(int id, std::string name);
    bool addFriendship(int id1, int id2);
    void printFriends(int id);

    bool removeUser(int id);
    bool removeFriendship(int id1, int id2);

    bool editUsername(int idNum, std::string userName);
};

#endif
