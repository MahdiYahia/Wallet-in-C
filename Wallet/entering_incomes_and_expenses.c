#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "headerfile.h"
void append(){

FILE *fp;//file pointer
entry ne;//structure to store the information of the new entry
char c;//variable to store the user's decision about the type of entry
int y,m,d;


  fp=fopen("Database.txt","a+");
  if (fp == NULL) {
      printf("The file was not opened successfully!");
      return NULL;
  }
//Giving the name of the entry
   printf("\nEnter the name of the entry:");

   scanf("%s",&ne.name);


   printf("\nChoose the type of the entry:");
//Testing if the type the user chose is available since he must choose between "income" and "Expense" only
   while(1){
        printf("\nIf it is an income please press 'I' if it is an expense please press 'E'");



        scanf(" %c",&c);





        if ((c=='I')||(c=='E')||(c=='i')||(c=='e'))
            break; //valid entry, break out
     }

    if((c=='I')||(c=='i'))
        strcpy(ne.type,"Income");
    else
        strcpy(ne.type,"Expense");

//Giving the category of the entry
   printf("\nEnter its category:");
   strcpy(ne.category,enter_category());
//Giving the value of the entry
   printf("\nEnter its value:");
   scanf("%f",&ne.value);
 //Giving the date of the entry
   printf("\nEnter the date of entry:");
   strcpy(ne.date,enter_date());


   //print the entry the user entered into the file Database
   fprintf(fp,"%s %s %.2f %s %s",ne.name,ne.type,ne.value,ne.category,ne.date);
   fprintf(fp,"\n");

   fclose(fp);
}
