/*Question:Find all elements in array which have at-least two greater elements.
Given an array of n distinct elements, the task is to find all elements in array which have at-least two greater element than themselves.
*/

#include<stdio.h>
#include<stdlib.h>

void fun(int arr[],int n)
{
int i,max1=0,max2=0;
if(n<3)//base case
{
return;
}
for(i=0;i<n;i++)
{
    if(max1<arr[i])
    {
    max1=arr[i];
    }
}
for(i=0;i<n;i++)
{
    if(max2<arr[i]&&arr[i]!=max1)
    {
    max2=arr[i];
    }
}

printf("\nElements that have at least two or more greater elements:\n");
for(i=0;i<n;i++)
{
    if(arr[i]<max2)
    	printf("%d\t",arr[i]);
}
}

int main()
{
int n,arr[]={2,8,7,1,5},brr[]={7,-2,3,4,9,-1};
fun(arr,sizeof(arr)/sizeof(arr[0]));
printf("\n");
fun(brr,sizeof(brr)/sizeof(brr[0]));
return 0;
}
/*Output:
mrunal@mrunal:~/sem3/ppa$ gcc task1.c
mrunal@mrunal:~/sem3/ppa$ ./a.out

Elements that have at least two or more greater elements:
2	1	5	

Elements that have at least two or more greater elements:
-2	3	4	-1	mrunal@mrunal:~/sem3/ppa$ 

*/
