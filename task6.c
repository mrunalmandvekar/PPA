/*Problem statement:
Given a string, deduce a mathematical formula to check if the string is palindrom or not. Implement
the function for the same.
Dont use reverse function.
 */
#include<stdio.h> 
#define true 1
#define false 0
int isPalindrome(int n) 
{  
	int div = 1; 
	while (n / div >= 10) 
		div *= 10; 

	while (n != 0) 
	{ 
		int start = n / div; 
		int end = n % 10; 
		if (start != end) 
			return false; 
		n = (n % div) / 10; 
		div = div / 100; 
	} 
	return true; 
} 
 
int main() 
{ 
    int n;
    printf("\nEnter number to check:");
    scanf("%d",&n);
    if(isPalindrome(n))
        printf("Palindrome");
        else
        printf("Not Palindrome");
	return 0; 
} 
/*Output:
mrunal@mrunal:~/sem3/pract/c$ gcc palin.c
mrunal@mrunal:~/sem3/pract/c$ ./a.out

Enter number to check:121
Palindromemrunal@mrunal:~/sem3/pract/c$ ./a.out

Enter number to check:1
Palindromemrunal@mrunal:~/sem3/pract/c$ ./a.out

Enter number to check:1001
Palindromemrunal@mrunal:~/sem3/pract/c$ ./a.out

Enter number to check:123435
Not Palindromemrunal@mrunal:~/sem3/pract/c$ 
 */