#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

vector<long long> sieve(long long x)
{
	vector<long long> primes;
	vector<bool> flags;
	flags.reserve(x);
	for(int i = 0; i < x; i++)
	{
		flags.push_back(false);
	}
	for(int num = 2; num < x; num++)
	{
		if(!flags[num])
		{
			primes.push_back(num);
			for(int i = num; i < x; i += num)
			{
				flags[i] = true;
			}
		}
	}
	return primes;
}

int main()
{
	for(int i = 10; i <= 30; i++)
	{
		time_t start = time(nullptr);
		sieve(pow(2, i));	
		time_t end = time(nullptr);
		cout << "Time to factor 10^" << i << " was: " << end - start << endl;
	}
	return 0;
}
