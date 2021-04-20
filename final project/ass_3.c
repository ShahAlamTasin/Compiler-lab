#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int main()

{
    FILE *p1, *p2;
    char ch0, ch1, ch2, ch3;
    int flag = 0;
    p1 = fopen("input.c", "r");
    p2 = fopen("output.c", "w");
    if(!p1)
    {

        printf(" File can not be opened.\n");
    }
    else
    {
        while((ch0 = fgetc(p1)) != EOF)

        {
            if(ch0=='#')
            {



                while((ch0 = fgetc( p1 ))!= '<');
                while((ch0= fgetc( p1 ))!= '>');
                ch0=fgetc( p1 );





            }

          else  if(ch0 == '/')
            {
                ch1 = getc(p1);
                if(ch1 == '*')
                {
                    while((ch2 = fgetc(p1)) != '*');
                    if((ch3 = fgetc(p1)) == '/')
                    {

                    }
                    else
                    {
                        fputc(ch3, p2);
                    }
                }
                else if(ch1 == '/')
                {
                    while((ch2 = fgetc(p1)) != '\n');
                }
                else
                {
                    fputc(ch0, p2);
                    fputc(ch1, p2);
                }
            }
            else fputc(ch0, p2);
        }
        fclose(p1);
        fclose(p2);
        p1 = fopen("output2.txt", "w");
        p2 = fopen("output.c", "r");
        while((ch0 = getc(p2)) != EOF)
        {
            if(ch0 == '\n')
            {
                while((ch1 = fgetc(p2)) == '\n');
                fputc(' ', p1);
                fputc(ch1, p1);
            }
            else fputc(ch0, p1);
        }
        fclose(p1);
        fclose(p2);
        p1 = fopen("output2.txt", "r");
        while((ch0 = getc(p1)) != EOF)
        {
            if(ch0 == ' ')
            {
                while((ch1 = fgetc(p1)) == ' ');

                printf("%c ",ch1);
            }
            else printf("%c",ch0);

        }
    }

}
