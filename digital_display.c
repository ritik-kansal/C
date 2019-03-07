#include<stdio.h>
#include<math.h>
void agd(int k)
    {
        int i;
        printf(" ");
        if(k==1)
        {
            for(i=0;i<3;printf("-",i++));
        }
        printf("  ");
        if(k==0)
        {
            for(i=0;i<3;printf(" ",i++));
        }
    }
void bfde(int b,int f)
{
    int i;
    if(f==1&&b==1)
    {
            printf("|   | ");
    }
    if(b==1&&f!=1)
    {
            printf("    | ");
    }
    if(f==1&&b!=1)
    {
            printf("|     ");
    }
}
int not(a)
{
    if(a==1)
        return 0;
    if(a==0)
        return 1;
}
int or(a,b)
{
    if(a==1||b==1)
        return 1;
    else
        return 0;
}
int and(a,b)
{
    if(a==0||b==0)
        return 0;
    else
        return 1;
}
int main()
    {
        int n;
        printf("enter number:");
        scanf("%d",&n);
        int b[10][4];
        int i,c,s,d=1,z,j,r,a1,b1,c1,d1,e1,f1,g1;
        c=n;
        for(i=0;n!=0||i==0;i++)//001
        {
            n=n/10;
        }
        n=c;
        c=i;
        for(i=0;i<c;i++)
        {
            d=d*10;
        }
        for(i=0;i!=c;i++)
        {
            j=0;
            s=n/(d/10);
            n=n%(d/10);
            d=d/10;
            for(r=3;r>=0;r--)
            {
                if(pow(2,r)<=s)
                {
                    b[i][r]=1;
                    s=s-pow(2,r);
                    j=1;
                }
                else
                {
                    b[i][r]=0;
                }
            }
        }
        for(z=0;z<=4;z++)
        {
            for(i=0;i!=c;i++)
            {
                   if(z==0)
                   {
                      a1=or(or(b[i][3],b[i][1]),or(and(b[i][2],b[i][0]),and(not(b[i][2]),not(b[i][0]))));
                      agd(a1);
                   }
                   if(z==1)
                   {
                       b1=or(or(not(b[i][2]),and(not(b[i][1]),not(b[i][0]))),and(b[i][1],b[i][0]));
                       f1=or(b[i][3],or(and(not(b[i][1]),not(b[i][0])),or(and(b[i][2],not(b[i][1])),and(b[i][2],not(b[i][0])))));
                       bfde(b1,f1);
                   }
                   if(z==2)
                   {
                       g1=or(or(and(not(b[i][2]),b[i][1]),and(b[i][1],not(b[i][0]))),or(and(b[i][2],not(b[i][1])),b[i][3]));
                       agd(g1);
                   }
                   if(z==3)
                   {
                       c1=or(or(b[i][2],not(b[i][1])),b[i][0]);
                       e1=or(and(not(b[i][2]),not(b[i][0])),and(b[i][1],not(b[i][0])));
                      bfde(c1,e1);
                   }
                   if(z==4)
                   {
                       d1=or(or(or(and(not(b[i][2]),not(b[i][0])),and(b[i][1],not(b[i][0]))),or(and(and(b[i][2],not(b[i][1])),b[i][0]),and(not(b[i][2]),b[i][1]))),b[i][3]);
                       agd(d1);
                   }
            }
            printf("\n");
        }
    }
