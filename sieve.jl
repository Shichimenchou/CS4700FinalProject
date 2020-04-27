using Printf

function sieve(x)
	flags = []
	primes = []
	for i in 0:x
		append!(flags, false)
	end
	for num in 2:x
		if !flags[num]
			append!(primes, num)	
			for i in num:num:x
				flags[i] = true
			end
				
		end
	end
	return primes
end

for i in 10:30
	@time sieve(2 ^ i)
end
