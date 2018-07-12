import subprocess
import random
import pylab
T = 100
K = 30
'''p_gas = 1.0 / K
stats_p = []
for k in xrange(K + 1):
	stats_time = []
	print("testing {}".format(k * p_gas))
	for t in xrange(T):
		seed = random.randrange(0, 1 << 32)
		cmd = subprocess.Popen('./vansim 15 20 20 1 1000 20 1.0 {} 1.0 0.1 100 1 {}'.format(k * p_gas, seed), shell=True, stdout=subprocess.PIPE)
		lines = cmd.stdout.readlines()
		if (len(lines) == 1): #encounter error in vansim
			continue
	
		N_gos = int(lines[1].split()[-1])
		N_norm = int(lines[3].split()[-1])
		t_gos = float(lines[2].split()[-1])
		t_norm = float(lines[4].split()[-1])
		impr = (t_norm - t_gos)/t_norm 
		stats_time.append(impr)
		#print("{0:.4f} vs {1:.4f}".format(t_gos, t_norm))
		#print("Gossiping is {0:.4f} better".format(impr))
	stats_p.append(sum(stats_time) / len(stats_time))'''

r = 0.5 / K
stats_p = []
for k in xrange(K + 1):
	stats_time = []
	print("testing {}".format(k * r))
	for t in xrange(T):
		seed = random.randrange(0, 1 << 32)
		cmd = subprocess.Popen('./vansim 15 20 20 1 1000 2 1 0 1 {} 100 1 {}'.format(k * r, seed), shell=True, stdout=subprocess.PIPE)
		lines = cmd.stdout.readlines()
		if (len(lines) == 1): #encounter error in vansim
			continue
	
		N_gos = int(lines[1].split()[-1])
		N_norm = int(lines[3].split()[-1])
		t_gos = float(lines[2].split()[-1])
		t_norm = float(lines[4].split()[-1])
		impr = (t_norm - t_gos)/t_norm 
		stats_time.append(impr)
		#print("{0:.4f} vs {1:.4f}".format(t_gos, t_norm))
		#print("Gossiping is {0:.4f} better".format(impr))
	stats_p.append(sum(stats_time) / len(stats_time))

with open("rho_NumA2_2.txt", "w") as fd:
	fd.write(str(stats_p))
