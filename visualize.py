import pylab
import numpy as np
with open("stats.txt", "r") as fd:
	y = eval(fd.read())
x = np.arange(0, 1.05, 0.05)
pylab.plot(x, y, "r.")
pylab.show()
