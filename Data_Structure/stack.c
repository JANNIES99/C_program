#include<stdio.h>
int display(int A[],int i){
int j=0;
printf("\n Stack\n");
for(j=0;j<(i+1);j++){
    printf("%d ",A[j]);
}
printf("\n");
}

int push(int A[],int i){
if (i==-1){
    i=0;
}
else{
    i++;
}
printf("Enter a number:");
scanf("%d",&A[i]);
display(A,i);
return i;
}

int pop(int A[],int i){
printf("%d\n",A[i]);
i--;
display(A,i);
return i;
}

int main(){
int Stack[100],n,i=-1,ch;
printf("Enter the length of stack:");
scanf("%d",&n);
while(1){
    printf("\tMENU\n1.Push\n2.Pop\n3.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    if (ch==1){
        if(i==n-1){
            printf("Stack Overflow......\n");
        }
        else{
            i=push(Stack,i);
        }
    }
    else if (ch==2){
        if(i==-1){
            printf("Stack Underflow......\n");
        }
        else{
            i=pop(Stack,i);
        }
    }
    else if (ch==3){
        break;
    }
    else{
        printf("Wrong option.....\n");
    }
}
}
