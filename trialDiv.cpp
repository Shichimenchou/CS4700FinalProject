#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

vector<long long> factor(long long x)
{
	vector<long long> v;
	for(long long i = 2; i < sqrt(x); i++)
	{
		if(x % i == 0)
		{
			//cout << x << " / " << i << " = " << x / i << endl;
			v.push_back(i);
			v.push_back(x / i);
		}
	}
	return v;
}

int main()
{
	for(int i = 40; i <= 60; i++)
	{
		time_t start = time(nullptr);
		factor(pow(2, i));	
		time_t end = time(nullptr);
		cout << "Time to factor 2^" << i << " was: " << end - start << endl;
	}
	return 0;
}
