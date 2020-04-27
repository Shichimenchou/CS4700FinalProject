from pylab import *

cpp = 1
julia = 56.73
python = 896.42

bar(1, cpp, label="C++")
bar(2, julia, label="Julia")
bar(3, python, label="Python")

legend()
xlabel("Language")
ylabel("Time (s)")
title("Newton's Method: (1/2)x^2 + x + 1 - e^x")
grid(True)
legend()
show()
