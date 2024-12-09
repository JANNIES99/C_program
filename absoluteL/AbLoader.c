#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char c[50],loc[20];
    int bl,seg,oe,i,n,new,addr;
    FILE *f1;
    f1=fopen("input1.txt","r");
    fscanf(f1,"%s",c);
    addr=0;
    while(!feof(f1)){
        fscanf(f1,"%s",c);
        n=0;
        if(c[0]=='T'){
        strncpy(loc, c + 2, 6);
        loc[6]='\0';
        new=(int)strtol(loc,NULL,16);
        if(new!=addr){
        if(seg>0){
            i=seg;
            for(i;i<8;i++){
                printf("X");
            }
        }
        printf("\n");
        seg=0;
        oe=0;
        
        }
        addr=new;
        bl=0;
        n=12;
        while(c[n]!='\0'){
            if(seg==0){
            printf("%X\t",addr);
            }
            if(bl==6){
                bl=0;
                n++;
                continue;
            }
            if(seg==8){
                seg=0;
                printf("\n");
                continue;
            }
            printf("%c",c[n]);
            if(oe==0){
                oe=1;
            }
            else{
                oe=0;
            }
            seg++;
            bl++;
            addr+=oe;
            n++;
        }
        }

    }
    if(seg>0){
        i=seg;
        for(i;i<8;i++){
            printf("X");
        }
    }
}