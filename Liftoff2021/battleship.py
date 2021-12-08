# Import standard libraries here
import random

class BattleshipAI:
	"""
	This class will contain the logic of your battleship AI. The code is a minimum working example of a BattleshipAI
	that randomly places its ships and fires its shots. Modify the code to improve the AI!

	GAME DESCRIPTION:
	Classic Battleship is a two-player-game where each player first arranges their ships on a 10-by-10 grid (the ocean),
	then takes turns firing shots at each other. There are 5 ships. Each ship consists of 5, 4, 3, 3, and 2 squares,
	respectively, arranged in a line. The objective of the game is to be the first player to sink the opponent's ships.
	A ship is considered "sunk" if all of its squares have been hit.

	In this variation of battleship, you receive information after each shot about the Manhattan Distance between that
	shot and the nearest square that has a ship. Manhattan distance is calculated as the sum of absolute differences
	between the coordinates of the shot and the square with the ship. If a shot hits a ship, the distance will be
	considered 0. If you sink a ship, you will also receive information about the ship that was sunk.

	ADDITIONAL COMMENTS:
	 - Two helper functions located at the bottom of the file are used to help generate ship placements.
	 - You can debug your AI using print() statements. All standard output will be stored in a file and returned to you
	   once your AI is done running.
	 - You can see the history and results of a match by going to the Round History tab.
	"""

	# DO NOT MODIFY METHOD SIGNATURE
	def __init__(self):
		"""
		Here, you can create variables that persist throughout a match.
		"""
		pass

	# DO NOT MODIFY METHOD SIGNATURE
	def fire_shot(self, my_previous_shots, opponent_previous_shots, grid_size=10):
		"""
		This method is called every turn. It will be given information about previous shots fired by you and your
		opponent and return the location of the next shot to fire.

		:param my_previous_shots: A nested list of tuples containing information about your previous shots. The list
								  is sorted such that the oldest shot is first. Each tuple contains 3 items:
								   - A tuple of integers (r, c) representing the location of the shot.
								   - An integer representing the manhattan distance to the nearest square with part of
									 an enemy ship. If the shot hits a ship, then this will be 0.
								   - A boolean representing whether the shot sunk a ship.
								  Ex. [((3, 3), 2, False), ...]
		:param opponent_previous_shots: The same as my_previous_shots but for shots fired by your opponent.
		:param grid_size: An integer representing the dimensions of the grid.
		:return: A tuple of integers (r, c) representing the location of the shot.
		"""
		pts=[]
		for i in my_previous_shots:
			pts.append(i[0])

		shot=(0, 0)
		my_previous_shots = sorted(my_previous_shots, key=lambda tup: tup[1])
		for i in range(10):
			for j in range(10):
				for pp in my_previous_shots:
					if(pp[2]==True): continue
					if(abs(pp[0][0]-i)+abs(pp[0][1]-j)==pp[1] and (i, j) not in pts):
						shot=(i, j)
						return (i, j)
		#shot = (random.randint(0, grid_size-1), random.randint(0, grid_size-1))
		#sorted_by_second = sorted(my_previous_shots, key=lambda tup: tup[1])

		while shot in [shot_location for shot_location, dist, sunk in my_previous_shots]:
			shot = (random.randint(0, grid_size - 1), random.randint(0, grid_size - 1))

		return shot

	# DO NOT MODIFY METHOD SIGNATURE
	def place_ships(self, grid_size=10, ship_sizes=(2,3,3,4,5)):
		"""
		This method will be called when the game first starts to arrange your ships (in the order defined in
		ship_sizes). Ships cannot intersect or go out of bounds.

		You will be returning an ordered list of tuples (r, c, d) representing the arrangement of the corresponding
		ship in ship_sizes, where r, c represent the row and column of the ship and d represents direction (heading).
		The possible headings are illustrated below:

		X marks the location of the ship (r, c), and the numbers represent the locations of the rest of the ship's body
		(0: north, 1: east, 2: south, 3: west)
				   2
				   2
				   2
			 1 1 1 X 3 3 3
				   0
				   0
				   0
		For example, if the ship has a "north" heading, then the ship would would start at X (r, c) and the rest of the
		ship would fall south of X.

		:param grid_size: An integer representing the size of the square battleship grid.
		:param ship_sizes: A tuple of integers representing the sizes of the ships and the order in which to return the
						   arrangements.
		:return: A list containing tuples representing the arrangement of the corresponding ship at that index.
		"""

		arrangements = []

		for size in ship_sizes:

			while True:
				r, c = random.randint(0, grid_size), random.randint(0, grid_size)
				possible_headings = []
				for d in [0, 1, 2, 3]:
					ship_arrangement = (r, c, d)

					# Check that the ship is in bounds
					if not ship_in_bounds(ship_arrangement, size, grid_size):
						continue

					# Check that the ship doesn't intersect other ships
					intersects = False
					squares = get_squares_occupied(ship_arrangement, size)

					for i, other_arrangement in enumerate(arrangements):
						other_squares = get_squares_occupied(other_arrangement, ship_sizes[i])
						if any(sq in other_squares for sq in squares):
							intersects = True
							break

					if intersects: continue

					possible_headings.append(ship_arrangement)

				if len(possible_headings) > 0:
					random_placement = random.choice(possible_headings)
					arrangements.append(random_placement)
					break

		return arrangements

# Helper functions
def ship_in_bounds(arrangement, ship_len, grid_size):
	"""
	Checks if a arrangement (r, c, d) of a ship of length ship_len is within the bounds of a grid with
	size (grid_size x grid_size).
	:param arrangement: A tuple of integers representing ship's arrangement.
	:param ship_len: An integer representing the ship's length.
	:param grid_size: An integer representing the dimensions of the grid.
	:return: A boolean representing whether the ship is in bounds.
	"""

	squares = get_squares_occupied(arrangement, ship_len)

	for (r, c) in squares:
		if not (0 <= r < grid_size and 0 <= c < grid_size):
			return False

	return True

def get_squares_occupied(arrangement, ship_len):
	"""
	Finds the locations (r, c) of the squares occupied by a ship of length ship_len and arrangement.
	:param arrangement: A tuple of integers representing the ship's arrangement.
	:param ship_len: An integer representing the ship's length
	:return: A list of tuples representing the squares occupied by the ship.
	"""

	r, c, d = arrangement

	if d == 0:
		# Ship faces north
		rr = r + ship_len
		cc = c + 1
	elif d == 1:
		# Ship faces east
		rr = r + 1
		cc = c + 1
		c = cc - ship_len
	elif d == 2:
		# Ship faces south
		rr = r + 1
		r = rr - ship_len
		cc = c + 1
	else:
		# Ship faces west
		rr = r + 1
		cc = c + ship_len

	squares = []
	for row in range(r, rr):
		for col in range(c, cc):
			squares.append([row, col])

	return squares