#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

struct TMetro
{
    char Station1[15],Station2[15];
    char Delay1[10],Delay2[10];
    TMetro* next;
};

void copy1 (TMetro *to, TMetro *from) { 
 strcpy (to->Station1, from->Station1); 
 strcpy (to->Station2, from->Station2);
 strcpy (to->Delay1, from->Delay1);
 strcpy (to->Delay2, from->Delay2);                                                                                                              
};



TMetro *addList (TMetro *head, TMetro *inf)
{ 
 TMetro *last = NULL;
 if (head!=NULL) {
  last=head;
  while (last->next!=NULL) last=last->next;
 }
 TMetro *current = new TMetro;
 copy1 (current,inf);
 current->next = NULL;
 if (last) last->next = current;
 return current;
};

void checkStr(char str[15],char title[]) {
   bool b = true;
 while (b == true) {
   printf ("\n%s ",title); scanf ("%s",str);
   int i = 0;
   bool flag = true;
   while ( str[i] && flag)  {
      if (isalpha(str[i]))
          flag = true;
      else
          { 
            printf("Нужно вводить буквы");
            flag = false;
          }
      i++; 
    }
    if ( flag == true)  b = false;
    }
}

void checkStr2(char str[15],char title[]) {
   bool b = true;
 while (b == true) {
   printf ("\n%s ",title); scanf ("%s",str);
   int i = 0;
   bool flag = true;
   while ( str[i] && flag)  {
      if (isalpha(str[i])) {
          printf("Нужно цифры");
            flag = false;
      }
      else
          { 
            flag = true;
          } 
      i++; 
    }
    if ( flag == true)  b = false;
    }
} 


TMetro Enter() { 
 TMetro p;
 char char1[]="Начальная станция: ";
 char char2[]="Конечная станция: ";
 char char3[]="Начало задержки: ";
 char char4[]="Конец задержки: ";
 checkStr(p.Station1,char1);
 checkStr(p.Station2,char2);
 checkStr2(p.Delay1,char3);
 checkStr2(p.Delay2,char4);
 return p;
};

TMetro *changeList(TMetro*head,int number,TMetro *inf)
{
   TMetro *prev = NULL, *start = head; int i=1;
   while (i<number) { 
      head = head->next;
      i++;
    }
  copy1(head,inf);
   return start;
};

int countP(TMetro *head){
 int count=0;
 if (head) while (1) {
  count++;
  if (head->next == NULL) break;
  head = head->next;
 }
 return count;  
}

int show (TMetro *head) { 
 if (head == NULL) printf("Список задержек пуст.\n");
 else {
 int count=0;
 if (head) while (1) {
  count++;
  printf ("\nЗадержка №%d\n  %s\n  %s\n  %s\n  %s",count,  head->Station1,  head->Station2, head->Delay1,  head->Delay2);  
  if (head->next == NULL) break;
  head = head->next;
 }
 printf ("\n");
 return count;
 }
};

TMetro *addHead (TMetro *head, TMetro *inf) { 
 TMetro *current = new TMetro;
 copy1 (current, inf); 
 if (head==NULL) current->next = NULL;
 return current;
};


  
TMetro *delete1 (TMetro *head0, int n) { 
 TMetro *head = head0;
 if (head==NULL) return NULL;
 if (n==1) {
  TMetro *ptr = head->next;
  delete head;
  return ptr;
 }
 TMetro *prev = NULL, *start = head; int i=1;
 while (i<n) {
  prev = head; head = head->next;
  if (head==NULL) return  start;
  i++;
 }
 TMetro *ptr = head->next;
 delete head; 
 
 prev->next = ptr;
 return start;
};

void SaveFile(TMetro *head)
{
	FILE *file;
	if ((file = fopen("logs","w")) == NULL) 
	{
		//system("CLS");
		printf("%s\n","Ошибка открытия файла");
		getchar();
		getchar();
	}
	else
	{
		//system("CLS");
		while (head != NULL)
		{
			fprintf(file,"%s\n", head->Station1);
			fprintf(file,"%s\n", head->Station2);
			fprintf(file,"%s\n", head->Delay1);
			fprintf(file,"%s\n", head->Delay2);
			head = head->next;
		}
		fclose(file);
		printf("%s","Файл записан успешно");
	}
}

void ReadFile(TMetro *head)
{
	TMetro *H = new TMetro;
    FILE *rfile;
    if ((rfile=fopen("logs","r"))==0) {
        //system("CLS");
        printf("Ошибка при открытии файла!");
        getchar();
        getchar();
    }
    else {
        int c=0;
        char temp_str[5];
        while (!feof(rfile)) {
            if (c==0) {
                fscanf(rfile,"%s ",head->Station1);
                fscanf(rfile,"%s ",head->Station2);
                fscanf(rfile,"%s ",head->Delay1);
                fscanf(rfile,"%s ",head->Delay1);
                head->next=H;
                c++;
            }
                fscanf(rfile,"%s ",H->Station1);
                fscanf(rfile,"%s ",H->Station2);
                fscanf(rfile,"%s ",H->Delay1);
                fscanf(rfile,"%s ",H->Delay1);
            H = head->next;    
            c++;
        }
    fclose(rfile);
    }
}


int main()
{   
    TMetro* head = new TMetro;
    TMetro temp;
    TMetro *cur;
    int a,n,count=0,all;
    char b; 
    head = delete1(head,1);
    while (1){
    printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n%s", "1.Добавить задержку.","2.Изменить задержку.", "3.Удалить задержку.","4.Вывод задержек.","5.Запись в файл.","6.Чтение из  файла.","7.Выход.","Выберите пункт меню: ");
    scanf("%c", &b);
      switch (b){
      case '1':
      if (count = 0)
        {
            //system("CLS");
            temp = Enter();
            head = addHead(head,&temp);
            count++;
        }
        else 
        {
            //system("CLS");
            temp = Enter();
            cur = addList(head,&temp);
	           if (head==NULL) head=cur;
            count++;
        }
        getchar();
        getchar();
        break;
      case '2':
        //system("CLS");
        show(head);
        int num;
        while (1) {
            int countp1 = 0;
            countp1 = countP(head);
            printf("\nВведите номер задержки(1-%d), которую нужно изменить: ",countp1);
            scanf("%d", &num);
            if ((num > 0) && (num <= countP(head))) break;
        }
        temp = Enter();
        head = changeList(head,num,&temp);  
        printf("\nЗадержка №%d изменена успешно!",n);
        getchar();
        getchar();
        break;
      case '3':
        //system("CLS");
        all = show(head);
        while (1) {
         printf ("\nВведите номер (1-%d): ",all);
         scanf("%d",&n);
         if (n>=1 && n<=all) break;
         }
        head = delete1(head,n);
        printf("\nЗадержка №%d удалена успешно!",n);
        getchar();
        getchar();
        break;
      case '4':
        //system("CLS");
        show(head);
        getchar();
        getchar();
        break;
	     case '5':
        //system("CLS");
        SaveFile(head);
        getchar();
        getchar();
        break;
     	case '6':
        //system("CLS");
	       ReadFile(head);
        getchar();
        getchar();
        break;
      case '7': exit (0); break;
    }
      //system("CLS");
    }
return 0;
} 