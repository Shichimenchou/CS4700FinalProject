using Printf

global itr = 0

function g(x)
	gx::BigFloat = x * x * x * x * x * x - 1
	return gx
end

function bisection(a, b, tolerance, ans)
	ga::BigFloat = g(a)
	gb::BigFloat = g(b)
	t::BigFloat = (a + b) / 2
	global itr = itr + 1
	println(string(itr, ": ", t))
	if abs(t - ans) < tolerance
		return t
	else
		if abs(ans - a) < abs(ans - b)
			return bisection(a, t, tolerance, ans)
		else
			return bisection(t, b, tolerance, ans)
		end
	end
end

a = -1000001
b = 10000000
ans = 1
tolerance = 0.000001

@time x = bisection(a, b, tolerance, ans)

println(string("The root was found to be approximately ", x, " in ", itr, " iterations."))
