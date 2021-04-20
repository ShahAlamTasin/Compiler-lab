#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#include<bits/stdc++.h>
using namespace std;
FILE *file1,*file2;
char ch,ch1,temp,temp1;
int intflag=0,floatflag=0,doubleflag=0,charflag =0,len=0;
char keyword[100];
void funcRemovingExtraSpaceComments()
{
    file1=fopen("input.cpp","r");
    file2=fopen("output1.cpp","w");

    if(!file1)
        cout<<"File can't be opened"<<endl;
    else

        while((ch=fgetc(file1))!=EOF)
        {
            if(ch=='#')
            {



                while((ch = fgetc(file1))!= '<');
                while((ch = fgetc(file1))!= '>');
                ch=fgetc(file1);
                fputc('\n',file2);




            }
            if(ch=='/')
            {
                ch=fgetc(file1);

                if(ch=='/')
                {
                    while(ch!='\n')
                    {
                        ch=fgetc(file1);
                    }
                }

                else if(ch=='*')
                {
                    while((ch=fgetc(file1))!=EOF)
                    {
                        if(ch=='*')
                        {
                            ch=fgetc(file1);
                            if(ch=='/')
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    fputc('/',file2);
                    fputc(ch,file2);
                }
            }
            else if(ch == '\n')
            {
                fputc('\n',file2);
            }
            else if(ch == ' ')
            {
                while(ch ==' ' || ch == '\n' )
                {

                    if(ch == '\n')
                    {
                        fputc('\n',file2);
                        break;
                    }
                    ch = fgetc(file1);

                }
                fputc(' ',file2);
                fputc(ch,file2);
            }
            else
            {
                fputc(ch,file2);
            }

        }

    fclose(file1);
    fclose(file2);



    printf("\n After removing spaces and comment the output is : \n");

    file2=fopen("output1.cpp","r");
    while((ch=fgetc(file2))!=EOF)
    {
        cout<<ch;
    }
    fclose(file2);
}


void funcAddingLineNumber()
{
    int countLine = 1;
    file1 = fopen("output1.cpp","r");
    file2 = fopen("output2.cpp","w");

    if(!file1)

        printf("\n File can't be opened \n");
    else
    {
        fprintf(file2,"%d",countLine);
        while((ch=fgetc(file1))!=EOF)
        {
            if(ch!='\n')
                fputc(ch,file2);
            else
            {
                countLine++;
                fputc(ch,file2);
                fprintf(file2,"%d",countLine);
            }
        }
    }
    fclose(file1);
    fclose(file2);


    printf("\n After second step done with line number the output is : \n");
    file2=fopen("output2.cpp","r");
    while((ch=fgetc(file2))!=EOF)
    {
        cout<<ch;
    }
    fclose(file2);
}

void funcIdToken()
{
    file1=fopen("output2.cpp","r");
    file2=fopen("output3.cpp","w");
    if(!file1)
    {

        printf("\nFile not found : \n");
    }
    else
    {
        while((ch=fgetc(file1))!=EOF)
        {
            //check for float
            if(ch=='f')
            {
                ch=fgetc(file1);
                if(ch=='l')
                {
                    ch=fgetc(file1);
                    if(ch=='o')
                    {
                        ch=fgetc(file1);
                        if(ch=='a')
                        {
                            ch=fgetc(file1);
                            if(ch=='t')
                            {
                                fputs("float",file2);
                                if(floatflag!=1)
                                {
                                    keyword[len++] ='f';
                                    keyword[len++] ='l';
                                    keyword[len++] ='o';
                                    keyword[len++] ='a';
                                    keyword[len++] ='t';
                                    keyword[len++] =' ';
                                    floatflag=1;
                                }
                            }
                            else
                            {
                                fputs("id floa",file2);
                            }
                        }
                        else
                        {
                            fputs("id flo",file2);
                        }
                    }
                    else
                    {
                        fputs("id fl",file2);
                    }
                }
                else if (isdigit(ch))
                {
                    fputs("id ",file2);
                    fputc('f',file2);
                    fputc(ch,file2);
                }
                else
                {
                    fputs("id f",file2);
                }
            }
            //check for int
            else if(ch=='i')
            {
                ch=fgetc(file1);
                if(ch=='n')
                {
                    ch=fgetc(file1);
                    if(ch=='t')
                    {
                        fputs("int",file2);
                        if(intflag!=1)
                        {
                            keyword[len++] ='i';
                            keyword[len++] ='n';
                            keyword[len++] ='t';

                            keyword[len++] =' ';
                            intflag=1;
                        }
                    }
                    else
                    {
                        fputs("id in",file2);
                    }
                }
                //check for if
                else if(ch=='f')
                {
                    fputs("if",file2);
                }
                else
                {
                    fputs("id i",file2);
                }
            }
            //check for char
            else if(ch=='c')
            {
                ch=fgetc(file1);
                if(ch=='h')
                {
                    ch=fgetc(file1);
                    if(ch=='a')
                    {
                        ch=fgetc(file1);
                        if(ch=='r')
                        {
                            fputs("char",file2);
                            if(charflag!=1)
                            {
                                keyword[len++] ='c';
                                keyword[len++] ='h';
                                keyword[len++] ='a';
                                keyword[len++] ='r';
                                keyword[len++] =' ';
                                charflag=1;
                            }

                        }
                        else
                        {
                            fputs("id cha",file2);
                        }
                    }
                    else
                    {
                        fputs("id ch",file2);
                    }
                }
                else
                {
                    fputs("id c",file2);
                }
            }

            //check for else
            else if(ch=='e')
            {
                ch=fgetc(file1);
                if(ch=='l')
                {
                    ch=fgetc(file1);
                    if(ch=='s')
                    {
                        ch=fgetc(file1);
                        if(ch=='e')
                        {
                            fputs("else",file2);
                        }
                        else
                        {
                            fputs("id els",file2);
                        }
                    }
                    else
                    {
                        fputs("id el",file2);
                    }
                }
                else
                {
                    fputs("id e",file2);
                }
            }
            //check for main
            else if (ch=='m')
            {
                ch1 = ch;
                ch=fgetc(file1);
                if(ch=='a')
                {
                    ch=fgetc(file1);
                    ch=fgetc(file1);
                    fputs("id main",file2);
                }
            }
            //check for void
            else if (ch=='v')
            {
                ch1=ch;
                ch=fgetc(file1);
                if(ch=='o')
                {
                    ch=fgetc(file1);
                    ch=fgetc(file1);
                }
                fputs("void",file2);
            }
            //check for return
            else if (ch=='r')
            {
                ch1=ch;
                ch=fgetc(file1);
                if(ch=='e')
                {
                    ch=fgetc(file1);
                    ch=fgetc(file1);
                    ch=fgetc(file1);
                    ch=fgetc(file1);
                    fputs("return",file2);
                }
            }
            //check for double
            else if (ch=='d')
            {
                ch1=ch;
                ch=fgetc(file1);
                if(ch=='o')
                {
                    ch1=ch;
                    ch=fgetc(file1);
                    if(ch=='u')
                    {
                        ch=fgetc(file1);
                        ch=fgetc(file1);
                        ch=fgetc(file1);
                        fputs("double",file2);
                        if(doubleflag!=1)
                        {
                            keyword[len++] ='d';
                            keyword[len++] ='o';
                            keyword[len++] ='u';
                            keyword[len++] ='b';
                            keyword[len++] ='l';
                            keyword[len++] ='e';
                            keyword[len++] =' ';
                            doubleflag=1;
                        }
                    }

                }
            }
            //check for identifier
            else if(isalpha(ch))
            {
                temp=ch;
                ch=fgetc(file1);
                if(isdigit(ch))
                {
                    fputs("id ",file2);
                    fputc(temp,file2);
                    fputc(ch,file2);
                }
                else if(ch=='_')
                {
                    temp1=ch;
                    ch=fgetc(file1);
                    fputs("id ",file2);
                    fputc(temp,file2);
                    fputc(temp1,file2);
                    fputc(ch,file2);
                }
                else
                {
                    fputs("id ",file2);
                    fputc(temp,file2);
                    fputc(ch,file2);
                }
            }
            //else
            else
            {
                fputc(ch,file2);
            }

        }
    }

    fclose(file1);
    fclose(file2);


    printf("\n After third step done the output is: \n");
    file2=fopen("output3.cpp","r");
    while((ch=fgetc(file2))!=EOF)
    {
        cout<<ch;
    }
    fclose(file2);

}

void funcError()
{
    int line1 = 1,line2 = 1,ifCounter = 0,elseCounter = 0,bracOpenCount = 0,bracCloseCount = 0;

    printf("\n After last step done:: \n");
    file1=fopen("output2.cpp","r");
    if(!file1)

        printf("\n File can't be opened \n");
    else
    {
        while((ch=fgetc(file1))!=EOF)
        {
            if(ch=='i')
            {
                ch=fgetc(file1);
                if(ch=='f')
                {
                    ifCounter++;
                }
            }
            else if(ch=='e')
            {
                ch=fgetc(file1);
                if(ch=='l')
                {
                    ch=fgetc(file1);
                    if(ch=='s')
                    {
                        ch=fgetc(file1);
                        if(ch=='e')
                        {
                            if(ifCounter<=0)
                            {
                                printf("Unmatched 'else' at line %d \n",line1);
                            }
                            else
                            {
                                elseCounter++;
                                if(elseCounter>ifCounter)
                                {
                                    printf("Unmatched 'else' at line %d \n",line1);
                                }
                                else
                                {
                                    ifCounter--;
                                }

                            }
                        }
                    }

                }
            }

            else if(ch=='{')
            {
                bracOpenCount++;
            }
            else if(ch=='\n')
            {
                line1++;
            }
            else if(ch=='}')
            {
                if(bracOpenCount<=0)
                {

                    printf("Unmatched '}' at line %d \n",line1);
                }
                else
                {
                    bracCloseCount++;
                    if(bracCloseCount>bracOpenCount)
                    {

                        printf("Unmatched '}' at line %d \n",line1);

                    }
                    else if(bracOpenCount>bracCloseCount)
                    {

                        printf("Unmatched '{' at line %d \n",line1);
                    }
                    else
                    {
                        bracOpenCount--;
                    }

                }
            }

        }

    }
    fclose(file1);

    file1=fopen("output2.cpp","r");
    if(!file1)
        cout<<"File can't be opened"<<endl;
    else
    {
        while((ch=fgetc(file1))!=EOF)
        {
            if(ch=='f')
            {
                ch=fgetc(file1);
                if(ch=='o')
                {
                    ch=fgetc(file1);
                    if(ch=='r')
                    {
                        while((ch=fgetc(file1))!=')')
                        {

                            if(ch==';')
                            {
                                ch=fgetc(file1);
                                if(ch==';')
                                {

                                    printf("Duplicate token at line %d \n",line2);
                                }

                            }
                        }
                    }
                }
            }
            else if(ch==';')
            {
                ch=fgetc(file1);
                if(ch==';')
                {

                    printf("Duplicate token at line %d \n",line2);
                }

            }
            else if(ch=='\n')
            {
                // cout<< " line 2 value is  " <<line2 <<" "<< endl;
                line2++;
            }
        }
    }
    fclose(file1);
}

void checkheader()
{
    FILE *p1;
    char c;

    p1 = fopen("input.cpp","r");

    if(!p1)
        printf("\n  File can't be opened!");
    else
    {
        printf("headers file are : \n");
        while((c = fgetc(p1)) != EOF)
        {
            if(c=='#')
            {
                while((c = fgetc(p1))!= '<');
                while((c = fgetc(p1))!= '>')
                    printf("%c", c);
                printf("\n");
            }

        }
    }
    fclose(p1);







}
void keywordchecker()
{
    printf(" keywords are :");
    for(int i = 0; i<len; i++)
    {
        printf("%c",keyword[i]);
    }


}
int main()
{
    char choose;

    while(choose != 't')
    {


        printf("\n Enter 1 for for error  \n");
        printf("Enter 2 see header files \n");
        printf("Enter 3 for tokenizing\n");
        printf("Enter 4 for error check\n");
        printf("Enter t for terminate\n");
        scanf("%c",&choose);
        switch(choose)
        {
        case '1':
            funcRemovingExtraSpaceComments();
            funcAddingLineNumber();
            funcIdToken();
            funcError();
            break;
        case '2':
            checkheader();
            break;
        case '3':
            keywordchecker();
            break;
        case '4':

            break;

        case 't':
            exit(0);
        }


    }


    return 0;
}
