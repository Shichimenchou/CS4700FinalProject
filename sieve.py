import time
from math import sqrt, floor

def sieve(x):
    primes = []
    flags = []
    for i in range(x+1):
        flags.append(False)
    for num in range(2, x+1):
        if not flags[num]:
            primes.append(num)
            i = num
            while i <= x:
                flags[i] = True
                i = i + num
    return primes

for i in range(10, 31):
    start = time.time()
    sieve(2 ** i)
    end = time.time()
    print("Time to find primes to 10^" + str(i) + " was: " + str(end - start))

