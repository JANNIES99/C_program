#include<stdio.h>
#include<stdlib.h>
#include<String.h>


void main(){
    FILE  *f1,*f2,*f3,*f4,*f5;
    char opnd[20],lab[20],op[20],addr[20],len[20],memon[20],opaddr[20],syaddr[20],Tlist[100];
    int p,s,i,j,f,in,oe;
    f1=fopen("intermidiate.txt","r");
    f2=fopen("optab.txt","r");
    f3=fopen("symtab.txt","r");
    f4=fopen("output.txt","w");
    f5=fopen("length.txt","r");
    p=0;
    fscanf(f1,"%s %s %s %s",addr,lab,op,opnd);
    fscanf(f5,"%s",len);
    printf(len);
    if (op=="START");
    fprintf(f4,"H^%s^%s^%s",lab,opnd,len);
    j=0;
    while(!feof(f1)){
        fscanf(f1,"%s %s %s %s",addr,lab,op,opnd);
        if(strcmp(op,"END")==0 || strcmp(op,"RESW")==0 || strcmp(op,"RESB")==0){
            continue;
        }
        if(strcmp(op,"WORD")==0){
            if(j==0){
                fprintf(f4,"\nT^%s^00",addr);
                in=2;
            }
            j+=3;
            fprintf(f4,"^");
            fprintf(f4,"%06d",atoi(opnd));
            in+=7;

            if(j>=16){
                in=-1*in;
                fseek(f4,in,SEEK_END);
                fprintf(f4,"%2X",j);
                fseek(f4,0,SEEK_END);
                j=0;
            }
            continue;
        }
        else if(strcmp(op,"BYTE")==0){
            if(j==0){
                fprintf(f4,"\nT^%s^00",addr);
                in=2;
            }
            fprintf(f4,"^");
            in=in+1;
            if(opnd[0]=='C')
            {
                for(i=2;i<strlen(opnd)-1;i++){
                fprintf(f4,"%02X",opnd[i]);
                in+=2;
                j++;
                }
            }
            if(opnd[0]=='X')
            {
                oe=strlen(opnd);
                if(oe%2==1){
                    fprintf(f4,"0");
                    in+=1;
                    oe=1;   
                }
                for(i=2;i<strlen(opnd)-1;i++){
                fprintf(f4,"%c",opnd[i]);
                in+=1;
                if(oe==1){
                    j++;
                    oe=0;
                }
                if(oe==0){
                    oe=1;
                }
                }
            }

            if(j>=16){
                in=-1*in;
                fseek(f4,in,SEEK_END);
                fprintf(f4,"%2X",j);
                fseek(f4,0,SEEK_END);
                in=0;
                j=0;
            }
            continue;
        }
        else{
        rewind(f2);
        f=0;
        while(!feof(f2)){
            fscanf(f2,"%s %s",memon,opaddr);
            if(strcmp(memon,op)==0){
                f=1;
                break;
            }
        }
        if(f==0){
            printf("!Error optab %s",op);
            exit(0);
        }
        rewind(f3);
        f=0;
        while(!feof(f3)){
            fscanf(f3,"%s %s",memon,syaddr);
            if(strcmp(memon,opnd)==0){
                f=1;
                break;
            }
        }
        if(f==0){
            strcpy(syaddr,"0000");
            exit(0);
        }
        if(j==0){
            fprintf(f4,"\nT^%s^00",addr);
            in=2;
        }
        j+=3;
        strcat(opaddr,syaddr);
        fprintf(f4,"^");
        fprintf(f4,"%s",opaddr);
        in+=7;

        if(j>=16){
            in=-1*in;
            fseek(f4,in,SEEK_END);
            fprintf(f4,"%2X",j);
            fseek(f4,0,SEEK_END);
            j=0;
        }
    }
    }
    if(j>0){
    in=-1*in;
    fseek(f4,in,SEEK_END);
    fprintf(f4,"0%X",j);
    fseek(f4,0,SEEK_END);
    }
    fprintf(f4,"\n");
    
    fprintf(f4,"E^%s\n",opnd);

}