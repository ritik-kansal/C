#include<stdio.h>
#include<windows.h>
char a[5][5]={};
int i,j,m=0,x,y,s=0,sum;
char thinking[]={"THINKING ---->"};
char resultl[]={"YOU LOSE"};
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
                if(s==1)
                a[2][0]='X';
                else
                a[0][2]='X';
            }
            else
            {
                s=1;
                if(s==1)
                a[0][4]='X';
                else
                a[4][0]='X';
            }
        }
    }
void output()
    {
        think();
        printf("\n");
        for(y=0;thinking[y]!='\0';y++)
        {
            printf("%c",thinking[y]);
            //Sleep(250);
        }
        printf("\n\n\n");
        display();
        Sleep(500);
    }
void input()
    {
        printf("\nWhere you want to enter \"O\":");
        scanf("%d%d",&i,&j);
        a[i][j]='O';
        m++;
    }
void output2()
    {
        
        int i2,j2,s2=0,jasos=1,sum2[8]={0};
        sum2[s2]=0;
        j2=0;
        //diagnol 1 sum 
        for(i2=0;i2<5;i2+=2)
        {
            sum2[s2]+=a[i2][j2];
            j2+=2;
        }
        //computer move
        if(sum2[s2]==158||sum2[s2]==176)
        {
            jasos=0;
            j2=0;
            for(i2=0;i2<5;i2+=2)
            {
                if(a[i2][j2]==32)
                {
                    a[i2][j2]='X';
                }
                j2+=2;
            }
        }
        //diagnol 2 sum

            s2++;
            sum2[s2]=0;
            i2=4;
            for(j2=0;j2<5;j2+=2)
            {
                sum2[s2]+=a[i2][j2];
                i2-=2;
            }
        //computer move
            if(sum2[s2]==158||sum2[s2]==176)
            {
                jasos=0;
                i2=4;
                for(j2=0;j2<5;j2+=2)
                {
                    if(a[i2][j2]==32)
                    {
                        a[i2][j2]='X';
                    }
                    i2-=2;
                }
            }    
        //rows sum

            s2++;
            for(i2=0;i2<5;i2+=2)
            {
                sum2[s2]=0;
                for(j2=0;j2<5;j2+=2)
                {
                    sum2[s2]+=a[i2][j2];
                }
                //computer move
                if(sum2[s2]==158||sum2[s2]==176)
                {
                    jasos=0;
                    for(j2=0;j2<5;j2+=2)
                    {
                        if(a[i2][j2]==32)
                        {
                            a[i2][j2]='X';
                        }
                    }
                }
                
                s2++;
            }
        //column sum
            for(j2=0;j2<5;j2+=2)
            {
                sum2[s2]=0;
                for(i2=0;i2<5;i2+=2)
                {
                    sum2[s2]+=a[i2][j2];
                }
                if(sum2[s2]==158||sum2[s2]==176)
                {
                    jasos=0;
                    for(i2=0;i2<5;i2+=2)
                    {
                        if(a[i2][j2]==32)
                        {
                            a[i2][j2]='X';
                        }
                    }
                }
               // j2++;
                s2++;
            }
    }
int main()
    {
        setup();
        printf("                                COMPUTER MOVES FIRST\n");
        printf("***********************************************************************************\n");
        a[2][2]='X';
        display();
        input();
        if(detect(i,j))
        { 
            output();
           // output2();
            input();
            output();
           // output2();
            if(s)
            {
                input();
                output();
              //  output2();
            }
        }
        else
        {
            output2();
            display();
            // input2();
            // output2();
            // input2();
            // output2();
            // input2();
            // output2();
        }
        getch();
    }