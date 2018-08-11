import math

test = int(input())

for t in range(1, test + 1):
	area = float(input())
	area = 1.0 / area
	angle = math.acos(area) * 180.0 / 3.14159265
	print area, angle