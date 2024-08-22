#include<stdio.h>
char infix[100],stack[100],postfix[100];
int n,s=-1,j=0;
int push(char ch){
if (s==-1){
    s=0;
}
else{
    s++;
}
stack[s]=ch;
}

int pop(){
postfix[j]=stack[s];
s--;
j++;
}

int main(){
char chr;
int i;
printf("Enter the Infix expression:");
scanf("%s",infix);
for(n=0;infix[n]!='\0';n++);
for(i=0;i<n;i++){
    chr=infix[i];
    if(chr=='+'||chr=='-'||chr=='*'||chr=='/'||chr=='^'||chr=='('||chr==')'){
        if(s==-1){
            push(chr);
        }
        else if(chr=='('){
            push(chr);
        }
        else if(chr==')'){
            while(stack[s]!='(' && s!=-1){
                  pop();
            }
            if(s!=-1){
                s--;
            }
        }
        else if(chr=='^'){
            while(stack[s]=='^'){
                pop();
            }
            push(chr);
        }
        else if(chr=='/'){
            while(stack[s]=='^'||stack[s]=='/'){
                pop();
            }
            push(chr);
        }
        else if(chr=='*'){
            while(stack[s]=='^'||stack[s]=='/'||stack[s]=='*'){
                pop();
            }
            push(chr);
        }
        else if(chr=='+'){
            while(stack[s]=='^'||stack[s]=='/'||stack[s]=='*'||stack[s]=='+'){
                pop();
            }
            push(chr);
        }
        else if(chr=='-'){
            while(stack[s]=='^'||stack[s]=='/'||stack[s]=='*'||stack[s]=='+'||stack[s]=='-'){
                pop();
            }
            push(chr);
        }
        }
        else{
            postfix[j]=chr;
            j++;
        }
    }
    while(s>=0){
        if(stack[s]!='('){
            pop();
        }
        else{
            s--;
        }
    }
printf("\n%s\n",postfix);
}


