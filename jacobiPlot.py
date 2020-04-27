from pylab import *

cpp = .0001 #C++ only returned 0, using .0001 so the bar is visible
julia = .25
python = .00027

bar(1, cpp, label="C++")
bar(2, julia, label="Julia")
bar(3, python, label="Python")

legend()
xlabel("Language")
ylabel("Time (s)")
title("Jacobi Iteration")
grid(True)
legend()
show()
