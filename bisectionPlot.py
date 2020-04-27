from pylab import *

cpp = .001 #C++ only returned 0, using .001 to show a tiny bar
julia = .54
python = .013

bar(1, cpp, label="C++")
bar(2, julia, label="Julia")
bar(3, python, label="Python")

legend()
xlabel("Language")
ylabel("Time (s)")
title("Bisection Method: x^6 - 1")
grid(True)
legend()
show()
