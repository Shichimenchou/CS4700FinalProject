from pylab import *

cpp = 0.001 # had to change from 0 to 0.001 so the bar was visible 
julia = 0.08
python = 0.026

bar(1, cpp, label="C++")
bar(2, julia, label="Julia")
bar(3, python, label="Python")

legend()
xlabel("Language")
ylabel("Time (s)")
title("Kruskal's Algorithm")
grid(True)
legend()
show()
