
s = input()

x = len([c for c in s if c != "(" and c != ")"])

if x % 3 != 0:
	print("impossible")
	exit()

target = x // 3

opens = []
sizes = [0]

one_third = []
two_thirds = []

available = True

for i, c in enumerate(s):
	if c == "(":
		opens.append(i)
		sizes.append(0)
	elif c == ")":
		size = sizes[-1]
		if size == target and available:
			one_third.append((opens[-1], i))
			available = False
		elif size == target * 2:
			two_thirds.append((opens[-1], i))
		opens.pop()
		sizes.pop()
		sizes[-1] += size
	else:
		sizes[-1] += 1
		available = True

if len(one_third) == 0:
	print("impossible")
	exit()

if len(one_third) >= 2:
	a, b = one_third[0]
	c, d = one_third[1]
	print(s[:a] + "[1]" + s[b + 1:c] + "[2]" + s[d + 1:])
	print("[1] " + s[a + 1:b])
	print("[2] " + s[c + 1:d])
	exit()

if len(two_thirds) == 0:
	print("impossible")
	exit()

a, d = two_thirds[0]
b, c = one_third[0]
if a > b or d < c:
	print("impossible")
	exit()


print(s[:a] + "[1]" + s[d + 1:])
print("[1] " + s[a + 1:b] + "[2]" + s[c + 1:d])
print("[2] " + s[b + 1:c])
