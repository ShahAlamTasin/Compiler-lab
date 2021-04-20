#include <stdio.h>
#include <string.h>
int main()
{
    char keyword[100][10]={"double","int","char","float","long","struct","break","if","else",
        "switch","case","return","continue","for","do","while"} ;
    char str[20];
    printf("Enter name: ");
    scanf("%s", str);
    int flag=0,i;
    for(i = 0; i < 20; i++)
    {
        if(strcmp(str,keyword[i])==0)
        {
            flag=1;
        }
    }
    if(flag==1)
        printf("%s is a keyword",str);
    else
        printf("%s is not a keyword",str);

}

