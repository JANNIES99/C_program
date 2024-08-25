#include<stdio.h>
typedef struct nod{
    int coof;
    int exp;
    struct nod *next;
}node;
node *head1=NULL;
node *head2=NULL;
node *head3=NULL;

node* insert(node *head){
    node *New;
    New=(node*)malloc(sizeof(node));
    New->next=NULL;
    printf("Enter a number and its exponent:");
    scanf("%d %d",&(New->coof),&(New->exp));
    if (head==NULL){
        head=New;
    }
    else{
        New->next=head;
        head=New;
    }
    return head;
}

node* sort(node *head){
    node *temp1;
    node *temp2;
    node *pev;
    int n=0,i,j;
    temp1=head;
    while(temp1!=NULL){
        temp1=temp1->next;
        n++;
    }
    if(n>1){
        for(i=0;i<n;i++){
            temp1=head->next;
            if((head->exp)<(temp1->exp)){
                head->next=temp1->next;
                temp1->next=head;
                head=temp1;
                temp1=temp1->next;
            }
            pev=head;
            temp1=head->next;
            temp2=temp1->next;
            for(j=1;j<n-1-i;j++){
                if((temp1->exp)<(temp2->exp)){
                    temp1->next=temp2->next;
                    temp2->next=temp1;
                    pev->next=temp2;
                }
                pev=pev->next;
                temp1=pev->next;
                temp2=temp1->next;
            }
        }
    }
    return(head);
}

int display(node *head){
    if (head==NULL){
        printf("List is empty");
    }
    else{
        node *temp;
        temp=head;
        printf("%dx^%d",temp->coof,temp->exp);
        temp=temp->next;
        while(temp!=NULL){
            printf(" +%dx^%d",temp->coof,temp->exp);
            temp=temp->next;
        }
    }
}


node* polymult(node *head1,node *head2,node *head3){
    node *temp1,*temp2,*temp3,*New,*pev;
    temp1=head1;
    temp2=head2;
    int pow;
    if(temp1!=NULL && temp2!=NULL){
        New=(node*)malloc(sizeof(node));
        New->coof=((temp1->coof)*(temp2->coof));
        New->exp=(temp1->exp+temp2->exp);
        New->next=NULL;
        head3=New;
    }
    temp3=head3;
    temp2=temp2->next;
    while(temp1!=NULL){
        while(temp2!=NULL){
            pow=temp1->exp+temp2->exp;
            while(temp3!=NULL){
                if(temp3->exp==pow){
                    temp3->coof=temp3->coof+((temp1->coof)*(temp2->coof));
                    break;
                }
                else if(pow>temp3->exp){
                    New=(node*)malloc(sizeof(node));
                    New->coof=((temp1->coof)*(temp2->coof));
                    New->exp=pow;
                    pev->next=New;
                    New->next=temp3;
                    break;
                }
                pev=temp3;
                temp3=temp3->next;

            }
            if(temp3==NULL){
                New=(node*)malloc(sizeof(node));
                New->coof=((temp1->coof)*(temp2->coof));
                New->exp=pow;
                pev->next=New;
                New->next=NULL;
            }
            temp3=head3;
            temp2=temp2->next;
        }
        temp2=head2;
        temp1=temp1->next;
    }
    return head3;
}



int main(){
    int n,i;
    printf("Enter the no of elements for first poly:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head1=insert(head1);
    }
    head1=sort(head1);
    printf("Enter the no of elements for second poly:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head2=insert(head2);
    }
    head2=sort(head2);
    head3=polymult(head1,head2,head3);

    display(head3);
}
