#include<stdio.h>
struct pr{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
}p[20],temp;
int A[20];

void G(int n){
    int i;
    printf("\n");
    if(p[0].at!=0){
        printf("|\t");
    }
    printf("|%d\t|",p[0].pid);
    for(i=1;i<n;i++){
        if(p[i-1].ct>=p[i].at){
            printf("%d\t|",p[i].pid);
        }
        else{
            printf("\t|%d\t|",p[i].pid);
        }
    }
    printf("\n");

    if(p[0].at!=0){
        printf("0\t");
    }
    printf("%d\t%d",p[0].at,p[0].ct);
    for(i=1;i<n;i++){
        if(p[i-1].ct>=p[i].at){
            printf("\t%d",p[i].ct);
        }
        else{
            printf("\t%d\t%d",p[i].at,p[i].ct);
        }
    }
}


int main (){
    int n,i,j,in,con;
    float stt=0,swt=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the details of Process %d\n",i+1);
        printf("Enter Process ID:");
        scanf("%d",&p[i].pid);
        printf("Enter Arrival Time:");
        scanf("%d",&p[i].at);
        printf("Enter Burst Time:");
        scanf("%d",&p[i].bt);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    
    p[0].ct=p[0].at+p[0].bt;
    p[0].tt=p[0].ct-p[0].at;
    p[0].wt=0;
    for(i=1;i<n;i++){
        if(p[i-1].ct>p[i].at){
            p[i].ct=p[i-1].ct+p[i].bt;
            p[i].tt=p[i].ct-p[i].at;
            p[i].wt=p[i].tt-p[i].bt; 
        }
        else{
            p[i].ct=p[i].at+p[i].bt;
            p[i].tt=p[i].ct-p[i].at;
            p[i].wt=0;
        }
    }

    printf("|PID\t|AT\t|BT\t|CT\t|TT\t|WT\t|\n");
    for(i=0;i<n;i++){
        printf("|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    }

    G(n);
    for(i=0;i<n;i++){
        stt+=p[i].tt;
        swt+=p[i].wt;
    }
    printf("\nThe total Turnaround Time:%f",stt);
    printf("\nThe total Waiting Time:%f",swt);
    printf("\nThe average Turnaround Time:%f",stt/n);
    printf("\nThe average Waiting Time:%f",swt/n);


}