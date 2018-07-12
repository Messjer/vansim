import pylab
import numpy as np
s = raw_input()
with open(s, "r") as fd:
	y = eval(fd.read())

x = np.linspace(0, 1, num = len(y))
pylab.plot(x, y, "r.")
pylab.show()
