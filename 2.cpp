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
   	printf("=          1---读取文件                    \n");
	printf("=          2---输入信息                    \n");
    printf("=          3---显示基本信息                \n");
    printf("=          4---显示成绩信息                \n");
    printf("=          5---排序信息                    \n");
	printf("=          6---修改信息                    \n");
	printf("=          7---查询信息                    \n");
	printf("=          8---删除信息                    \n");
    printf("=          9---保存信息                    \n");
    printf("=          0---退出                        \n");
    printf("========================================\n");
    printf("请输入(0-9)进入模块:\n");
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
  printf("\n\n\n\n\n\t-----   欢 迎 使 用 学 生 管 理 系 统   -----\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\t\t\t请 输 入 八 位 数 密 码 ：   ");
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
          printf("\n\n\n\n\n\n\t -----        密 码 输入 正 确   !   ---\n\n");
          printf("\t\t\t  ---------      欢 迎 使 用 !     -----\n\n\n\n\n\n");
		  printf("===============================================================\n");
          printf("按 Enter 键 继 续 !");
		  getchar();
          
		  break;
        }
      else
        {
          system("cls");
          printf("\t\t对不起 ! 您输入的密码错误 ! 请重新输入! :\n"); 
		  continue;
        }
    }while(1);
}



 /*information input function*/
void input(void)
{
  
  printf("请 输 入 学 生 基 本 信 息:\n");

  printf("学号:");
  scanf("%d",&student[count].number);
  printf("姓名:");
  scanf("%s",student[count].name);
  printf("性别:");
  scanf("%s",student[count].sex);
  printf("年龄:");
  fflush(stdin);
  scanf("%d",&student[count].age);
  printf("爱好:");
  scanf("%s",student[count].kind);
  printf("宿舍号:");
  scanf("%s",student[count].dormitory);
  printf("家庭地址:");
  scanf("%s",student[count].address);
  printf("电话号码:");
  scanf("%s",student[count].phone);
  printf("请输入分值在0~100的各科成绩:\n");
  printf("数学:\n");
  scanf("%d",&student[count].score1);
  printf("物理:\n");
  scanf("%d",&student[count].score2);
  printf("c语言:\n");
  scanf("%d",&student[count].score3);
  printf("英语:\n");
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

  printf("学生信息情况如下:\n");
  printf("================================================================\n");
  printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭地址\t电话号码\n");
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
  printf("按任意键继续!\n");
  getch();
}
 



/*result display*/
void displayscore(void)
{
  int i;
  printf("学生成绩查询结果如下:\n");
  printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总成绩\t平均成绩\n");
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
    printf("按任意键返回主菜单!");
    getch();
}

/*排序*/
void sort()
{
	int in;
	do
	{
		printf("---请输入学生信息对其排序----\n");
		printf("=============================================\n");
		printf("-     1 根据学号进行排序              -\n");
		printf("-     2 根据电话号码进行排序          -\n");
printf("-     3 根据物理成绩进行排序          -\n");
printf("-     4 根据平均分进行排序            -\n");
        printf("-     5 不进行排序                    -\n");
		printf("=============================================\n");
		printf("\n");
		printf("请选择 (1~5)模块\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>5)
		{
			printf("没有当前功能! 请重新输入1~5的值!");
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


/*按学号排序*/
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
	printf("按学号排序结果如下:\n");
	printf("================================================================\n");
    printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭住址\t电话号码\n");
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
	printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总成绩\t平均成绩\n");
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

/*按电话号码排序*/
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
	printf("按电话号码排序结果如下s:\n");
	printf("================================================================\n");
    printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭住址\t电话号码\n");
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
	printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总成绩\t平均成绩\n");
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


/*按物理成绩排序*/
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
	printf("按物理成绩排序结果如下:\n");
	printf("================================================================\n");
    printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭住址\t电话号码\n");
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
	printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总成绩\t平均成绩\n");
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


/*按总成绩排序*/
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
	printf("按总成绩排序结果如下:\n");
	printf("================================================================\n");
    printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭住址\t电话号码\n");
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
	printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总成绩\t平均成绩\n");
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
		printf("---请输入学生学号并对其进行修改----\n");
		printf("=============================================\n");
		printf("-     1 根据学号查询进行修改         -\n");
		printf("-     2 根据姓名查询进行修改          -\n");
        printf("-     3 不进行修改                    -\n");
		printf("=============================================\n");
		printf("\n");
		printf("请选择 (1~3)模块\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("没有当前功能! 请重新输入1~3的值!");
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
		printf("请输入要修改的学号:\n");
		scanf("%d",&revise_num);
		for(i=0;i<count;i++)
		{
			if(student[i].number==revise_num)
			{
				printf("该学生的信息如下:\n");
			    printf("\n 选择 (0~8)的数\n");
			    printf("请选择你要修改的模块(1~4)\n");
			    printf("===========================================\n");
				printf("-            1  修改数学成绩               -\n");
			    printf("-            2  修改物理成绩               -\n");
			    printf("-            3  修改C语言成绩             -\n");
			    printf("-            4  修改英语成绩               -\n");
			    printf("===========================================\n");
				scanf("%d",&choice);
				switch(choice)
				{
				case 1:
					printf("输入修改的数学成绩:\n");
					scanf("%d",&student[i].score1);
					break;
				case 2:
					printf("输入修改的物理成绩:\n");
                 	scanf("%d",&student[i].score2);		
                    break; 
			    case 3:
					printf("输入修改的C语言成绩:\n");
                 	scanf("%d",&student[i].score3);		
                    break;
                case 4:
					printf("输入修改的英语成绩:\n"); 
                 	scanf("%d",&student[i].score4);		
                    break;
				}
			}
			if(i==MAX)
			{
				printf("\n 该学生没有参加教学任务:");
				getch();
			}
		}
		printf("\n\n 是否继续修改 ?(yes/no)");
		choice=getch();
		if(choice=='y'||choice=='Y')
		{
			flag=1;
			printf("\n 请继续 !\n");
		}
		else 
			flag=0;
	}while(flag==1);
	printf("\n按任意键返回主菜单:");
	getch();
}



/*revise the score depend on the name*/
void revise_name(void)
{
	int i=0,choice,flag;
	char revise_name[10];
	do
	{
		printf("请输入修改者的姓名:\n");
		scanf("%s",revise_name);
		for(i=0;i<count;i++)
		{
			if((strcmp(student[i].name,revise_name)==0))
			{
				printf("该学生的信息如下:\n");
			    printf("\n 选择(0~8)的值\n");
			    printf("请选择你要修改的模块(1~4)\n");
			    printf("===========================================\n");
				printf("-            1  修改数学成绩               -\n");
			    printf("-            2  修改物理成绩               -\n");
			    printf("-            3  修改C语言成绩             -\n");
			    printf("-            4  修改英语成绩               -\n");
			    printf("===========================================\n");
				scanf("%d",&choice);
				switch(choice)
			    {
				  case 1:
					  printf("输入修改的数学成绩:\n");
					  scanf("%d",&student[i].score1);
					  break;
				  case 2:
					  printf("输入修改的物理成绩:\n");
                 	  scanf("%d",&student[i].score2);		
                      break; 
			      case 3:
					  printf("输入修改的C语言成绩:\n");
                 	  scanf("%d",&student[i].score3);		
                      break;
                  case 4:
					  printf("输入修改的英语成绩:\n"); 
                 	  scanf("%d",&student[i].score4);		
                     break;
				}
			}
			if(i==MAX)
			{
				printf("\n 该学生没有参加教学任务:");
				getch();
			}
		}
		printf("\n\n 是否继续修改 ?(yes/no)");
		choice=getch();
		if(choice=='y'||choice=='Y')
		{
			flag=1;
			printf("\n 请继续 !\n");
		}
		else 
			flag=0;
	}while(flag==1);
	printf("\n按任意键返回主菜单:");
	getch();
}



/*inquire the student's information*/
void inquire()
{
	int in;
	do
	{
		printf("---请选择学号查询模块(1~4)----\n");
	    printf("=============================================\n");
		printf("-     1 依学号进行查询       -\n");
		printf("-     2 依姓名进行查询       -\n");
        printf("-     3 不进行查询           -\n");
		printf("=============================================\n");
		printf("\n");
		printf("请选择 (1~3)模块\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("没有当前功能! 请重新输入1~3的值!");
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
	printf("\n请输入你想查询的学生学号 \n");
	printf("学号是:");
	scanf("%d",&no);
	for(i=0;i<count;i++)
	{
		if(student[i].number==no)
		{
			printf("查询结果如下:\n");
	        printf("================================================================\n");
            printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭住址\t电话号码\n");
            printf("%d\t",student[i].number);
            printf("%s\t",student[i].name);
            printf("%s\t",student[i].sex);
            printf("%s\t",student[i].kind);
            printf("%d\t",student[i].age);
            printf("%s\t",student[i].dormitory);
            printf("%s\t",student[i].address);
            printf("%s\n",student[i].phone);
			printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总分\t平均分\n");
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
	printf("请输入你想查询学生的姓名:\n");
	fflush(stdin);
	scanf("%s",name);
	for(i=0;i<count;i++)
	{
		if((strcmp(student[i].name,name))==0)
        {
			printf("the result you want to know is follows:\n");
	        printf("================================================================\n");
            printf("学号\t姓名\t性别\t爱好\t年龄\t宿舍号\t家庭住址\t电话号码\n");
            printf("%d\t",student[i].number);
            printf("%s\t",student[i].name);
            printf("%s\t",student[i].sex);
            printf("%s\t",student[i].kind);
            printf("%d\t",student[i].age);
            printf("%s\t",student[i].dormitory);
            printf("%s\t",student[i].address);
            printf("%s\n",student[i].phone);
			printf("学号\t姓名\t数学\t物理\tC语言\t英语\t总分\t平均分\n");
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
		printf("---请选择你要删除的模块----\n");
		printf("-     1  依学号进行删除              -\n");
		printf("-     2  依姓名进行删除              -\n");
        printf("-     3  不进行删除                  -\n");
		printf("=============================================\n");
		printf("\n");
		printf("请选择 (1~3)模块\n");
		scanf("%d",&in);
		fflush(stdin);
		if(in<1||in>3)
		{
			printf("没有当前功能! 请重新输入1~3的值!");
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
	printf("请输入删除学生学号\n");
	printf("\n 输入你想删除学生学号:\n");
	scanf("%d",&delnumber);
	for(i=0;i<count;i++)
	{
		if(student[i].number==delnumber)
		{   
			printf("\n");
		    printf("是否删除(yes\no)");
		    fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{
				for(j=i;j<count-1;j++)
					student[j]=student[j+1];
				printf("该学生学生信息已经成功删除!");
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
    printf("\n 输入你想删除的学生姓名:\n");
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
				printf("学生信息已经删除成功!");
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
		   printf("文本不能被保存!\n");
		}
	printf("数据已经保存成功!");
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
			printf("\n学号\t姓名\t年龄\t数学\n");
			printf("\n%d",stu[i].number);
			printf("\t%s",stu[i].name);
			printf("\t%d",stu[i].age);
			printf("\t%d",stu[i].score1);
		}
	
	}
}

