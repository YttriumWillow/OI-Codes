import sympy as s

base = (s.sqrt(5) + 1) / 2
x = 1
y = 1

for i in range(10):
	x = s.simplify(x * base)
	print('A' + str(i + 1), "=", x)
	# print('A' + str(i + 1), "= (" , x * 2, ") / 2")

# A1 = 1/2 + sqrt(5)/2
# A2 = sqrt(5)/2 + 3/2
# A3 = 2 + sqrt(5)
# A4 = 3*sqrt(5)/2 + 7/2
# A5 = 11/2 + 5*sqrt(5)/2
# A6 = 4*sqrt(5) + 9
# A7 = 29/2 + 13*sqrt(5)/2
# A8 = 21*sqrt(5)/2 + 47/2
# A9 = 38 + 17*sqrt(5)
# A10 = 55*sqrt(5)/2 + 123/2



 # A1 : (   1 +  1*sqrt(5) ) / 2
 # A2 : (   3 +  1*sqrt(5) ) / 2
 # A3 : (   4 +  2*sqrt(5) ) / 2
 # A4 : (   7 +  3*sqrt(5) ) / 2
 # A5 : (  11 +  5*sqrt(5) ) / 2
 # A6 : (  18 +  8*sqrt(5) ) / 2
 # A7 : (  29 + 13*sqrt(5) ) / 2
 # A8 : (  47 + 21*sqrt(5) ) / 2
 # A9 : (  76 + 34*sqrt(5) ) / 2
# A10 : ( 123 + 55*sqrt(5) ) / 2
