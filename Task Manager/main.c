//
//  main.c
//  Task Manager
//
//  Created by Ayush Agrawal on 27/04/18.
//  Copyright © 2018 Ayush Agrawal. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//    STRUCTURE THAT WILL TAKE DATA OF A TASK

struct todo{
    char *task;
    char date[9];
};

//  Dynamic memory allocation to entity strings of structure

char* dynamic(char*ch, struct todo *a){
    
    char *p;
    unsigned long int len;
    len=strlen(ch);
    p=(char*)malloc(len+1);
    strcpy(p, ch);
    return p;
};

//  ADD TASKS
void addtask(struct todo *a ,int n, int flag){
    //Add name of task
    char name[50];
    int i=0;
    FILE *fp;
    fp=fopen("/Users/ayush/Desktop/Task Manager/Task Manager/Data.txt","w");
    a=calloc(n, sizeof(struct todo));
    
    for (i=0; i<n; i++){
        printf("Enter task name: \n");
        if (i==0) {
            getchar();
        }
        
        gets(name);
        
        (a+i)->task=dynamic(name,a);
        if( (flag==1)||((flag==2)&&(i==0)) ){
            printf("Enter Date as dd/mm/yy:\n");
            gets((a+i)->date);
            (a+i)->date[8]='\0';
        }
        else if((flag==2)&&(i!=0)){
            strcpy((a+i)->date, (a+0)->date);
        }
        

    
        //  WRITING CONTENTS IN FILE
        fputs((a+i)->task, fp);
        fputc('\t', fp);
        fputs((a+i)->date, fp);
        fputc('\n', fp);
    }
}









int main()
{
    struct todo* t=NULL;
    int menu,n;

    sos:
    //MENU
    printf("MENU:  \n");
    printf("ADD TAKS\n");
    printf("\t 1: Add Tasks \n");
    printf("\t 2: Add Multiple Tasks of same date \n");
    printf("Mark Completed Tasks \n");
    printf("\t 3: Tasks Done\n");
    
    scanf("%d", &menu);
    
    switch (menu) {
        case 1:
            //Adding Tasks
            printf("Enter number of tasks");
            scanf("%d",&n);
            addtask( t ,n,1);
            break;
        
        case 2:
            printf("Enter number of tasks");
            scanf("%d",&n);
            addtask( t ,n,2);
            break;
            
        default:
            goto sos;
            break;
    }
    

    
    return 0;
}
