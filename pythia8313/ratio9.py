import numpy as np


data = np.loadtxt("muondata9.txt")
pT, eta = data[:, 0], data[:, 1]

detected_muons = ((pT > 5) & (abs(eta) < 2.5))

num_detected = np.sum(detected_muons)
total_muons = len(pT)
probability = num_detected / total_muons

print(f"probability of detecting a muon in the given system: {probability:.4f}")
