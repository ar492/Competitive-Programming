f = open("input.txt", "r").read()
numbers=[int(i) for i in f.split("\n",1)[0].split(',')]
numbers=sorted(numbers)
#m=numbers[len(numbers)//2]
m=sum(numbers)//(len(numbers))
m1=m+1
print("m is ", m)
ans=0
ans1=0
for i in numbers:
	x=(abs(m-i))
	ans+=(x*(x+1))//2
for i in numbers:
	x=(abs(m1-i))
	ans1+=(x*(x+1))//2
print(ans)
print(ans1)