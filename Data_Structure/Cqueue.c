#include<stdio.h>
int Front=-1,Rear=-1,CQ[],n;

int display(){
    int i=Front;
    int max=Rear;
    while(i!=max){
        printf("%d ",CQ[i]);
        i=(i+1)%n;
    }
    if(Front!=-1){
        printf("%d \n",CQ[i]);
    }
}


int CInsert(){
    int Location;
    Location=(Rear+1)%n;
    if (Front==Location){
        printf("CQueue is full.......\n");
    }
    else{
        Rear=Location;
        printf("Enter a number:");
        scanf("%d",&CQ[Rear]);
        if(Front==-1){
            Front=0;
        }
    }

}

int CDelete(){
    if (Front==-1){
        printf("CQueue is empty.....\n");
    }
    else{
        printf("%d \n",CQ[Front]);
        if (Front==Rear){
            Front=-1;
            Rear=-1;
        }
        else if(Front==n-1){
            Front=0;
        }
        else{
            Front=Front+1;
        }
    }

}


int main(){
    int ch;
    printf("Enter the length of queue:");
    scanf("%d",&n);
    while(1){
        printf("Menu\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter a choice:");
        scanf("%d",&ch);
        switch (ch){
        case (1):
            {
                CInsert();
                break;
            }
        case (2):
            {
                CDelete();
                break;
            }
        case(3):
            {
                display();
                break;
            }
        case(4):
            {
                exit(0);
            }
        default:
            {
                printf("Wrong Option.........\n");
            }

        }
    }
}
