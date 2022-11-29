#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define size 11

typedef struct{
    char data[size];
    int top;
}stack;

stack s;

void push(char data){
    if(s.top==(size-1))
        printf("Stack is Full!!\n");
    else
        s.data[++s.top]=data;
}

void pop(){
    if(s.top==-1)
        printf("Stack is Empty!!\n");
    else
        s.top--;
}

void display(){
    for(int i=strlen(s.data)-1;i>-1;i--)
        printf("%c\n",s.data[i]);
}

bool balanced(char p[],int s1){
    for(int i=0;i<s1;i++){
        if(p[i] == '(' || p[i] == '{')
            push(p[i]);
        else{
            if(s.top==-1)
                return false;
            else if(p[i] == ')' || p[i] == '}')
                pop();
        }
    }
    if(s.top==-1)
        return true;
    else
        return false;
}

int main()
{
    s.top=-1;
    char p[size]="{(({{()}}))}";

    if(balanced(p,strlen(p)))
        printf("Balanced!\n");
    else
        printf("Unbalanced!\n");
    return 0;
}
