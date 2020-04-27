#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double g(double x)
{
	double gx = pow(x, 6) - 1;
	return gx;
}

double bisection(double a, double b, double tolerance, double ans, int& itr)
{
	double ga = g(a);
	double gb = g(b);
	double t = (a + b) / 2;
	itr++;
	cout << itr << ": " << t << endl;
	if(abs(t - ans) < tolerance)
	{
		return t;
	}
	else
	{
		if(abs(ans - a) < abs(ans - b))
		{
			return bisection(a, t, tolerance, ans, itr);
		}
		else
		{
			return bisection(t, b, tolerance, ans, itr);
		}
	}
}

int main()
{
	double a = -1000001;
	double b = 10000000;
	double ans = 1;
	int itr = 0;
	double tolerance = 0.000001;

	time_t start = time(nullptr);	
	double x = bisection(a, b, tolerance, ans, itr);
	time_t end = time(nullptr);	
	
	cout << "The root was found to be approximately " << x << " in " << itr << " iterations and " << end - start  << " seconds." << endl;

	return 0;
}
