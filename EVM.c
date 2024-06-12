#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
//#include"INTRO.h"

int candcount;

struct dates
{
	int date, month, year;
};

struct winner
{
	int num, votes;
	char fname[50], lname[50], partyname[50], symbol[10];
};

struct info
{
	char fname[10], lname[10];
	int age;
	double cnic;
};

struct info2
{
	int num;
	char fname[30];
	char lname[30];
	char partyname[100];
	char symbol[20];
}c;

struct info1
{
	char fname[10], lname[10];
	int age;
	double cnic;
}voter;

struct cand_info
{
	int num;
	char fname[30], lname[30], partyname[30], symbol[10];
};

int main()
{

	FILE *fp;
	int pin, i, mod;
	struct dates d1;
		
	//Intro();	

	system("cls");
	
	PASSWORD();
	
	int count;
	FILE *fp1;
	
	fp1 = fopen("Counts.txt","r");
	fscanf(fp1, "%d", &count);
	candcount = count;
	fclose(fp1);
	
	while(1)
	{
	
		printf("\n\nEnter Date, Month & year (dd/mm/yyyy): ");
		scanf("%d/%d/%d",&d1.date,&d1.month,&d1.year);
	
		mod = d1.year%4;
	
		if(d1.date>31 || d1.month>12 || d1.year>2021 || d1.year<2010)
		{
	
			printf("\nPlease Enter Correct Date!\n");
			continue;
	
		}
		else if(d1.date>31 && (d1.month==1 || d1.month==3 || d1.month==5 || d1.month==7 || d1.month==8 || d1.month==10 || d1.month==12))
		{
	
			printf("\nPlease Enter Correct Date!\n");
			continue;
	
		}
		else if(d1.date>30 && (d1.month==4 || d1.month==6 || d1.month==9 || d1.month==11))
		{
	
			printf("\nPlease Enter Correct Date!\n");
			continue;
	
		}
		else if(mod!=0 && d1.month==2 && d1.date>28)
		{
	
			printf("\nPlease Enter Correct Date!\n");
			continue;
	
		}
		else if(mod==2 && d1.month==2 && d1.date>29)
		{
	
			printf("\nThis is a Leap Year and Only has 29 Days!\n");
			continue;
	
		}
		else
		{
			break;
		}
	
	}
	if(d1.date<18 && d1.month<=12)
	{
	
		while(1)
		{
	
			char ans;
			int opt;
	
			printf("\nSelect Option:\n1. Voter Registration\n2. Candidate Registration.\n");
			scanf("%d",&opt);
	
			if(opt==1)
			{
	
				system("cls");
				VOTERS();
	
			}
			else if(opt==2)
			{
	
				system("cls");
				CANDIDATES();
	
			}
			else
			{
	
				printf("Please Enter Correct Option.\n");
				continue;
	
			}
			
			while(1)
			{
	
				printf("\nAny more Candidate or Voter to Register? (Y/N)\n");
				scanf(" %c",&ans);
	
				if(ans!='Y' && ans!='N')
				{
	
					printf("Please Select Correct Option.\n");
					continue;
	
				}
				if(ans=='Y')
				{
	
					break;
					system("cls");
				
				}
				else if(ans=='N')
				{
				
					printf("\nThank You for Registration.\n");
					_Exit(0);
				
				}
			
			}
	    
		}
	
	}
	
	else if(d1.date==18 && d1.month==12)
	{
	
		while(1)
		{
		
			int opt;
		
			printf("\nSelect Option:\n1. Cast Vote\n2. Leading Candidate\n");
			scanf("%d",&opt);
			if(opt==1)
			{
				VOTING();
			}
			else if(opt==2)
			{
				LEADING();
			}
			else
			{
		
				printf("\nPlease Enter Correct Option.\n");
				continue;
		
			}
	    
		}
	
	}
	
	else if(d1.date>18 && d1.month>=12)    //REMAINING
	{
		
		system("cls");
		printf("\n\t\t\tELECTRONIC VOTING MACHINE\n");
		WINNER();
	
	}

}
//VOTERS REGISTRATION
int VOTERS()
{
	FILE *fp;
	char ans;
	struct info voter;
	int flag=0;
	long int recsize;
	char fname[10], lname[10];
	int age;
	double cnic;
		
	recsize = sizeof(voter);
	
	system("cls");

//	gotoxy(50,5);
	printf("VOTERS REGISTRATION");

//	gotoxy(50,7);
	printf("\n1. Register Voters");

//	gotoxy(50,9);
	printf("\n2. List Voters");

//	gotoxy(50,11);
	printf("\n3. Exit");

//	gotoxy(50,13);
	printf("\nYour choice: ");
		
	fflush(stdin);
	ans = getche();

	switch(ans)
	{
		case '1':
			    	
			printf("\nEnter first name:\n");
			scanf("%s", &fname);
			
			printf("Enter second name:\n");
			scanf("%s", &lname);				

			printf("Enter CNIC(without hyphen):\n");
			scanf("%lf", &cnic);

			printf("Enter age:\n");
			scanf("%d", &age);

			while((cnic < 4000000000001 || cnic > 4999999999999) || (age <= 0))
		    {
		 		printf("Invalid CNIC Number/Age.\n");

				printf("Enter your CNIC(without hyphen):\n");
				scanf(" %lf", &cnic);

				printf("Enter your age:\n");
				scanf(" %d", &age);		
	        }
	            
			if(age >= 18)
	        {
	            	
				fp = fopen("Voters.txt","a+");
	        
				if(fp == NULL)
	            {    
					puts("Cannot open file");
		            exit(1);
	            }
	            
	            while(!feof(fp))
	            {
		                
					fscanf(fp, "%s %s %lf %d", voter.fname, voter.lname, &voter.cnic, &voter.age);
	                	
	                if(voter.cnic == cnic)
	                {
	    	            flag = 1;
			            break;
		            }

	            }
		            
				if(flag == 0)
		        {
            		strcpy(voter.fname,fname);
            		strcpy(voter.lname,lname);
                    voter.age = age;
					voter.cnic = cnic;
				    
					fp = fopen("Voters.txt","a");
					
					fprintf(fp,"\n%s %s %.0lf %d", voter.fname, voter.lname, voter.cnic, voter.age);
				    printf("Voter successfully registered.\n");
				}
				
				else if(flag == 1)
				{
					printf("CNIC already registered.\n");
				}	            	
			}
				
			else
			{
				printf("You are not eligible to vote.\n");
				exit(0);
			}
            break;
        case '2':
            
			fp = fopen("Voters.txt","r");
            
			if(fp == NULL)
            {
            		
					puts("Cannot open file");
					exit(1);
			}

			while(!feof(fp))
	        {
		            
				fscanf (fp, "%s %s %lf %d",voter.fname, voter.lname, &voter.cnic , &voter.age); 
		        printf("\n%s %s %.0lf %d\n",voter.fname,voter.lname,voter.cnic,voter.age);
            }
			break;
		case '3':
			exit(0);
	}		
	
	fclose (fp);
}
// CANDIDATES REGISTRATION
int CANDIDATES()
	{
		printf("\t\t\t\t\tCandidate`s Registration\n\n");
	
		FILE *fptr;
	
		puts("Entre candidate`s voting number, name, respective party and symbol ?");
		puts("Entre EOF to end input");
	
		int num, flag = 0;
		char fname[30];
		char lname[30];
		char partyname[100];
		char symbol[20];
	
		printf("? ");
		printf("Voting number : ");
		scanf("%i", &num);
		fflush(stdin);
	
		printf("First name : ");
		scanf("%s", &fname);
	
		printf("Last name : ");
		scanf("%s", &lname);
	
		printf("Respective party : ");
	    scanf("%s", &partyname);
	
	    printf("Symbol : ");
	    scanf("%s", &symbol);
	
	    fptr = fopen("candidates.txt", "r");
	    if (fptr==NULL)
		{
	
			printf("File could not be opened !");
			return 0;
	
		}
		while (!feof(fptr))
		{
	
			fscanf(fptr, "%i %s %s %s %s", &c.num, c.fname, c.lname, c.partyname, c.symbol);
			if (c.num==num)
			{
	
				flag=1;
				break;
	
			}
		
		}
		if(flag == 0)
		{
	
			strcpy(c.fname,fname);
			strcpy(c.lname,lname);
			strcpy(c.partyname,partyname);
			strcpy(c.symbol,symbol);
	    
		    c.num = num;
	
		    fptr = fopen("candidates.txt","a");
			fprintf(fptr,"\n%i %s %s %s %s", c.num, c.fname, c.lname, c.partyname, c.symbol);
		    printf("Candidate successfully registered.\n");
	
		    int count;
			FILE *fp;
	
			fp = fopen("Counts.txt","a+");
			fscanf(fp,"%d",&count);
			count++;
			printf("\nCount: %d",count);
			fp = fopen("Counts.txt","w");
			fprintf(fp,"%d",count);
			fclose(fp);
	
		}
	    else if (flag==1)
		{
			printf("Candidate already registered with this Voting Number!");
		}

		fclose(fptr);

}
int VOTING()
{

	struct cand_info cand[candcount];
	FILE *fp, *fp1, *fp2;
	double cnic,cnic2;
	int vote,flag=0;
	
	//CNIC VERIFICATION
    printf("CNIC: ");
    scanf("%lf",&cnic);
	
	while(cnic<4000000000000 || cnic>4999999999999)
	{
	
	    printf("CNIC: ");
	    scanf("%lf",&cnic);
	
	}
	if ((fp = fopen("Voters(CNIC).txt","a+"))==NULL)
	{
	
		puts("Voters(CNIC).txt could not be opened");
		return 0;
	
	}
	else if ((fp2 = fopen("Voters.txt", "r"))==NULL)
	{
	
		puts("Voters.txt could not be opened");
		return 0;
	
	}
	else
	{
	
		int flag1=0;

		while(!feof(fp2))
		{
	
			fscanf(fp2,"%s %s %lf %d",voter.fname,voter.lname,&voter.cnic,&voter.age);

			if(cnic==voter.cnic)
			{

				flag1=1;
				break;

			}

		}

		if(flag1 == 1)
		{
			printf("\nYou are Registered.\n");
		}
		else
		{

			printf("\nYou are not Registered.\n");
			return;

		}

		fclose(fp2);

		int flag2=0;

		if(fp==NULL)
		{
			fprintf(fp,"\n%.0lf",cnic);
		}

		while(!feof(fp))
		{

			fscanf(fp,"%lf",&cnic2);

			if(cnic==cnic2)
			{

				flag2=1;
				break;

			}

		}

		if(flag2 == 1)
		{

			printf("\nYou have already Vote.\n");
			return;

		}
		else
		{
			printf("\nYou can Vote.\n");
		}

	}
	
	//VOTING================//VOTING

	int i=0;

	if ((fp1=fopen("candidates.txt", "r"))==NULL)
	{

		puts("candidates.txt could not be opened");
		return 0;

	}
	else 
	{

		while (!feof(fp1))
		{

			fscanf(fp1, "%i %s %s %s %s", &cand[i].num, cand[i].fname, cand[i].lname, cand[i].partyname, cand[i].symbol);
			printf("\nVoting number : %i\nCandidate`s name : %s %s\nRespective party : %s\nSymbol : %s\n\n",cand[i].num, cand[i].fname, cand[i].lname, cand[i].partyname, cand[i].symbol);
			printf("\t");
			i++;
		}
	
		fclose(fp1);
	}	

	while(flag==0)
	{
		printf("CAST YOUR VOTE: \n\n");
		scanf("%d",&vote);
		for(i=0;i<candcount;i++)
		{

			if(vote==cand[i].num)
			{

				printf("\nYou have Voted %s %s of party %s.\n",cand[i].fname,cand[i].lname,cand[i].partyname);
				flag=1;
				break;

			}

		}

		if(flag==0)
		{
			printf("\nPlease Vote the Given Candidate.\n");
			continue;
		}
		else if(flag==1)
		{
			fprintf(fp,"\n%.0lf",cnic);
			fclose(fp);
			break;
		}

	}
	
	FILE *fp3;
	
	int j,k,array[candcount];

	fp3 = fopen("votecast.txt","a+");

	for(j=0;j<2;j++)
	{
		fscanf(fp3,"%d",&array[j]);
	}

	for(k=0;k<vote;k++)
	{
		if(k==vote-1)
		{
			array[k]++;
		}
	}

	fp3 = fopen("votecast.txt","w");

	for(j=0;j<candcount;j++)
	{
		fprintf(fp3,"\n%d",array[j]);
	}

	printf("\nVoting number \tCandidate`s name \tRespective party \tSymbol\t\tCurrent Votes");

	for(i=0;i<candcount;i++)
	{

		printf("\n%i\t\t%s %s\t\t%s\t\t\t%s\t\t\t%d",cand[i].num, cand[i].fname, cand[i].lname, cand[i].partyname, cand[i].symbol, array[i]);
		printf("\t");

	}

	fclose(fp3);

}
int LEADING()
{

	FILE *fptr, *fptr1;

	if ((fptr=fopen("candidates.txt", "r"))==NULL)
	{

		puts("File could not be opened");
		return 0;

	}
	else if((fptr1=fopen("votecast.txt", "r"))==NULL)
	{
	
		puts("File could not be opened");
		return 0;
	
	}
	else 
	{
	
		int i=0,j,array[candcount];
	
		for(j=0;j<candcount;j++)
		{
			fscanf(fptr1,"%d",&array[j]);
		}
		fclose(fptr1);
	
		int num;
		char fname[30];
		char lname[30];
		char partyname[100];
		char symbol[20];
	
		while (!feof(fptr))
		{
	
			fscanf(fptr, "%i %s %s %s %s", &num, fname, lname, partyname, symbol);
			printf("Voting number : %i\nCandidate`s name : %s %s\nRespective party : %s\nSymbol : %s\nCurrent Votes : %d\n\n", num, fname, lname, partyname, symbol,array[i]);
			i++;
			printf("\t");
	
		}
	
		fclose(fptr);
	
	}

}
int WINNER()
{

	struct winner results[candcount];
	FILE *fptr, *fptr1;

	if ((fptr=fopen("candidates.txt", "r"))==NULL)
	{

		puts("File could not be opened");
		return 0;

	}
	else if((fptr1=fopen("votecast.txt", "r"))==NULL)
	{

		puts("File could not be opened");
		return 0;

	}
	else 
	{

		int i=0,j,index;

		for(j=0;j<candcount;j++)
		{
			fscanf(fptr1,"%d",&results[j].votes);
		}
		fclose(fptr1);

		int num,max=0;
		char fname[30];
		char lname[30];
		char partyname[100];
		char symbol[20];

		while (!feof(fptr))
		{

			fscanf(fptr, "%i %s %s %s %s", &results[i].num, results[i].fname, results[i].lname, results[i].partyname, results[i].symbol);
			i++;

		}

		fclose(fptr);

		for(i=0;i<candcount;i++)
		{

			if(results[i].votes>max)
			{

				max=results[i].votes;
				index=i;

			}

		}

		for(i=0;i<candcount;i++)
		{
			fscanf(fptr, "%i %s %s %s %s %d", &results[i].num, results[i].fname, results[i].lname, results[i].partyname, results[i].symbol, results[i].votes);
		}

		printf("\nTHE WINNER OF THE ELECTION IS: \n\n");
		printf("Voting number : %i\nCandidate`s name : %s %s\nRespective party : %s\nSymbol : %s\nCurrent Votes : %d\n\n", results[index].num, results[index].fname, results[index].lname, results[index].partyname, results[index].symbol, results[index].votes);
		printf("\nCongratulations! %s %s for Winning the Election.\n",results[index].fname,results[index].lname);

	}

}
int PASSWORD()
{
	FILE *fptr;
	char chkpass[8];
	char ch;
	char password[10];
	int count=0, flag=0, i, j;

	while(count!=3 && flag!=1)
	{
	
		printf("Password : ");
	
		for(i=0; i<10; i++)
		{
	
			ch = getch();
			if(ch == 13)
			{
			    break;
			}
	
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
	
		}
	
		if ((fptr=fopen("password.txt", "r"))==NULL)
		{
	
			puts("\nFile could not be opened");
			return 0;
	
		}
		else 
		{
	
			int i=0;
	
			while (!feof(fptr) && i<8)
			{
	
				chkpass[i]=fgetc(fptr);
				i++;
	
			}
	
		}
	
		for (i=0; i<8; i++)
		{
			if (chkpass[i]!=password[i])
			{
	
				printf("\n\n\aAccess Denied !");
				count++;
				printf("\n\n%d Tries Left.", 3-count);
				printf("\n\n");
				flag=0;
				break;
	
			}
			else
			{
				flag=1;
			}
		}
	
	}
	if(flag==0)
	{
	
		printf("Locked ! Try again later.\n");
		_Exit(0);
	
	}
	else
	{
	
		printf("\n\nAccess Given !");
	    fclose(fptr);		
	
	}

}

