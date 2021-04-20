#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int len=0,flg;
    cout<<"enter any string: ";
    cin>>str;
    if(str[0]=='c')
    {


            int  a = str.find('_');
            for(int i=1; i<a; i++)
            {
                if((str[i]>='a'&& str[i]<='z') )
                {
                    if(str[a]=='_')
                    {

                        for(int j=a+1; j<sizeof(str); j++)
                        {
                            if((str[j]>='0'&& str[j]<='9'))
                                len++;
                        }


                    }

                }
            }
            if(len==str.length())
            {
                flg=1;
            }


    }

    else
    {
        flg=0;
    }

    if(flg==0)
        cout<<str<<" not valid"<<endl;

    else

        cout<<str<<" valid "<<endl;

    return 0;
}
