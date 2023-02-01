#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"

char *enter_category()
{

  char c_entry[30];

  printf("Enter the category you want to enter:\n");

  // c_entry is the user's input
  scanf("%s", c_entry);

  // Append new entered category to the categories.txt file
  ReadAndAppendtoCategories(c_entry, 2);

  return c_entry;
}

void delete_category(char *dcategory){

  FILE *cfp,*dfp;

  elem * head = NULL ;
  celem *headc=NULL;
  char name[30],type[8],category[30],date[11],value[15];



  cfp=fopen("categories.txt","a+");//Reading the file containing the categories before modification
  dfp=fopen("Database.txt","a+");//Reading the database before modification

  //checking if the files were opened successfully
  if((cfp==NULL) || (dfp==NULL)){
      printf("Error!");
      return NULL;
  }


  while(fscanf(cfp,"%s",category)!=EOF){
    if (strcmp(dcategory,category)!=0){
           headc=insertcat(headc,category);
            }
     }


fclose(cfp);

  while( fscanf(dfp,"%s %s %s %s %s",name,type,value,category,date)!=EOF){
     if (strcmp(dcategory,category)!=0)
         {
         head=einsert(head,name,type,value,category,date);
         }
     }
  fclose(dfp);


WriteTocategories(headc);
WriteToDataBase(head);

}

char *ReadAndAppendtoCategories(char *c_entry, int add)
{
   char category[30];
    int p;
    FILE *fp; // file pointer
    fp = fopen("categories.txt", "a+");

   if (fp == NULL)
   {
     printf("The file was not opened successfully!\n");
     return NULL;
   }

    if(add==1)
      {
       printf("These are the current categories:");
       while(fscanf(fp,"%s",category)!=EOF)
         {
          printf("\n");
          printf("%s",category);
         }
        printf("\n");
      }

    else if(add==2)
     {
     //checking if the category we want to enter is already in the categories' database
        p=0;
        while(fscanf(fp,"%s",category)!=EOF)
         {
           if (strcmp(c_entry,category)==0)
           p=1;
         }

     //printing the category in the database if it is not already there
        if (p==0)
          {
          fprintf(fp,"\n");
          fprintf(fp,"%s",c_entry);
          }
     }
fclose(fp);
      }


void WriteTocategories(celem *headc)
{
  FILE *cfp;
  celem *q = headc;

  cfp = fopen("categories.txt", "w");

  if (cfp == NULL)
  {
    printf("Error!");
    return NULL;
  }

  while (q != NULL)
  {
    fprintf(cfp, "%s", q->str);
    fprintf(cfp, "\n");
    q = q->next;
  }

  clist_delete(headc);
  fclose(cfp);
}

void WriteToDataBase(elem *head)
{
  FILE *dfp;
  dfp = fopen("Database.txt", "w");

  if (dfp == NULL)
  {
    printf("Error!");
    return NULL;
  }

  elem *p = head;
  while (p != NULL)
  {
    fprintf(dfp, "%s %s %s %s %s", p->string1, p->string2, p->string3, p->string4, p->string5);
    fprintf(dfp, "\n");
    p = p->next;
  }
  list_delete(head);
  fclose(dfp);
}
elem* einsert( elem *head ,char* first,char* second ,char* third ,char* fourth,char* fifth)
  {
 elem *p;

   if ( head == NULL ){ // in case of an empty list
     p = ( elem *) malloc ( sizeof ( elem ));
     strcpy(p->string1,first) ;
     strcpy(p->string2,second) ;
     strcpy(p->string3,third) ;
     strcpy(p->string4,fourth) ;
     strcpy(p->string5,fifth) ;
     head = p;
     return head ;

 }
  for (p = head ; p-> next != NULL ; p = p-> next );
      p-> next = ( elem *) malloc ( sizeof ( elem ));
      strcpy(p->next->string1,first) ;
      strcpy(p->next->string2,second) ;
      strcpy(p->next->string3,third) ;
      strcpy(p->next->string4,fourth) ;
      strcpy(p->next->string5,fifth) ;
      p->next-> next = NULL ;
      return head ;
 }
 celem * insertcat( celem *headc ,char* cat)
  {
 celem *q;

   if ( headc == NULL ){ // in case of an empty list
     q = ( elem *) malloc ( sizeof ( celem ));
     strcpy(q->str,cat) ;
     headc= q;
     return headc ;
     }
  for (q = headc ; q-> next != NULL ; q = q-> next );
      q-> next = ( celem *) malloc ( sizeof ( celem ));
      strcpy(q->next->str,cat) ;
      q->next->next = NULL ;
      return headc ;
 }

elem* list_delete(elem* head){
     elem *p,*v;
      v=head;

    while (v!=NULL){

        p=v->next;
       free(v);
       v=p;
      }
     return NULL;
 }


celem* clist_delete(celem* head){
     celem *p,*v;
      v=head;

    while (v!=NULL){

        p=v->next;
       free(v);
       v=p;
      }
     return NULL;
 }
