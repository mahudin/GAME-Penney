#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#define STOSP 10
int getchar();
void nowa_gra();
char* ustal_seria(char *g,int dlugosc_serii,int m);
int losowanie(char *g1,char *g2);
void instrukcje();
int main()
{
  char wybor=0;
  while(1)
  	{
  	printf("Gry Penney`a\n-MENU-\n\n1.Nowa gra\n2.Instrukcja\n3.Wyjscie\n\nTwoj wybor:");
  	wybor=getchar();
	if(wybor=='1') nowa_gra(); 
	else if(wybor=='2') instrukcje(); 
	else if(wybor=='3')  return 0; 
   	else if(wybor) system("cls"); 
  	}
}	 

  void nowa_gra()
  {
	system("cls");
	int dlugosc_serii;
	int win1=0,win2=0,zwyciestwo=2,ilosc,index;
	char *g1,*g2,contin,iloscchar[32];
	g1=ustal_seria(g1,dlugosc_serii,1);
	g2=ustal_seria(g2,dlugosc_serii,2);
	printf("\nSTART\n");
	system("cls");
	while(1)
	{
		CONT:
		index=0;
		printf("\n\nOPCJE");
		printf("\n1.Pojedynkuj\n2.Powrot do menu");
		printf("\n\nTwoj wybor:");
		contin=getchar();
		if(contin=='2') break;
		if(contin=='1')
		{
			system("cls");
		  	printf("\n\nLiczba walk:");
		  	scanf("%d",&ilosc);
		  	ilosc++;	
		}
		else
		{
			system("cls");
			goto CONT;
		}  
		while(index++<ilosc)
		 {
		 system("cls");
		 printf("\nGracz 1=%s          Wynik:%d\n ",g1,win1);
		 printf("\nGracz 2=%s          Wynik:%d\n ",g2,win2);
		 printf("\nPrzebieg:");
		 zwyciestwo=losowanie(g1,g2);
		 if(zwyciestwo==1) {win1++; zwyciestwo=2;}
		 else if (!zwyciestwo){win2++; zwyciestwo=3;}
	     }
	     printf("\n\n\n");
		 system("pause");
    }
	free(g1);
	free(g2);
	system("cls");
  }

    char* ustal_seria(char *seria, int dlugosc_serii, int m)
    {
    	printf("\nGracz %d- Podaj jego serie (tylko (o)rzelki i (r)eszki).\nENTER konczy podawanie:",m);
		int a=0,b=0;
		char znak=NULL;
		bool koniec=false;
		int zm_p=1;
		seria=(char*) malloc(zm_p * sizeof(char));
		seria=NULL;
    	while(seria==NULL || koniec==false)
    	{
    		scanf("%c",&znak);
    		if(islower(znak))
    		{
    			if(znak=='o'||znak=='r')
				{
					seria = realloc(seria, zm_p+=1 * sizeof(int));
					seria[a]=znak;
					a++;
				}
			}
    		if(znak=='\n' && seria!=NULL) koniec=true;
    	}
    	seria[a]='\0';
    	printf("Podales:%s\n",seria);
    	return seria;
    }
    
    int losowanie(char *g1,char *g2)
    {
    	int proba=0,pamiec=STOSP;
    	double *liczby=(double*)malloc(STOSP * sizeof(double));
    	char *strmon=(char*)malloc(STOSP * sizeof(int));
    	srand((unsigned int) time(NULL));
    		LOOP: 
    		liczby[proba]=rand()%2;
    		if(liczby[proba]==1) strmon[proba]='o';
    		else if(liczby[proba]==0) strmon[proba]='r';
    		printf("%c",strmon[proba]);
    		liczby=realloc(liczby,++pamiec * sizeof(double));
    		strmon=realloc(strmon,pamiec * sizeof(int));
    		if(strstr(strmon,g1))
    		{
    			free(liczby);
    			free(strmon);
    			return 1;
    		}
    		if(strstr(strmon,g2))
    		{
    			free(liczby);
    			free(strmon);
    			return 0;
    		}
    		++proba;
    		goto LOOP;
    } 
    
void instrukcje()
{
	system("cls");
	printf("Zasady tej gry sa proste !\n\n");
	printf("Dwoch graczy, wybiera sobie 2 serie rzutow moneta(orzelki lub reszki)\n");
	printf("Nastepuje losowanie, w ktorym partie wygrywa ten gracz, ktorego seria\n");
	printf("zostanie wylosowana jako pierwsza. \n\nMozna ustalic bardzo rozlegla liczbe ");
	printf("takich pojedynkow, by sprawdzic \nktora seria w takim losowaniu ma wieksza ");
	printf("szanse powodzenia !\n\n");
	system("pause");
	system("cls");
}
