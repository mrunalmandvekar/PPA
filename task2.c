/*Problem statement: Given an array of integers print all alternate prime numbers from the list */
#include<stdio.h>
#include<stdlib.h>
int count=0;
void printPrime(int arr[],int n)
{

    int i,prime[100],num; 
    printf("All prime numbers from list:\n");
    for(int j=0;j<n;j++)
    { 
        num=arr[j];
        for(i=2; i<num; i++)
        {
            if(num%i ==0)
            {
                break;
            }
        }

        if(num==i)
           {
           printf("%d\t",num);
            prime[count]=num;
            count++;
           }
        
    }
    printf("\nAll alternate prime numbers from the list:\n");
    for(i=0;i<count;i++)
    {
    	if(i%2==0)
    	{
        printf("%d\t",prime[i]);
        }

    }

}
int main()
{      
    int arr[100],n,i;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printPrime(arr,n);
    return 0;
}
/*Output:
mrunal@mrunal:~/sem3/ppa$ gcc task2.c
mrunal@mrunal:~/sem3/ppa$ ./a.out
Enter array size:10
Enter array elements:
2
3
4
5
6
7
8
9
10
11
All prime numbers from list:
2	3	5	7	11	
All alternate prime numbers from the list:
2	5	11	mrunal@mrunal:~/sem3/ppa$ 

 */
