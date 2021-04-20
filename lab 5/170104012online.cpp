
#include<bits/stdc++.h>
using namespace std;

struct dataTable
{

    int serialNumber;
    char variableName[20];
    string id;
    string dataType;
    string value;
    string scope;
};

void step2(int ptr)
{

    struct dataTable dataTableArray[100];
    FILE *file1,*file2,*file3;
    char stringTemp[200],stringTemp2[100];
    int cnt = 0,serialno = 0,cnt2 = 0,k = 0,i=0;
    file1 = fopen("output1.cpp","r");

    char ch;
    int serialCnt = 0,nameCnt = 0,valueCnt = 0;

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

}

int main()
{
    char choose;

    cout<<"Enter 7 for step 3  "<<endl;

    cin>>choose;
    switch(choose)
    {

    case '7':
        step2(7);
        break;

    }

    return 0;
}
