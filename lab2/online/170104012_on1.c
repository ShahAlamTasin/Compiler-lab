

#include<stdio.h>


int count = 0;

int main()

{

    FILE *fp1, *fp2;
    char c, c1, c2, c3;

    fp1 = fopen("on1_input.c", "r");

    if(!fp1)
    {
       printf("file not found");
    }
    else
    {
        while((c = fgetc(fp1)) != EOF)
        {

            c1 =fgetc(fp1);
            c2 =  fgetc(fp1);

            c3 =  fgetc(fp1);

            if(c == 'p'&& c1 == 'r'&&c2 == 'i' && c3 == 'n')
            {
                while((c1 = fgetc(fp1)) != ')');
                if((c1 = fgetc(fp1)) == '%')
                {
                    if((c1 = fgetc(fp1)) == 'f')
                    {
                        count++;
                    }

                }

            }
        }


    }

}
