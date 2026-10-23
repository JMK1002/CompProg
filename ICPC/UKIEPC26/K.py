rows, cols = map(int, input().split())

grid = [input() for _ in range(rows)]

alphabet = "abcdefghijklmnopqrstuvwxyz"

row_counts = [{c: 0 for c in alphabet} for _ in range(rows)]
col_counts = [{c: 0 for c in alphabet} for _ in range(cols)]

for r in range(rows):
	for c in range(cols):
		row_counts[r][grid[r][c]] += 1
		col_counts[c][grid[r][c]] += 1

row_nonzero = [len([c for c in row_count.values() if c != 0]) for row_count in row_counts]
col_nonzero = [len([c for c in col_count.values() if c != 0]) for col_count in col_counts]

next_rows = [r for r in range(rows) if row_nonzero[r] == 1]
next_cols = [c for c in range(cols) if col_nonzero[c] == 1]

commands = []

rows_finished = set()
cols_finished = set()

considered_swap_row = {c: False for c in alphabet}
considered_swap_col = {c: False for c in alphabet}

solutions = []


while len(rows_finished) < rows and len(cols_finished) < cols and (len(next_rows) > 0 or len(next_cols) > 0):
	if len(next_rows) > 0:
		row = next_rows.pop()
		char = next(c for c in alphabet if row_counts[row][c] > 0)
		rows_finished.add(row)
		if not considered_swap_row[char]:
			for other_row in range(rows):
				if other_row in rows_finished:
					continue
				if row_nonzero[other_row] > 2:
					break
				if row_nonzero[other_row] == 2 and row_counts[other_row][char] == 0:
					break
			else:
				row_commands = []
				considered_swap_row[char] = True
				relevant_rows = list(set(range(rows)) - rows_finished)
				relevant_cols = list(set(range(cols)) - cols_finished)
				relevant_cols.sort(key=lambda x: col_counts[x][char])
				blocked = set()
				valid = True
				for relevant_col in relevant_cols[::-1]:
					for other_row in blocked:
						if grid[other_row][relevant_col] == char:
							valid = False
					for other_row in relevant_rows:
						if grid[other_row][relevant_col] != char and other_row not in blocked:
							blocked.add(other_row)
							row_commands.append(f"y={other_row + 1} " + grid[other_row][relevant_col])
					row_commands.append(f"x={relevant_col + 1} " + char)

				if valid:
					solutions.append(commands + row_commands)

		commands.append(f"y={row + 1} " + char)
		for col in range(cols):
			col_counts[col][grid[row][col]] -= 1
			if col_counts[col][grid[row][col]] == 0:
				col_nonzero[col] -= 1
				if col_nonzero[col] == 1:
					next_cols.append(col)
	else:
		col = next_cols.pop()
		char = next(c for c in alphabet if col_counts[col][c] > 0)
		cols_finished.add(col)
		if not considered_swap_col[char]:
			for other_col in range(cols):
				if other_col in cols_finished:
					continue
				if col_nonzero[other_col] > 2:
					break
				if col_nonzero[other_col] == 2 and col_counts[other_col][char] == 0:
					break

			else:
				col_commands = []
				considered_swap_col[char] = True
				relevant_rows = list(set(range(rows)) - rows_finished)
				relevant_cols = list(set(range(cols)) - cols_finished)
				relevant_rows.sort(key=lambda x: row_counts[x][char])
				blocked = set()
				valid = True
				for relevant_row in relevant_rows[::-1]:
					for other_col in blocked:
						if grid[relevant_row][other_col] == char:
							valid = False
					for other_col in relevant_cols:
						if grid[relevant_row][other_col] != char and other_col not in blocked:
							blocked.add(other_col)
							col_commands.append(f"x={other_col + 1} " + grid[relevant_row][other_col])
					col_commands.append(f"y={relevant_row + 1} " + char)

				if valid:
					solutions.append(commands + col_commands)

		commands.append(f"x={col + 1} " + char)
		for row in range(rows):
			row_counts[row][grid[row][col]] -= 1
			if row_counts[row][grid[row][col]] == 0:
				row_nonzero[row] -= 1
				if row_nonzero[row] == 1:
					next_rows.append(row)

if len(rows_finished) == rows or len(cols_finished) == cols:
	solutions.append(commands)

if solutions:
	solution = min(solutions, key=lambda x: len(x))
	print(len(solution))
	print("\n".join(solution[::-1]))
else:
	print("impossible")
