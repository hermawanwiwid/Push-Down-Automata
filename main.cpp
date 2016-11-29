#include "pushdownautomata.h"
#include <iostream>

using namespace std;

int main()
{
    string masukkan;
    string token[100];
    int counter [100];
    int i,j,k;
    bool check;

    cout << "#### TUGAS BESAR TEORI BAHASA DAN AUTOMATA ####"<<endl
         << "       #### KELOMPOK 10 ####\n"<<endl;


    cout<<"Masukkan : ";
    getline(cin,masukkan);
    j = masukkan.length();
    check=true;
    k=0;
    i=0;

    while ( i <= j && masukkan[i]!='\0' && check ) {
        while (masukkan[i] == ' ' && check) {
            i++;
        }
        if (masukkan[i] == 'p' || masukkan[i] == 'q' || masukkan[i] == 'r' || masukkan[i] == 's') {
            i++;
            if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                k++;
                token[k] = '1';
            } else {
                check = false;
            }

        } else if (masukkan[i] == 'n') {
            i++;
            if (masukkan[i] == 'o') {
                i++;
                if (masukkan[i] == 't') {
                    i++;
                    if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                        k++;
                        token[k] = '2';
                    } else {
                        check = false;
                    }
                } else {
                    check = false;
                }
            } else {
                check = false;
            }

        } else if (masukkan[i] == 'a') {
            i++;
            if (masukkan[i] == 'n') {
                i++;
                if (masukkan[i] == 'd') {
                    i++;
                    if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                        k++;
                        token[k] = '3';
                    } else {
                        check = false;
                    }
                } else {
                    check = false;
                }
            } else {
                check = false;
            }

        } else if (masukkan[i] == 'o') {
            i++;
            if (masukkan[i] == 'r') {
                i++;
                if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                    k++;
                    token[k] = '4';
                } else {
                    check = false;
                }
            } else {
                check = false;
            }

        } else if (masukkan[i] == 'x') {
            i++;
            if (masukkan[i] == 'o') {
                i++;
                if (masukkan[i] == 'r') {
                    i++;
                    if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                        k++;
                        token[k] = '5';
                    } else {
                        check = false;
                    }
                } else {
                    check = false;
                }
            } else {
                check = false;
            }

        } else if (masukkan[i] == 'i') {
            i++;
            if (masukkan[i] == 'f') {
                i++;
                if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                    k++;
                    token[k] = '6';
                } else if (masukkan[i] == 'f') {
                    i++;
                    if (masukkan[i] != ' ' || masukkan[i] != '\0') {
                        k++;
                        token[k] = '8';
                    }
                } else {
                    check = false;
                }
            } else {
                check = false;
            }

        } else if (masukkan[i] == 't') {
            i++;
            if (masukkan[i] == 'h') {
                i++;
                if (masukkan[i] == 'e') {
                    i++;
                    if (masukkan[i] == 'n') {
                        i++;
                        if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                            k++;
                            token[k] = '7';
                        }
                    } else {
                        check = false;
                    }
                } else {
                    check = false;
                }
            } else {
                check = false;
            }

        } else if (masukkan[i] == '(') {
            i++;
            if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                k++;
                token[k] = '9';
            } else {
                check = false;
            }

        } else if (masukkan[i] == ')') {
            i++;
            if (masukkan[i] == ' ' || masukkan[i] == '\0') {
                k++;
                token[k] = "10";
            } else {
                check = false;
            }
        } else {
            check = false;
        }
        if (check == false) {
            while (masukkan[i] != ' ' && masukkan[i] != '\0') {
                i++;
            }
            k++; //token
            token[k] = "error";
        }
    }
    cout<<"Keluaran : ";
    for(i=1; i<=k; i++)
    {
        cout<<token[i]<<" ";
    }


    Stack S;
    bool checktoken;
    createstack(S);
    push(S, "#");
    i=1;
    checktoken =true;

    while (token[i] != "" && checktoken) {
        if (token[i] == "1" &&(S.info[top(S)]=="Z" || S.info[top(S)]=="A"  ||S.info[top(S)]=="#" || S.info[top(S)]=="W" || S.info[top(S)]=="B" || S.info[top(S)] == "Y") ) {
            if (S.info[top(S)]=="Z" || S.info[top(S)]=="A" || S.info[top(S)]=="B") {
                pop(S);
                push(S, "X");
            }
            else if (S.info[top(S)]=="#" || S.info[top(S)]=="W" || S.info[top(S)] == "Y") {
                push(S,"X");
            }
            else {
                checktoken=false;
            }
        }
        else if(token[i] == "2" && (S.info[top(S)]=="#" || S.info[top(S)] == "Y" || S.info[top(S)] == "B" || S.info[top(S)] == "A")) {
            if (S.info[top(S)] == "B" || S.info[top(S)] == "A") {
                pop(S);
                push(S, "Z");
            }
            else if (S.info[top(S)]=="#" || S.info[top(S)] == "Y")
                push(S, "Z");
        }
        else if(token[i] == "6" && (S.info[top(S)]=="Y" || S.info[top(S)]=="#" || S.info[top(S)]=="Y")) {
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
            checktoken=false;
        }

        cout<<endl;
        printinfo(S);
        cout<<endl;
        i++;
    }
    if (S.info[top(S)]=="X" || S.info[top(S)]=="C")
        pop(S);
    pop(S);
    if (top(S)==-1&& checktoken)
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