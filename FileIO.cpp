#include "FileIO.h"
#include "Graph.h"
#include <fstream>
#include <sstream>
using namespace std;

void saveToFile(Graph& g, const std::string& filename){
    ofstream file(filename);

    if(!file.is_open()){
        return;
    }

    //Save users
    for (const auto& pair : g.getUsers()){
        file << "USER" << pair.second.id << " " << pair.second.name << "\n";
    }
    //Save friendships
    for(const auto& pair : g.getAdjList()){
        int from = pair.first;
        for(int to : pair.second){
            if(from < to){
               file << "EDGE " << from << " " << to << "\n";
            }
        }
    }
    file.close();
}

void loadFromFile(Graph& g, const std::string& filename){
    ifstream file(filename);
    string dataType;

    if(!file.is_open()){
        return;
    }

    //Load users
    while (file >> dataType){
        if (dataType == "USER"){
            int id;
            string name;
            file >> id >> name;

            g.addUser(id, name);
        }
        //Load friendships
        else if (dataType == "EDGE"){
            int id1, id2;
            file >> id1 >> id2;

            g.addFriendship(id1, id2);
        }
    }
    file.close();
}