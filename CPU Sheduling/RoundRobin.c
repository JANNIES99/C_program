#include<stdio.h>
struct pr{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
}p[20],q[20],temp;
int qt;

void G(int n){
    printf("\nGantt Chart\n");
    int i,co=1,r,rear=0,tim=p[0].at;
    for(i=0;i<=n+1;i++){
        q[i].pid=-1;
    }
    printf("\n");
    if(p[0].at!=0){
        printf("|\t");
    }
    q[0]=p[0];


    while(1){
        if(q[0].pid==-1){
            if(co<n){
                printf("|\t");
                q[0]=p[co];
                tim=p[co].at;
                rear=0;
                co++;
            }
            else{
                printf("|");
                break;
            }
        }
        else{
            printf("|  P%d\t",q[0].pid);
            if(q[0].bt<=qt){
                tim+=q[0].bt;
                for(i=0;i<n;i++){
                    if(p[i].pid==q[0].pid){
                        p[i].ct=tim;
                    }
                }
                r=co;
                for(i=r;i<n;i++){
                    if(tim>=p[i].at){
                        rear++;
                        co++;
                        q[rear]=p[i];
                    }
                    else
                        break;
                }
                for(i=0;i<=rear;i++){
                    q[i]=q[i+1];
                }
                rear--;
            }
            else{
                tim=tim+qt;
                q[0].bt-=qt;
                r=co;
                for(i=r;i<n;i++){
                    if(tim>=p[i].at){
                        rear++;
                        co++;
                        q[rear]=p[i];
                    }
                    else
                        break;
                }
                q[rear+1]=q[0];
                for(i=0;i<=rear+1;i++){
                    q[i]=q[i+1];
                }
            }
            
        }
    }

    
    printf("\n");


    for(i=0;i<=n;i++){
        q[i].pid=-1;
    }
    if(p[0].at!=0){
        printf("0\t");
    }
    q[0]=p[0];
    tim=q[0].at;
    co=1;
    
    rear=0;
    while(1){
        if(q[0].pid==-1){
            if(co<n){
                printf("%d\t",tim);
                q[0]=p[co];
                tim=p[co].at;
                rear++;
                co++;
            }
            else{
                printf("%d",tim);
                break;
            }
        }
        else{
            printf("%d\t",tim);
            if(q[0].bt<=qt){
                tim+=q[0].bt;
                r=co;
                for(i=r;i<n;i++){
                    if(tim>=p[i].at){
                        rear++;
                        co++;
                        q[rear]=p[i];
                    }
                    else
                        break;
                }
                for(i=0;i<=rear+1;i++){
                    q[i]=q[i+1];
                }
                q[rear].pid=-1;
                rear--;
            }
            else{
                tim=tim+qt;
                q[0].bt-=qt;
                r=co;
                for(i=r;i<n;i++){
                    if(tim>=p[i].at){
                        rear++;
                        co++;
                        q[rear]=p[i];
                    }
                    else
                        break;
                }
                q[rear+1]=q[0];
                for(i=0;i<=rear+1;i++){
                    q[i]=q[i+1];
                }
                q[rear+1].pid=-1;
            }
            r=co;
        }
    }
    printf("\n");
}


int main (){
    int n,i,j,in,con;
    float stt=0,swt=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the quntunm time:");
    scanf("%d",&qt);
    for(i=0;i<n;i++){
        printf("Enter the details of Process %d\n",i+1);
        p[i].pid=i+1;
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

    G(n);

    for(i=0;i<n;i++){
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt; 
    }

    printf("\n TABLE \n");
    printf("_____________________________________________________________________________\n");
    printf("| pid | Arrivaltime | BurstTime | CompletionTime | TurnaroudTime | WaitTime |\n");
    printf("-----------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    printf("| %2d  |     %2d      |     %2d    |       %2d       |       %2d      |     %2d   |\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    printf("-----------------------------------------------------------------------------\n");

    for(i=0;i<n;i++){
        stt+=p[i].tt;
        swt+=p[i].wt;
    }
    printf("\nThe total Turnaround Time:%f",stt);
    printf("\nThe total Waiting Time:%f",swt);
    printf("\nThe average Turnaround Time:%f",stt/n);
    printf("\nThe average Waiting Time:%f",swt/n);


}