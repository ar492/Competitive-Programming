

def fibCypher(option, num1, num2, key, msg):
	ans=""
	mod=26
	f=[num1%mod, num2%mod]
	for i in range(2, 202):
		f.append((f[i-1]+f[i-2])%mod)
	for i in range(1, len(f), 2):
		f[i]=-f[i]
	if(option=='E'):
		for i in range(len(msg)):
			if(i):
				ans+=" "
			k=ord(key)+f[i]
			if (k < ord('a')):
				k += 26;
			if (k > ord('z')):
				k -= 26;
			ans+=str(k * 3 + ord(msg[i]))
	else:
		nums=[int(i) for i in msg.split()]
		for i in range(len(nums)):
			k=ord(key)+f[i]
			if (k < ord('a')):
				k += 26;
			if (k > ord('z')):
				k -= 26;
			ans+=chr(nums[i]-3*k)
	return ans

print(fibCypher('D', 2, 5, 'j', "396 404 447 472 329 380 381 341 423 411 436 408 474 428 383 405 414 431 332 437 474 485 347 407 453 377 430 459 471 421 401 353 413 446 456 424 392 457 447 441 419 435 413 442 330"))
#print(fibCypher('E', 3, 7, 'h', "ACSL Sr-5 c2"))