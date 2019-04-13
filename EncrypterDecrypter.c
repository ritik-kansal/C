#include<stdio.h>
#include<windows.h>
int main()
{
    printf("********************************CRYPTOGRAPHER********************************\n");
    int status;
    while(status)
    {    
        int choice;
        printf("For \n   Encryption Press 1\n   Decryption Press 2\n                     :");
        scanf("%d",&choice);
        if(choice==1)
        {
            int key,i;
            printf("Enter your key(any number) for cipher:");
            scanf("%d",&key);
            getchar();
            char s[100],e[100],c;
            printf("Enter your text (you can use maximum 100 charachters):");
            gets(s);
            for(i=0;s[i]!=0;i++)
            {
                if(s[i]!=32)
                {
                    c=s[i]-key;
                    if(c<65&&s[i]<=90&&s[i]>=65)
                        c=90-(65-c-1);
                    if(c<97&&s[i]<=122&&s[i]>=97)
                        c=122-(97-c-1);
                    e[i]=c;
                }
                else
                    e[i]=32;
            }
            printf("\n\n\nEncrypted text is \n");

            for(i=0;s[i]!=0;i++)
            {
                printf("%c",e[i]);
                Sleep(250);
            }
        }
        else
        {
            int key,i;
            printf("Enter your key(any number) for decryption:");
            scanf("%d",&key);
            getchar();
            char s[100],e[100],c;
            printf("Enter your text (you can use maximum 100 charachters):");
            gets(s);
            for(i=0;s[i]!=0;i++)
            {
                if(s[i]!=32)
                {
                    c=s[i]+key;
                    if(c>90&&s[i]<=90&&s[i]>=65)
                        c=65+(c-90-1);
                    if(c>122&&s[i]<=122&&s[i]>=97)
                        c=97+(c-122-1);
                    e[i]=c;
                }
                else
                    e[i]=32;
            }
            printf("\n\n\nDecrypted Text is \n");
            for(i=0;s[i]!=0;i++)
            {
                printf("%c",e[i]);
                Sleep(250);
            }
        }
        printf("\n\n\nTo Run Program Again Type 1 otherwise type 0:");
        scanf("%d",&status);
    }
}