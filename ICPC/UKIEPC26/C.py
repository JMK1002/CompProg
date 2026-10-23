import itertools

s = input()
x, y = s.split("=")[0].split("+")
z = s.split("=")[1]


numbers = {c: 0 for c in "abcde"}

power = 1
for i in range(1000):
	if i < len(x):
		numbers[x[len(x)-i-1]] += power
	if i < len(y):
		numbers[y[len(y)-i-1]] += power
	if i < len(z):
		numbers[z[len(z)-i-1]] -= power
	power *= 10

for a, b, c, d in itertools.permutations(list(range(10)), r=4):
	amount = a * numbers["a"] + b * numbers["b"] + c * numbers["c"] + d * numbers["d"]
	if numbers["e"] == 0:
		if amount == 0:
			e = min([x for x in range(10) if x not in {a, b, c, d}])
			print(str(a) + str(b) + str(c) + str(d) + str(e))
			exit()
	elif amount % numbers["e"] == 0:
		e = (-amount) // numbers["e"]
		if 0 <= e < 10 and e not in {a, b, c, d}:
			print(str(a) + str(b) + str(c) + str(d) + str(e))
			exit()
print("impossible")
