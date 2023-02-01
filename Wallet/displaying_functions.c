#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(){
   FILE *fp; // file pointer

   float max,min,value;
   char name[30],type[8],date[11],category[30];//these are the variables we will use for extracting the elements
                                            //of each entry in the database

   fp =fopen("Database.txt","r");
   if (fp == NULL) {
        printf("The file was not opened successfully!");
        return NULL;
    }
//read the first element of the database to initialize the value of min and max
    fscanf(fp,"%s %s %f %s %s",name,type,&value,category,date);
    printf("\n");
    printf("%s,%s,%.2f,%s,%s",name,type,value,category,date);

//max is a variable to store the biggest value in the Database
    max=value;
//min is a variable to store the smallest value in the Database
    min=value;

//reading the elements of the Database till the end of file
    while( fscanf(fp,"%s %s %f %s %s",name,type,&value,category,date)!=EOF){
        printf("\n");
        printf("%s,%s,%.2f,%s,%s",name,type,value,category,date);

//testing the current read value from the file with max and min value to know if we need to update them
        if(value>max)
           max=value;
        if(value<min)
           min=value;
    }

    printf("\nThe smallest value in the wallet is %.2f\n",min);
    printf("The greatest value in the wallet is %.2f\n",max);

   fclose(fp);
}
float balance(){

FILE *fp;
float b,value;//variable to store the balance
char name[30],type[8],date[11],category[30];//these are the variables we will use for extracting the elements
                                            //of each entry in the database

  fp=fopen("Database.txt","r+");

 b=0;
  //checking the type of each element of the list then adding the values of incomes and subtracting the values of Expenses
 while(fscanf(fp,"%s %s %f %s %s",name,type,&value,category,date)!=EOF){

       if(strcmp(type,"Income")==0)
          b=b+value;
       else
          b=b-value;
      }
 fclose(fp);

return b;//returning the balance value
}
