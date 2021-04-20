#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>









struct dataTable
{

    int serialNumber;
    char variableName[20];
    char id[100];
    char dataType[100];
    char value[100];
    char scope[100];
};
void step1()
{
    FILE *file1,*file2;
    char ch,stringTemp[500];
    int cnt=0;
    file1 = fopen("input.cpp","r");
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

    file2=fopen("outputdemo.cpp","r");
    printf(":::::::::::::::After step 1 done the output is:::::::::::::: \n \n");

    while((ch=fgetc(file2))!=EOF)
    {
        printf("%c",ch);
    }

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

        printf("SL--Name--IdType--DataType--Value\n\n");
        for(int i =0; i<serialCnt; i++)
        {
            printf("%d-- %s-- %s-- %s-- %s\n\n",dataTableArray[i].serialNumber,dataTableArray[i].variableName,dataTableArray[i].id,dataTableArray[i].dataType,dataTableArray[i].value);

        }

    }



}

int main()
{
    char choose;
    printf("Enter 1 for view the output after step 1 process \n");
    printf("enter 2 for view the Symbol Table  \n");
    scanf("%c",&choose);

    switch(choose)
    {
    case '1':
        step1();
        break;
    case '2':
        step2(2);
        break;
    case '3':
        step2(3);
        break;
    case '4':
        step2(4);
        break;
    case '5':
        step2(5);
        break;
    case '6':
        step2(6);
        break;
    case '7':
        step2(7);
        break;

    }

    return 0;
}
