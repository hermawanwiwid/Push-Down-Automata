#ifndef TBA2_H_INCLUDED
#define TBA2_H_INCLUDED
#include <iostream>
#define top(S) S.top

using namespace std;

typedef string infotype;
struct Stack{
    infotype info[20];
    int top;
};

void createstack(Stack &S);
void push (Stack &S, infotype x);
infotype pop(Stack &S);
void printinfo(Stack &S);
void movefoward();


#endif // TBA2_H_INCLUDED
