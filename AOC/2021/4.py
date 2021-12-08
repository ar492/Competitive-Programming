
f = open("input.txt", "r").read()
numbers=[int(i) for i in f.split("\n",1)[0].split(',')]
f=f.split('\n',2)[-1] # get rid of first two lines

boards=[]

while f.count('\n'):
	board = [[int(j) for j in f.splitlines()[i].split("\n")[0].split()] for i in range(5)]
	boards.append(board)
	f=f.split('\n',6)[-1]

index=-1
winning_number=-1
um=0
wins=[]
for x in range(len(boards)):
	wins.append(False)

for i in numbers:
	for z in range(len(boards)):
		b=boards[z]
		s=0
		for j in range(5):
			for k in range(5):
				if(b[j][k]==i):
					b[j][k]=-b[j][k]-1
				if(b[j][k]>=0):
					s+=b[j][k]
		win=False
		for j in range(5):
			good=True
			for k in range(5):
				if(b[j][k]>=0):
					good=False
			if(good):
				win=True
		for j in range(5):
			good=True
			for k in range(5):
				if(b[k][j]>=0):
					good=False
			if(good):
				win=True
		if(win and not wins[z]):
			wins[z]=True
			print(s*i)
			#quit()


