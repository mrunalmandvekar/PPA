/*Problem statment:
Write a program that prints the numbers from 1 to 100 and for multiples of '3' print "Fizz" instead of
the number and for the multiples of '5' print "Buzz".
*/


#include<stdio.h>
int main()
{
    int i=1;
    while(i<=100)
    {
        if(i%3==0)
        {
            printf("\tFizz");
        }
        if(i%5==0)
        {
            printf(" Buzz");
        }
        else
            printf("\t%d",i);
        i++;
    }
    return 0;
}

/*Output:
mrunal@mrunal:~/sem3/pract/c$ gcc buzz.c
mrunal@mrunal:~/sem3/pract/c$ ./a.out
1	2	Fizz	3	4 Buzz	Fizz	6	7	8	Fizz	9 Buzz	11	Fizz	12	13	14	Fizz Buzz16	17	Fizz	18	19 Buzz	Fizz	21	22	23	Fizz	24 Buzz	26	Fizz	27	28	29	Fizz Buzz	31	32	Fizz	33	34 Buzz	Fizz	36	37	38	Fizz	39 Buzz	41	Fizz	42	43	44	Fizz Buzz	46	47	Fizz	48	49 Buzz	Fizz	51	52	53	Fizz	54 Buzz	56	Fizz	57	58	59	Fizz Buzz	61	62	Fizz	63	64 Buzz	Fizz	66	67	68	Fizz	69 Buzz	71	Fizz	72	73	74	Fizz Buzz	76	77	Fizz	78	79 Buzz	Fizz	81	82	83	Fizz	84 Buzz	86	Fizz	87	88	89	Fizz Buzz	91	92	Fizz	93	94 Buzz	Fizz	96	97	98	Fizz	99 Buzz
mrunal@mrunal:~/sem3/pract/c$ */
