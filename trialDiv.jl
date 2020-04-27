using Printf

function factor(x)
	a = []
	for i in 2:floor(sqrt(x))
		if x % i == 0
			#output::String = string(x) + " / " + string(i) + " = " + string(x / i)
			#println(string(x, " / ", i, " = ", x / i))
			append!(a, i)
			append!(a, x / i)
		end
	end
end

for i in 40:60
	@time factor(2 ^ i)
end
