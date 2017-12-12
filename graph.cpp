/*
 * graph.cpp
 * for undirected graph;
 *  Created on: 2017Äê9ÔÂ6ÈÕ
 *      Author: xinyi zhang
 */
#include<iostream>
#include"graph.h"
using namespace std;
graph::graph(int V){
	this->V=V;
	adj=new list<int>[V];
	treeStruct=new list<int>[V];
}
void graph::addEdge(int v, int w){
	adj[v].push_back(w);
/*bool flag=false;
do{

	if(v>=V)
	{
	flag=true;
	cout<<"The index of the vertex is out of boundry."<<endl;
	cout<<"Try again."<<endl;
    }
	else
	adj[v].push_back(w);
}while(flag==true);*/
}
void graph::DFSUtil(int v,bool* visited){
//visited=new bool[V];
	visited[v]=true;
list<int>::iterator it;
for(it=adj[v].begin();it!=adj[v].end();it++){
	if(visited[*it]!=true)
	   {
		visited[*it]=true;
//		addEdge(v,*it);
		DFS_Struct(v,*it);
		drawTree(v,*it);
        DFSUtil(*it,visited);
	   }
}
}
void graph::DFS(int v){
	bool* visit=new bool[V];
	for(int i=0;i<V;i++){
		visit[V]=false;
	}
	DFSUtil(v,visit);
	for(int i=0;i<V;i++){

	}
}
void graph::DFS_Struct(int first,int second){
	pair<int,int> edge=std::make_pair(first,second);
	vec.push_back(edge);
}
void graph::printfStruct(){
	vector<pair<int,int>>::iterator t;
	for(t=vec.begin();t!=vec.end();t++){
		cout<<(*t).first<<"---"<<(*t).second;
	}
}
void graph::drawTree(int ace,int dec){
	//check size init;
	int k;
/*	k=sizeof(adj);///sizeof(treeStruct[0]);
	cout<<"*******"<<k<<"*******************"<<endl;
    if((sizeof(treeStruct)/sizeof(treeStruct[0]))==V)*/
	treeStruct[ace].push_back(dec);
}
void graph::printTree(){
list<int>::iterator it;
cout<<"Tree Struct is "<<": "<<endl;
for(int i=0;i<V;i++){
	cout<<i;
	for(it=(treeStruct[i]).begin();it!=(treeStruct[i]).end();it++){
		cout<<"---"<<*it;
	}
	cout<<endl;
}
}


int main(){
	graph dfsGraph(5);
	dfsGraph.addEdge(1,2);
	dfsGraph.addEdge(1,3);
	dfsGraph.addEdge(1,0);
	dfsGraph.addEdge(2,1);
	dfsGraph.addEdge(2,4);
	dfsGraph.addEdge(3,1);
	dfsGraph.addEdge(3,0);
	dfsGraph.addEdge(4,2);
	dfsGraph.addEdge(0,1);
	dfsGraph.addEdge(0,4);

	dfsGraph.DFS(0);
	dfsGraph.printfStruct();
	dfsGraph.printTree();

	return 0;
}



