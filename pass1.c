#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
    char a[20],m[20],r[20],sop[20];
    int op,count,c,fl;
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("input1.txt","r");
    f2=fopen("output1.txt","w");
    f3=fopen("symtab1.txt","w");
    f4=fopen("optab1.txt","r");
    fscanf(f1,"%s %s %d",a,m,&op);
    if(strcmp(m,"START")==0){
        printf("\t%s %s %d\n",a,m,op);
        count=op%10;
        itoa(op,sop,10);
        op=(int)strtol(sop, NULL, 16);
        fprintf(f2,"**\t%s %s %s\n",a,m,sop);
        while(!feof(f1))
        {

            printf("%X\t",op);
            fscanf(f1,"%s %s %s",a,m,r);
            printf("%s %s %s\n",a,m,r);
            if (a[0]!='*' && a[1]!='*'){
                fprintf(f3,"%s\t%X\n",a,op);
            }
            fprintf(f2,"%X\t%s %s %s\n",op,a,m,r);
            if (strcmp(m,"RESW")==0)
            {
                count=atoi(r);
                op=op+(count*3);
            }
            else if(strcmp(m,"WORD")==0)
            {
                op+=3;
            }
            else if(strcmp(m,"BYTE")==0)
            {
                c=strlen(r);
                for(int i=0;i<c;i++){
                    if(r[i]=='\'' && fl==0){
                        fl=1;
                        continue;
                    }
                    else if(r[i]=='\'' && fl==1){
                        fl=0;
                    }
                    if(fl==1){
                        op++;
                    }
                }
            }
            else if(strcmp(m,"RESB")==0)
            {
                op+=atoi(r);
            }
            else
                op+=3;
       }
    }
}
