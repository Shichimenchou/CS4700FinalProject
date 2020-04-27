#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double g(double x)
{
	double gx = .5 * x * x + x + 1 - exp(x);
	return gx;
}

double gp(double x)
{
	double gpx = x + 1 - x * exp(x);
	return gpx;
}

double newtong(double xn)
{
	double ans = xn - (g(xn)) / (gp(xn));
	return ans;
}

int main()
{
	double x = 100;
	double ans = 0;
	int itr = 0;
	double tolerance = 0.001;

	time_t start = time(nullptr);
	while(abs(x - ans) > tolerance)
	{
		x = newtong(x);
		itr++;	
	}
	time_t end = time(nullptr);	

	cout << "The root was found to be approximately " << x << " in " << itr << " iterations and " << end - start << " seconds." << endl;

	return 0;
}
