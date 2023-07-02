#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ull unsigned long long 
using namespace std;
FILE *Finn,*Fout,*Fstd,*Fres;
const int N=5005;
int n,c,ans,a[N],b[N];
char ch[N*10];
void Return(double p,int s){
	fprintf(Fres,"%.3lf\n%d",p,s);
	exit(0);
}
int	main(int args, char** argv){
	Finn=fopen("walk.in","r");
	Fstd=fopen("walk.out","r");
	Fout=fopen("walk.me","r");
	Fres=fopen("walk.judge","w");
	
	fscanf(Finn,"%d%d",&n,&c);
	for(int i=1;i<=n;i++)fscanf(Finn,"%d",&a[i]);
	for(int i=1;i<=n;i++)fscanf(Finn,"%d",&b[i]);
	fscanf(Fout,"%s",ch);
	int t1=1,t2=1;
	for(int i=0;i<=2*(n-1);i++){
		if(t1>n||t2>n)Return(0,0);
		ans+=a[t1]*b[t2]%c;
		if(ch[i]=='D')t1++; else if(ch[i]=='R')t2++; else if(i<2*(n-1))Return(0,0);
	}
	int t;
	fscanf(Fstd,"%d",&t);
	if(ans>t)Return(2,1200); else
	if(ans==t)Return(1,114514);
	else if(ans*5>=t*4)Return(0.2,500);
	else Return(0,1);
}
