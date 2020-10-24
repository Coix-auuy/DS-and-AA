//
// Created by auuy on 2019/9/28.
//

#ifndef SQSTACK_SQSTACK_H
#define SQSTACK_SQSTACK_H

#endif //SQSTACK_SQSTACK_H
#include<stdlib.h>
#include<stdio.h>
typedef char ElemType;
#define MaxSize 100
typedef struct {
    ElemType  data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack *&s) {
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
}
void DestroyStack(SqStack *&s) {
    free(s);
}
bool StackEmpty(SqStack *s) {
    return s->top == -1;
}
bool Push(SqStack *&s, ElemType e) {
    if(s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(SqStack *&s, ElemType &e) {
    if(s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s, ElemType &e) {
    if(s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}
