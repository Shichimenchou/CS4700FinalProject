#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

vector<vector<int>> dist;

int checkNeighbors(vector<vector<int>> edges, int n, int m, int k)
{
	int mn = 1000000;
	for(int i = k; i < 10; i++)
	{
		if(i != n && 1 != m)
		{
			if(dist[n][m] > (edges[n][i] + checkNeighbors(edges, n, i, i+1)) || (dist[n][m] > (edges[m][i] + checkNeighbors(edges, m, i, i+1))))
			{
				int val = min(edges[n][i] + checkNeighbors(edges, n, i, i+1), edges[m][i] + checkNeighbors(edges, m, i, i+1));
				if(val < mn)
				{
					mn = val;
				}		
			}
		}
	}
	if(mn != 1000000)
	{
		return mn;
	}
	else
	{
		return edges[n][m];
	}
}

void dijkstra(vector<vector<int>> edges)
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			dist[i][j] = checkNeighbors(edges, i, j, 1);
			dist[j][i] = dist[i][j];
		}
	}	
}

int main()
{
	for(int i = 0; i < 10; i++)
	{
		vector<int> row;
		for(int j = 0; j < 10; j++)
		{
			if(i == j)
			{
				row.push_back(0);
			}
			else
			{
				row.push_back(1000000);
			}
		}
		dist.push_back(row);
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
	dijkstra(e);
	time_t end = time(nullptr);

	cout << "The spanning tree was found in " << end - start << " seconds." << endl;

	return 0;
}
