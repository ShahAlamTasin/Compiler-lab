#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char str[100];
int f = 0,i = 0,l;

void stat();
void asgn_stat();
void dscn_stat();
void loop_stat();
void expn();
void smpl_expn();
void extn();
void relop();
void extn1();
void E();
void T();
void F();


void loop_stat()
{
    if(str[i] == 'w' || str[i+1] == 'h'|| str[i+2] == 'i'|| str[i+3] == 'l'|| str[i+4] == 'e')
    {
        i = i+5;
        if(str[i] == '(')
        {
            i++;
            expn();
            if(str[i] == ')')
            {
                i++;
                stat();
                if(i==l)
                    return;
                else
                {
                    f = 0;
                    return;
                }

            }
            else
                return;
        }
        else
        {
            f = 0;
            return;
        }
    }
    else if(str[i] = 'f' || str[i+1] == 'o' || str[i+2] == 'r')
    {
        i = i+3;
        if(str[i] == '(')
        {
            i++;
            asgn_stat();
            if(str[i] == ';')
            {
                i++;
                expn();
                if(str[i] == ';')
                {
                    i++;
                    asgn_stat();
                    if(str[i] == ')')
                    {
                        i++;
                        stat();
                        if(i==l)
                            return;
                        else
                        {
                            f = 0;
                            return;
                        }
                    }
                    else
                    {
                        f = 0;
                        return;
                    }

                }
                else
                {
                    f = 0;
                    return;
                }
            }
            else
            {
                f = 0;
                return;
            }
        }
        else
        {
            f = 0;
            return;
        }
    }
    else
    {
        f = 0;
        return;
    }
}


void extn1()
{
    if((l-1) == i)
    {
        f = 1;
        i++;
        return;
    }
    else
    {
        if(str[i] == 'e' && str[i+1] == 'l' && str[i+2] =='s' || str[i+3] == 'e')
        {
            i=i+4;
            f=0;
            stat();
            if(f == 1)
                return;
            else
            {
                f = 0;
                return;
            }
        }
        else
        {
            f = 0;
            return;
        }
    }
}


void dscn_stat()
{
    if(str[i] == 'i')
    {
        i++;
        if(str[i] == 'f')
        {
            i++;
            if(str[i] == '(')
            {
                i++;
                expn();
                if(str[i] == ')')
                {
                    i++;
                    stat();
                    if(i==l)
                        return;
                    else
                    {
                        if(f == 1)
                        {
                            extn1();
                        }
                        else
                            return;
                        }

                }
            }
        }
    }
    else
    {
        f = 0;
        return;
    }
}
void F()
{
    if(isdigit(str[i]))
    {
        i++;
        f = 1;
        return;
    }
    else if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd')
    {
        i++;
        f = 1;
        return;
    }
    else if(str[i] == '(')
    {
        i++;
        E();
        i++;
        if(str[i] == ')')
        {
            f = 1;
            return;
        }
    }
}


void T()
{
    F();
    if(i==l)
        return;
    if(i<l-1)
    {
        if(str[i] == '*' || str[i] == '/')
        {
            i++;
            F();
        }
        else if(f == 1)
        {
            return;
        }
    }

}

void E()
{
    T();

    if(i == l)
        return;
    if(i < l-1)
    {
        if(str[i] == '+' || str[i] == '-')
        {
            i++;
            T();
        }
        else if(f == 1)
        {
            return;
        }
    }

}

void smpl_expn()
{
    E();
    if(f == 1 && l==i)
    {
        return;
    }
    else
        return;
}

void relop()
{
    if(str[i] == '=')
    {
        i++;
        if(str[i] == '=')
        {
           f  = 1;
           return;
        }
        else
        {
            f = 0;
            return;
        }
    }
    else if(str[i] == '!')
    {
        i++;
        if(str[i] == '=')
        {
           f  = 1;
           return;
        }
        else
        {
            f = 0;
            return;
        }
    }
    else if(str[i] == '<')
    {
        i++;
        f = 1;
        if(str[i] == '=')
        {
           f  = 1;
           return;
        }
        else
        {
            return;
        }
    }
    else if(str[i] == '>')
    {
        i++;
        f = 1;
        if(str[i] == '=')
        {
           i++;
           f  = 1;
           return;
        }
        else
        {
            return;
        }
    }
    else if(str[i] == '>')
    {
        i++;
        f  = 1;
        return;
    }
    else if(str[i] == '<')
    {
        i++;
        f  = 1;
        return;
    }
    else
    {
        f = 0;
        return;
    }

}


void extn()
{
    if((l-1) == i)
    {
        f = 1;
        i++;
        return;
    }
    else
    {
        relop();
        if(f == 1)
        {
            smpl_expn();
            if(l == i)
                return;
        }
        else
            return;
    }
}


void expn()
{
    smpl_expn();
    if(l == i)
    {
        return;
    }
    else
    {

        if(f == 1)
        {
            extn();
            return;
        }

    }


}


void asgn_stat()
{
    if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c'|| str[i] == 'd'|| str[i] == 'e')
    {
        i++;
        if(str[i] == '=')
        {
            i++;
            expn();
            if(f ==1 && i==l)
            {
                return;
            }
            else
            {
                f=1;
                return;
            }

        }

    }
    else
    {
        f = 0;
        return;
    }
}



void stat()
{
    int as = 0;
    asgn_stat();
    as = 1;
    if(f ==1 && (l==i))
    {
        return;
    }
    else if(f==1)
        return;

    if(as == 1 && f == 0)
    {
        //i=0;
        dscn_stat();
        if(f == 0)
        {
            //i = 0;
            loop_stat();
        }

    }
}

int main()
{
    cout <<"CFG: " <<endl;
    cout << "<stat> -> <asgn_stat> | <dscn_stat> | <loop_stat>" <<endl << "<asgn_stat> -> id = <expn>"<<endl<<
            "<expn> -> <smpl_expn> <extn>"<<endl<<"<extn> -> <relop> <smpl_expn> | epsilon"<<endl<<"<dcsn_stat> -> if (<expn> ) <stat> <extn1>"<<endl<<
            "<extn1> -> else <stat> | epsilon "<<endl<<"<loop_stat> -> while (<expn>) <stat> | for (<asgn_stat> ; <expn> ; <asgn_stat> ) <stat>" <<endl<<
            "<relop> -> == | != | <= | >= | >| <"<<endl;

    //VALID:
    //b=1,c=a,b=a*3,
    //if(a)b=1,if(a>5)b=1elsec=2,if(a>5)b=5elseif(a<5)c=5,if(a>5)b=5elseif(a<5)c=5elsed=5,
    //while(a)b=1,while(a>=b)a=1,while(a>=b)if(a>5)b=5elseif(a<5)c=5elsed=5
    //for(a=0;a<2;c=1)b=3,for(a=0;a<5;a=a+1)b=a+b,for(a=0;a<5;a=a+1)if(a>5)b=a,for(a=0;a<5;a=a+1)if(a>5)b=aelsec=b,for(a=0;a<5;a=a+1)if(a>5)b=aelseif(a<5)c=b;

    cout <<endl;
    cout <<"Enter string: "<<endl;
    cin >> str;
    cout <<endl;

    l = strlen(str);
    if(l >= 1 )
        stat();
    else
        cout <<"invalid string"<<endl;
    if(l == i && f == 1 )
        cout <<"Valid string"<<endl;
    else
    {
        cout <<"invalid string"<<endl;
    }


    return 0;
}

