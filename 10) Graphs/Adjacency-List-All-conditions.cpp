#include "Graphs.h"
#include<iostream>
#include<vector>
using namespace std;

////adjacency list
////undirected unweighted graph
//int main()
//{
//	int vertex, edges;
//	cout << "Enter the number of vertex " << endl;
//		cin >> vertex;
//	cout << "Enter the number of edges " << endl;
//	cin >> edges; 
//
//	vector<vector<int>> AdjList(vertex);
//		
//	int u, v;
//
//	for (int i = 0; i < edges; i++)
//	{
//		cout << "Enter which vertex is connected to which" << endl;
//		//u v are adjacent connected vertexs
//		cin >> u >> v;
//		AdjList[u].push_back(v);
//		AdjList[v].push_back(u);
//		
//	
//	}
//	for (int i = 0; i < vertex; i++)
//	{
//		cout << i << " -> ";
//		for (int j = 0; j < AdjList[i].size(); j++)
//		{
//			cout << AdjList[i][j] << " ";
//
//		}
//		cout << endl;
//	}
//	return 0;

////adjacency list
////undirected weighted graph
//int main()
//{
//	int vertex, edges;
//	cout << "Enter the number of vertex " << endl;
//	cin >> vertex;
//	cout << "Enter the number of edges " << endl;
//	cin >> edges;
//
//	vector<vector<pair<int,int>>>AdjList(vertex);
//
//	int u, v,weight;
//
//	for (int i = 0; i < edges; i++)
//	{
//		cout << "Enter which vertex is connected to which" << endl;
//		//u v are adjacent connected vertexs
//		cin >> u >> v;
//		cout << "Enter the weight of the edge from"<<u<<" "<<v << endl;
//		cin >> weight;
//		AdjList[u].push_back(make_pair(v,weight));
//		AdjList[v].push_back(make_pair(u, weight));
//
//
//	}
//	for (int i = 0; i < vertex; i++)
//	{
//		cout << i << " -> ";
//		for (int j = 0; j < AdjList[i].size(); j++)
//		{
//			cout << AdjList[i][j].first << " "<< AdjList[i][j].second<<" ";
//
//		}
//		cout << endl;
//	}
//	return 0;

//adjacency list
//directed weighted graph
int main()
{
	int vertex, edges;
	cout << "Enter the number of vertex " << endl;
	cin >> vertex;
	cout << "Enter the number of edges " << endl;
	cin >> edges;

	vector<vector<pair<int, int>>>AdjList(vertex);

	int u, v, weight;

	for (int i = 0; i < edges; i++)
	{
		cout << "Enter which vertex is connected to which" << endl;
		//u v are adjacent connected vertexs
		cin >> u >> v;
		cout << "Enter the weight of the edge from" << u << " " << v << endl;
		cin >> weight;
		AdjList[u].push_back(make_pair(v, weight));


	}
	for (int i = 0; i < vertex; i++)
	{
		cout << i << " -> ";
		for (int j = 0; j < AdjList[i].size(); j++)
		{
			cout << AdjList[i][j].first << " " << AdjList[i][j].second << " ";

		}
		cout << endl;
	}
	return 0;



}
