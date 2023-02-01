#include<stdio.h>
#include<stdlib.h>
char* enter_date(){
    int y,m,d;
    char s[11];

    printf("Give the year of entry");
    scanf("%d",&y);
 //Testing the validity of a the year entered knowing that it has to be between 2000 and 3000
    if (3000<y||y<2000){
        do {
           printf("Your choice is not valid!\nPlease choose a valid year!") ;
           scanf("%d", &y);

           if(2000<=y<=3000) {
              break; //valid entry, break out
           }
         }
        while(1);
        }

//testing the validity of the month entered knowing that it has to be between 1 and 12
     printf("Give the month of entry");
     scanf("%d", &m);


     if ((1<=m && m<=12)==0){
        do {
          printf("Your choice is not valid!\nPlease choose a valid month!") ;
          scanf("%d", &m);

          if(1<=m && m<=12) {
             break; //valid entry, break out
           }
        }
        while(1);
    }

    printf("Give the day of entry");
    scanf("%d", &d);
//testing the validity of the date entered knowing that it has to be between 1 and 31 in the months 1,3,5,7,8,10,12
    if ((m==1) || (m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)){
       if ((1<=d && d<=31)==0){
           do {
              printf("Your choice is not valid!\nPlease choose a valid day number!") ;
              scanf("%d",&d);

              if(1<=d && d<=31)
                 break; //valid entry, break out
               }
           while(1);
    }
    }

//testing the validity of the date entered knowing that it has to be between 1 and 30 in the months 4,6,9,11
    else if ((m==4) || (m==6)||(m==9)||(m==11)){
         if ((1<=d && d<=30)==0){
             do {
                printf("Your choice is not valid!\nPlease choose a number from the list above!") ;
                scanf("%d", &d);

                if(1<=d && d<=31) {
                   break; //valid entry, break out
                   }
             }
             while(1);
           }
    }

//if the month is 2 and the year is a leap year the day has to be between 1 and 29
    else if(((m==2) && ((y%100)!=0) && ((y%4)==0))==1){
         if ((1<=d && d<=29)==0){
            do {
               printf("Your choice is not valid!\nPlease choose a number from the list above!") ;
               scanf("%d",&d);

               if(1<=d && d<=29)
                  break; //valid entry, break out

            }
            while(1);
         }
    }

//if the month is 2 and the year is not a leap year the day has to be between 1 and 28
    else{
         if ((1<=d && d<=28)==0){
             do {
                printf("Your choice is not valid!\nPlease choose a number from the list above!") ;
                scanf("%d",&d);

                if(1<=d && d<=28)
                   break; //valid entry, break out

              }
              while(1);
         }
    }

//converting the date we entered in the form of integers to a string
sprintf(s,"%02d\\%02d\\%02d",y,m,d);
//returning the string storing the date
return s;
}

//A function that will compare two dates
//It will return 1 if the date entered first is later, 2 if the date entered second is later and 0 if they are identical
int datescmp (int y1,int m1, int d1 ,int y2, int m2 , int d2){

if (y1>y2)
    return 1;
if (y2>y1)
    return 2;
if (m1>m2)
    return 1;
if (m1<m2)
    return 2;
if (d1>d2)
    return 1;
if (d1<d2)
    return 2;

return 0;
}
void periodstat(char *date1,char *date2){

int y1,y2,m1,m2,d1,d2,y,m,d;
char category[30],categoryind[30],date[11],type[8],name[30];
float value,total,c;

//converting the strings holding the dates specifying the period to integers to be able to compare them
sscanf(date1,"%d\\%d\\%d",&y1,&m1,&d1);
sscanf(date2,"%d\\%d\\%d",&y2,&m2,&d2);




 FILE *fp;

  fp=fopen("Database.txt","a+");

 if(fp==NULL)  {
     printf("Error!");
        return NULL;
    }
 total=0;
      //reading all the database elements until the end of file
       while( fscanf(fp,"%s %s %f %s %s",name,type,&value,categoryind,date)!=EOF){

         //reading the date in the form of integers
              sscanf(date,"%d\\%d\\%d",&y,&m,&d);
        //checking if the date of the database element is in the specified period
       if(((datescmp(y1,m1,d1,y,m,d)==2)||(datescmp(y1,m1,d1,y,m,d)==0))&&((datescmp(y2,m2,d2,y,m,d)==1)||(datescmp(y2,m2,d2,y,m,d)==0)))
            total=total+value;//finding the total value in the specified
           }
           fclose(fp);


  FILE* cfp,*dfp;//categories file pointer and database file pointer


   cfp=fopen("categories.txt","a+");

   if(cfp==NULL)  {
     printf("Error!");
        return NULL;
    }




  while(fscanf(cfp,"%s",category)!=EOF){

     dfp=fopen("Database.txt","a+");

     if(dfp==NULL)  {
      printf("Error!");
         return NULL;
      }

   c=0;

   while( fscanf(dfp,"%s %s %f %s %s",name,type,&value,categoryind,date)!=EOF){


        if (strcmp(category,categoryind)==0){

                 sscanf(date,"%d\\%d\\%d",&y,&m,&d);

                 //checking if the date of the database element is in the specified period
                 if(((datescmp(y1,m1,d1,y,m,d)==2)||(datescmp(y1,m1,d1,y,m,d)==0))&&((datescmp(y2,m2,d2,y,m,d)==1)||(datescmp(y2,m2,d2,y,m,d)==0))){
                    c=c+value;}
             }
      }




   if (((c/total)*100)!=0){

    //printing the budget share of each category in percentage in the specified period
     printf("The budget share of the category %s in the specified period is %%%.1f\n",category, (c/total)*100);
    }
 fclose(dfp);
}
 fclose(cfp);
}
