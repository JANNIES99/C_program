#include<stdio.h>
int m,n,Work[20],Alloc[20][20],Max[20][20],Need[20][20],Fin[20],Ava[20],Se[20],Total[20];
int main(){
int i,j,sum,count,fl;
printf("Enter the number of Processes and Resource:");
scanf("%d %d",&n,&m);
for(i=0;i<n;i++){
	Fin[i]=0;
}
printf("Enter the Total instances:");
for(i=0;i<m;i++){
	scanf("%d",&Total[i]);
}
printf("Enter the allocated resource in\n");
for(i=0;i<n;i++){
	printf("P%d:",i);
	for(j=0;j<m;j++){
		scanf("%d",&Alloc[i][j]);
}
}

printf("Enter the max resource in\n");
for(i=0;i<n;i++){
	printf("P%d:",i);
	for(j=0;j<m;j++){
		scanf("%d",&Max[i][j]);
}
}

for(i=0;i<m;i++){
	sum=0;
	for(j=0;j<n;j++){
		sum+=Alloc[j][i];
		Need[j][i]=Max[j][i]-Alloc[j][i];
	}
	Ava[i]=Total[i]-sum;
}



for(j=0;j<m;j++){
	printf("%d ",Ava[j]);
}

for(i=0;i<m;i++){
	Work[i]=Ava[i];
}
sum=0;
while (count<n && sum<n){
	count=0;
	for(i=0;i<n;i++){
		fl=0;
		if(Fin[i]==0){
			for(j=0;j<m;j++){
				if(Need[i][j]>Work[j]){
					fl=1;
				}
			}
			if(fl==0){
				for(j=0;j<m;j++){
					Work[j]+=Alloc[i][j];
				}
				Se[sum]=i;			
				sum++;
				Fin[i]=1;
				break;
			}
		}
		count++;		
	}
}


if(count==n){
	printf("The System is the deadlock condition");
}
else{
	printf("The System is in Safe State Sequence:");
	for(i=0;i<n;i++){
		printf(" P%d",Se[i]);
	}
}


}
