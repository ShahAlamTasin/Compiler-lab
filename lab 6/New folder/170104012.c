#include<stdio.h>
#include<string.h>
char str[30];
int len,i=0,f=0;
void X()
{
    if(len-1 == i)
    {
        i++;
        f = 1;
        return;
    }
    else
    {
        if(str[i] == 'b')
        {
            i++;
            if(str[i] == 'b' || str[i] == 'c')
            {
                i++;
                X();

            }
        }
        else
        {
            f = 0;
            return;
        }
    }
}
void A()
{
    if(str[i] == 'a')
    {
        i++;
        X();
        if(f==1)
        {
            if(str[i-1] == 'd')
                f = 1;
            else
                 f = 0;

            return;
        }
    }
}
int main(void)
{
   printf("CFG: \n");
    printf("A -> aXd\nX -> bbX | bcX | epsilon\n");     ///Valid : ad,abbd,abbbbd,abcd,abcbbd ,etc.

   char c[100];
   FILE *fptr,*p2;
   p2 = fopen("output_file.txt","w");
   if ((fptr = fopen("input.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   while(fscanf(fptr,"%s",&str)>0)
   {
        i = 0;
        len = strlen(str);
        if(len>=1)
            {
                A();
            }
        else
            fprintf(p2,"Go find another string %s please!\n",str);
        if(len == i && f == 1)
            fprintf(p2,"Your will %s is valid..\n",str);
         else
            fprintf(p2,"Again you have come to disturb!! your will %s is not valid!\n",str);
   }
   fclose(fptr);
   fclose(p2);
   return 0;
}

