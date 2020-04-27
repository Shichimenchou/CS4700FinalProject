using Printf

function g(x)
	gx::BigFloat = .5 * x * x + x + 1 - exp(x)
	return gx
end

function gp(x)
	gpx::BigFloat = x + 1 - x * exp(x)
	return gpx
end

function newton(xn)
	return xn - (g(xn)) / (gp(xn))
end

global x = 100.0
ans = 0
tolerance = 0.001
global itr = 0

@time while abs(x - ans) > tolerance
	global x = newton(x)
	global itr = itr + 1
end

println(typeof(x))
println("The root was found to be approximately ", x::BigFloat, " in  ", itr, " iterations")
println(x)

