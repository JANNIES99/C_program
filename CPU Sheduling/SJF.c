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

    temp=p[0];
    in=0;
    for(j=1;j<n;j++){
        if(temp.at>p[j].at){
            temp=p[j];
            in=j;
        }
        else if(temp.at==p[j].at){
            if(temp.bt>p[j].bt){
                temp=p[j];
                in=j;
            }
        }
    }
    temp=p[0];
    p[0]=p[in];
    p[in]=temp;
    p[0].ct=p[0].at+p[0].bt;

    for(i=1;i<n;i++){
        con=0;
        A[0]=0;
        for(j=i;j<n;j++){
            if(p[i-1].ct>=p[j].at){
                A[con]=j;
                con++;
            }
        }
        if(A[0]==0){
            temp=p[i];
            in=i;
            for(j=i+1;j<n;j++){
                if(temp.at>p[j].at){
                    temp=p[j];
                    in=j;
                }
                else if(temp.at==p[j].at){
                    if(temp.bt>p[j].bt){
                        temp=p[j];
                        in=j;
                    }
                }
            }
            temp=p[i];
            p[i]=p[in];
            p[in]=temp;
            p[i].ct=p[i].at+p[i].bt;    
            
        }
        else{
            in=A[0];
            for(j=1;j<con;j++){
                if(p[in].bt>p[A[j]].bt){
                    in=A[j];
                }
            }
            temp=p[i];
            p[i]=p[in];
            p[in]=temp;
            p[i].ct=p[i-1].ct+p[i].bt;
        }

    }    
    
    for(i=0;i<n;i++){
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
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
