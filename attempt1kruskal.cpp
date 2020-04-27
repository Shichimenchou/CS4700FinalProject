#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void kruskal(int vert, vector<vector<double>> dist, vector<vector<bool>>& edge, vector<vector<bool>> frst)
{
	bool done = false;

	while(!done)
	{
		done = true;
		double minDist = pow(10, 6);
		int minX = 0;
		int minY = 0;
		for(int i = 0; i < vert; i++)
		{
			for(int j = i + 1; j < vert; j++)
			{
				if(dist[i][j] < minDist)
				{
					minDist = dist[i][j];
					minX = i;
					minY = j;
				}
			}
		}

		if(!frst[minX][minY])
		{
			edge[minX][minY] = true;
			edge[minY][minX] = true;
			for(int i = 0; i < vert; i++)
			{
				if(frst[minX][i] && minX != i)
				{
					frst[minY][i] = true;
					frst[i][minY] = true;
					for(int j = 0; j < vert; j++)
					{

					}
				}
				if(frst[minY][i] && minY != i)
				{
					frst[minX][i] = true;
					frst[i][minX] = true;
				}
				frst[minX][minY] = true;
				frst[minY][minX] = true;
			}
			dist[minX][minY] = pow(10, 6);
			dist[minY][minX] = pow(10, 6);
		}
		else
		{
			dist[minX][minY] = pow(10, 6);
			dist[minY][minX] = pow(10, 6);
		}

		for(int i = 0; i < vert; i++)
		{
			done = done && frst[0][i];
		}
	}

	for(int i = 0; i < vert; i++)
	{
		for(int j = 0; j < vert; j++)
		{
			cout << edge[i][j];
		}
		cout << endl;
	}
	return;
}

int main()
{
	int numVertices = 10;
	vector<int> xCoords = {6, 32, 72, 100, 50, 77, 76, 74, 12, 16};
	vector<int> yCoords = {67, 63, 3, 76, 75, 65, 20, 90, 25, 21};
	//xCoords.reserve(numVertices);
	//yCoords.reserve(numVertices);
	
	//int last = 0;
	//for(int i = 0; i < numVertices; i++)
	//{
	//	xCoords.push_back(numVertices - i);
	//	yCoords.push_back(i + last);
	//	last = i;
	//}

	vector<vector<double>> distances;
	vector<vector<bool>> edges;
	vector<vector<bool>> forest;
	distances.reserve(numVertices);
	edges.reserve(numVertices);
	for(int i = 0; i < numVertices; i++)
	{
		vector<double> v;
		vector<bool> vv;
		vector<bool> vvv;
		for(int j = 0; j < numVertices; j++)
		{
			v.push_back(0);
			vv.push_back(false);
			if(i == j)
			{
				vvv.push_back(true);
			}
			else
			{
				vvv.push_back(false);
			}
		}
		distances.push_back(v);
		edges.push_back(vv);
		forest.push_back(vvv);
	}
	for(int i = 0; i < numVertices; i++)
	{
		for(int j = 0; j < numVertices; j++)
		{
			distances[i][j] = sqrt(pow((xCoords[i] - xCoords[j]), 2) + pow((yCoords[i] - yCoords[j]), 2));
			distances[j][i] = sqrt(pow((xCoords[i] - xCoords[j]), 2) + pow((yCoords[i] - yCoords[j]), 2));
		}
	}

	kruskal(numVertices, distances, edges, forest);
	
	return 0;
}
