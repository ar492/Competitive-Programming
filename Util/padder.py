import sys
import regex as re

assert(len(sys.argv)>1)
filename=sys.argv[1]
print(sys.argv)
file = open(filename, 'r')
lines = file.readlines()

with open(filename, "w") as f:
	f.truncate()
	for i in range(len(lines)):
		if not "#" in lines[i]:
			lines[i]=re.sub(r"([^\+\-*\/=:\?><\|!\^&%\s]+)(\s*)([\+\-*\/=:\?><\|!\^&%]+)(\s*)(?=([^\+\-*\/=:\?><\|!\^&%\s]+))", "\\1 \\3 ", lines[i])
		f.write(lines[i])

# python "C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\padder.py" "C:\Users\gbpol\Desktop\Useful\Competitive-Programming\Util\testing.txt"