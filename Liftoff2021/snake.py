# Import standard libraries here
import random

class SnakeAI:
	"""
	This class will contain the logic of your snake AI. The code is a minimum working example of a SnakeAI
	that randomly moves around.

	GAME DESCRIPTION:
	Snake is a game where you will be facing 7 other players in a 25x25 grid. The objective of the game is to grow as
	long as possible within a certain number of turns without dying.

	Each player controls a "snake" (a line of blocks with a head in front) of initial length 2 and facing up. Every
	turn, each snake will move in one of four directions (Up, down, left, and right). When snakes move, their head first
	moves to a location, followed by the rest of their body.

	Food will be scattered at random locations on the grid. If a snake eats the food by moving its head over the food's
	location, it will grow in length such that next turn, the tail of the snake will remain in the same location.

	If a snake's head collides with its own body, or another snake's body, or goes out of bounds, the snake will die and
	the space occupied by its body will be replaced by food. If two snakes collide head-on, then the smaller snake will
	die, or both will die if they have the same size. If a player dies, their score will remain as their snake's final
	length.

	A match ends if it exceeds a certain number of turns or if all of the snakes die. At the end of a match, players
	will be ranked according to their final length (including dead players). Snakes that live longer are also
	prioritized over snakes that die early.

	ADDITIONAL COMMENTS:
	 - You can debug your AI using print() statements. All standard output will be stored in a file and returned to you
	   once your AI is done running.
	 - You can see the history and results of a match by going to the Round History tab.
	"""

	# DO NOT MODIFY METHOD SIGNATURE
	def __init__(self):
		"""
		Here, you can create variables that persist throughout a match.
		"""
		self.x=0
		self.y=0
		pass

	# DO NOT MODIFY METHOD SIGNATURE
	def poll(self, snakes, food, current_turn, max_turns=400, grid_size=25):
		"""
		Method poll() will be called every turn. It will be given the state of the current match and return the
		direction in which the snake should move. Note that the snake can die from moving "into" its own body if it was
		initially moving in one direction and then immediately goes in the opposite direction.

		:param snakes: A nested list containing lists of tuples representing the locations of the body segments of each
					   snake. The first tuple is the location of the snake's head. The order of the snakes are
					   consistent, and your snake will always be FIRST.
					   Ex. [[(1, 1), (1, 2)], [(4, 5), (4, 6)], ...]
		:param food: A list containing tuples representing the locations of food on the grid.
					 Ex. [(0, 0), (6, 8), (3, 2), ...]
		:param current_turn: An integer representing the current turn number.
		:param max_turns: An integer representing the maximum number of turns a match can have.
		:param grid_size: An integer representing the width and height of the square grid.
		:return: A string (either 'u', 'd', 'l', 'r') representing the direction your snake should move.
		"""
	# move clockwise around border
		if self.x!=24 and self.x!=0 and self.y!=24 and self.y!=0: # not on border
			self.x+=1
			return 'r'
		
		if self.x==24:
			if self.y==0:
				self.x-=1
				return 'l'
			else:
				self.y-=1
				return 'd'
		if self.x==0:
			if self.y==24:
				self.x+=1
				return 'r'
			else:
				self.y+=1
				return 'u'
		if self.y==24:
			if self.x==24:
				self.y-=1
				return 'd'
			else:
				self.x+=1
				return 'r'
		if self.y==0:
			if self.x==0:
				self.y+=1
				return 'u'
			else:
				self.x-=1
				return 'l'
		return random.choice(["u", "d", "l", "r"])

