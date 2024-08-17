#include<stdio.h>
#include<stdlib.h>
int P[20][2],S[20][3],p,s,i,j,fl,in,max;

int read(){
    printf("Enter to number of spaces:");
    scanf("%d",&s);
    printf("Enter the spaces(KB):");
    for(i=0;i<s;i++){
        scanf("%d",&S[i][0]);
    }
    printf("Enter to number of process:");
    scanf("%d",&p);
    printf("Enter the process space(KB):");
    for(i=0;i<p;i++){
        scanf("%d",&P[i][0]);
        P[i][1]=i;
    }
}

int display(){
    printf("\nAS\tUS\tPID");
    for(j=0;j<s;j++){
        printf("\n%d\t%d\t%d",S[j][0],S[j][1],S[j][2]);
    }
}

int FF(){
    read();
    for(i=0;i<s;i++){
        S[i][2]=-1;
    }
    for(i=0;i<p;i++){
        fl=0;
        for(j=0;j<s;j++){
            if(S[j][0]>=P[i][0] && S[j][2]==-1){
                S[j][1]=P[i][0];
                S[j][2]=i;
                fl=1;
                break;
            }
        }
        if(fl==0){
            printf("There is no space for a process of %d",P[i][0]);
            break;
        }
    }
    display();
}

int BF(){
    read();
    for(i=0;i<s;i++){
        S[i][2]=-1;
    }
    for(i=0;i<p;i++){
        fl=-1;
        for(j=0;j<s;j++){
            if(fl==-1){
                if((S[j][0]-P[i][0])>=0 && S[j][2]==-1){
                    fl=S[j][0]-P[i][0];
                    in=j;
                }
            }
            else{
                if((S[j][0]-P[i][0])<fl && S[j][2]==-1){
                    fl=S[j][0]-P[i][0];
                    in=j;
                }
            }
        }
        if(fl==-1){
            printf("There is no space for a process of %d",P[i][0]);
            break;
        }
        else{
            S[in][1]=P[i][0];
            S[in][2]=i;
        }
    }
    display();
}

int WF(){
    read();
    for(i=0;i<s;i++){
        S[i][2]=-1;
    }
    for(i=0;i<p;i++){
        fl=-1;
        in=0;
        for(j=0;j<s;j++){
            if(S[in][2]!=-1){
                in++;
            }
            if(S[in][0]<S[j][0] && S[j][2]==-1){
                in=j;
            }
        }
        if(P[i][0]<S[in][0] && S[in][2]==-1){
            S[in][1]=P[i][0];
            S[in][2]=i;
        }
        else{
            printf("There is no space for a process of %d",P[i][0]);
            break;
        }
    }
    display();
}

int main(){
    int ch;
    while(1){
        printf("\nMenu\n1.First Fit\n2.Best Fit\n3.Worst Fit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            FF();
            break;
            case 2:
            BF();
            break;
            case 3:
            WF();
            break;
            case 4:
            exit(0);
        }
    }
}