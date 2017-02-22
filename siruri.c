#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void put(char* s[], char *p, int l)
{
	s[l]=p;
}

int cauta(char* s[], char *p, int l)
{
	int i;
	for(i=0;i<l;i++)
		if(strcmp(s[i],p))
			return 1;
	return -1;
}

char *nxtid(char* s, char* id)
{
	int i=0;
	while( 1 )
	{
		if( *(s+i) == *id ) 
			{id=(s+i+1); printf("%d\n", i); return id;}
		i++;
	}
	return s;
}

int pseudocmp(char s[], char d[])
{
	int i=0,j=0,ok=0;
	while(ok==0 )
	{
		if(s[i]<d[j])
			ok=-1;
		else
			ok=1;
		i++;j++;

	}
	return ok;
}

int puting(int n, void* tab[][2], char* nume, int val)
{
	tab[n][1]=nume;
	tab[n][2]=val;
	return n+1;	
}


int neg_poz(int a[][100], int neg[], int poz[],int m, int n)
{
	int i,j,p_neg=0,p_poz=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(a[i][j]<0)
			{
				neg[p_neg]=a[i][j];
				p_neg++;
			}
			
				if(a[i][j]>0)
				{
					poz[p_poz]=a[i][j];
					p_poz++;
				}
		}
		return p_poz;
}

void scriere(char const *argv[])
{
	int s=1, v=2;
	FILE *f=fopen(argv[1],"wb");
	fwrite(&s,1,sizeof(int),f);
	fwrite(&v,1,sizeof(int),f);
	fclose(f);
}

void citire(char const *argv[])
{
	FILE *f=fopen(argv[1],"rb");
	int j,v[3],k,i=0;
	while(fread(&k,1,sizeof(int),f))
	//fread(&j,1,sizeof(int),f);
	printf("%d \n", k);
	
	fclose(f);
}


int main(int argc, char const *argv[])
{
	
  /*char* s[10];
  char unu[10],doi[10];
  char *p, *k,*a,*b,*d;
  p=(char *)malloc(20*sizeof(char));
  k=(char *)malloc(20*sizeof(char));
  a=(char *)malloc(20*sizeof(char));
  b=(char *)malloc(20*sizeof(char));
  d=(char *)malloc(20*sizeof(char));

  strcpy(p,"iubi ma iubeste");
  strcpy(k,"motanedragut");
  strcpy(a,"suntplictisita");
  strcpy(b,"vreausamafacblonda");
  strcpy(d,"m");

  s[0]=p;
  s[1]=k;
  s[2]=a;
  s[3]=b;

  scanf("%s%s",unu,doi);
  printf("%d %d\n", pseudocmp(unu,doi), strcmp(unu,doi));
  //d=nxtid(p,d);
  //printf("%s\n", d);*/

	/*void* tab[20][2]; 
	int n=0,i;
	char s[10]="meow";
	for(i=1;i<10;i++)
		n=puting(n,tab,s,3);
	for(i=0;i<n;i++)
		printf("%s %d\n", tab[i][1], tab[i][2] );
	return 0;*/

	/*int a[100][100], i,j,n ,m,neg[1000],poz[1000];
	int p_poz, p_neg;
	scanf("%d%d", &n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d", &a[i][j]);
	p_poz=neg_poz(a,neg,poz,m,n);
	p_neg=(n*m)-p_poz;
	for(i=0;i<p_poz;i++)
		printf("%d ", poz[i] );
	printf("\n");
	for(i=0;i<3;i++)
		printf("%d ", neg[i] );
	printf("\n");*/
	scriere(argv);
	citire(argv);



   return 0;
}