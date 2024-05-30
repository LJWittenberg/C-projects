def gcd(x : int, y : int) -> tuple[int, int]:
	assert(x > 0 and y > 0)

	iterations = 0
	while y:
		iterations += 1
		x, y = y, x % y
	return (x, iterations)
def gcd_iteration_matrix(width : int, height : int) -> list[list[int]]:
	matrix = [[gcd(x+1,y+1)[1] for x in range(12345)] for y in range(20211)]
	return matrix
def write_pgm(filename : str, matrix : list[list[int]]) -> None:
	with open(filename, 'w') as file:
		file.write(f"P2\n")
		file.write(f"# GCD Iteration Matrix\n")
		file.write(f"{len(matrix[0])} {len(matrix)}\n")
		file.write(f"255\n")
		for row in matrix:
			file.write(" ".join(str(value) for value in row))
			file.write("\n")
grid_width = 12345
grid_height = 20211

# Generate the iteration matrix for the grid
iteration_matrix = gcd_iteration_matrix(grid_width, grid_height)
# Write the iteration matrix to a PGM file
output_filename = "gcd_iteration_matrix.pgm"
write_pgm(output_filename, iteration_matrix)
