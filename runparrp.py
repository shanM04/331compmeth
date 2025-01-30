import subprocess
import os

os.makedirs("output", exist_ok=True)

processes = []
for i in range(1,11):
	with open(f"output/output_{i}.txt", "w") as outfile:
		p=subprocess.Popen(["./hello", str(i)], stdout=outfile)
		processes.append(p)

for p in processes:
	p.wait()

print('jobs completed p')
