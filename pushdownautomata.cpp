//
// Created by Mobile Innovation 3 on 30/11/2016.
//

#include "pushdownautomata.h"


void createstack(Stack &s)
{
    top(s)= -1;
}

void push (Stack &s, infotype x)
{
    if(top(s)!=19)
    {
        top(s)++;
        s.info[top(s)]=x;
    }
}

infotype pop(Stack &s)
{
    if(top(s)>=0)
    {
        string x = s.info[top(s)];
        top(s)--;
        return x;
    }
}

void printinfo (Stack &s)
{
    if (top(s)== -1)
    {
        cout<<"Kosong";
    }
    else
    {
        for(int i = top(s); i >= 0; i--)
        {
            cout<<s.info[i]<<" ";
        }
    }
}

