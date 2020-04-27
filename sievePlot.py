from pylab import *

t = arange(10, 31)
cpp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 4, 9, 20, 41, 83, 173]
julia = [0.000038, 0.000065, 0.00012, 0.00027, 0.00058, 0.0011, 0.0021, 0.0048, 0.0084, 0.018, 0.041, 0.094, 0.21, 0.61, 1.03, 2.05, 4.21, 9.77, 26.62, 76.77, 379.12]
python = [0.00025, 0.00058, 0.0010, 0.0021, 0.0046, 0.009, 0.018, 0.038, 0.076, 0.16, 0.35, 0.76, 1.58, 3.44, 6.90, 14.43, 29.38, 59.28, 121.00, 266.12, 559.05]

print(len(cpp))
print(len(julia))
print(len(python))

plot(t, cpp, label="C++")
plot(t, julia, label="Julia")
plot(t, python, label="Python")

legend()
xlabel("Order (2^x)")
ylabel("Time (s)")
title("Sieve of Eratosthenes")
grid(True)
legend()
show()
