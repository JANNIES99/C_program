#include<stdio.h>
#include<stdlib.h>
int Q[20],Seq[20],n,head,hp,hm,ch,i,j,temp,Max;

void display(int n){
	printf("Se2quence\n%d",head);
	for(i=0;i<n;i++){
		printf("->%d",Seq[i]);
	}
}
// fcfs
void FCFS(){
	printf("Enter the no of tracks:");
	scanf("%d",&n);
	printf("Enter the head pointer:"); 
	scanf("%d",&head);
	printf("Enter the traces:");
	for(i=0;i<n;i++){
		scanf("%d",&Q[i]);
	}
	hm=0;
	hp=head;
	for(i=0;i<n;i++){
	hm+=abs(hp-Q[i]);
	hp=Q[i];
	Seq[i]=Q[i];
	}
	display(n);
	printf("\nThe total header movement: %d\n",hm);
}

void Scan(){
	printf("Enter the no of tracks:");
	scanf("%d",&n);
	printf("Enter the head pointer:"); 
	scanf("%d",&head);
	printf("Enter the maximum disk size:");
	scanf("%d",&Max);
	Max--;
	printf("Enter the traces:");
	for(i=0;i<n;i++){
		scanf("%d",&Q[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(Q[j]>Q[j+1]){
				temp=Q[j];
				Q[j]=Q[j+1];
				Q[j+1]=temp;
			}
		}
	}
	temp=0;
	hm=0;
	hp=head;
	for(i=0;i<n;i++){
		if(hp<=Q[i]){
			Seq[temp]=Q[i];
			hm+=abs(hp-Q[i]);
			hp=Q[i];
			temp++;
		}
	}
	Seq[temp]=Max;
	hm+=abs(hp-Max);
	hp=Max;
	temp++;
	for(i=n-1;i>=0;i--){
		if(hp>Q[i] && head>Q[i]){
			Seq[temp]=Q[i];
			hm+=abs(hp-Q[i]);
			hp=Q[i];
			temp++;
		}
	}
	display(n+1);
	printf("\nThe total header movement: %d\n",hm);
}

void CScan(){
	printf("Enter the no of tracks:");
	scanf("%d",&n);
	printf("Enter the head pointer:"); 
	scanf("%d",&head);
	printf("Enter the maximum disk size:");
	scanf("%d",&Max);
	Max--;
	printf("Enter the traces:");
	for(i=0;i<n;i++){
		scanf("%d",&Q[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(Q[j]>Q[j+1]){
				temp=Q[j];
				Q[j]=Q[j+1];
				Q[j+1]=temp;
			}
		}
	}
	temp=0;
	hm=0;
	hp=head;
	for(i=0;i<n;i++){
		if(hp<=Q[i]){
			Seq[temp]=Q[i];
			hm+=abs(hp-Q[i]);
			hp=Q[i];
			temp++;
		}
	}
	Seq[temp]=Max;
	hm+=abs(hp-Max);
	hp=Max;
	temp++;
	Seq[temp]=0;
	hm+=abs(Max);
	temp++;
	hp=0;
	for(i=0;i<n;i++){
		if(hp<Q[i] && head>Q[i]){
			Seq[temp]=Q[i];
			hm+=abs(hp-Q[i]);
			hp=Q[i];
			temp++;
		}
	}
	display(n+2);
	printf("\nThe total header movement: %d\n",hm);
}



int main(){
	while(1){
		printf("Menu\n1.FCFS\n2.Scan\n3.CScan\n4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			FCFS();
			break;
			case 2:
			Scan();
			break;
			case 3:
			CScan();
			break;
			case 4:
			exit(0);
		}	
		
	}	
}