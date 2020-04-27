import time
import math
import decimal

def g(x):
    gx = decimal.Decimal(x) ** decimal.Decimal(6) - decimal.Decimal(1);
    return gx;

def bisection(a, b, tolerance, ans):
    ga = g(a)
    gb = g(b)
    t = (decimal.Decimal(a) + decimal.Decimal(b)) / 2
    print(str(t))
    if abs(t - ans) < tolerance:
        return t
    else:
        if abs(ans - a) < abs(ans - b):
            return bisection(a, t, tolerance, ans)
        else:
            return bisection(t, b, tolerance, ans)

a = decimal.Decimal(-1000001)
b = decimal.Decimal(10000000)
ans = decimal.Decimal(1)
tolerance = decimal.Decimal(0.000001)

start = time.time()
x = bisection(a, b, tolerance, ans)
end = time.time()

print("The root was found to be approximately ", str(x), " in ", str(end - start), " seconds.")

