#include<stdio.h>
#include<stdlib.h>
#include "headerfile.h"

int change_currency(char *c_cur){//c_cur is the current currency


char toc[4];//the currency we will make the conversion to
int x=0; //integer to store the choice
FILE *cfp;
change_rate *p1,*p2,*p3;

p1=(change_rate*)malloc(sizeof(change_rate));
p2=(change_rate*)malloc(sizeof(change_rate));
p3=(change_rate*)malloc(sizeof(change_rate));

//Creating a linked list containing change rates from the current currency that should be the same as the one in the first element
//p1=head;
strcpy(p1->currency,"HUF");
p1->rate=1;
p1->nxt=(change_rate*)malloc(sizeof(change_rate));
strcpy(p1->nxt->currency,"EUR");
p1->nxt->rate=0.0028;
p1->nxt->nxt=(change_rate*)malloc(sizeof(change_rate));
strcpy(p1->nxt->nxt->currency,"USD");
p1->nxt->nxt->rate=0.0034;
p1->nxt->nxt->nxt=NULL;

//Creating a linked list containing change rates from the current currency that should be the same as the one in the first element
//p2=head;
strcpy(p2->currency,"EUR");
p2->rate=1;
p2->nxt=(change_rate*)malloc(sizeof(change_rate));
strcpy(p2->nxt->currency,"HUF");
p2->nxt->rate=360;
p2->nxt->nxt=(change_rate*)malloc(sizeof(change_rate));
strcpy(p2->nxt->nxt->currency,"USD");
p2->nxt->nxt->rate=1.21;
p2->nxt->nxt->nxt=NULL;

//Creating a linked list containing change rates from the current currency that should be the same as the one in the first element
//p3=head;
strcpy(p3->currency,"USD");
p3->rate=1;
p3->nxt=(change_rate*)malloc(sizeof(change_rate));
strcpy(p3->nxt->currency,"HUF");
p3->nxt->rate=297;
p3->nxt->nxt=(change_rate*)malloc(sizeof(change_rate));
strcpy(p3->nxt->nxt->currency,"EUR");
p3->nxt->nxt->rate=0.83;
p3->nxt->nxt->nxt=NULL;

     cfp =fopen("Currency.txt","w");
    if (cfp==NULL){
        printf("The file was not opened successfully!");
        return 1;
    }

  //The code below is made for what the program will show if the user chose to change the currency
     printf("Please choose your new default currency!\n");
     printf("To choose euro, please press the number '1'\n");
     printf("To choose US dollar, please press the number '2'\n");
     printf("To choose HU forint, please press the number '3'\n");



     //Checking if the user chose an available entry or not.
    do {
    printf("Pick a currency from the above: ");
    scanf("%d", &x);
    if(x==1 || x == 2 || x==3) {
      break; //valid entry, break out
    }
  }
  while(1);
      switch(x){
         case 1:
            fprintf(cfp,"EUR");
            strcpy(toc,"EUR");
            break;
         case 2:
            fprintf(cfp,"USD");
            strcpy(toc,"USD");
            break;
         case 3:
            fprintf(cfp,"HUF");
            strcpy(toc,"HUF");
            break;
          }

   if (strcmp(c_cur,"HUF")==0)
       change(p1,toc);
   else if(strcmp(c_cur,"EUR")==0)
      change(p2,toc);
   else if(strcmp(c_cur,"USD")==0)
      change(p3,toc);

deletelist(p1);
deletelist(p2);
deletelist(p3);

     printf("Your currency was changed successfully");
     fclose(cfp);
return 0;
}

void change(change_rate* p,char *c)
{
     FILE *dfp;

  elem_for_cc * head = NULL ;
  char name[30],type[8],category[30],date[11];
  float value;


  dfp=fopen("Database.txt","a+");//Reading the database before modification

  //checking if the files were opened successfully
  if(dfp==NULL)
    {
      printf("Error!");
      return NULL;
    }
  if (strcmp(p->nxt->currency,c)==0)
  {
   while( fscanf(dfp,"%s %s %f %s %s",name,type,&value,category,date)!=EOF)
      {
          value=value * (p->nxt->rate);
          head=einsert_for_cc(head,name,type,value,category,date);

        }
   }
else if (strcmp(p->nxt->nxt->currency,c)==0)
    {
          while( fscanf(dfp,"%s %s %f %s %s",name,type,&value,category,date)!=EOF)
           {
              value=value*(p->nxt->nxt->rate);
              head=einsert_for_cc(head,name,type,value,category,date);

            }
     }
   fclose(dfp);

ccWriteToDataBase(head);

}






void ccWriteToDataBase(elem_for_cc *head)
{
  FILE *dfp;
  dfp = fopen("Database.txt", "w");

  if (dfp == NULL)
  {
    printf("Error!");
    return NULL;
  }

  elem_for_cc *p = head;
  while (p != NULL)
  {
    fprintf(dfp, "%s %s %.2f %s %s", p->string1, p->string2, p->value, p->string4, p->string5);
    fprintf(dfp, "\n");
    p = p->next;
  }
  cclist_delete(head);
  fclose(dfp);
}



change_rate* deletelist(change_rate* head){
     change_rate *p,*v;
      v=head;

    while (v!=NULL){

        p=v->nxt;
       free(v);
       v=p;
      }
     return NULL;
 }


elem_for_cc* cclist_delete(elem_for_cc* head){
     elem_for_cc *p,*v;
      v=head;

    while (v!=NULL){

        p=v->next;
       free(v);
       v=p;
      }
     return NULL;
 }
elem_for_cc* einsert_for_cc( elem_for_cc *head ,char* first,char* second ,float third ,char* fourth,char* fifth)
  {
 elem_for_cc *p;

   if ( head == NULL ){ // in case of an empty list
     p = ( elem_for_cc *) malloc ( sizeof ( elem_for_cc ));
     strcpy(p->string1,first) ;
     strcpy(p->string2,second) ;
     p->value=third ;
     strcpy(p->string4,fourth) ;
     strcpy(p->string5,fifth) ;
     head = p;
     return head ;

 }
  for (p = head ; p-> next != NULL ; p = p-> next );
      p-> next = ( elem_for_cc *) malloc ( sizeof ( elem_for_cc ));
      strcpy(p->next->string1,first) ;
      strcpy(p->next->string2,second) ;
      p->value=third ;
      strcpy(p->next->string4,fourth) ;
      strcpy(p->next->string5,fifth) ;
      p->next-> next = NULL ;
      return head ;
 }
