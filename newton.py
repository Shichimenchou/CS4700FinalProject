import time
import math
import decimal

def g(x):
    gx = decimal.Decimal(.5) * decimal.Decimal(x) * decimal.Decimal(x) + decimal.Decimal(x) + decimal.Decimal(1) - decimal.Decimal(math.e) ** decimal.Decimal(x)
    return gx

def gp(x):
    gpx = decimal.Decimal(x) + decimal.Decimal(1) - decimal.Decimal(x) * decimal.Decimal(math.e) ** decimal.Decimal(x)
    return gpx

def newtong(xn):
    return decimal.Decimal(xn) - (decimal.Decimal(g(decimal.Decimal(xn)))) / (decimal.Decimal(gp(decimal.Decimal(xn))))

x = decimal.Decimal(100.0)
ans = decimal.Decimal(0)
itr = 0
tolerance = decimal.Decimal(0.001)

start = time.time()
while(abs(decimal.Decimal(x) - decimal.Decimal(ans)) > decimal.Decimal(tolerance)):
    x = decimal.Decimal(newtong(decimal.Decimal(x)))
    itr = itr + 1
end = time.time()

print("The root was found to be approximately " + str(decimal.Decimal(x)) + " in " + str(itr) + " iterations and " + str(end - start) + " seconds.")
