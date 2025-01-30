import re

def ext(filepath):
	format = r'totrecorded\(\/pb\)\s+([\d\.]+)'
	format1 = r'totrecorded(\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\.\d+\s*\|\s*\d+\.\d+\s*\|)'
	format2 = r'totrecorded(\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*[\d.]+\s*\|\s*([\d.]+)\s*\|)'
	format3 = r"\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*[\d\.]+\s*\|\s*([\d\.]+)\s*\|"


	try:
		with open(filepath, 'r') as file:
			content = file.read()
#		print('match check:\n', content[-500:])
#		print('content:\n', content)
		match = re.search(format3, content)

		if match:
			lumpb = float(match.group(1))
			lumfb = lumpb*0.001
			print(f'required luminosity: {lumfb:.1f}/fb')
		else:
			print('haha thought you fixed it?')

	except FileNotFoundError:
		print(f'{filepath} not found')

filepath = 'Exercises/brilcalc.log'
ext(filepath)
