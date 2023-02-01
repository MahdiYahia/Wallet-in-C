#ifndef HEADER_FILE
#define HEADER_FILE




typedef struct change_rate{
    char currency[4];
    float rate;
    struct change_rate *nxt;
} change_rate;


//char* enter_category();
void append();
void display();
void delete_category(char *s);
int change_currency();
//A function to enter dates
char* enter_date();
void change(change_rate* p,char *c);
change_rate* deletelist(change_rate* head);
char* enter_category();
int datescmp (int y1,int m1, int d1 ,int y2, int m2 , int d2);

float balance();
char *ReadAndAppendtoCategories(char *c_entry, int add);
void cdsearch(char *s,char *d);

//defining a type entry to store incomes and expenses
typedef struct entry{
char name[30];
char type[8];
char category[30];
float value;
char  date[11];
}entry;




typedef struct elem{
char string1[30];
char string2[8];
char string3[15];
char string4[30];
char string5[11];
struct elem* next;
} elem;

typedef struct celem{

char str[30];
struct celem* next;
} celem;

typedef struct elem_for_cc{
char string1[30];
char string2[8];
float value;
char string4[30];
char string5[11];
struct elem* next;
} elem_for_cc;



elem* einsert( elem *head ,char* first,char* second ,char* third ,char* fourth,char* fifth);
celem* insertcat( celem *head ,char* cat);
elem_for_cc* einsert_for_cc(elem_for_cc* head,char* name,char* type,float value,char* category,char* date);

elem* list_delete(elem* head);
celem* clist_delete(celem* head);
elem_for_cc* cclist_delete(elem_for_cc* head);
#endif // HEADER_FILE

