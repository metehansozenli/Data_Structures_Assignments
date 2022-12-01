#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define size 50

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
    for(int i=s.top;i>-1;i--)
        printf("%c\n",s.data[i]);
}

bool balanced(char p[],int s1){
    int i=0;
    while(p[i]!='\0'){
        if(p[i] == '(' || p[i] == '{')
            push(p[i]);
        else{
            if(s.top==-1)
                return false;
            else if(s.data[s.top] == '(' && p[i] == ')' || s.data[s.top] == '{' && p[i] == '}')
                pop();
            else
                return false;
        }
        i++;
    }
    if(s.top==-1)
        return true;
    else
        return false;
}

int main()
{
    s.top=-1;
    char p[size]="{({{()}})}";

    if(balanced(p,strlen(p)))
        printf("Balanced!\n");
    else
        printf("Unbalanced!\n");

    return 0;
}
