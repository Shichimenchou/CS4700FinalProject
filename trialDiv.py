import time
from math import sqrt, floor

def factor(x):
    factors = []
    for i in range(2, floor(sqrt(x))):
        if x % i == 0:
            #print(str(x) + " / " + str(i) + " = " + str(x / i))
            factors.append(i)
            factors.append(x / i)
    return factors

for i in range(40, 61):
    start = time.time()
    factor(2 ** i)
    end = time.time()
    print("Time to factor 2^" + str(i) + " was: " + str(end - start))

