/*Given two strings, check if they’re anagrams or not. Two strings are
anagrams if they are written using the same exact letters, ignoring
space, punctuation and capitalization. Each letter should have the same
count in both strings.
For example, ‘Eleven plus two’ and ‘Twelve plus one’ are meaningful
anagrams of each other. */

#include<stdio.h>
#include<string.h>

int main()
{
    char s1[20],s2[20],ch='a';
    int i,count1[26]={0},count2[26]={0},x;
    printf("\nEnter string1:");
    scanf("%[^'\n']s",s1);
    printf("\nEnter string2:");
    scanf(" %[^'\n']s",s2);
    while(s1[i]!='\0') 
       {
           if(s1[i]>='A' && s1[i]<='Z')
           {
               s1[i] = s1[i] + 32;
           }
            if (s1[i]>='a'&&s1[i]<='z')
            {
            x=s1[i]-'a';
            count1[x]++;
            }
            i++;
        }
    i=0;
    while(s2[i]!='\0') 
       {
           if(s2[i]>='A' && s2[i]<='Z')
           {
               s2[i] = s2[i] + 32;
           }
            if (s2[i]>='a'&&s2[i]<='z')
            {
            x = s2[i]-'a';
            count2[x]++;
            }
            i++;
        }
 
 
   for (i=0;i<26;i++)
        {
            if(count1[i]!=count2[i])
                break;
        }
    if(i==26)
    {
        printf("\nStrings are anagram");
    }
    else
    {
        printf("\nStrings are not anagram");
    }
    
return 0;
}

/*Output:
mrunal@mrunal:~/sem3/ppa/test4$ gcc q2.c
mrunal@mrunal:~/sem3/ppa/test4$ ./a.out

Enter string1: myname IS

Enter string2: MYNAME si

Strings are anagram
mrunal@mrunal:~/sem3/ppa/test4$ ./a.out

Enter string1: my name

Enter string2:os

Strings are not anagram
mrunal@mrunal:~/sem3/ppa/test4$ 

 */