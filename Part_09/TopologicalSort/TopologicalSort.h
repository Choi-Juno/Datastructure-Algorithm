#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "Graph.h"
#include "LinkedList.h"

void TopologicalSort(Vertex *V, Node **List);
void TS_DFS(Vertex *V, Node **List);

#endif // !TOPOLOGICALSORT_H