
# Complexity
# BS: O(log(n))
# BA: O(log(log(n/m)))

# Binary Search
def sqrt_BS(n):
	if n <= 1:
		return n
	l = 1
	r = n
	while l <= n:
		mid = (l+r)//2
		check = mid*mid
		if check == n:
			return mid
		elif check > n:
			r = mid - 1
		else:
			l = mid + 1
	return None

# Babylonian Algorithm Float
def sqrt_BA(n):
	if n < 0:
		return None
	elif n <= 1:
		return n
	g = n/2.0
	pg= g+1
	while g < pg:
		pg = g
		g = (g + (n/g))/2.0
	return g

# Babylonian Algorithm Int
def isqrt_BA(n):
	if n <= 1:
		return n
	g = n//2
	p = g+1
	while g < p:
		p = g
		g = (g + (n//g))//2
	return g

def is_square(n):
	check = isqrt_BA(n)
	if check*check != n:
		return False
	return True

# Use when the gaps between p and q is smaller sqrt(max(p, q)), even quicker if they share haft of their leading bit
def fermatFactorRSA(n):
	if n <= 0:
		return None, None
	elif n%2 == 0:
		return 2, n//2
	a = isqrt_BA(n)
	while not is_square(a*a - n):
		a += 1
	b = isqrt_BA(a*a - n)
	return ((a-b), (a+b))

def gcd(a, b):
	while a != 0:
		a, b = b%a, a
	return b