#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<vector<double>> matrixAdd(vector<vector<double>> A, vector<vector<double>> B)
{
	vector<vector<double>> AB;
	for(int i = 0; i < A.size(); i++)
	{
		vector<double> ab;
		for(int j = 0; j < A[0].size(); j++)
		{
			ab.push_back(A[i][j] + B[i][j]);
		}
		AB.push_back(ab);
	}
	return AB;
}

vector<double> vectorSub(vector<double> a, vector<double> b)
{
	vector<double> ab;
	for(int i = 0; i < a.size(); i++)
	{
		ab.push_back(a[i] - b[i]);
	}
	return ab;
}

vector<double> matrixVectorMult(vector<vector<double>> A, vector<double> x)
{
	vector<double> b;
	double bi;
	for(int i = 0; i < A.size(); i++)
	{
		bi = 0;
		for(int j = 0; j < A[0].size(); j++)
		{
			bi += A[i][j] * x[j];
		}
		b.push_back(bi);
	}
	return b;
}

vector<double> jacobi(vector<vector<double>> Dinv, vector<double> b, vector<vector<double>> L, vector<vector<double>> U, vector<double> xn)
{
	vector<vector<double>> LU = matrixAdd(L, U);
	vector<double> LUx = matrixVectorMult(LU, xn);
	vector<double> bmLUx = vectorSub(b, LUx);
	vector<double> x = matrixVectorMult(Dinv, bmLUx);
	return x;
}

int main()
{
	vector<double> b = {3, 9, -6};
	vector<double> x = {10, 100, 1000};
	vector<double> xPrev;
	vector<vector<double>> L = {{0, 0, 0}, {-2, 0, 0}, {-1, 1, 0}};
	vector<vector<double>> U = {{0, -1, -1}, {0, 0, 1}, {0, 0, 0}};
	vector<vector<double>> Dinv = {{0.25, 0, 0}, {0, 0.1666667, 0}, {0, 0, 0.14286}};

	double err = 1000000;
	double tolerance = 0.00001;

	time_t start = time(nullptr);
	while(err > tolerance)
	{
		err = 0;
		xPrev = x;
		x = jacobi(Dinv, b, L, U, x);
		vector<double> diff = vectorSub(x, xPrev);
		for(int i = 0; i < diff.size(); i++)
		{
			err += abs(diff[i]);
		}
	}
	time_t end = time(nullptr);

	cout << "The solution to Ax = b was found to be approximately " << x[0] << ", " << x[1] << ", " << x[2] << " in " << end - start << " seconds." << endl;

	return 0;
}
