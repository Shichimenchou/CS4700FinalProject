#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<vector<bool>> connections;
vector<vector<bool>> tree;
int mn = 1000000;
int mnX = 1;
int mnY = 1;


void updateConnections(int n, int m, int k)
{
	for(int i = k; i < 10; i++)
	{
		if(connections[i][n])
		{
			connections[i][m] = true;
			connections[m][i] = true;
		}
		if(connections[i][m])
		{
			connections[i][n] = true;
			connections[n][i] = true;
		}
	}
	return;
}

void kruskal(vector<vector<int>> edges)
{
	while(true)
	{
		mn = 1000000;
		for(int i = 0; i < 10; i++)
		{
			for(int j = i+1; j < 10; j++)
			{
				if (edges[i][j] < mn && !connections[i][j])
				{
					mn = edges[i][j];
					mnX = i;
					mnY = j;
				}
			}
		}
		edges[mnX][mnY] = 1000000;
		edges[mnY][mnX] = 1000000;
		connections[mnX][mnY] = true;
		connections[mnY][mnX] = true;
		updateConnections(mnX, mnY, 0);

		bool flag = true;
		for(int k = 0; k < 10; k++)
		{
			flag = flag && connections[0][k];
		}
		if(flag)
		{
			break;
		}
	}
	return;
}

int main()
{
	for(int i = 0; i < 10; i++)
	{
		vector<bool> row;
		vector<bool> rowTree;
		for(int j = 0; j < 10; j++)
		{
			if(i == j)
			{
				row.push_back(true);
				rowTree.push_back(true);
			}
			else
			{
				row.push_back(false);
				rowTree.push_back(false);
			}
		}
		connections.push_back(row);
		tree.push_back(rowTree);
	}

	vector<vector<int>> e = {{0, 26, 48, 61, 15, 59, 84, 43, 51, 61},
		{26, 0, 24, 20, 71, 89, 5, 43, 7, 94}, 
		{48, 24, 0, 37, 37, 39, 18, 55, 99, 23}, 
		{61, 20, 37, 0, 4, 66, 3, 86, 64, 68}, 
		{15, 71, 37, 4, 0, 15, 45, 62, 58, 36}, 
		{59, 89, 39, 66, 15, 0, 8, 35, 84, 90}, 
		{84, 5, 18, 3, 45, 8, 0, 13, 92, 8}, 
		{43, 43, 55, 86, 62, 35, 13, 0, 13, 43}, 
		{51, 7, 99, 64, 58, 84, 92, 13, 0, 50}, 
		{61, 94, 23, 68, 36, 90, 8, 43, 50, 0}};

	time_t start = time(nullptr);
	kruskal(e);
	time_t end = time(nullptr);

	cout << "The time to find the minimum spanning tree is: " << end - start << " seconds." << endl; 

	return 0;
}
