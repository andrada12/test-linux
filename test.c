#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produs{
   int id;
   char denumire[30];
   float pret;
}Produs;


Produs* creare(char const *argv[])
{
  Produs *v;
  FILE *f;
  int s;
  f=fopen(argv[1], "r");
  fscanf(f,"%d",&s);
  v=(Produs *)malloc(s*sizeof(Produs));
  return v;
}


int cmp(const void *p, const void *q)
{
	char l[20];
	strcpy( l, ((Produs *)p)->denumire);
	char r[20];
	strcpy(r, ((Produs *)q)->denumire);
	return strcmp(l,r);
}

int cmp2(const void *p, const void *q)
{
	int l=((Produs *)p)->id;
	int r=((Produs *)q)->id;
	return (l-r);
}

int cauta(char *s, Produs v[], int i)
{
	Produs *t, aux;
	strcpy(aux.denumire,s);
	t=(Produs *)bsearch(&aux,v,i,sizeof(Produs),cmp);
	return t-v;
}

int main(int argc, char const *argv[])
{
  Produs *v;
  v=creare(argv);

  FILE *f;
  int i=0,j,capacitate=5,indice_prod;
  char prod[30];
  f=fopen(argv[1],"r");
  v=(Produs *)malloc(5*sizeof(Produs));
  while(fscanf(f,"%d%s%f", &v[i].id, v[i].denumire, &v[i].pret) != EOF)
   { 
   	i++;
   	if(i==capacitate)
   	{   capacitate=2*capacitate;
   		v=(Produs *)realloc(v,10*sizeof(Produs));
   	}
   	printf("%d %s %f\n", v[i-1].id, v[i-1].denumire, v[i-1].pret);
   }
   printf("\n");
   /*qsort(v,i, sizeof(Produs),cmp);
   for(j=0;j<i;j++)
   	   	printf("%d %s %f\n", v[j].id, v[j].denumire, v[j].pret);*/
   	printf("%s\n", "Introdu produsul pe care vrei sa il cauti: ");
   	scanf("%s",prod);
   	indice_prod=cauta(prod,v,i);
   	printf("%f\n", v[indice_prod].pret);


   return 0;

}
