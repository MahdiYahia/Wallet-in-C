#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "headerfile.h"

void cdsearch(char *s,char *d){//s holds the name of the category we want to search in the database and d holds the date we will search for in the database
   FILE *fp; // file pointer
   char name[30],type[8],category[30],date[11];//these are the variables we will use for extracting the elements
   float value;                                //of each entry in the database

    //opening the Database file containing all the entries
    fp =fopen("Database.txt","r");
    if (fp == NULL) {
        printf("The file was not opened successfully!");
        return NULL;
    }

    while( fscanf(fp,"%s %s %f %s %s",name,type,&value,category,date)!=EOF){
     if (strcmp(s,"none")==0)
     {
              if (strcmp(d,date)==0)
                {
                  //printing the database elements in which the date is the same as the one we are searching for
                  printf("%s,%s,%.2f,%s,%s",name,type,value,category,date);
                  printf("\n");
                 }
      }

     else if  (strcmp(d,"none")==0)
     {
              if ((strcmp(category,s)==0))
                {
                  //printing the database elements in which the date is the same as the one we are searching for
                  printf("%s,%s,%.2f,%s,%s",name,type,value,category,date);
                  printf("\n");

                 }
       }
     else if ((strcmp(s,"none")!=0) && (strcmp(d,"none")!=0)){
              if ((strcmp(d,date)==0)&&(strcmp(s,category))){
                  //printing the database elements in which the date is the same as the one we are searching for
                  printf("%s,%s,%.2f,%s,%s",name,type,value,category,date);
                  printf("\n");

                 }
       }
}
     fclose(fp);

}
