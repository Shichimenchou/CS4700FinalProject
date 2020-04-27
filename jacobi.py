import time
import math

def matrixAdd(A, B):
    AB = []
    for i in range(0, len(A)):
        ab = []
        for j in range(0, len(A[0])):
                ab.append(A[i][j] + B[i][j])
        AB.append(ab)
    return AB

def vectorSub(a, b):
    ab = []
    for i in range(0, len(a)):
        ab.append(a[i] - b[i])
    return ab

def matrixVectorMult(A, x):
    b = []
    bi = 0
    for i in range(0, len(A)):
        bi = 0
        for j in range(0, len(A[0])):
            bi = bi + A[i][j] * x[j]
        b.append(bi)
    return b

def jacobi(Dinv, b, L, U, xn):
    LU = matrixAdd(L, U)
    LUx = matrixVectorMult(LU, xn)
    bmLUx = vectorSub(b, LUx)
    x = matrixVectorMult(Dinv, bmLUx)
    return x

b = [3, 9, -6]
x = [10, 100, 1000]
L = [[0, 0, 0], [-2, 0, 0], [-1, 1, 0]]
U = [[0, -1, -1], [0, 0, 1], [0, 0, 0]]
Dinv = [[0.25, 0, 0], [0, 0.1666667, 0], [0, 0, 0.14286]]

err = 1000000
tolerance = 0.00001

start = time.time()
while err > tolerance:
    err = 0;
    xPrev = x;
    x = jacobi(Dinv, b, L, U, x);
    diff = vectorSub(x, xPrev)
    for i in range(0, len(diff)):
        err = err + abs(diff[i])
end = time.time()

print("The solution to Ax = b was found to be approximately ", str(x[0]), ", ", str(x[1]), ", ", str(x[2]), " in ", str(end - start), " seconds.")


