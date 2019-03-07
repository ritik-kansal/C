#include<stdio.h>
#include<string.h>
#include<windows.h>
int fact(n)
    {
        if(n==1)
            return 1;
        else
            return n*fact(n-1);
    }
int main()
    {
        int n,v=10,fg;
        printf("Enter numbers in list: ");
        scanf("%d",&n);
        int f=fact(n);
        printf("fact=%d\n",f);
        int cv,flag,loop,i,j,k;
        printf("checkpoint1\n");
        char a[f][n][v],ac[f][n],b[n][v];
        printf("checkpoint2\n");
        printf("Enter elements of list separated by space: ");
        for(i=0;i<n;i++)//input elements
        {
            fflush(stdin);
            gets(b[i]);//scanf("%d",&b[i]);
            puts(b[i]);
            printf("\n");
        }
        for(j=0;j<n;j++)//permutations formed and stored in first layer of cubical storage
        {
            k=j-1;
            for(i=0;i<f;i++)
            {
                if((i)%(fact(n-j)/(n-j))==0)
                {
                    k++;
                }
                    if(k>=n)
                {
                    k=k/n-1;
                }
                for(cv=0;cv<j;cv++)
                {
                    if(a[i][cv][0]==k)
                    {
                        k++;
                        cv=-1;
                    }
                    if(k>=n)
                    {
                        k=k%n;
                    }
                }
                a[i][j][0]=k;
                ac[i][j]=k;
            }
        }
        for(j=0;j<f;j++)
        {
            for(i=0;i<n;i++)
            {
                for(fg=0;1;fg++)
                {
                    a[j][i][fg]=b[ac[j][i]][fg];
                    if(b[i][fg]=='\0')
                    break;
                }
            }
        }
        for(i=0;i<f;i++)
        {
            flag=0;
            for(cv=0;cv<i;cv++)
            {
                flag=0;
                for(j=0;j<n;j++)
                {
                    //printf("a[i][j]=%s a[cv][j]=%s\n",a[i][j],a[cv][j]);
                    if(!strcmp(a[i][j],a[cv][j]))
                    {
                       // printf("                  flag statement true flag=%d\n",flag);
                        flag++;
                    }
                }
               // printf("\nflag=%d n=%d\n",flag,n);
                if(flag==n)
                    break;
            }
            if(flag!=n)
            {
                for(j=0;j<n;j++)
                {
                    printf("%s  ",a[i][j]);
                }
                printf("\n");
            }
        }
    }