#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "headerfile.h"
int main()

{

    char s[30],categorytodelete[30],mostexpensive[30];//string to store the category to search for or to delete
    char da[11],date1[30],date2[30];//string to store the date we will make the search with
    char  cc[4] ; //cc is current currency
    int  c1,c2,x; //c1 and c2 are integers to store the choices and x is to store if the change of the currency was successful or not
    FILE *cfp,*fpc; //cfp currency file pointer fpc is file pointer for categories


    while (1){

    //opening the file containing the default currency then reading it
     cfp =fopen("Currency.txt","a+");
     if (cfp == NULL) {
        printf("The file was not opened successfully!");
        return 1;
    }
     fscanf(cfp,"%s",&cc);
     fclose(cfp);




    //This will be the menu the users will encounter when they first open the program
     printf("Welcome To your wallet!\n");
     printf("The current default currency is %s\n",cc);
     printf("To check your balance, Please press the key '1'\n");
     printf("To make a new entry, please press the key '2'\n");
     printf("To manage the incomes' or expenses'  categories, please press the key '3'\n");
     printf("To display the general information of your wallet, please press the key '4'\n");
     printf("To check your finances for a specified date or category, please press the key '5'\n");
     printf("To display the statistics of one period, please press the key '6'\n");
     printf("To change the default currency, please press the key '7'\n");
     printf("To exit the program, please press the key '8'\n\n");





     scanf(" %d",&c1);

    //Making sure the entered choice is valid
    if (((c1==1) || (c1==2) || (c1==3) || (c1==4) || (c1==5) || (c1==6) || (c1==7)||(c1==8))==0){
        do {
             printf("Your choice is not valid!\nPlease choose a number from the list above!") ;

             scanf(" %d", &c1);

             if((c1==1) || (c1==2) || (c1==3) || (c1==4) || (c1==5) || (c1==6) || (c1==7)||(c1==8)) {
                     break; //valid entry, break out
                    }
        } while(1);
    }
    switch (c1){

         case 1:
              printf("You current balance is: %.2f\n",balance());
              break;
         case 2:
              append();
              break;

         case 3:
             //the menu appearing in case the choice from the initial menu is 2
              ReadAndAppendtoCategories(" ",1);
              printf("If you want to add a new category, Please press on '1'\n");
              printf("If you want to delete a category, Please press on '2'\n");
              printf("If you want to keep the categories unchanged, Please press the number '3'\n");

              scanf("%d",&c2);
              //Making sure the entered choice is valid
              if (((c2==1) || (c2==2) || (c2==3))==0){
                  do {
                       printf("Your choice is not valid!\nPlease choose a number from the list above!\n") ;

                       scanf(" %d", &c2);

                       if((c2==1) || (c2==2) || (c2==3)) {
                            break; //valid entry, break out
                         }
                   } while(1);
               }

               switch(c2){
                      case 1:
                         enter_category();
                         break;
                      case 2:
                         printf("\nGive the category you want to delete!");


                         scanf(" %s", categorytodelete);

                         delete_category(categorytodelete);
                         break;
                      case 3:
                         break;
                         }
               break;
        case 4:
               display();
               break;
        case 5:
               printf("Give the category you want to search for!\n Please enter 'none' in case you don't want to make a search based on categories!");
               scanf(" %s",s);
               printf("\n Please enter 'none' in case you don't want to make a search based on dates!or anything else to enter the date!");
               scanf(" %s",da);
               if(strcmp(da,"none")==0)
                  cdsearch(s,"none");
                else
                    strcpy(da,enter_date());
                   cdsearch(s,da);
                break;
         case 6:
                printf("Please enter the dates that determine the period:\n");
                printf("Give the first date\n");
                strcpy(date1,enter_date());
                printf("Give the second date\n");
                strcpy(date2,enter_date());
                periodstat(date1,date2);
                break;
         case 7:
                x=change_currency(cc);
                if (x==0)
                   break;
                else
                   return 1;

         case 8:
            return 0;
}
printf("\n\n\n\n");
}
}
