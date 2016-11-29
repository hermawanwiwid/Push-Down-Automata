#include <iostream>
#include "tba2.h"

using namespace std;

string input;
string token[100];
int i,k,b;
bool cek;

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
    if (top(s)==-1)
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

void moveForward()
{
    while(input[i]!=' ' && input[i]!='\0')
    {
        i++;
    }
}

int main()
{
    cout<<"Input : ";
    getline(cin,input);
    k = input.length();
    cek=true;
    b=0;
    i=0;
    while ( i <= k && input[i]!='\0' && cek )
    {
        while(input[i]==' ' && cek)
        {
            i++;
        }
        if (input[i]=='p'|| input[i]=='q' || input[i]=='r' || input[i]=='s')
        {
            i++;
            if(input[i]==' '|| input[i]=='\0')
            {
                b++;
                token[b]='1';
            }
            else
            {
                cek = false;
            }
        }
        else if (input[i]=='n')
        {
            i++;
            if (input[i]=='o')
            {
                i++;
                if (input[i]=='t')
                {
                    i++;
                    if(input[i]==' '|| input[i]=='\0')
                    {
                        b++;
                        token[b]='2';
                    }
                    else
                    {
                        cek = false;
                    }
                }
                else
                {
                    cek = false;
                }
            }
            else
            {
                cek = false;
            }
        }
        else if (input[i]=='a')
        {
            i++;
            if (input[i]=='n')
            {
                i++;
                if (input[i]=='d')
                {
                    i++;
                    if(input[i]==' '|| input[i]=='\0')
                    {
                        b++;
                        token[b]='3';
                    }
                    else
                    {
                        cek = false;
                    }
                }
                else
                {
                    cek=false;
                }
            }
            else
            {
                cek = false;
            }
        }
        else if (input[i]=='o')
        {
            i++;
            if (input[i]=='r')
            {
                i++;
                if(input[i]==' '|| input[i]=='\0')
                {
                    b++;
                    token[b]='4';
                }
                else
                {
                    cek=false;
                }
            }
            else
            {
                cek=false;
            }
        }
        else if (input[i]=='x')
        {
            i++;
            if (input[i]=='o')
            {
                i++;
                if (input[i]=='r')
                {
                    i++;
                    if(input[i]==' '|| input[i]=='\0')
                    {
                        b++;
                        token[b]='5';
                    }
                    else
                    {
                        cek=false;
                    }
                }
                else
                {
                    cek=false;
                }
            }
            else
            {
                cek=false;
            }
        }
        else if (input[i]=='i')
        {
            i++;
            if (input[i]=='f')
            {
                i++;
                if(input[i]==' '|| input[i]=='\0')
                {
                    b++;
                    token[b]='6';
                }
                else if(input[i]=='f')
                {
                    i++;
                    if(input[i]!=' '|| input[i]!='\0')
                    {
                        b++;
                        token[b]='8';
                    }
                }
                else
                {
                    cek=false;
                }
            }
            else
            {
                cek=false;
            }
        }
        else if (input[i]=='t')
        {
            i++;
            if (input[i]=='h')
            {
                i++;
                if (input[i]=='e')
                {
                    i++;
                    if (input[i]=='n')
                    {
                        i++;
                        if(input[i]==' '|| input[i]=='\0')
                        {
                            b++;
                            token[b]='7';
                        }
                    }
                    else
                    {
                        cek=false;
                    }
                }
                else
                {
                    cek=false;
                }
            }
            else
            {
                cek=false;
            }
        }
        else if (input[i]=='(')
        {
            i++;
            if(input[i]==' '|| input[i]=='\0')
            {
                b++;
                token[b]='9';
            }
            else
            {
                cek=false;
            }
        }
        else if (input[i]==')')
        {
            i++;
            if(input[i]==' '|| input[i]=='\0')
            {
                b++;
                token[b] = "10";
            }
            else
            {
                cek=false;
            }
        }
        else
        {
            cek=false;
        }
        if (cek == false)
        {
            moveForward();
            b++;
            token[b]="error";
            //cout<<"ini"<<endl;
            // cek = true;
        }
    }
    cout<<"Output : ";
    for(i=1; i<=b; i++)
    {
        cout<<token[i]<<" ";
    }
    Stack S;
    bool cek2;
    createstack(S);
    push(S, "#");
    i=1;
    cek2 =true;
    while (token[i] != "" && cek2)
    {
        if (token[i] == "1" &&(S.info[top(S)]=="Z" || S.info[top(S)]=="A"  ||S.info[top(S)]=="#" || S.info[top(S)]=="W" || S.info[top(S)]=="B" || S.info[top(S)] == "Y") )
        {
            if (S.info[top(S)]=="Z" || S.info[top(S)]=="A" || S.info[top(S)]=="B")
            {
                pop(S);
                push(S, "X");
            }
            else if (S.info[top(S)]=="#" || S.info[top(S)]=="W" || S.info[top(S)] == "Y")
            {
                push(S,"X");
            }
            else
            {
                cek2=false;
            }
        }
        else if(token[i] == "2" && (S.info[top(S)]=="#" || S.info[top(S)] == "Y" || S.info[top(S)] == "B" || S.info[top(S)] == "A"))
        {
            if (S.info[top(S)] == "B" || S.info[top(S)] == "A")
            {
                pop(S);
                push(S, "Z");
            }
            else if (S.info[top(S)]=="#" || S.info[top(S)] == "Y")
                push(S, "Z");
        }
        else if(token[i] == "6" && (S.info[top(S)]=="Y" || S.info[top(S)]=="#" || S.info[top(S)]=="Y"))
        {
            if (token[i]=="6")
                push(S,"W");
        }
        else if((token[i] == "3" || token[i] == "4" || token[i] == "5" || token[i] == "8" )&& (S.info[top(S)] == "C"||S.info[top(S)] == "X" ))
        {
            pop(S);
            push(S, "A");
        }
        else if(token[i] == "7" && (S.info[top(S)]=="X" || S.info[top(S)] == "C"))
        {
            if (S.info[top(S)] == "X" || S.info[top(S)] == "C")
            {
                pop(S);
                if (S.info[top(S)] == "W")
                {
                    pop(S);
                    push(S, "B");
                }
            }
        }
        else if(token[i] == "9" && (S.info[top(S)] == "X" ||S.info[top(S)] == "#" || S.info[top(S)] == "W" || S.info[top(S)] == "Y" || S.info[top(S)] == "A" || S.info[top(S)] == "Z" || S.info[top(S)] == "B"))
        {
            if (S.info[top(S)] == "A" || S.info[top(S)] == "Z" || S.info[top(S)] == "B")
            {
                pop(S);
                push(S, "Y");
            }
            else if ((S.info[top(S)] == "X" ||S.info[top(S)] == "#" || S.info[top(S)] == "W" || S.info[top(S)] == "Y"))
            {
                push(S, "Y");
            }
        }
        else if(token[i] == "10" && (S.info[top(S)] == "X" || S.info[top(S)] == "C"))
        {
            if (S.info[top(S)] == "X" || S.info[top(S)] == "C")
            {
                pop(S);
                if (S.info[top(S)] == "Y")
                {
                    pop(S);
                    push(S, "C");
                }
            }
        }
        else
        {
            cek2=false;
        }

        cout<<endl;
        printinfo(S);
        cout<<endl;
        i++;
    }
    if (S.info[top(S)]=="X" || S.info[top(S)]=="C")
        pop(S);
    pop(S);
    if (top(S)==-1&& cek2)
    {
        cout<<"valid";
    }
    else
    {
        cout<<"not valid";
    }
    cout<<endl;

    return 0;
}
