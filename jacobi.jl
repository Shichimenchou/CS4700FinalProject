using Printf

function matrixAdd(A, B)
	AB = []
	for i in 1:length(A)
		ab = []
		for j in 1:length(A[1])
			append!(ab, A[i][j] + B[i][j])
		end
		append!(AB, [ab])
	end
	return AB
end

function vectorSub(a, b)
	ab = []
	for i in 1:length(a)
		append!(ab, a[i] - b[i])
	end
	return ab
end

function matrixVectorMult(A, y)
	b = []
	bi = 0
	for i in 1:length(A)
		bi = 0
		for j in 1:length(A[1])
			bi = bi + (A[i][j] * y[j])
		end
		append!(b, bi)
	end
	return b
end

function jacobi(Dinv, b, L, U, xn)
	LU = matrixAdd(L, U)
	LUx = matrixVectorMult(LU, xn)
	bmLUx = vectorSub(b, LUx)
	return matrixVectorMult(Dinv, bmLUx)
end

b = [3, 9, -6]
x = [10, 100, 1000]
L = [[0, 0, 0], [-2, 0, 0], [-1, 1, 0]]
U = [[0, -1, -1], [0, 0, 1], [0, 0, 0]]
Dinv = [[0.25, 0, 0], [0, 0.1666667, 0], [0, 0, 0.14286]]

tolerance = 0.001

@time while (true)
	err = 0
	xPrev = x
	global x = jacobi(Dinv, b, L, U, x)
	diff = vectorSub(x, xPrev)
	for i in 1:length(diff)
		err = err + abs(diff[i])
	end
	if err < tolerance
		break
	end
end

println(string("The solution to Ax = b was found to be approximately ", x[1], ", ", x[2], ", ", x[3]))
