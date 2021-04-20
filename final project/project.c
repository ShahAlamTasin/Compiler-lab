
/* CSE 4130 : Spring 2020 Final Project ID:170104012 */




#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>



FILE *file1,*file2,*finaloutput;
char ch,ch1,temp,temp1;
int intflag=0,floatflag=0,doubleflag=0,charflag =0,len=0;
char keyword[100];
char identifier[100] [100];

char input[1000000] ;
struct dataTable
{

    int serialNumber;
    char variableName[20];
    char id[100];
    char dataType[100];
    char value[100];
    char scope[100];
};
char keywords[10][100] =
{
    "void","int","float","char","if","else","for","return","while","double"
};

int isKeyword(char str[])
{
    int flag = 0;

    for(int i = 0; i < 10; i++)
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
void funcRemovingExtraSpaceComments()
{
    file1=fopen("input.cpp","r");
    file2=fopen("output1.cpp","w");

    if(!file1)
        printf(" File can't be opened  \n ");
    else
    {
        while((ch=fgetc(file1))!=EOF)
        {
            if(ch=='#')
            {



                while((ch = fgetc(file1))!= '<');
                while((ch = fgetc(file1))!= '>');
                ch=fgetc(file1);
                fputc('\n',file2);




            }
            else  if(ch=='/')
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
    }
    fclose(file1);
    fclose(file2);




}


void funcAddingLineNumber()
{
    int countLine = 1;
    file1 = fopen("output1.cpp","r");
    file2 = fopen("output2.cpp","w");
    finaloutput=fopen("outputoffinalcode.txt","w");
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
    fprintf(finaloutput," adding line  the output is : \n");

    printf("\n After  step done with adding line number the output is : \n");
    file2=fopen("output2.cpp","r");

    while((ch=fgetc(file2))!=EOF)
    {
        printf("%c",ch);
        fputc(ch,finaloutput);

    }
    fprintf(finaloutput,"\n");
    fprintf(finaloutput,"\n");
    fprintf(finaloutput,"\n");
    fclose(file2);
    fclose(finaloutput);
    printf("bal bal");
}

void funcIdToken()
{
    printf("bal");
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




}

void funcError()
{
    int line1 = 1,line2 = 1,ifCounter = 0,elseCounter = 0,bracOpenCount = 0,bracCloseCount = 0;
    finaloutput=fopen("outputoffinalcode.txt ","a");
    fprintf(finaloutput,"\n error checking  step done: \n");
    printf("\n After error checking  step done:: \n \n");
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
                                fprintf(finaloutput,"Unmatched 'else' at line %d \n",line1);
                            }
                            else
                            {
                                elseCounter++;
                                if(elseCounter>ifCounter)
                                {
                                    printf("Unmatched 'else' at line %d \n",line1);
                                    fprintf(finaloutput,"Unmatched 'else' at line %d \n",line1);
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
                    fprintf(finaloutput,"Unmatched '}' at line %d \n",line1);
                }
                else
                {
                    bracCloseCount++;
                    if(bracCloseCount>bracOpenCount)
                    {

                        printf("Unmatched '}' at line %d \n",line1);
                        fprintf(finaloutput,"Unmatched '}' at line %d \n",line1);

                    }
                    else if(bracOpenCount>bracCloseCount)
                    {

                        printf("Unmatched '{' at line %d \n",line1);
                        fprintf(finaloutput,"Unmatched '{' at line %d \n",line1);
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
        printf("File can't be opened \n");
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
                                    fprintf(finaloutput,"Duplicate token at line %d \n",line2);
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
                    fprintf(finaloutput,"Duplicate token at line %d \n",line2);
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
    fprintf(finaloutput,"\n");
    fprintf(finaloutput,"\n");
    fprintf(finaloutput,"\n");
    fclose(finaloutput);
}
void checkheader()
{
    FILE *p1;
    char c;

    p1 = fopen("input.cpp","r");
    finaloutput=fopen("outputoffinalcode.txt ","a");
    fprintf(finaloutput,"headers file are : \n \n \n");
    if(!p1)
        printf("\n  File can't be opened!");
    else
    {
        printf("headers file are : \n \n \n");
        while((c = fgetc(p1)) != EOF)
        {
            if(c=='#')
            {
                while((c = fgetc(p1))!= '<');
                while((c = fgetc(p1))!= '>')
                {
                    printf("%c", c);

                    fprintf(finaloutput,"%c",c);
                }
                fprintf(finaloutput,"\n");
                fprintf(finaloutput,"\n");
                printf("\n");
            }

        }
    }
    fclose(p1);

    fclose(finaloutput);





}
void keywordchecker()
{
    printf(" keywords are :");
    finaloutput=fopen("outputoffinalcode.txt ","a");
    fprintf(finaloutput,"keywords are : \n \n \n");

    for(int i = 0; i<len; i++)
    {
        printf("%c",keyword[i]);

        fprintf(finaloutput,"%c",keyword[i]);
    }
    fprintf(finaloutput,"\n");
    fprintf(finaloutput,"\n");
    fprintf(finaloutput,"\n");

    fclose(finaloutput);
    printf("\n \n \n");


}
void lexicalanalysis_step2()
{


    FILE *p1 =fopen("output2.txt", "r");
    FILE *p2 =fopen("outputlexa.txt", "w");

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


                fputs("[op ",p2);

                fputc(step1[i],p2);
                fputc(step1[++i],p2);
                fputs("]",p2);
            }
            else
            {

                fputs("[op ",p2);
                fputc(step1[i],p2);
                fputs("]",p2);
            }
        }
        else if(isSeperator(step1[i]))
        {

            fputs("[sep ",p2);
            fputc(step1[i],p2);
            fputs("]",p2);
        }
        else if(isParenthesis(step1[i]))
        {

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

                        fputs("[kw ",p2);
                        fputs(temp,p2);
                        fputs("]",p2);
                    }
                    else if(isIdentifier(temp))
                    {

                        fputs("[id ",p2);
                        fputs(temp,p2);
                        fputs("]",p2);
                    }
                    else if(isNumber(temp))
                    {

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
    fclose(p2);
    return 0;







}

void lexicalanalysis_step1()
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
            else
                fputc(ch0, p2);
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
            else if(ch0 == ' ')
            {
                while((ch1 = fgetc(p2)) == ' ');
                fputc(' ', p1);
                fputc(ch1, p1);
            }
            else if(ch0 == '(')
            {

                fputc(' ', p1);
                fputc('(', p1);
            }
            else
                fputc(ch0, p1);
        }
        fclose(p1);
        fclose(p2);

    }



}

void step1()
{
    FILE *file1,*file2;
    char ch,stringTemp[500];
    int cnt=0;
    file1 = fopen("outputlexa.txt","r");
    file2 = fopen("outputdemo.cpp","w");
    int flag = 0;
    if(!file1)
    {

        printf(" File not found \n ");
    }
    else
    {
        while((ch=getc(file1))!=EOF)
        {
            if(ch=='[')
            {
                fputc(ch,file2);
                while((ch=getc(file1))!=' ')
                {
                    stringTemp[cnt++]=ch;
                }
                stringTemp[cnt]='\0';
                if(strcmp("id",stringTemp)==0)
                {
                    fputs(stringTemp,file2);
                    fputc(' ',file2);
                }
                while((ch=getc(file1))!=']')
                {
                    fputc(ch,file2);
                }
                fputc(ch,file2);
                cnt=0;
            }
        }
    }
    fclose(file1);
    fclose(file2);


    printf("\n\n");

}

void step2(int ptr)
{

    struct dataTable dataTableArray[100];
    FILE *file1,*file2,*file3;
    char stringTemp[200],stringTemp2[100];
    int cnt = 0,serialno = 0,cnt2 = 0,k = 0,i=0,nlen=0;
    file1 = fopen("outputdemo.cpp","r");
    finaloutput=fopen("outputoffinalcode.txt","a");


    char ch;
    int serialCnt = 0,nameCnt = 0,valueCnt = 0;
    while((ch=fgetc(file1))!=EOF)
    {
        if(ch == '[')
        {
            while((ch=fgetc(file1))!=']')
            {
                stringTemp[cnt++] = ch;
            }
            stringTemp[cnt]= '\0';
            if(strcmp("int",stringTemp)==0)
            {
                serialno++;
                if((ch=fgetc(file1))=='[')
                {
                    while((ch=fgetc(file1))!=' ');
                    while((ch=fgetc(file1))!=']')
                    {
                        dataTableArray[serialCnt].serialNumber=serialno;
                        dataTableArray[serialCnt].variableName[nameCnt++]=ch;
                        dataTableArray[serialCnt].dataType[nlen++]='i';
                        dataTableArray[serialCnt].dataType[nlen++]='n';
                        dataTableArray[serialCnt].dataType[nlen++]='t';
                        nlen =0;
                    }
                    ch=fgetc(file1);
                    if((ch=fgetc(file1))=='(')
                    {
                        dataTableArray[serialCnt].id[nlen++]='f';
                        dataTableArray[serialCnt].id[nlen++]='u';
                        dataTableArray[serialCnt].id[nlen++]='n';
                        dataTableArray[serialCnt].id[nlen++]='c';
                        nlen =0;

                    }
                    else if(ch == '=')
                    {
                        dataTableArray[serialCnt].id[nlen++]='v';
                        dataTableArray[serialCnt].id[nlen++]='a';
                        dataTableArray[serialCnt].id[nlen++]='r';
                        nlen =0;
                        ch = fgetc(file1);
                        ch = fgetc(file1);

                        while((ch=fgetc(file1))!=']')
                        {
                            if((isdigit(ch)))
                            {

                                dataTableArray[serialCnt].value[nlen++]=ch;

                            }
                            nlen =0;
                        }


                    }
                    else
                    {
                        dataTableArray[serialCnt].id[nlen++]='v';
                        dataTableArray[serialCnt].id[nlen++]='a';
                        dataTableArray[serialCnt].id[nlen++]='r';
                        nlen =0;
                    }
                    nameCnt=0;

                    serialCnt++;

                }

            }

            //float
            else if(strcmp("float",stringTemp)==0)
            {
                serialno++;
                if((ch=fgetc(file1))=='[')
                {
                    while((ch=fgetc(file1))!=' ');
                    while((ch=fgetc(file1))!=']')
                    {
                        dataTableArray[serialCnt].serialNumber=serialno;
                        dataTableArray[serialCnt].variableName[nameCnt++]=ch;
                        dataTableArray[serialCnt].dataType[nlen++]='f';
                        dataTableArray[serialCnt].dataType[nlen++]='l';
                        dataTableArray[serialCnt].dataType[nlen++]='o';
                        dataTableArray[serialCnt].dataType[nlen++]='a';
                        dataTableArray[serialCnt].dataType[nlen++]='t';
                        nlen =0;
                    }
                    ch=fgetc(file1);
                    if((ch=fgetc(file1))=='(')
                    {
                        dataTableArray[serialCnt].id[nlen++]='f';
                        dataTableArray[serialCnt].id[nlen++]='u';
                        dataTableArray[serialCnt].id[nlen++]='n';
                        dataTableArray[serialCnt].id[nlen++]='c';
                        nlen =0;

                    }
                    else if(ch == '=')
                    {
                        dataTableArray[serialCnt].id[nlen++]='v';
                        dataTableArray[serialCnt].id[nlen++]='a';
                        dataTableArray[serialCnt].id[nlen++]='r';
                        nlen =0;
                        ch = fgetc(file1);
                        ch = fgetc(file1);
                        int i =0;
                        while((ch=fgetc(file1))!=']')
                        {
                            if((isdigit(ch)||ch=='.'))
                            {
                                dataTableArray[serialCnt].value[nlen++]=ch;
                            }

                        }
                        nlen =0;

                    }
                    else
                    {
                        dataTableArray[serialCnt].id[nlen++]='v';
                        dataTableArray[serialCnt].id[nlen++]='a';
                        dataTableArray[serialCnt].id[nlen++]='r';
                        nlen =0;
                    }
                    nameCnt=0;

                    serialCnt++;

                }

            }
            //double
            else if(strcmp("double",stringTemp)==0)
            {
                serialno++;
                if((ch=fgetc(file1))=='[')
                {
                    while((ch=fgetc(file1))!=' ');
                    while((ch=fgetc(file1))!=']')
                    {
                        dataTableArray[serialCnt].serialNumber=serialno;
                        dataTableArray[serialCnt].variableName[nameCnt++]=ch;
                        dataTableArray[serialCnt].dataType[nlen++] = 'd';
                        dataTableArray[serialCnt].dataType[nlen++] = 'o';
                        dataTableArray[serialCnt].dataType[nlen++] = 'u';
                        dataTableArray[serialCnt].dataType[nlen++] = 'b';
                        dataTableArray[serialCnt].dataType[nlen++] = 'l';
                        dataTableArray[serialCnt].dataType[nlen++] = 'e';
                        nlen=0;
                    }
                    ch=fgetc(file1);
                    if((ch=fgetc(file1))=='(')
                    {
                        dataTableArray[serialCnt].id[nlen++]='f';
                        dataTableArray[serialCnt].id[nlen++]='u';
                        dataTableArray[serialCnt].id[nlen++]='n';
                        dataTableArray[serialCnt].id[nlen++]='c';
                        nlen =0;


                    }
                    else if(ch == '=')
                    {
                        dataTableArray[serialCnt].id[nlen++]='v';
                        dataTableArray[serialCnt].id[nlen++]='a';
                        dataTableArray[serialCnt].id[nlen++]='r';
                        nlen =0;
                        ch = fgetc(file1);
                        ch = fgetc(file1);
                        int i =0;
                        while((ch=fgetc(file1))!=']')
                        {
                            if((isdigit(ch)||ch=='.'))
                            {
                                dataTableArray[serialCnt].value[nlen++]=ch;
                            }
                        }
                        nlen =0;

                    }
                    else
                    {
                        dataTableArray[serialCnt].id[nlen++]='v';
                        dataTableArray[serialCnt].id[nlen++]='a';
                        dataTableArray[serialCnt].id[nlen++]='r';
                        nlen =0;
                    }
                    nameCnt=0;

                    serialCnt++;

                }

            }
            //return
            else if(strcmp("return", stringTemp)==0)
            {
                if((ch=fgetc(file1))=='[')
                {
                    while((ch=fgetc(file1))!=' ');
                    while((ch=fgetc(file1))!=']');
                }
            }
            //id
            else if(stringTemp[0]=='i')
            {
                if(stringTemp[1]=='d')
                {

                    ch=fgetc(file1);
                    for(int j=3; j<cnt; j++)
                    {
                        stringTemp2[cnt2++]=stringTemp[j];

                    }
                    stringTemp2[cnt2]='\0';

                    k=0;
                    for(int i =0; i<serialCnt; i++)
                    {
                        if(strcmp(stringTemp2, dataTableArray[i].variableName)==0)
                        {
                            k=i;

                            break;
                        }
                    }
                }
                //****
                while((ch=fgetc(file1))=='=')
                {
                    int i =0;
                    ch=fgetc(file1);
                    ch=fgetc(file1);
                    while((ch=fgetc(file1))!=']')
                    {

                        if(ch=='i')
                        {
                            ch=fgetc(file1);
                            if(ch=='d')
                            {
                                while(ch=fgetc(file1)!=']');
                            }
                        }
                        else if((isdigit(ch)||ch=='.'))
                        {
                            dataTableArray[k].value[nlen++]=ch;
                        }
                    }
                    nlen=0;

                }

            }
            cnt=0;
            cnt2=0;
        }
    }
    if (ptr==2)
    {

        printf("Step2:\n");

        printf("variables are : - \n");
        fprintf(finaloutput,"variables are : - \n");
        for(int i =0; i<serialCnt; i++)
        {
            if(strcmp("var",dataTableArray[i].id)==0)
            {

                printf("-- %s-- ",dataTableArray[i].variableName);
                fprintf(finaloutput,"-- %s-- ",dataTableArray[i].variableName);
            }
            //   printf("%d-- %s-- %s-- %s-- %s\n\n",dataTableArray[i].serialNumber,dataTableArray[i].variableName,dataTableArray[i].id,dataTableArray[i].dataType,dataTableArray[i].value);

        }
        printf("\n");
        fprintf(finaloutput,"\n");
        printf("functions are : - \n");
        fprintf(finaloutput,"functions are : - \n");
        for(int i =0; i<serialCnt; i++)
        {
            if(strcmp("func",dataTableArray[i].id)==0)
            {

                printf("-- %s-- ",dataTableArray[i].variableName);
                fprintf(finaloutput,"-- %s-- ",dataTableArray[i].variableName);
            }
            //   printf("%d-- %s-- %s-- %s-- %s\n\n",dataTableArray[i].serialNumber,dataTableArray[i].variableName,dataTableArray[i].id,dataTableArray[i].dataType,dataTableArray[i].value);

        }

    }
    fclose(finaloutput);
}


int main()
{

    char choose;
    printf("Enter 1 for view the code after line number \n");
    printf("enter 2 for view the code error & keyword  \n");
    printf("enter 3 for view the header of code \n");

    printf("enter 4 for view the variable and function of code \n");
    printf("enter t for exit \n");
    scanf("%c",&choose);

    switch(choose)
    {
    case '1':
        funcRemovingExtraSpaceComments();
        funcAddingLineNumber();
        break;
    case '2':
        funcIdToken();
        funcError();
        keywordchecker();
        break;
    case '3':
        checkheader();

        break;
    case '4':
        lexicalanalysis_step1();
        lexicalanalysis_step2();
        step1();
        step2(2);
        break;

    case 't':
        exit(0);
        break;


    }



    return 0;
}
