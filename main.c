#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char z[4][8];

void movie_list();
void zootopia();
void confirm();
void logout();
void payment();
void summary1();
void summary2();
void login()
{
    char nm[30],ph[10],pw[6];
    printf("Enter Name:\n");
    scanf("%s",nm);
    printf("Enter Mobile Number:\n");
    scanf("%s",ph);
    for(;;)
    {
        printf("Enter your 6 letter password:\n");
        scanf("%s",pw);
        if(strlen(pw) != 6)
        {
            printf("Password incorrect\n");
        }
        else 
          break;
    }
    printf(" %s you have successfully logged in to Book My Ticket!!!\n ",nm);
}

void movie_list()
{
    int n;
    printf("Movies for the day!!!\n");
    printf("1.Zootopia\n");
    printf("2.Inside Out\n");
    printf("3.Ron's Gone Wrong\n");
    printf("Select the movie\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:zootopia();break;
        //case 2:inside_out();break;
        //case 3:rons_gone();break;
    }
}

void zootopia()
{
    FILE * fp;
    int offset;
    fp=fopen("zero.txt","r+");
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<7;j++)
        {
            fscanf(fp," %c",&z[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
             printf("%c\t",z[i][j]);
        }
        printf("\t");
        for(j=3;j<7;j++)
        {
            printf("%c\t",z[i][j]);
        }
        printf("\n");
    }
        int n;
        int c,r;char s[3];
      
        char o='1';
        printf("No.of.seats\n");
        scanf("%d",&n);
        printf("Select the seats\n");
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
          
            c=(int)(s[0]-'1');
            r=(int)(s[1]-'@');
          
            rewind(fp);
            offset=(r*7)+c;
            fseek(fp,offset,SEEK_CUR);
         
            z[r][c]='1';
        }
      for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
             printf("%c\t",z[i][j]);
        }
        printf("\t");
        for(j=3;j<7;j++)
        {
            printf("%c\t",z[i][j]);
        }
        printf("\n");
    }
    confirm();
}

void confirm()
{
    int ch,n;
    printf("Do you want to cofirm the booking\n");
    printf("1.Yes\n2.No\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    if(ch==1)
      payment();
    else 
    {
      printf("1.Go to the movie list\n2.Exit from the website\n");
      printf("Enter your choice\n");
      if(n==1)
        movie_list();
      else 
        logout();
    }
}

void logout()
{
    printf("Logging out\n");
    exit(0);
}

void summary()
{
    //To print the current date 
    printf("Ticket summary\n");
    printf("%s\n",__DATE__);
    printf("%s\n",__TIME__);
    printf("Movie Name\n");
    printf("Cost of ticket\n");
    printf("Seat Numbers\n");
    /* //To print the current day
    char buffer[32];
    struct tm *ts;
    size_t last;
    time_t timestamp = time(NULL);
    ts   = localtime(&timestamp);
    last = strftime(buffer, 32, "%A", ts);
    buffer[last] = '\0';
    printf("%s\n", buffer);*/
}

void payment()
{
    int ch;
    char atmno[20],cvv[3],holdnm[20];
    float cost,amount;
    printf("Total cost of the ticket is %f",cost);
    printf("1.Online Payment\n2.Offline Payment\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter your ATM number\n");
        scanf("%s",atmno);
        printf("Enter your CVV\n");
        scanf("%s",cvv);
        printf("Card Holder Name\n");
        scanf("%s",holdnm);
        printf("Enter the amount\n");
        scanf("%f",amount);
        summary1();
    }
    else
        summary2();
}

void summary1()
{
    printf("Payment mode:Online\n");
    printf("Rules and guidelines\n");
    printf("Please download the e-ticket sent to your registered mobile number\n");
    printf("Please be present at movie theatre 30 minutes prior to the show time\n");
    printf("No food and beverages from outside are allowed\n ");
    summary();
}

void summary2()
{
    printf("Payment mode:Offline\n");
    printf("Rules and guidelines\n");
    printf("Tickets will be confirmed after successful payment \n");
    printf("Payment must be done 1 hour prior to the show timings, else tickets will be canceled\n");
    printf("No food and beverages from outside are allowed\n ");
}

int main()
{
    login();
    movie_list();
    summary();
}
