#include<stdio.h>
#include<stdbool.h>
#include<string.h>


bool ifSeparator(char c)
{
    if(c==';'||c==','||c=='\"' || c=='{' || c=='}' || c=='[' || c==']' || c=='(' || c==')'|| c=='\'')
    {
        return true;
    }
    return false;

}

int isKeyWord(char array[])
{
    if(strcmp(array,"void")==0)
    {
        return 1;
    }
    else if(strcmp(array,"main")==0)
    {
        return 2;
    }
    else if(strcmp(array,"float")==0)
    {
        return 3;
    }
    else if(strcmp(array,"double")==0)
    {
        return 4;
    }
    else if(strcmp(array,"int")==0)
    {
        return 5;
    }
    else if(strcmp(array,"char")==0)
    {
        return 6;
    }
    else if(strcmp(array,"for")==0)
    {
        return 7;
    }
    else if(strcmp(array,"while")==0)
    {
        return 8;
    }
    else if(strcmp(array,"if")==0)
    {
        return 9;
    }
    else if(strcmp(array,"else")==0)
    {
        return 10;
    }
    else if(strcmp(array,"return")==0)
    {
        return 11;
    }
    else
    {
        return 0;
    }
}


bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='=' ||
            c=='>' || c=='<' || c=='!' || c=='%' || c=='&' || c=='|')
        return true;

    return false;
}


bool isIdentifier(char array[])
{

    if(array[0]=='_' || (array[0]>='a' && array[0]<='z') || (array[0]>='A' && array[0]<='Z'))
    {
        int i=1;
        for(; i<strlen(array); i++)
        {
            if(!(array[i]=='_' || (array[i]>='a' && array[i]<='z')
                    || (array[i]>='A' && array[i]<='Z') || (array[i]>='0' && array[i]<='9')))
            {
                return false;
            }
        }
        return true;
    }
    else
        return false;
}


bool loop1(char array[], int i)
{
    while(i<strlen(array))
    {
        if(!(array[i]>='0' && array[i]<='9'))
            return false;
        i++;
    }

    return true;
}


bool loop0(char array[])
{
    int i=1;
    while(i<strlen(array))
    {
        if(array[i]=='.')
        {
            return loop1(array,i+1);
        }
        else if(!(array[i]>='0' && array[i]<='9'))
        {
            return false;
        }
        else
            i++;
    }
    return true;
}

bool isNum(char array[])
{

    if(array[0]=='0' && array[1]=='x' )
    {
       return loop1(array,2);
    }

    else if(array[0]>='0' && array[0]<='9' )
    {
        return loop0(array);
    }
    else if(array[0]=='.')
    {
        return loop1(array,1);
    }

    else
        return false;
}

int main()
{
    FILE *p1, *p2;
    char c,c1, separator, operator,operator1;
    char array[100];
    int i=0, s=0, d=0, error=0, k=0;
    char errors[100][100];

    p1=fopen("input.c","r");
    p2=fopen("input.c","r");




    printf("Output: \n");
    while((c=fgetc(p1))!=EOF)
    {
        i=d=0;
        separator=operator=operator1=' ';
        while(c!=' ')
        {
            if(ifSeparator(c))
            {
                d=1;
                separator=c;
                break;
            }
            else if(isOperator(c))
            {
                if(isOperator(c1=fgetc(p1))&& ((c=='+' && c1=='+') || (c=='=' && c1=='-')  ))
                {
                    d=2;
                    operator=c;
                    operator1=c1;
                    break;
                }
                else
                {
                    d=1;
                    operator=c;
                    c=c1;

                    c1=' ';
                    break;
                }

            }
            array[i]=c;
            i++;
            c=fgetc(p1);
        }
        array[i]='\0';

        s=0;
        if((s=isKeyWord(array))>0)
        {
            switch(s)
            {
            case 1:
            {
                printf("[%s]", array);
                break;
            }
            case 2:
            {
                printf("[%s]", array);
                break;
            }
            case 3:
            {
                printf("[%s]", array);
                break;
            }
            case 4:
            {
                printf("[%s]", array);
                break;
            }
            case 5:
            {
                printf("[%s]", array);
                break;
            }
            case 6:
            {
                printf("[%s]", array);
                break;
            }
            case 7:
            {
                printf("[%s]", array);
                break;
            }
            case 8:
            {
                printf("[%s]", array);
                break;
            }
            case 9:
            {
                printf("[%s]", array);
                break;
            }
            case 10:
            {
                printf("[%s]", array);
                break;
            }
            case 11:
            {
                printf("[%s]", array);
                break;
            }
            }
        }
        else if(isIdentifier(array))
        {
            printf("[id %s]", array);
        }
        else if(isNum(array))
        {
            printf("[%s]", array);
        }
        else
        {
            if(i>0)
            {
              //  printf("[unkn %s]", array);
                error=1;
                int j=0;
                for(; j<strlen(array); j++)
                    errors[k][j]=array[j];
                errors[k][j]='\0';
                k++;
            }
        }

        if(d==1)
        {

            if(separator!=' ')
                printf("[%c]",separator);
            else
            {
                printf("[%c]",operator);
            }
        }
        else if(d==2)
        {
            printf("[%c%c]",operator,operator1);
        }
    }

    if(error)
    {
        //printf("\n\nError message:\n");
        for(int i=0; i<k; i++)
        {
            for(int j=0; errors[i][j]!='\0'; j++)
            {
               // printf("%c",errors[i][j]);
            }
            //printf(" unknown token\n");
        }
    }

    return 0;
}

