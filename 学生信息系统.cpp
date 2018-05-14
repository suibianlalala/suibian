#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 50



/*student basic information struct*/
typedef struct
{
  int number;
  char name[10];
  char sex[2];
  int  age;
  char kind[20];
  char dormitory[10];
  char address[30];
  char phone[11];
  int score1;
  int score2;
  int score3;
  int score4;
  int sum;
  double average;
}STUDENT;


void password(void);
void input(void);
void sort();
void displaybasic(void);
void displayscore(void);
void revise(void);
void revise_num(void);
void revise_name(void);
void inquire(void);
void inquire_number(void);
void inquire_name(void);
void del(void);
void del_number(void);
void del_name(void);
void save(void);
void read(void);


STUDENT student[MAX];


int count=0;

void main()
{
  int select=-1;
  password();
  while(select!=0)
  {
	printf("\n");
	printf("========================================\n");
   	printf("=          1---read                     \n");
	printf("=          2---Input                    \n");
    printf("=          3---Displaybasic             \n");
    printf("=          4---Displayscore             \n");
    printf("=          5---sort                     \n");
	printf("=          6---Revise                   \n");
	printf("=          7---inquire                  \n");
	printf("=          8---delete                   \n");
    printf("=          9---save                     \n");
    printf("=          0---Exit                     \n");
    printf("========================================\n");
    printf("Please input select(0-9):\n");
    scanf("%d",&select);

    switch (select)
   {
	  case 1:
		read();
		break;
      case 2:
	    input();
	    break;
      case 3:
	    displaybasic();
	    break;
      case 4:
        displayscore();
	    break;
      case 5:
		sort();
		break;
	  case 6:
		revise();
		break;
	  case 7:
		inquire();
		break;
	  case 8:
		del();
		break;
	  case 9:
        save();
	    break;
	  case 0:
	    break;
    }
  }
} 


/*input the secret code function*/
void password()
{
  int i;
  char n[8],m[8];
  m[0]='1';m[1]='1';m[2]='0';m[3]='6';m[4]='1';m[5]='1';m[6]='2';m[7]='9';
  printf("\n\n\n\n\n\t-----   Welcome to the student's status manage system    -----\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\t\t\tPlease input the secret code£º   ");
  do
    {
      for(i=0;i<8;i++)
        {
          n[i]=getch();
          if(n[i]>='0'||n[i]<='9'||n[i]>='a'||n[i]<='z'||n[i]>='A'||n[i]<='Z')
          putchar('*');
        }
      getch();
      if(n[0]==m[0]&&n[1]==m[1]&&n[2]==m[2]&&n[3]==m[3]&&n[4]==m[4]&&n[5]==m[5]&&n[6]==m[6]&&n[7]==m[7])
        {
		  
          system("cls");
		  printf("=================================================================\n");
          printf("\n\n\n\n\n\n\t -----       The secret code is right   !  ---\n\n");
          printf("\t\t\t  -------------      Wellcome to use!     -----\n\n\n\n\n\n");
		  printf("===============================================================\n");
          getchar();
          printf("press any key contiue!");
		  break;
        }
      else
        {
          system("cls");
          printf("\t\tSorry ! the secret code is wrong !please input again! :\n"); continue;
        }
    }while(1);
}



 /*information input function*/
void input(void)
{
  
  printf("please input student basic intormation:\n");

  printf("number:");
  scanf("%d",&student[count].number);
  printf("name:");
  scanf("%s",student[count].name);
  printf(" sex:");
  scanf("%s",student[count].sex);
  printf(" age:");
  fflush(stdin);
  scanf("%d",&student[count].age);
  printf("kind:");
  scanf("%s",student[count].kind);
  printf("dormitory:");
  scanf("%s",student[count].dormitory);
  printf("address:");
  scanf("%s",student[count].address);
  printf("phone:");
  scanf("%s",student[count].phone);
  printf("please input number between 0~100:\n");
  printf("math:\n");
  scanf("%d",&student[count].score1);
  printf("physics:\n");
  scanf("%d",&student[count].score2);
  printf("c:\n");
  scanf("%d",&student[count].score3);
  printf("English:\n");
  scanf("%d",&student[count].score4);
  student[count].sum=student[count].score1+student[count].score2+student[count].score3+student[count].score4;
  student[count].average=student[count].sum/4.0;
  count++;
}



/*display the basic information function*/
void displaybasic(void)
{
  int i;

  if (count==0)
  {
    printf("not input before!\n");
    getch();
    return;
  }

  printf("Student Information as follows:\n");
  printf("================================================================\n");
  printf("number\tname\tsex\tkind\tage\tdormitory\taddress\tphone\n");
  for(i=0; i<count; i++)
  {
    printf("%d\t",student[i].number);
    printf("%s\t",student[i].name);
    printf("%s\t",student[i].sex);
    printf("%s\t",student[i].kind);
    printf("%d\t",student[i].age);
    printf("%s\t",student[i].dormitory);
    printf("%s\t",student[i].address);
    printf("%s\n",student[i].phone);
  }
  printf("================================================================\n");
  printf("Press any key to continue!\n");
  getch();
}
 



/*result display*/
void displayscore(void)
{
  int i;
  printf("student result as follows:\n");
  printf("Number\tName\tMath\tPhysic\tC\tEnglish\tEverage\n");
  for(i= 0;i<count;i++)
  {
    printf("%d\t",student[i].number);
    printf("%s\t",student[i].name);
    printf("%d\t",student[i].score1);
    printf("%d\t",student[i].score2);
    printf("%d\t",student[i].score3);
    printf("%d\t",student[i].score4);
    student[i].sum=student[i].score1+student[i].score2+student[i].score3+student[i].score4;
    student[i].average=student[i].sum/4.0;
	printf("%f\n",student[i].average);
   
  }
    printf("press any key to come to the menu!");
    getch();
}



/*sort depend on the number*/
void sort(void)
{  
	int i,j;
    STUDENT t;
	for(j=0;j<count-1;j++)
        for(i=j+1;i<count;i++)
           if(student[i].number<student[j].number)
		   {
               t=student[i];
               student[i]=student[j];
               student[j]=t;
		   }
	printf("the result you want to know as follows:\n");
	printf("================================================================\n");
    printf("number\tname\tsex\tkind\tage\tdormitory\taddress\tphone\n");
    for(i=0;i<count;i++)
    {
		printf("%d\t",student[i].number);
        printf("%s\t",student[i].name);
        printf("%s\t",student[i].sex);
        printf("%s\t",student[i].kind);
        printf("%d\t",student[i].age);
        printf("%s\t",student[i].dormitory);
        printf("%s\t",student[i].address);
        printf("%s\n",student[i].phone);
	}
	printf("number\tname\tmath\tphysic\tC\tEnglish\tsum\taverage\n");
	for(i=0;i<count;i++)	
    {	
	    printf("%d\t",student[i].number);
		printf("%s\t",student[i].name);
        printf("%d\t",student[i].score1);
        printf("%d\t",student[i].score2);
        printf("%d\t",student[i].score3);
        printf("%d\t",student[i].score4);
        printf("%d\t",student[i].sum);
        printf("%f\n",student[i].average);
	} 
	printf("================================================================\n");
	printf("\n");
}



/*revise student result function*/
void revise()
{
	int in;
	do
	{
		printf("---please choice the number revise number----\n");
		printf("=============================================\n");
		printf("-     1 inquire revise depend on number     -\n");
		printf("-     2 inquire revise depend on name       -\n");
        printf("-     3 not to revise                       -\n");
		printf("=============================================\n");
		printf("\n");
		printf("please choice between (1~3)\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("the input is wrong! please input again!");
			continue;
		}
		else break;
	}while(1);
	switch(in)
	{
	case 1:
		revise_num();
		break;
	case 2:
		revise_name();
		break;
    case 3:
		break;
	}
}


/*revise the score depend on the number*/
void revise_num(void)
{
	int i=0,choice,flag,revise_num;
	do
	{
		printf("please input the revise number:\n");
		scanf("%d",&revise_num);
		for(i=0;i<count;i++)
		{
			if(student[i].number==revise_num)
			{
				printf("the student result information as follows:\n");
			    printf("\n choice between (0~8)\n");
			    printf("please choice the number you want to revise\n");
			    printf("===========================================\n");
				printf("-            1  revise Math               -\n");
			    printf("-            2  revise Physic             -\n");
			    printf("-            3  revise C                  -\n");
			    printf("-            4  revise English            -\n");
			    printf("===========================================\n");
				scanf("%d",&choice);
				switch(choice)
				{
				case 1:
					printf("input the revise math score:\n");
					scanf("%d",&student[i].score1);
					break;
				case 2:
					printf("input the revise physic:\n");
                 	scanf("%d",&student[i].score2);		
                    break; 
			    case 3:
					printf("input the revise C:\n");
                 	scanf("%d",&student[i].score3);		
                    break;
                case 4:
					printf("input the revise English:\n"); 
                 	scanf("%d",&student[i].score4);		
                    break;
				}
			}
			if(i==MAX)
			{
				printf("\n have no the student:");
				getch();
			}
		}
		printf("\n\n going on revise ?(y/n)");
		choice=getch();
		if(choice=='y'||choice=='Y')
		{
			flag=1;
			printf("\n please contiue !\n");
		}
		else 
			flag=0;
	}while(flag==1);
	printf("\n printf any key to the menu:");
	getch();
}




/*revise the score depend on the name*/
void revise_name(void)
{
	int i=0,choice,flag;
	char revise_name[10];
	do
	{
		printf("please input the revise name:\n");
		scanf("%s",revise_name);
		for(i=0;i<count;i++)
		{
			if((strcmp(student[i].name,revise_name)==0))
			{
				printf("the student result information as follows:\n");
			    printf("\n choice between (0~8)\n");
			    printf("please choice the number you want to revise\n");
			    printf("===========================================\n");
				printf("-            1  revise Math               -\n");
			    printf("-            2  revise Physic             -\n");
			    printf("-            3  revise C                  -\n");
			    printf("-            4  revise English            -\n");
			    printf("===========================================\n");
				scanf("%d",&choice);
				switch(choice)
				{
				case 1:
					printf("input the revise math score:\n");
					scanf("%d",&student[i].score1);
					break;
				case 2:
					printf("input the revise physic:\n");
                 	scanf("%d",&student[i].score2);		
                    break; 
			    case 3:
					printf("input the revise C:\n");
                 	scanf("%d",&student[i].score3);		
                    break;
                case 4:
					printf("input the revise English:\n"); 
                 	scanf("%d",&student[i].score4);		
                    break;
				}
			}
			if(i==MAX)
			{
				printf("\n have no the student:");
				getch();
			}
		}
		printf("\n\n going on revise ?(y/n)");
		choice=getch();
		if(choice=='y'||choice=='Y')
		{
			flag=1;
			printf("\n please contiue !\n");
		}
		else 
			flag=0;
	}while(flag==1);
	printf("\n printf any key to the menu:");
	getch();
}


/*inquire the student's information*/
void inquire()
{
	int in;
	do
	{
		printf("---please choice the number inquire number----\n");
	    printf("=============================================\n");
		printf("-     1 inquire result depend on numbe      -\n");
		printf("-     2 inquire result depend on name       -\n");
        printf("-     3 not to inquire                      -\n");
		printf("=============================================\n");
		printf("\n");
		printf("please choice between (1~3)\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("the input is wrong! please input again!");
			continue;
		}
		else break;
	}while(1);
	switch(in)
	{
	case 1:
		inquire_number();
		break;
	case 2:
		inquire_name();
		break;
    case 3:
		break;
	}
}


/*inquire result depend on number*/
void inquire_number()
{
	int no;
	int i;
	printf("\n please input the student number you want to inquire \n");
	printf("the number is:");
	scanf("%d",&no);
	for(i=0;i<count;i++)
	{
		if(student[i].number==no)
		{
			printf("the result you want to know is follows:\n");
	        printf("================================================================\n");
            printf("number\tname\tsex\tkind\tage\tdormitory\taddress\tphone\n");
            printf("%d\t",student[i].number);
            printf("%s\t",student[i].name);
            printf("%s\t",student[i].sex);
            printf("%s\t",student[i].kind);
            printf("%d\t",student[i].age);
            printf("%s\t",student[i].dormitory);
            printf("%s\t",student[i].address);
            printf("%s\n",student[i].phone);
			printf("number\tname\tmath\tphysic\tC\tEnglish\tsum\taverage\n");
			printf("%d\t",student[i].number);
			printf("%s\t",student[i].name);
            printf("%d\t",student[i].score1);
            printf("%d\t",student[i].score2);
            printf("%d\t",student[i].score3);
            printf("%d\t",student[i].score4);
            printf("%d\t",student[i].sum);
            printf("%f\n",student[i].average);
			printf("================================================================\n");
			printf("\n");
		}
	}
}
 

/*inquire result depend on name*/
void inquire_name()
{
	char name[10];
	int i;
	printf("please input the name you want to inquire:\n");
	fflush(stdin);
	scanf("%s",name);
	for(i=0;i<count;i++)
	{
		if((strcmp(student[i].name,name))==0)
        {
			printf("the result you want to know is follows:\n");
	        printf("================================================================\n");
            printf("number\tname\tsex\tkind\tage\tdormitory\taddress\tphone\n");
            printf("%d\t",student[i].number);
            printf("%s\t",student[i].name);
            printf("%s\t",student[i].sex);
            printf("%s\t",student[i].kind);
            printf("%d\t",student[i].age);
            printf("%s\t",student[i].dormitory);
            printf("%s\t",student[i].address);
            printf("%s\n",student[i].phone);
			printf("number\tname\tmath\tphysic\tC\tEnglish\tsum\taverage\n");
			printf("%d\t",student[i].number);
			printf("%s\t",student[i].name);
            printf("%d\t",student[i].score1);
            printf("%d\t",student[i].score2);
            printf("%d\t",student[i].score3);
            printf("%d\t",student[i].score4);
            printf("%d\t",student[i].sum);
            printf("%f\n",student[i].average);
			printf("================================================================\n");
			printf("\n");
		}
	}
}



/*delete student information function*/
void del()
{
	int in;
	do
	{
		printf("=============================================\n");
		printf("---please choice the number delete number----\n");
		printf("-     1  delete depend on number            -\n");
		printf("-     2  delete depend on name              -\n");
        printf("-     3 not to delete                       -\n");
		printf("=============================================\n");
		printf("\n");
		printf("please choice between (1~3)\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("the input is wrong! please input again!");
			continue;
		}
		else break;
	}while(1);
	switch(in)
	{
	case 1:
		del_number();
		break;
	case 2:
		del_name();
		break;
    case 3:
		break;
	}
}



/*delete information depend on number*/
void del_number()
{
	int j;
	int delnumber=0;
	int i=0;
	char ch;
	printf("please input the delete  student number\n");
	printf("\n input the student number you want to delete:\n");
	scanf("%d",&delnumber);
	for(i=0;i<count;i++)
	{
		if(student[i].number==delnumber)
		{   
			printf("\n");
		    printf("delete or not(y\n)");
		    fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{
				for(j=i;j<count-1;j++)
					student[j]=student[j+1];
				printf("the student information have been delete success!");
				count--;
				break;
			}
		}
	}
}


/*delete information depend on name*/
void del_name()
{
	char delname[10];
	int i,j;
    char ch;
    printf("\n input the student name you want to delete:\n");
	scanf("%s",delname);
	for(i=0;i<count;i++)
	{
		if((strcmp(student[i].name,delname)==0))
		{
			printf("delete or not(y\n)");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{
				for(j=i;j<count-1;j++)
					student[j]=student[j+1];
				printf("the student information have been delete success!");
				count--;
				break;
			}
		}
	}
}



/*save the date to a file*/
void save()
{
	int i=0;
	FILE *fp;
	fp=fopen("f:\\student.txt","w+");
	for(i=0;i<count;i++)
	    if(fwrite(&student[i],sizeof(STUDENT),1,fp)!=1)
		{
		   printf("the file not be save!\n");
		}
	printf("You have save the data success!");
	fclose(fp);
}


/*read the data from a file*/
void read()
{
	int i;
	int counter=0;
	STUDENT stu[MAX];
    FILE *fp;
	fp=fopen("f:\\student.txt","r+");
	if(fp==NULL)
	{
		printf(" open the file is fail!");
	}
	else
	{
		i=0;
		while(!feof(fp))
		{
			fread(&stu[i],sizeof(STUDENT),1,fp);
			i++;
			counter++;
		}
		counter--;
		for(i=0;i<counter;i++)
		{
			printf("\nnumber\tname\tage\tmath\n");
			printf("\n%d",stu[i].number);
			printf("\t%s",stu[i].name);
			printf("\t%d",stu[i].age);
			printf("\t%d",stu[i].score1);
		}
	
	}
}
