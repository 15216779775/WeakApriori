#include<stdio.h>
#include"StdAfx.h"
int sup=3;
int NowLength=0;
int maxlength=0;
int a[10000];
int b[10000][10000];//输出用的项集 
int c[10000][10000];//中间过渡
FILE *r;
FILE *w;
int Count(int *a)
{
	int count=0;
    for (int i=0;i<100000;i++)
       {
          int x;int p=0;
		  char c=' ';
		  while  (c!='\n')
		  {
			 fscanf(r,"%d%c",&x,&c);
			 if (a[p]==x)  p++;
             if (a[p]<x) {p=0;continue;}
             if (p==NowLength) count++;
			 a[x]++;
		  }
       }
	return count;
}
int init()
{
    int t;
    for (int i=0;i<10;i++)
    {
		int l=0;
		char c=' ';
		while  (c!='\n')
		{
			l++;
			fscanf(r,"%d%c",&t,&c);
			a[t]++;
		}
		if (l>maxlength) maxlength=l;
	}
	for (int i=0;i<10;i++)
	{
	   if (a[i]>sup) 
	   {
		    b[0][0]++;
			b[b[0][0]][1]=i;
	   } 
	}
   return 0;
}
int countSim(int *a,int *b,int l)// 计算两个数组的最大相似长度(认为是有序数组)
{
	int c=0;
    int i=1,j=1;
	while ( i<=a[0] & j<b[0])
	{
		while (a[i]==a[j] && i<=a[0] && j<b[0]){i++;j++; c++;}
		if (a[i]>a[j]) j++;
		else if (a[j]>a[j]) i++;
	}
	return l;
}
int countDiff(int *a,int *b ,int x)//计算两个数组的不相似度
{
	int l=0;
	int i=1,j=1;
	while (l<2)
	{
		if (a[i]==b[j]){i++;j++;}if (i>x) break;if (j>x) break;
		if (a[i]<b[j]){i++; l++;}if (i>x) break;
		if (a[i]>b[j]){j++; l++;}if (j>x) break;
	}
   return 0;
}
int movc2b()
{
  for (int i=0;i<100000;i++)
	  for (int j=0;j<100000;j++)
		  b[i][j]=c[i][j];
  return 0;
}
void mergaTest(int *a,int *b)//将一定能够合并的数组合并起来
{
	//merga
	int cc[100000];//用于合并的数组
	int i=0,j=0;
	cc[0]=0;
	while (cc[0]<NowLength)
	{
		if (a[i]==b[j]){ cc[0]++;cc[cc[0]]=a[i];}
		else
		{
			cc[0]++;cc[cc[0]]=a[i];
			if (a[i]<b[j]) i++;
		     else j++;
		}
	    if(cc[0]==NowLength) break;
	}
	int count=Count(cc);
	if (count>=sup)
	{
		c[0][0]++;
	    int tmp=c[0][0];
		for (int i=1;i<100000;i++) c[tmp][i]=cc[i];
	}
	i=0;j=0;
	cc[0]=0;
	while (cc[0]<NowLength)
	{
		if (a[i]==b[j]){ cc[0]++;cc[cc[0]]=a[i];}
		else
		{
			cc[0]++;cc[cc[0]]=b[j];
			if (a[i]<b[j]) i++;
		     else j++;
		}
	    if(i==NowLength) break;
	}
	count=Count(cc);
	if (count>=sup)
	{
		c[0][0]++;
	    int tmp=c[0][0];
		for (int i=1;i<100000;i++) c[tmp][i]=cc[i];
	}
}
void get()
{
	for (int i=1;i<=b[0][0]-NowLength+1;i++)
		 for (int j=i+1;j<b[0][0];j++)
		 {
			if (countDiff(b[i],b[j],1)==1)
			{
			    mergaTest(b[i],b[j]);
			}
		 }
}
int main()
{
	FILE *r=fopen("asdasdas","r");
	FILE *w=fopen("asdad","w");
    init();
    for (NowLength=2;NowLength<=maxlength;NowLength++)
	{
		get();
	}
	fprintf(w,"%d",1);
	fclose(r);
	fclose(w);
	return 0;
}
