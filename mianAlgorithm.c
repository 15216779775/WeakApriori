#include<drdio.h>

int Count()
{
    for (int i=0;i<100000;i++)
       {
          int x;int p=0;
          while ((scanf("%d",&x)!=EOF))
          {
             if (a[p]==x)  p++;
             if (a[p]<x) {p=0;continue;}
             if (p==NowLength) return 1;
          }
       }

}
int init()
{


   return 0;
}
int main()
{
    for (int i=0;i<100000;i++){}

}
