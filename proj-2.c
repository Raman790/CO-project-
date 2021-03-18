#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>



struct indianairlines{
	char name[50];
	char landingdestination[30];
    char pasportnumber[9];
	char emailid[30];
	int seatnum;
	struct indainairlines *var;
}
*start,*ptr;


void main()
{   
   void booking(int x),cusdetails(),print(),save(),login() ,cancel(void) ;
	int choice;
	start = ptr = NULL;  
	int no = 1;
	 login();
	do
	{ 
printf("\n\t                                                ***********************                               *****                                    \n");              
printf("\n\t                                               *                     *                               *    *                                              \n");
printf("\n\t                                              *                     *                              *     *                                                  \n");
printf("\n\t       ***************************************                      ******************************      *                           \n");
printf("\n\t     *      **                                                                                         *                                                                               \n");
printf("\n\t    *      **                 WELCOME                                                                 *                                                              \n");
printf("\n\t   *********                              TO    INDIAN AIRLINES                                      *                                                                       \n");
printf("\n\t  *                                                                                                 *                                                                                   \n");
printf("\n\t *                                                               FLY WTIH US                       *                                                                                    \n");
printf("\n\t  ********************************************                  ***********************************                                        \n");                                    
printf("\n\t                                              *                  *                                                                                                                \n");
printf("\n\t                                               *                  *                                                                \n");
printf("\n\t                                                ********************                                                                \n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("\n\t                      Flight Ticket Booking Counter (INDIAN AIRLINES)                                 \n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("\n\n\t MENU INDIAN AIRLINES");
printf("\n\n\t 1.BOOKING TICKET ");
printf("\n\n\t 2.DISPLAY BOOKINGS RECORDS");				  	
printf("\n\n\t 3.CANCEL YOUR TICKET");
printf("\n\n\t 4.EXIT");
printf("\n\n\t FOR MORE DETAILS VISIT: indian_airline.com");
printf("\n\n\t ENTER YOUR CHOICE :");
scanf("%d",&choice);fflush(stdin);
system("cls"); 


switch(choice)
{
	case 1: booking(no);
		    no++;
		break;
    case 2: print();
	    break;
	case 3: cancel();
	    break;
	case 4: {
		save();
		break;
	} 
	default:
		printf("\n\n INVALID CHOICE! ");
		printf("\n\n CHOOSE FORM (1-4)");
	}
	getch();
}while(choice!=4);
}

void cusdetails()
{   printf("\n\n\t CUSTOMER DETAIL FORM ");
	printf("\n\t ENTER YOUR PASSPORT NUMBER :");
	gets(ptr->pasportnumber);
	printf("\n\t ENTER YOUR NAME :");
	gets(ptr->name);
	printf("\n\tENTER YOUR DESTINATION :");
    gets(ptr->landingdestination);
	printf("\n\t ENTER YOUR EMAIL ID :");
	gets(ptr->emailid);	
}
void cusdetails();

void booking(int x)
{
	ptr=start;
	if(start == NULL)
	{  // 1st customer//
		start = ptr= (struct indianairlines*)malloc(sizeof(struct indianairlines));
	    cusdetails();
	    ptr->var= NULL ;
	    printf("\n YOUR SEAT BOOKING SUCCESSFUL!");
	    printf("\n YOUR SEAT NUMBER IS : SEAT S-%d",x);
	    ptr->seatnum=x;
	    return;
	}
	else if (x>10)
	{
		printf("\n THE AIRCRAFT IS FULL! NO SEATS AVAILABLE");
		return;
	}
	else
	{
		//for next customer
		while(ptr->var)
		ptr=ptr->var;
		ptr->var = (struct indianairlines *)malloc(sizeof (struct indianairlines));
		cusdetails();
		ptr ->var = NULL;
		printf("\n SEAT BOOKING SUCESSFUL!");
		printf("\n YOUR SEAT NUMBER IS : SEAT S-%d", x);
		ptr->seatnum=x;
		return;
	}
}
void save()
{
    FILE *fpointer =fopen("indianairlines","w");
    if(!fpointer)
    {
    	printf("\n error in opening the file");
    	return;
	}
	ptr=start;
    while(ptr)
    {
    	fprintf(fpointer, "%-9s", ptr->pasportnumber);
		fprintf(fpointer, "%-50s", ptr->name);
		fprintf(fpointer, "%-30s", ptr->emailid);
        fprintf(fpointer, "%-30s", ptr->landingdestination);
        fprintf(fpointer, "\n");
		ptr->var;
	}
	printf("\n\n FILES SAVED INDAIN AIRLINES");
	fclose(fpointer);
}
void print()
{
	ptr=start;
	while (ptr)
	{
		printf("\n\n\n NAME : %-50s",ptr->name);
		printf("\n\n PASSPORT NUMBER :%-9s",ptr->pasportnumber);
		printf("\n\n EMAIL ADDRESS:%-30s",ptr->emailid);
		printf("\n\n DESTINATION:%-30s",ptr->landingdestination);
		printf("\n\n SEAT NUMBER S-%d",ptr->seatnum);
		printf("\n============****************==============");
		ptr=ptr->var;
	}
}                 
//------------------------------------------------------------------------------------------------------                  
   void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	printf("\n=========================INDIAN AIRLINES =============================\n");
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==10) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"ramanahlawat790")==0 && strcmp(pword,"123456")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
		system("cls");
	}
}
	 while(a<=10);

		system("cls");	
return ;
}  

void cancel(void)   
{

	system("cls");
	int flightnum;
	printf("-----------------------\n");
		printf("ENTER YOUR SEAT NUMBER: \n");
			printf("-----------------------\n");
	
		scanf("%i",&flightnum);
		printf("\n\nYOUR TICKET IS CANCELLED");  
		getch();
}
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
