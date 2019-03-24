#include<stdio.h>
#include<windows.h>
char a[5][5]={};
int i,j,m=0,x,y,s=0,sum;
char thinking[]={"---->"};
char resultl[]={"!!!YOU LOSE"};
char win[]={"DRAW!!!"};
int setup()
    {
        for(i=0;i<5;i++)
        {
            if(i==1||i==3)
            {
                a[i][1]='-';
                a[i][3]='-';
            }
        }
        for(i=0;i<5;i=i+2)
        {
            a[i][1]='|';
            a[i][3]='|';
            a[1][i]='-';
            a[3][i]='-';
        }
        return 0;
    }
void display()
    {
        int i,j;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
int detect(int a,int b)
    {
        int p;
        if((a==2||b==2)&&(a*b!=4))
        {
            p=1;
        }
        else
        {
            p=0;
        }
        return p;
    }
int didblock(int z,int v)
    {
        sum=0;
        y=0;
        if(z==0&&v==0)
        for(x=0;x<5;x++)
        {
            sum=sum+a[x][y];
            x++;
            y=y+2;
        }
        if(z==4&&v==0)
        {
            x=4;
            sum=0;
            for(y=0;y<5;y=y+2)
            {
                sum=sum+a[x][y];
                x=x-2;
            }
        }
        if(sum==255)
            return 1;
        return 0;
    }
void think()
    {
        int p=detect(i,j);
        if(m==1)
        {
            if(p==1)
            {
                a[0][0]='X';
            }
        }
        if(m==2)
        {
            if(didblock(0,0))
            {
                if(a[4][2]=='O'||a[0][2]=='O')
                {
                    a[4][0]='X';
                    s=1;
                }
                else
                {
                    a[0][4]='X';
                    s=1;
                }
            }
            else
            {
                a[4][4]='X';

            }
        }
        if(m==3)
        {
            if(didblock(4,0))
            {
                if(a[4][2]=='O'||a[0][2]=='O')
                a[2][0]='X';
                else
                a[0][2]='X';
            }
            else
            {
                s=1;
                //printf("did not blocked at 4,0 at move 3");
                i=4;
                for(j=0;j<5;j+=2)
                {
                    if(a[i][j]==0)
                    a[i][j]='X';
                    i-=2;
                }
            }
        }
    }
void output()
    {
        think();
        printf("THINKING ");
        for(y=0;thinking[y]!='\0';y++)
        {
            printf("%c",thinking[y]);
            Sleep(250);
        }
        printf("\nTHINKING ");
        for(y=0;thinking[y]!='\0';y++)
        {
            printf("%c",thinking[y]);
            Sleep(250);
        }
        printf("\n\n\n\a");
        display();
        //Sleep(500);
    }
void input()
    {
        enteragain: 
        printf("\n\n(Type '3 2'  if you want to enter 'O' at third row and second column without quotes)\nWhere you want to enter \"O\":");
        scanf("%d%d",&i,&j);
        
        if(i==1)
        i=0;
        if(i==3)
        i=4;
        if(j==1)
        j=0;
        if(j==3)
        j=4;
        
        if(a[i][j]==0)
        a[i][j]='O';
        else
        {
            printf("Wrong entry\n\n\n");
            goto enteragain;
        }
        m++;
    }
int output2()
    {
        int i1;
        printf("THINKING ");
        for(i1=0;thinking[i1]!='\0';i1++)
        {
            printf("%c",thinking[i1]);
            Sleep(250);
        }
        printf("\nTHINKING ");
        for(i1=0;thinking[i1]!='\0';i1++)
        {
            printf("%c",thinking[i1]);
            Sleep(250);
        }
        printf("\n\n\n\a");
        int i2=0,j2=0,s2=0,jasos=1,sum2[8]={0},b=1;
        if(m==1)
        {
            if(a[0][0]=='O')
            a[4][4]='X';
            if(a[4][4]=='O')
            a[0][0]='X';
            if(a[4][0]=='O')
            a[0][4]='X';
            if(a[0][4]=='O')
            a[4][0]='X';
        }
        if(m!=1)
        {
            //diagnol 1 sum
            j2=0;
            for(i2=0;i2<5;i2+=2)
            {
                sum2[s2]+=a[i2][j2];
                j2+=2;
            }
            if(sum2[s2]==176)
            {
                b=0;
                j2=0;
                for(i2=0;i2<5;i2+=2)
                {
                    if(a[i2][j2]==0)
                    a[i2][j2]='X';
                    j2+=2;
                }
            }
            //diagnol 2 sum
            if(b)
            {
                s2++;
                i2=4;
                for(j2=0;j2<5;j2+=2)
                {
                    sum2[s2]+=a[i2][j2];
                    i2-=2;
                }
                if(sum2[s2]==176)
                {
                    b=0;
                    i2=4;
                    for(j2=0;j2<5;j2+=2)
                    {
                        if(a[i2][j2]==0)
                        a[i2][j2]='X';
                        i2-=2;
                    }
                }
            }
            if(b)
            {
                //row sum
                s2++;
                for(i2=0;i2<5;i2+=2)
                {
                    for(j2=0;j2<5;j2+=2)
                    {
                        sum2[s2]+=a[i2][j2];
                    }
                    if(sum2[s2]==176)
                    {
                        b=0;
                        for(j2=0;j2<5;j2+=2)
                        {
                            if(a[i2][j2]==0)
                            a[i2][j2]='X';
                        }
                    }
                s2++;
                }
            }
            if(b)
            {
                //col sum
                for(j2=0;j2<5;j2+=2)
                {
                    for(i2=0;i2<5;i2+=2)
                    {
                        sum2[s2]+=a[i2][j2];
                    }
                    if(sum2[s2]==176)
                    {
                        b=0;
                        for(i2=0;i2<5;i2+=2)
                        {
                            if(a[i2][j2]==0)
                            a[i2][j2]='X';
                        }
                    }
                s2++;
                }
            }
            //setting sum2 again =0
            for(s2=0;s2<8;s2++)
            {
                sum2[s2]=0;
            }
            if(b)
            {
                //checking sum = 158
                //diagnol 1 sum
                j2=0;
                s2=0;
                for(i2=0;i2<5;i2+=2)
                {
                    sum2[s2]+=a[i2][j2];
                    j2+=2;
                }
                if(sum2[s2]==158)
                {
                    jasos=0;
                    j2=0;
                    for(i2=0;i2<5;i2+=2)
                    {
                        if(a[i2][j2]==0)
                        a[i2][j2]='X';
                        j2+=2;
                    }
                }
                //diagnol 2 sum
                if(jasos)
                {
                    s2++;
                    i2=4;
                    for(j2=0;j2<5;j2+=2)
                    {
                        sum2[s2]+=a[i2][j2];
                        i2-=2;
                    }
                    if(sum2[s2]==158)
                    {
                        jasos=0;
                        i2=4;
                        for(j2=0;j2<5;j2+=2)
                        {
                            if(a[i2][j2]==0)
                            a[i2][j2]='X';
                            i2-=2;
                        }
                    }
                }
                if(jasos)
                {
                    //row sum
                    s2++;
                    for(i2=0;i2<5;i2+=2)
                    {
                        for(j2=0;j2<5;j2+=2)
                        {
                            sum2[s2]+=a[i2][j2];
                        }
                        if(sum2[s2]==158)
                        {
                            jasos=0;
                            for(j2=0;j2<5;j2+=2)
                            {
                                if(a[i2][j2]==0)
                                a[i2][j2]='X';
                            }
                        }
                    s2++;
                    }
                }
                if(jasos)
                {
                    //col sum
                    for(j2=0;j2<5;j2+=2)
                    {
                        for(i2=0;i2<5;i2+=2)
                        {
                            sum2[s2]+=a[i2][j2];
                        }
                        if(sum2[s2]==158)
                        {
                            jasos=0;
                            for(i2=0;i2<5;i2+=2)
                            {
                                if(a[i2][j2]==0)
                                a[i2][j2]='X';
                            }
                        }
                    s2++;
                    }
                }
            }
            if(b&&jasos)
            {
                jasos=0;
                for(i2=0;i2<5;i2+=2)
                {
                    for(j2=0;j2<5;j2+=2)
                    {
                        if(a[i2][j2]==0)
                        {
                            jasos=1;
                            a[i2][j2]='X';
                            break;
                        }
                    }
                    if(jasos)
                    break;
                }
            }
        }
        return b;
    }
int main()
    {
        //creating display
        setup();
        printf("                                COMPUTER MOVES FIRST\n");
        printf("***********************************************************************************\n");
        a[2][2]='X';
        display();
        input();
        //detect will return 1 if not corner
        if(detect(i,j))
        {
            output();
            input();
            output();
            if(s)
            {
                input();
                output();
            }
            printf("                                ");
            for(i=0;resultl[i]!='\0';i++)
            {
                printf("%c",resultl[i]);
                Sleep(250);
            }
        }
        //if corner
        else
        {
            int b;//i=0;
            while(1)
            {
                //i++;
                b=output2();//b will be 0 if computer wins
                display();
                if(b==0||m==4)
                break;
                input();
            }
            if(b)
            {
                printf("                                ");
                for(i=0;win[i]!='\0';i++)
                {
                    printf("%c",win[i]);
                    Sleep(250);
                }
            }
            else
            {
                printf("                                ");
                for(i=0;resultl[i]!='\0';i++)
                {
                    printf("%c",resultl[i]);
                    Sleep(250);
                } 
            }
        }
        getch();
    }
