#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>


char input[1000000] ;

char keywords[9][50] =
{
    "void","int","float","char","if","else","for","return","while"
};

int isKeyword(char str[])
{
    int flag = 0;

    for(int i = 0; i < 9; i++)
    {
        if(strcmp(keywords[i], str) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int isOperator(char ch)
{
    int flag = 0;
    if (ch == '+' || ch == '-' || ch == '*' ||ch == '/' || ch == '>' || ch == '<' ||ch == '=' ||ch == '!' || ch == '&' || ch == '|')
    {
        flag = 1;
    }
    return flag;
}

int isSeperator(char ch)
{
    int flag = 0;
    if (ch == ';' || ch == ',' || ch == '\'' )
    {
        flag = 1;
    }
    return flag;
}

int isParenthesis(char ch)
{
    int flag = 0;
    if (ch == '(' || ch == ')' || ch == '{'  || ch == '}' || ch == '[' || ch == ']' )
    {
        flag = 1;
    }
    return flag;
}

int isIdentifier(char str[])
{
    if (!(isalpha(str[0]) || str[0]== '_'))
        return 0;

    for (int i = 1; i < strlen(str); i++)
    {
        if (!(isalpha(str[i]) || isdigit(str[i]) || str[i] == '_'))
            return 0;
    }

    return 1;
}

int isNumber(char str[])
{
    int flag = 1;
    int point = 0;

    if(str[0] == '0' && str[1] == 'x')
    {
        for(int i = 2; i < strlen(str); i++)
        {
            if( isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F') )
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    for(int i = 0; i < strlen(str); i++)
    {
        if(isdigit(str[i]))
        {
            flag = 1;
            continue;
        }
        else if(str[i] == '.')
        {
            point++;
        }
        else
        {
            flag = 0;
            break;

        }
    }
    if(point <=1 && flag == 1)
        return 1;
    else
        return 0;
}






int main()
{
    FILE *p1 =fopen("input.c", "r");
    FILE *p2 =fopen("output.c", "w");
    char c;
    int i = 0;
    if (!p1)
    {
        printf("Error! No file Detected");
    }
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            input[i] = c;
            i++;
        }
    }
    fclose(p1);

    char step1[1000000];
    char temp[1000];
    int j = 0;
    for(i = 0; i < strlen(input) ; i++)
    {
        if(isSeperator(input[i]))
        {
            step1[j++] = ' ';
            step1[j++] = input[i];
            step1[j++] = ' ';
        }
        else if(isOperator(input[i]))
        {
            if(isOperator(input[i+1]))
            {
                step1[j++] = ' ';
                step1[j++] = input[i];
                step1[j++] = input[++i];
                step1[j++] = ' ';
            }
            else
            {
                step1[j++] = ' ';
                step1[j++] = input[i];
                step1[j++] = ' ';
            }
        }
        else
        {
            step1[j++] = input[i];
        }
    }
    step1[j] = '\0';

    j=0;

    for(i=0; i<strlen(step1); ++i)
    {
        if(isOperator(step1[i]))
        {
            if(isOperator(step1[i+1]))
            {
                printf("[op %c",step1[i]);
                printf("%c]\n",step1[++i]);
                fputs("[op ",p2);
                fputc(step1[i],p2);
                  fputc(step1[++i],p2);
                  fputs("]",p2);
            }
            else
            {
                printf("[op %c]\n",step1[i]);
               fputs("[op ",p2);
                fputc(step1[i],p2);
                 fputs("]",p2);
            }
        }
        else if(isSeperator(step1[i]))
        {
            printf("[sep %c]\n",step1[i]);
            fputs("[sep ",p2);
                fputc(step1[i],p2);
                 fputs("]",p2);
        }
        else if(isParenthesis(step1[i]))
        {
            printf("[par %c]\n",step1[i]);
            fputs("[par ",p2);
                fputc(step1[i],p2);
                 fputs("]",p2);
        }
        else
        {
            if(step1[i]!=' ')
            {
                temp[j++]= step1[i];
            }
            else
            {
                temp[j]='\0';
                j =0;
                if(strlen(temp)>=1)
                {
                    if(isKeyword(temp))
                    {
                        printf("[kw %s]\n",temp);
                        fputs("[kw ",p2);
                        fputs(temp,p2);
                         fputs("]",p2);
                    }
                    else if(isIdentifier(temp))
                    {
                        printf("[id %s]\n",temp);
                        fputs("[id ",p2);
                     fputs(temp,p2);
                      fputs("]",p2);
                    }
                    else if(isNumber(temp))
                    {
                        printf("[num %s]\n",temp);
                        fputs("[num ",p2);
                     fputs(temp,p2);
                      fputs("]",p2);
                    }
                    else
                    {
                        printf("[unkn %s]   Unknown Syntax!!\n",temp);
                    }

                }
            }
        }
    }
    return 0;
}
