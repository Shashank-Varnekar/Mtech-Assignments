*Platform used:
This program was performed on Linux in gedit text editor and g++ compiler.
Language used - C++

*Input Parameters:
n(integer): size of the array i.e 1000000

Compiler: g++

command to run program
>g++ 1.cpp
>./a.out

Working of program :

arr, new_arr are global vectors


1. Find Duplicates:
	Algorithm:
	
	01. count = 0                                                 ...1
	02. for i = 0 to arr.size()                                   ...n
	03.      if isDuplicate(arr[i], i) == true // function call   ...n*(n-1)
	08.           insert i in new_arr                             ...n
			  //newarr contains location of duplicate   
	09. 	        count++							  ...n
	
	isDuplicate(value, i)
	04.	for j = 0 to i-1                                        ...n-1
	05.		if arr[j] == value					  ...n-1
	06.			return true						  ...1
	07.	return false							  ...1

	Asymptotic Analysis:
	
	T(n) = 1 + n + n*(n-1) + n-1 + n-1 + 1 + 1 + n + n
	     = 1 + n + n*n - n + n + n + n + n
	     = n^2 + 4n + 1
	     <= 2n^2
	
	Therefore, T(n) = O(n^2)

2. Round Duplicates:
	Algorithm:
	
	roundoffDups(new_arr, n)
	01. for i = 0 to n                                          ... n
	02.     value = arr value at loc new_arr[i]                 ... 1
	03.     left = value - 1                                    ... 1
	04.     right = value                                       ... 1
	05.     while(isDuplicate(left, n))                         ... n*(n-1)
	06.          left--						      ... n
	07.	  while(isDuplicate(right, n))                        ... n*(n-1)
	08.          right++                                        ... n
	09. 	  if(left > 0)                                        ... n
	10.     	if(abs(value-left) <= abs(value-right))         ... n
	11. 		    arr[new_arr[i]] = left                      ... n
	12.		else                                            ... n
	13.		    arr[new_arr[i]] = right                     ... n
	14.	  else                                                ... n
	15.	      arr[new_arr[i]] = right                         ... n

	Aysmtotic anylysis
	
	T(n) = n * ( 1 + 1 + 1 + n*(n-1) + n + n*(n-1) + n + 7n)
	     = n * (3 + 2n^2 + 7n)
	     = 2n^3 + 7n^2 +3n
	     <= 4n^3

	Therefore, T(n) = O(n^3)
























