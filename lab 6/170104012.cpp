#include<bits/stdc++.h>
using namespace std;

string s;
int sz;
int i = 0;

bool X()
{
    if(s[i]=='b')
    {
         cout<<s[i]<<endl;
        i++;
        if(s[i]=='b' || s[i]=='c')
        {
            cout<<s[i]<<endl;
            i++;

            X();
        }
        else
        {

            i--;
            cout<<s[i+1]<<endl;
            return false;
        }
    }
    else
        return false;
}

bool A()
{
    if(s[i]=='a')
    {
         cout<<s[i]<<endl;
        i++;
        if(X())
            return true;
        else if(s[i]=='d'&& (i+1)==sz)
            return true;
        else
             cout<<s[i]<<endl;
            return false;
    }
}

int main()
{
    cout<<"A --> aXd\n";
    cout<<"X --> bbX\n";
    cout<<"X --> bcX\n";
    cout<<"X --> epsilon\n";
    char ch;
    FILE *file1,*file2;
    file1=fopen("input1.cpp","r");
    file2=fopen("output1.cpp","w");
    if(!file1)
        cout<<"File can't be opened"<<endl;
    else
    {
        while((ch=fgetc(file1))!=EOF)
        {

            if(ch!='\n')
            {
                s+=ch;

            }
            else if(ch=='\n')
            {

                sz = s.size();
                if(sz>=2 && sz!=' ')
                {

                    if(A())
                    {
                        cout<<s[i]<<endl;
                         cout<<s<<endl;
                        cout<<"valid\n";
                        fputc('v',file2);
                        fputc('a',file2);
                        fputc('l',file2);
                        fputc('i',file2);
                        fputc('d',file2);
                        fputc('\n',file2);

                       s.clear();
                    i=0;
                    }
                    else
                    {
                        cout<<s[i]<<endl;
                       cout<<s<<endl;
                        cout<<"invalid\n";
                        fputc('i',file2);
                        fputc('n',file2);
                        fputc('v',file2);
                        fputc('a',file2);
                        fputc('l',file2);
                        fputc('i',file2);
                        fputc('d',file2);
                        fputc('\n',file2);

                      s.clear();
                i=0;

                    }
                }
                else
                {
                    cout<<"invalid\n";
                    fputc('i',file2);
                    fputc('n',file2);
                    fputc('v',file2);
                    fputc('a',file2);
                    fputc('l',file2);
                    fputc('i',file2);
                    fputc('d',file2);
                    fputc('\n',file2);

                   s.clear();
                  i=0;
                }
            }
        }
        i=0;
        sz = s.size();
        if(sz>=2 && sz!=' ')
        {

            if(A())
            {
              cout<<s<<endl;

                cout<<"valid\n";
                fputc('v',file2);
                fputc('a',file2);
                fputc('l',file2);
                fputc('i',file2);
                fputc('d',file2);
                fputc('\n',file2);

                s=' ';

            }
            else
            {

                 cout<<s<<endl;
                cout<<"invalid\n";
                fputc('i',file2);
                fputc('n',file2);
                fputc('v',file2);
                fputc('a',file2);
                fputc('l',file2);
                fputc('i',file2);
                fputc('d',file2);
                fputc('\n',file2);

                s=' ';


            }
        }

        else
        {
            cout<<s<<endl;
            cout<<"invalid\n";
            fputc('i',file2);
            fputc('n',file2);
            fputc('v',file2);
            fputc('a',file2);
            fputc('l',file2);
            fputc('i',file2);
            fputc('d',file2);
            fputc('\n',file2);

            s=' ';
            cout<<s<<endl;
        }



    }





}
