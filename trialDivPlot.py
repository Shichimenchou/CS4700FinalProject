from pylab import *

t = arange(40, 61)
cpp = [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 2, 2, 2, 4, 5, 7, 11, 14]
julia = [0.064, 0.088, 0.13, 0.18, 0.26, 0.38, 0.53, 0.75, 1.07, 1.51, 2.14, 3.04, 4.36, 6.16, 8.72, 12.45, 17.72, 25.10, 36.21, 52.43, 71.66]
python = [0.11, 0.17, 0.22, 0.30, 0.43, 0.62, 0.86, 1.22, 1.72, 2.46, 3.46, 4.91, 6.97, 9.80, 13.77, 19.51, 27.48, 38.69, 54.66, 77.09, 121.43]

print(len(cpp))
print(len(julia))
print(len(python))

plot(t, cpp, label="C++")
plot(t, julia, label="Julia")
plot(t, python, label="Python")

legend()
xlabel("Order (2^x)")
ylabel("Time (s)")
title("Trial Division")
grid(True)
legend()
show()
