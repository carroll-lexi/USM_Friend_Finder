#include <map>
#include <vector>
#include "User.h"

class Graph {
private:
    std::map<int, User> users;
    std::map<int, std::vector<int>> adjList;

public:
    bool addUser(int id, std::string name);
    bool addFriendship(int id1, int id2);
    void printFriends(int id);

    bool removeUser(int id);
    bool removeFriendship(int id1, int id2);

    bool editUsername(int idNum, std::string userName);
};
