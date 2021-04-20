#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

struct Stack
{
    int top;
    int array[MAXSIZE];
} st;

void initialize()
{
    st.top = -1;
}

int isFull()
{
    if(st.top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}

int isEmpty()
{
    if(st.top == -1)
        return TRUE;
    else
        return FALSE;
}

void push(int num)
{
    if (isFull())
        printf("Stack is Full...\n");
    else
    {
        st.array[st.top + 1] = num;
        st.top++;
    }
}

int pop()
{
    if (isEmpty())
        printf("Stack is Empty...\n");
    else
    {
        st.top = st.top - 1;
        return st.array[st.top+1];
    }
}

int main()
{
    char inputString[100], c;
    int i, length;
    initialize();
    FILE *file1,*file2;
    char ch,stringTemp[500];
    int cnt=0;
    file1 = fopen("inputfile.txt","r");
    while((ch=getc(file1))!=EOF)
    {

        if(ch == '{')
            push(ch);
        else if(ch == '}')
            pop();

    }
    if(isEmpty())
        printf("Valid Paranthesis Expression\n");
    else
        printf("InValid Paranthesis Expression\n");

    return 0;

}
