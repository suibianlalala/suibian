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
void sort(void);
void sort_num(void);
void sort_phone(void);
void sort_score1(void);
void sort_sum(void);
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
   	printf("=          1---��ȡ�ļ�                    \n");
	printf("=          2---������Ϣ                    \n");
    printf("=          3---��ʾ������Ϣ                \n");
    printf("=          4---��ʾ�ɼ���Ϣ                \n");
    printf("=          5---������Ϣ                    \n");
	printf("=          6---�޸���Ϣ                    \n");
	printf("=          7---��ѯ��Ϣ                    \n");
	printf("=          8---ɾ����Ϣ                    \n");
    printf("=          9---������Ϣ                    \n");
    printf("=          0---�˳�                        \n");
    printf("========================================\n");
    printf("������(0-9)����ģ��:\n");
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
  int i,x,y;
  char n[8],m[8];
  m[0]='1';m[1]='1';m[2]='0';m[3]='6';m[4]='0';m[5]='1';
  printf("\n\n\n\n\n\t-----   �� ӭ ʹ �� ѧ �� �� �� ϵ ͳ   -----\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\t\t\t�� �� �� �� λ �� �� �� ��   ");
  do
    {
      for(i=0;i<8;i++)
        {
          n[i]=getch();
          if(n[i]>='0'||n[i]<='9'||n[i]>='a'||n[i]<='z'||n[i]>='A'||n[i]<='Z')
          putchar('*');
        }
      getch();
      if(n[0]==m[0]&&n[1]==m[1]&&n[2]==m[2]&&n[3]==m[3]&&n[4]==m[4]&&n[5]==m[5]&&(n[6]>='0'||n[6]<='3')&&(n[7]>='0'||n[7]<='9'))
        {
		  
          system("cls");
		  printf("=================================================================\n");
          printf("\n\n\n\n\n\n\t -----        �� �� ���� �� ȷ   !   ---\n\n");
          printf("\t\t\t  ---------      �� ӭ ʹ �� !     -----\n\n\n\n\n\n");
		  printf("===============================================================\n");
          printf("�� Enter �� �� �� !");
		  getchar();
          
		  break;
        }
      else
        {
          system("cls");
          printf("\t\t�Բ��� ! �������������� ! ����������! :\n"); 
		  continue;
        }
    }while(1);
}



 /*information input function*/
void input(void)
{
  
  printf("�� �� �� ѧ �� �� �� �� Ϣ:\n");

  printf("ѧ��:");
  scanf("%d",&student[count].number);
  printf("����:");
  scanf("%s",student[count].name);
  printf("�Ա�:");
  scanf("%s",student[count].sex);
  printf("����:");
  fflush(stdin);
  scanf("%d",&student[count].age);
  printf("����:");
  scanf("%s",student[count].kind);
  printf("�����:");
  scanf("%s",student[count].dormitory);
  printf("��ͥ��ַ:");
  scanf("%s",student[count].address);
  printf("�绰����:");
  scanf("%s",student[count].phone);
  printf("�������ֵ��0~100�ĸ��Ƴɼ�:\n");
  printf("��ѧ:\n");
  scanf("%d",&student[count].score1);
  printf("����:\n");
  scanf("%d",&student[count].score2);
  printf("c����:\n");
  scanf("%d",&student[count].score3);
  printf("Ӣ��:\n");
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

  printf("ѧ����Ϣ�������:\n");
  printf("================================================================\n");
  printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥ��ַ\t�绰����\n");
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
  printf("�����������!\n");
  getch();
}
 



/*result display*/
void displayscore(void)
{
  int i;
  printf("ѧ���ɼ���ѯ�������:\n");
  printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܳɼ�\tƽ���ɼ�\n");
  for(i= 0;i<count;i++)
  {
    printf("%d\t",student[i].number);
    printf("%s\t",student[i].name);
    printf("%d\t",student[i].score1);
    printf("%d\t",student[i].score2);
    printf("%d\t",student[i].score3);
    printf("%d\t",student[i].score4);
    student[i].sum=student[i].score1+student[i].score2+student[i].score3+student[i].score4;
    printf("%d\t",student[i].sum);
student[i].average=student[i].sum/4.0;
	printf("%f\n",student[i].average);
   
  }
    printf("��������������˵�!");
    getch();
}

/*����*/
void sort()
{
	int in;
	do
	{
		printf("---������ѧ����Ϣ��������----\n");
		printf("=============================================\n");
		printf("-     1 ����ѧ�Ž�������              -\n");
		printf("-     2 ���ݵ绰�����������          -\n");
printf("-     3 ��������ɼ���������          -\n");
printf("-     4 ����ƽ���ֽ�������            -\n");
        printf("-     5 ����������                    -\n");
		printf("=============================================\n");
		printf("\n");
		printf("��ѡ�� (1~5)ģ��\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>5)
		{
			printf("û�е�ǰ����! ����������1~5��ֵ!");
			continue;
		}
		else break;
	}while(1);
	switch(in)
	{
	case 1:
		sort_num();
		break;
	case 2:
		sort_phone();
		break;
case 3:
    sort_score1();
		break;
case 4:
    sort_sum();
		break;
	}
}


/*��ѧ������*/
void sort_num()
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
	printf("��ѧ������������:\n");
	printf("================================================================\n");
    printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥסַ\t�绰����\n");
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
	printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܳɼ�\tƽ���ɼ�\n");
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

/*���绰��������*/
void sort_phone()
{  
	int i,j;
    STUDENT t;
	for(j=0;j<count-1;j++)
        for(i=j+1;i<count;i++)
           if(student[i].phone<student[j].phone)
		   {
               t=student[i];
               student[i]=student[j];
               student[j]=t;
		   }
	printf("���绰��������������s:\n");
	printf("================================================================\n");
    printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥסַ\t�绰����\n");
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
	printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܳɼ�\tƽ���ɼ�\n");
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


/*������ɼ�����*/
void sort_score1()
{  
	int i,j;
    STUDENT t;
	for(j=0;j<count-1;j++)
        for(i=j+1;i<count;i++)
           if(student[i].score1<=student[j].score1)
		   {
               t=student[i];
               student[i]=student[j];
               student[j]=t;
		   }
	printf("������ɼ�����������:\n");
	printf("================================================================\n");
    printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥסַ\t�绰����\n");
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
	printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܳɼ�\tƽ���ɼ�\n");
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


/*���ܳɼ�����*/
void sort_sum(void)
{  
	int i,j;
    STUDENT t;
	for(j=0;j<count-1;j++)
        for(i=j+1;i<count;i++)
           if(student[i].sum<student[j].sum)
		   {
               t=student[i];
               student[i]=student[j];
               student[j]=t;
		   }
	printf("���ܳɼ�����������:\n");
	printf("================================================================\n");
    printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥסַ\t�绰����\n");
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
	printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܳɼ�\tƽ���ɼ�\n");
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
		printf("---������ѧ��ѧ�Ų���������޸�----\n");
		printf("=============================================\n");
		printf("-     1 ����ѧ�Ų�ѯ�����޸�         -\n");
		printf("-     2 ����������ѯ�����޸�          -\n");
        printf("-     3 �������޸�                    -\n");
		printf("=============================================\n");
		printf("\n");
		printf("��ѡ�� (1~3)ģ��\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("û�е�ǰ����! ����������1~3��ֵ!");
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
		printf("������Ҫ�޸ĵ�ѧ��:\n");
		scanf("%d",&revise_num);
		for(i=0;i<count;i++)
		{
			if(student[i].number==revise_num)
			{
				printf("��ѧ������Ϣ����:\n");
			    printf("\n ѡ�� (0~8)����\n");
			    printf("��ѡ����Ҫ�޸ĵ�ģ��(1~4)\n");
			    printf("===========================================\n");
				printf("-            1  �޸���ѧ�ɼ�               -\n");
			    printf("-            2  �޸�����ɼ�               -\n");
			    printf("-            3  �޸�C���Գɼ�             -\n");
			    printf("-            4  �޸�Ӣ��ɼ�               -\n");
			    printf("===========================================\n");
				scanf("%d",&choice);
				switch(choice)
				{
				case 1:
					printf("�����޸ĵ���ѧ�ɼ�:\n");
					scanf("%d",&student[i].score1);
					break;
				case 2:
					printf("�����޸ĵ�����ɼ�:\n");
                 	scanf("%d",&student[i].score2);		
                    break; 
			    case 3:
					printf("�����޸ĵ�C���Գɼ�:\n");
                 	scanf("%d",&student[i].score3);		
                    break;
                case 4:
					printf("�����޸ĵ�Ӣ��ɼ�:\n"); 
                 	scanf("%d",&student[i].score4);		
                    break;
				}
			}
			if(i==MAX)
			{
				printf("\n ��ѧ��û�вμӽ�ѧ����:");
				getch();
			}
		}
		printf("\n\n �Ƿ�����޸� ?(yes/no)");
		choice=getch();
		if(choice=='y'||choice=='Y')
		{
			flag=1;
			printf("\n ����� !\n");
		}
		else 
			flag=0;
	}while(flag==1);
	printf("\n��������������˵�:");
	getch();
}



/*revise the score depend on the name*/
void revise_name(void)
{
	int i=0,choice,flag;
	char revise_name[10];
	do
	{
		printf("�������޸��ߵ�����:\n");
		scanf("%s",revise_name);
		for(i=0;i<count;i++)
		{
			if((strcmp(student[i].name,revise_name)==0))
			{
				printf("��ѧ������Ϣ����:\n");
			    printf("\n ѡ��(0~8)��ֵ\n");
			    printf("��ѡ����Ҫ�޸ĵ�ģ��(1~4)\n");
			    printf("===========================================\n");
				printf("-            1  �޸���ѧ�ɼ�               -\n");
			    printf("-            2  �޸�����ɼ�               -\n");
			    printf("-            3  �޸�C���Գɼ�             -\n");
			    printf("-            4  �޸�Ӣ��ɼ�               -\n");
			    printf("===========================================\n");
				scanf("%d",&choice);
				switch(choice)
			    {
				  case 1:
					  printf("�����޸ĵ���ѧ�ɼ�:\n");
					  scanf("%d",&student[i].score1);
					  break;
				  case 2:
					  printf("�����޸ĵ�����ɼ�:\n");
                 	  scanf("%d",&student[i].score2);		
                      break; 
			      case 3:
					  printf("�����޸ĵ�C���Գɼ�:\n");
                 	  scanf("%d",&student[i].score3);		
                      break;
                  case 4:
					  printf("�����޸ĵ�Ӣ��ɼ�:\n"); 
                 	  scanf("%d",&student[i].score4);		
                     break;
				}
			}
			if(i==MAX)
			{
				printf("\n ��ѧ��û�вμӽ�ѧ����:");
				getch();
			}
		}
		printf("\n\n �Ƿ�����޸� ?(yes/no)");
		choice=getch();
		if(choice=='y'||choice=='Y')
		{
			flag=1;
			printf("\n ����� !\n");
		}
		else 
			flag=0;
	}while(flag==1);
	printf("\n��������������˵�:");
	getch();
}



/*inquire the student's information*/
void inquire()
{
	int in;
	do
	{
		printf("---��ѡ��ѧ�Ų�ѯģ��(1~4)----\n");
	    printf("=============================================\n");
		printf("-     1 ��ѧ�Ž��в�ѯ       -\n");
		printf("-     2 ���������в�ѯ       -\n");
        printf("-     3 �����в�ѯ           -\n");
		printf("=============================================\n");
		printf("\n");
		printf("��ѡ�� (1~3)ģ��\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("û�е�ǰ����! ����������1~3��ֵ!");
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
	printf("\n�����������ѯ��ѧ��ѧ�� \n");
	printf("ѧ����:");
	scanf("%d",&no);
	for(i=0;i<count;i++)
	{
		if(student[i].number==no)
		{
			printf("��ѯ�������:\n");
	        printf("================================================================\n");
            printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥסַ\t�绰����\n");
            printf("%d\t",student[i].number);
            printf("%s\t",student[i].name);
            printf("%s\t",student[i].sex);
            printf("%s\t",student[i].kind);
            printf("%d\t",student[i].age);
            printf("%s\t",student[i].dormitory);
            printf("%s\t",student[i].address);
            printf("%s\n",student[i].phone);
			printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܷ�\tƽ����\n");
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
	printf("�����������ѯѧ��������:\n");
	fflush(stdin);
	scanf("%s",name);
	for(i=0;i<count;i++)
	{
		if((strcmp(student[i].name,name))==0)
        {
			printf("the result you want to know is follows:\n");
	        printf("================================================================\n");
            printf("ѧ��\t����\t�Ա�\t����\t����\t�����\t��ͥסַ\t�绰����\n");
            printf("%d\t",student[i].number);
            printf("%s\t",student[i].name);
            printf("%s\t",student[i].sex);
            printf("%s\t",student[i].kind);
            printf("%d\t",student[i].age);
            printf("%s\t",student[i].dormitory);
            printf("%s\t",student[i].address);
            printf("%s\n",student[i].phone);
			printf("ѧ��\t����\t��ѧ\t����\tC����\tӢ��\t�ܷ�\tƽ����\n");
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
		printf("---��ѡ����Ҫɾ����ģ��----\n");
		printf("-     1  ��ѧ�Ž���ɾ��              -\n");
		printf("-     2  ����������ɾ��              -\n");
        printf("-     3  ������ɾ��                  -\n");
		printf("=============================================\n");
		printf("\n");
		printf("��ѡ�� (1~3)ģ��\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("û�е�ǰ����! ����������1~3��ֵ!");
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
	printf("������ɾ��ѧ��ѧ��\n");
	printf("\n ��������ɾ��ѧ��ѧ��:\n");
	scanf("%d",&delnumber);
	for(i=0;i<count;i++)
	{
		if(student[i].number==delnumber)
		{   
			printf("\n");
		    printf("�Ƿ�ɾ��(yes\no)");
		    fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{
				for(j=i;j<count-1;j++)
					student[j]=student[j+1];
				printf("��ѧ��ѧ����Ϣ�Ѿ��ɹ�ɾ��!");
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
    printf("\n ��������ɾ����ѧ������:\n");
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
				printf("ѧ����Ϣ�Ѿ�ɾ���ɹ�!");
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
	fp=fopen("c:\\student.txt","w+");
	for(i=0;i<count;i++)
	    if(fwrite(&student[i],sizeof(STUDENT),1,fp)!=1)
		{
		   printf("�ı����ܱ�����!\n");
		}
	printf("�����Ѿ�����ɹ�!");
	fclose(fp);
}


/*read the data from a file*/
void read()
{
	int i;
	int counter=0;
	STUDENT stu[MAX];
    FILE *fp;
	fp=fopen("c:\\student.txt","r+");
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
			printf("\nѧ��\t����\t����\t��ѧ\n");
			printf("\n%d",stu[i].number);
			printf("\t%s",stu[i].name);
			printf("\t%d",stu[i].age);
			printf("\t%d",stu[i].score1);
		}
	
	}
}

