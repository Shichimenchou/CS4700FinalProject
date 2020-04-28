from pylab import *

cpp = 4 
julia = 1.376
python = 1.342

bar(1, cpp, label="C++")
bar(2, julia, label="Julia")
bar(3, python, label="Python")

legend()
xlabel("Language")
ylabel("Time (s)")
title("Dijkstra's Algorithm")
grid(True)
legend()
show()
