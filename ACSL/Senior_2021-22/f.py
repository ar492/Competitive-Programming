
import math
import os
import random
import re
import sys



#
# Complete the 'findTime' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING cstr as parameter.
#


def findTime(cstr):
    # Write your code here
	ans={
		"hr": 00,
		"min": 00,
		"sec": 00
	}
	mp = {
		"R": ["hr"],
		"G": ["min"],
		"B": ["sec"],
		"C": ["sec", "min"],
		"Y": ["min", "hr"],
		"M": ["hr", "sec"],
		"W":[]
	}

	fib=[1, 1, 2, 3, 5]
	for i in range(len(cstr)):
		c=cstr[i]
		for j in mp[c]:
			ans[j]+=fib[i]
	ans["min"]*=5
	ans["sec"]*=5
	ans["min"]+=ans["sec"]//60
	ans["sec"]%=60
	ans["hr"]+=ans["min"]//60
	ans["min"]%=60
	ans["hr"]%=12
	hr=str(ans["hr"])
	mn=str(ans["min"])
	sec=str(ans["sec"])
	if(len(hr)==1): hr="0"+hr
	if(len(mn)==1): mn="0"+mn
	if(len(sec)==1): sec="0"+sec
	return hr+":"+mn+":"+sec


print(findTime("WRBGB")) # 01:15:35
print(findTime("RWGBG")) # 01:35:15
print(findTime("RCMGB")) # 03:20:40