#include<iostream>
#include<vector>
using namespace std;

//adjacency matrix
//undirected unweighted graph
int main()
{
	//int vertex, edges;
	//cout << "Enter the number of vertices" << endl;
	//cin >> vertex;
	//cout << endl;
	//cout << "Enter the number of edges" << endl;
	//cin >> edges;

	//vector<vector<bool>>AdjMat(vertex, vector<bool>(vertex, 0));

	//int u, v;

	//cout << "Enter which vertex is connected to which" << endl;
	//for (int i = 0; i < edges; i++)
	//{
	//	//u v are adjacent connected vertexs
	//	cin >> u >> v;
	//	AdjMat[u][v] = 1; //agar edge howa to 1 kardo
	//	AdjMat[v][u] = 1;
	//}

	//	for (int i = 0; i < vertex; i++)
	//	{
	//		for (int j = 0;	j < vertex; j++)
	//		{
	//			cout << AdjMat[i][j] << " ";
	//			
	//		}
	//		cout << endl;
	//	}
	//	return 0;

//	//Undirected weighted graph
//	int vertex, edges;
//	cout << "Enter the number of vertices" << endl;
//	cin >> vertex;
//	cout << endl;
//	cout << "Enter the number of edges" << endl;
//	cin >> edges;
//
//	vector<vector<int>>AdjMat(vertex, vector<int>(vertex, 0));
//
//	int u, v,weight;
//
//	
//	for (int i = 0; i < edges; i++)
//	{
//		cout << "Enter which vertex is connected to which" << endl;
//		//u v are adjacent connected vertexs
//		cin >> u >> v;
//		cout << "Enter the weight between " << u << " " << v << endl;
//		cin >> weight;
//		AdjMat[u][v] = weight; //agar edge howa to 1 kardo
//		AdjMat[v][u] = weight;
//	}
//
//	for (int i = 0; i < vertex; i++)
//	{
//		for (int j = 0; j < vertex; j++)
//		{
//			cout << AdjMat[i][j] << " ";
//
//		}
//		cout << endl;
//	}
//	return 0;
//	
//}

	////Directed unweighted graph
	//int vertex, edges;
	//cout << "Enter the number of vertices" << endl;
	//cin >> vertex;
	//cout << endl;
	//cout << "Enter the number of edges" << endl;
	//cin >> edges;

	//vector<vector<bool>>AdjMat(vertex, vector<bool>(vertex, 0));

	//int u, v;

	//for (int i = 0; i < edges; i++)
	//{
	//	cout << "Enter which vertex is connected to which" << endl;
	//	//u v are adjacent connected vertexs
	//	cin >> u >> v;
	//	AdjMat[u][v] = 1;//agar edge howa to 1 kardo
	//}

	//for (int i = 0; i < vertex; i++)
	//{
	//	for (int j = 0; j < vertex; j++)
	//	{
	//		cout << AdjMat[i][j] << " ";

	//	}
	//	cout << endl;
	//}
	//return 0;

	//Directed weighted graph
	int vertex, edges;
	cout << "Enter the number of vertices" << endl;
	cin >> vertex;
	cout << endl;
	cout << "Enter the number of edges" << endl;
	cin >> edges;

	vector<vector<int>>AdjMat(vertex, vector<int>(vertex, 0));

	int u, v,weight;

	for (int i = 0; i < edges; i++)
	{
		cout << "Enter which vertex is connected to which" << endl;
		//u v are adjacent connected vertexs
		cin >> u >> v;
		cout << "Enter the weight between " << u << " " << v << endl;
		cin >> weight;
		AdjMat[u][v] = weight;//agar edge howa to 1 kardo
	}

	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex; j++)
		{
			cout << AdjMat[i][j] << " ";

		}
		cout << endl;
	}
	return 0;

}
