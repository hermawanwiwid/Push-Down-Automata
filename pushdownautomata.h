//
// Created by Mobile Innovation 3 on 30/11/2016.
//

#ifndef PUSH_DOWN_AUTOMATA_VERSI_2_PUSHDOWNAUTOMATA_H
#define PUSH_DOWN_AUTOMATA_VERSI_2_PUSHDOWNAUTOMATA_H

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

#endif //PUSH_DOWN_AUTOMATA_VERSI_2_PUSHDOWNAUTOMATA_H
