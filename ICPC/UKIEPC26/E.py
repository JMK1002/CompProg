a, b, c = map(float, input().split())

amount = max(a, b, c / 10 * 3)

print(amount - a, amount - b, amount * 10 / 3 - c)
