#include<stdio.h>
int read(int P1[][2],int n){
int A[100],temp,i,j;
printf("Enter the exponents:");
for (i=0;i<n;i++){
    scanf("%d",&A[i]);
}
for (i=0;i<n;i++){
    for (j=0;j<n-1-i;j++){
        if(A[j+1]>A[j]){
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
        }
    }
}
for (i=0;i<n;i++){
    printf("Enter the cooifient of %d:", A[i]);
    scanf("%d",&P1[i][0]);
    P1[i][1]=A[i];
}
}

int polyadd(int P1[][2],int P2[][2],int P3[][2],int n,int q){
int i=0,j=0,k=0;
while(i<n && j<q){
    if(P1[i][1]==P2[j][1]){
        P3[k][0]=P1[i][0]+P2[j][0];
        P3[k][1]=P1[i][1];
        i++;
        j++;
        k++;
    }
    else if(P1[i][1]>P2[j][1]){
        P3[k][0]=P1[i][0];
        P3[k][1]=P1[i][1];
        i++;
        k++;
    }
    else{
        P3[k][0]=P2[j][0];
        P3[k][1]=P2[j][1];
        j++;
        k++;
    }
}
while(i<n){
    P3[k][0]=P1[i][0];
    P3[k][1]=P1[i][1];
    i++;
    k++;
}
while(j<q){
    P3[k][0]=P2[j][0];
    P3[k][1]=P2[j][1];
    j++;
    k++;
}
return k;
}

int main(){
int P1[100][2],P2[100][2],P3[100][2],n,q,r,i;
printf("Enter the number of element of poly1:");
scanf("%d",&n);
read(P1,n);
printf("Enter the number of element of poly2:");
scanf("%d",&q);
read(P2,q);
r=polyadd(P1,P2,P3,n,q);
printf("%dx^%d",P3[0][0],P3[0][1]);
for(i=1;i<r;i++){
    printf(" + %dx^%d",P3[i][0],P3[i][1]);
}
}
