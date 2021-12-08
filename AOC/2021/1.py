with open('input.txt') as f:
	lines = f.readlines()
	
nums=[]
for line in lines:
	nums.append(int(line))

nums2=[]
prev=1e1000
ans=0
for i in range(len(nums)):
	s=0
	for j in range(0, 3):
		if i+j<len(nums):
			s+=nums[i+j]
	ans+=(s>prev)
	prev=s
print(ans)
