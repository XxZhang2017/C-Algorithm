/*
 * graph.h
 *
 *  Created on: 2017Äê9ÔÂ6ÈÕ
 *      Author: xinyi zhang
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#ifndef GRAPH_H_
#define GRAPH_H_

class graph{
   list<int> *adj;
   int V;
   void DFSUtil(int v,bool visited[]);
   vector<pair<int,int>> vec;
   list<int> *treeStruct;
public:
	graph(int V);
	void DFS(int v);
	void addEdge(int v,int w);
	void DFS_Struct(int,int);
	void printfStruct();
	void drawTree(int,int);
	void printTree();
};
#endif /* GRAPH_H_ */
