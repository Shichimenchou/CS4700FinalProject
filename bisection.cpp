#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double g(double x)
{
	double gx = .5 * x * x + x + 1 - exp(x);
	return gx;
}

double bisection(double a, double b, double tolerance, double ans, int itr)
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
		if(abs(ga - ans) > abs(gb - ans))
		{
			return bisection(t, b, tolerance, ans, itr);
		}
		else
		{
			return bisection(a, t, tolerance, ans, itr);
		}
	}
}

int main()
{
	double a = -1;
	double b = 10;
	double ans = 0;
	int itr = 0;
	double tolerance = 0.001;

	time_t start = time(nullptr);	
	double x = bisection(a, b, tolerance, ans, itr);
	time_t end = time(nullptr);	
	
	cout << "The root was found to be approximately " << x << " in " << itr << " iterations and " << end - start  << " seconds." << endl;

	return 0;
}
