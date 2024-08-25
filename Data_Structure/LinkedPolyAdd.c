#include<stdio.h>
typedef struct nod{
    int coof;
    int exp;
    struct nod *next;
}node;
node *head1=NULL;
node *head2=NULL;
node *head3=NULL;

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

node* polyadd(node* head1,node* head2,node* head3){
    node *temp1,*temp2,*temp3,*New;
    temp1=head1;
    temp2=head2;
    if(temp1->exp==temp2->exp){
        New=(node*)malloc(sizeof(node));
        New->exp=temp1->exp;
        New->coof=(temp1->coof+temp2->coof);
        New->next=NULL;
        head3=New;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    else if(temp1->exp>temp2->exp){
        New=(node*)malloc(sizeof(node));
        New->exp=temp1->exp;
        New->coof=temp1->coof;
        New->next=NULL;
        head3=New;
        temp1=temp1->next;
    }
    else{
        New=(node*)malloc(sizeof(node));
        New->exp=temp2->exp;
        New->coof=temp2->coof;
        New->next=NULL;
        head3=New;
        temp2=temp2->next;
    }
    temp3=head3;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            New=(node*)malloc(sizeof(node));
            New->exp=temp1->exp;
            New->coof=temp1->coof+temp2->coof;
            New->next=NULL;
            temp3->next=New;
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        else if(temp1->exp>temp2->exp){
            New=(node*)malloc(sizeof(node));
            New->exp=temp1->exp;
            New->coof=temp1->coof;
            New->next=NULL;
            temp3->next=New;
            temp1=temp1->next;
            temp3=temp3->next;
        }
        else{
            New=(node*)malloc(sizeof(node));
            New->exp=temp2->exp;
            New->coof=temp2->coof;
            New->next=NULL;
            temp3->next=New;
            temp2=temp2->next;
            temp3=temp3->next;
        }
    }
    while(temp1!=NULL){
        New=(node*)malloc(sizeof(node));
        New->exp=temp1->exp;
        New->coof=temp1->coof;
        New->next=NULL;
        temp3->next=New;
        temp1=temp1->next;
        temp3=temp3->next;
    }
    while(temp2!=NULL){
        New=(node*)malloc(sizeof(node));
        New->exp=temp2->exp;
        New->coof=temp2->coof;
        New->next=NULL;
        temp3->next=New;
        temp2=temp2->next;
        temp3=temp3->next;
    }
    return head3;
}

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
    head3=polyadd(head1,head2,head3);

    display(head3);
}
