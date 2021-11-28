

tc = int(input())
for tc in range(1, tc + 1):
	n=int(input())
	s = str(input())
	while True:
		old=s
		for i in range(10):
			s=s.replace(str(i)+str((i+1)%10), str((i+2)%10))
		if old==s:
			break 
	print("Case #" + str(tc) + ": " + s)
