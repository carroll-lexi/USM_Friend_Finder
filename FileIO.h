#ifndef fileio_h
#define fileio_h

#include "Graph.h"

void saveToFile(Graph& g, const std::string& filename);
void loadFromFile(Graph& g, const std::string& filename);

#endif