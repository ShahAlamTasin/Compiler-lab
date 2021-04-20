
#include<bits/stdc++.h>
using namespace std;

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
    file2 = fopen("output1.cpp","w");
    int flag = 0;
    if(!file1)
    {
        cout<<"File not found"<<endl;
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

    file2=fopen("output1.cpp","r");
    cout<<":::::::::::::::After step 1 done the output is::::::::::::::"<<endl<<endl;
    while((ch=fgetc(file2))!=EOF)
    {
        cout<<ch;
    }

    fclose(file2);
    cout<<endl<<endl;

}
void step2(int ptr)
{

    struct dataTable dataTableArray[100];
    FILE *file1,*file2,*file3;
    char stringTemp[200],stringTemp2[100];
    int cnt = 0,serialno = 0,cnt2 = 0,k = 0,i=0,nlen=0;
    file1 = fopen("output1.cpp","r");

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
        cout<<"Step2:\n";
        cout<<"SL"<<"--"<<"Name"<<"--"<<"IdType"<<"--"<<"DataType"<<"--"<<"Value"<<"\n\n";
        for(int i =0; i<serialCnt; i++)
        {
            cout<<dataTableArray[i].serialNumber<<"---"<<dataTableArray[i].variableName<<"---"<<dataTableArray[i].id<<"--"<<dataTableArray[i].dataType<<"---"<<dataTableArray[i].value<<"\n";
        }

    }
/*
    else if (ptr==3)
    {
        int j;
        serialCnt++;
        string demo,datatype,value;
        char name[20];
        cout<<"enter values to insert variable"<<endl;
        cout<<"enter variable name"<<endl;
        cin>>demo;
        cout<<"enter variable datatype "<<endl;
        cin>>datatype;
        cout<<"enter variable value "<<endl;
        cin>>value;
        j = serialCnt;
        dataTableArray[j].serialNumber =j;
        for(int i = 0; i<sizeof(demo); i++)
        {
            dataTableArray[j].variableName[i] = demo[i];

        }

        dataTableArray[j].id ="var";
        dataTableArray[j].dataType =datatype;
        dataTableArray[j].value =value;
        cout<<"Step3:\n";
        cout<<"SL"<<"--"<<"Name"<<"--"<<"IdType"<<"--"<<"DataType"<<"--"<<"Value"<<"\n\n";
        for(int i =0; i<=j; i++)
        {
            cout<<dataTableArray[i].serialNumber<<"---"<<dataTableArray[i].variableName<<"---"<<dataTableArray[i].id<<"--"<<dataTableArray[i].dataType<<"---"<<dataTableArray[i].value<<"\n";
        }
    }

    else if (ptr==4)
    {
        int delid;
        cout<<"enter id for delete"<<endl;
        cin>>delid;

        if(delid>serialCnt)
        {
            cout<<"enter valid id for delete"<<endl;
        }
        else
        {
            for( int i = delid ; i<=serialCnt; i++)
            {
                dataTableArray[i-1].serialNumber =dataTableArray[i].serialNumber;
                for(int j = 0; j<sizeof(dataTableArray[i].variableName); j++)
                {
                    dataTableArray[i-1].variableName[j] = dataTableArray[i].variableName[j];
                }
                dataTableArray[i-1].id =dataTableArray[i].id ;
                dataTableArray[i-1].dataType =dataTableArray[i].dataType;
                dataTableArray[i-1].value =dataTableArray[i].value;

            }
        }
        serialCnt --;
        cout<<"Step4:\n";
        cout<<"SL"<<"--"<<"Name"<<"--"<<"IdType"<<"--"<<"DataType"<<"--"<<"Value"<<"\n\n";
        for(int i =0; i<serialCnt; i++)
        {
            cout<<dataTableArray[i].serialNumber<<"---"<<dataTableArray[i].variableName<<"---"<<dataTableArray[i].id<<"--"<<dataTableArray[i].dataType<<"---"<<dataTableArray[i].value<<"\n";
        }
    }

    else if (ptr==5)
    {
        int searchid;
        cout<<"enter id for search"<<endl;
        cin>>searchid;
        cout <<"Search result " <<endl;
        for(int i =0; i<serialCnt; i++)
        {
            if(i==searchid-1)
            {
                cout<<"SL"<<"--"<<"Name"<<"--"<<"IdType"<<"--"<<"DataType"<<"--"<<"Value"<<"\n\n";
                cout<<dataTableArray[i].serialNumber<<"---"<<dataTableArray[i].variableName<<"---"<<dataTableArray[i].id<<"--"<<dataTableArray[i].dataType<<"---"<<dataTableArray[i].value<<"\n";
            }
        }
    }
    else if (ptr==6)
    {
        int updateid;
        string updatevalue;
        cout<<"enter id for update"<<endl;
        cin>>updateid;
        cout<<"enter value for update"<<endl;
        cin>>updatevalue;

        for(int i =0; i<serialCnt; i++)
        {
            if(i==updateid-1)
            {
                if(dataTableArray[i].id=="var" && dataTableArray[i].dataType=="int")
                {
                    dataTableArray[i].value =updatevalue;
                }
                else if(dataTableArray[i].id=="var" && (dataTableArray[i].dataType=="float" ||dataTableArray[i].dataType=="double"))
                {

                    if(updatevalue.find('.')!=-1)
                        dataTableArray[i].value =updatevalue;
                    else
                        cout<<"enter correct format"<<endl;

                }
            }
        }

        cout<<"Step6:\n";
        cout<<"SL"<<"--"<<"Name"<<"--"<<"IdType"<<"--"<<"DataType"<<"--"<<"Value"<<"\n\n";
        for(int i =0; i<serialCnt; i++)
        {
            cout<<dataTableArray[i].serialNumber<<"---"<<dataTableArray[i].variableName<<"---"<<dataTableArray[i].id<<"--"<<dataTableArray[i].dataType<<"---"<<dataTableArray[i].value<<"\n";
        }

    }

    else if (ptr==7)
    {
        fclose(file1);

        int  i =0,k=0;
        char ch1;
        file1 = fopen("output1.cpp","r");
        file3 = fopen("file2.txt","w");
        while((ch=fgetc(file1))!=EOF)
        {

            if(ch=='i')
            {
                if((ch1=fgetc(file1))=='d')
                {
                    char str[20];
                    fputc('i',file3);
                    cout<<'i';
                    fputc('d',file3);
                    cout<<'d';
                    ch=fgetc(file1);
                    fputc(' ',file3);
                    cout<<' ';
                    i=0;
                    while((ch=fgetc(file1))!=']')
                    {
                        str[i] = ch;
                        i++;
                    }
                    str[i] ='\0';

                    k=0;
                    for(int j =0; j<serialCnt; j++)
                    {
                        if(strcmp(str, dataTableArray[j].variableName)==0)
                        {
                            k=j;

                            break;
                        }
                    }
                    char c=(char)k;
                    fputc(c,file3);
                    cout<<k;
                    fputc(']',file3);
                    cout<<']';


                }
                else
                {

                    fputc(ch,file3);
                    cout<<ch;
                    fputc(ch1,file3);
                    cout<<ch1;

                }


            }
            else
            {
                fputc(ch,file3);
                cout<<ch;
            }

        }

    }
*/
}

int main()
{
    char choose;
    cout<<"Enter 1 for view the output after step 1 process,"<<endl;
    cout<<"enter 2 for view the Symbol Table "<<endl;
    cout<<"Enter 3 for insert "<<endl;
    cout<<"Enter 4 for delete "<<endl;
    cout<<"Enter 5 for search "<<endl;
    cout<<"Enter 6 for update "<<endl;
    cout<<"Enter 7 for step 3  "<<endl;

    cin>>choose;
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
