import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("muondata9.txt")
pT, eta = data[:, 0], data[:, 1]

plt.figure(figsize=(12,5))

plt.subplot(1,2,1)
plt.hist(pT, bins=50, range=(0, 10), histtype='step', color='blue')
plt.xlabel("transverse momentum (GeV)")
plt.ylabel("counts")
plt.title("Muon pT distribution")

plt.subplot(1,2,2)
plt.hist(eta, bins=50, range=(-5, 5), histtype='step', color='red')
plt.xlabel("pseudo-rapidity (η)")
plt.ylabel("counts")
plt.title("Muon η distribution")

plt.show()
