#include<bits/stdc++.h>
using namespace std;

string s;
int i = 0;
bool F();

bool ID()
{
    if(s[i]=='a' || s[i]=='b' || s[i]=='c' || s[i]=='d' || s[i]=='e')return true;
    else return false;
}

bool NUM()
{
    if(s[i]>='0' && s[i]<='9')return true;
    else return false;
}

bool T()
{
    if(F())
    {
        i++;
        if(s[i]=='*' || s[i]=='/' )
        {
            i++;
            if(F())return true;
            else
            {
                i--;
                return false;
            }
        }
        else
        {
            i--;
            return true;
        }
    }
    else return false;
}

bool E()
{
    if(T())
    {
        i++;
        if(s[i]=='+' || s[i]=='-')
        {
            i++;
            if(T())return true;
            else
            {
                i--;
                return false;
            }
        }
        else
        {
            i--;
            return true;
        }
    }
    else return false;
}

bool F()
{
    if(s[i]=='(')
    {
        i++;
        if(E())
        {
            i++;
            if(s[i]==')')return true;
            else
            {
                i--;
                return false;
            }
        }
        else
        {
            i--;
            return false;
        }
    }
    else if(ID())return true;
    else if(NUM())return true;
    else return false;
}




int main()
{
    cout<<"<Exp> --> <Term> + <Term> | <Term> - <Term> | <Term>\n";
    cout<<"<Term> --> <Factor> * <Factor> | <Factor> / <Factor> | <Factor>\n";
    cout<<"<Factor> --> ( <Exp> ) | ID | NUM\n";
    cout<<"ID --> a|b|c|d|e\n";
    cout<<"NUM --> 0|1|2|3|4|5|6|7|8|9\n";
 char ch;


        FILE *file1,*file2;
    file1=fopen("input2.cpp","r");
    file2=fopen("output2.cpp","w");
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
            else
            {
                    if(E()){


                        cout<<"valid\n";
                        fputc('v',file2);
                        fputc('a',file2);
                        fputc('l',file2);
                        fputc('i',file2);
                        fputc('d',file2);
                        fputc('\n',file2);
                          i = 0;
                         s.clear();
                    }
                    else{


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
                       i = 0;
                    }

            }
        }

      i = 0;
        if(E()){


                        cout<<"valid\n";
                        fputc('v',file2);
                        fputc('a',file2);
                        fputc('l',file2);
                        fputc('i',file2);
                        fputc('d',file2);
                        fputc('\n',file2);

                         s.clear();
                    }
                    else{


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

                    }




    }




}
//(a+2)*(a-2)
