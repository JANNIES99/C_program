#include<stdio.h>
#include<stdlib.h>
int DQE[100],Front=-1,Rear=-1,n;

int display(){
    int i=Front;
    while(i!=Rear){
        printf("%d ",DQE[i]);
        i=(i+1)%n;
    }
    if(Front!=-1){
        printf("%d \n",DQE[i]);
    }
    else{
        printf("Queue is Empty........\n");
    }
}

int InsertAtF(){
    if (Front==((Rear+1)%n)){
        printf("Queue is Full........\n");
    }
    else{
        if(Front==-1){
            Front=n-1;
            Rear=n-1;
        }
        else if(Front==0){
            Front=n-1;
        }
        else{
            Front=Front-1;
        }
        printf("Enter a Number:");
        scanf("%d",&DQE[Front]);
    }
}

int InsertAtR(){
    int Location;
    Location=(Rear+1)%n;
    if (Front==Location){
        printf("Queue is full.......\n");
    }
    else{
        Rear=Location;
        printf("Enter a number:");
        scanf("%d",&DQE[Rear]);
        if(Front==-1){
            Front=0;
        }
    }

}

int DeleteAtF(){
    if (Front==-1){
        printf("Queue is empty.....\n");
    }
    else{
        printf("%d \n",DQE[Front]);
        if (Front==Rear){
            Front=-1;
            Rear=-1;
        }
        else{
            Front=(Front+1)%n;
        }
    }
}

int DeleteAtR(){
    if (Front==-1){
        printf("Queue is empty.....\n");
    }
    else{
        printf("%d \n",DQE[Rear]);
        if (Front==Rear){
            Front=-1;
            Rear=-1;
        }
        else if(Rear==0){
            Rear=n-1;
        }
        else{
            Rear=Rear-1;
        }
    }
}



int main(){
    int ch,ch1;
    printf("Enter the length of queue:");
    scanf("%d",&n);
    printf("Menu\n1.Insertion at Front and Rear\n2.Deletion at Front and Rear\n");
    printf("Enter a choice:");
    scanf("%d",&ch);
    while(ch==1){
        printf("Menu\n1.Insertion at Front\n2.Insertion at Rear\n3.Deletion\n4.Display\n5.Exit\n");
        printf("Enter a choice:");
        scanf("%d",&ch1);
        switch (ch1){
        case (1):
            {
                InsertAtF();
                break;
            }
        case (2):
            {
                InsertAtR();
                break;
            }
        case (3):
            {
                DeleteAtF();
                break;
            }
        case (4):
            {
                display();
                break;
            }
        case(5):
            {
                exit(0);
            }
        default:
            {
                printf("Wrong Option.........\n");
            }

        }

    }
    while(ch==2){
        printf("Menu\n1.Insertion\n2.Deletion at Front\n3.Deletion at Rear\n4.Display\n5.Exit\n");
        printf("Enter a choice:");
        scanf("%d",&ch1);
        switch (ch1){
        case (1):
            {
                InsertAtR();
                break;
            }
        case (2):
            {
                DeleteAtF();
                break;
            }
        case (3):
            {
                DeleteAtR();
                break;
            }
        case (4):
            {
                display();
                break;
            }
        case(5):
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
