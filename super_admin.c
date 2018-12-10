#include <stdio.h>
#include <getch.h>
#include <string.h>
#include <stdlib.h>
void view(void);        //显示主界面
void add_admin(void);       //添加管理员
void anykey_continue(void);     
char get_cmd(char start,char end);   
void show_msg(char* msg,int sec);   
int find_name(char* str);    //按名字查找
int find_number(int num);    //按工号查找
void del_admin(void);       //删除管理员
void reset_pass(void);      //重置管理员密码
void unlock_admin(void);     //解锁管理员帐号
void list_admin(void);        //显示所有管理员

struct Admin
{
	int number;//工号
	char name[20];//姓名
	char code[20];//密码
	int year;//出生年
	int work_year;//参加工作的那年
	char sex;//性别
	char state;//0正常 1 冻结 2 离职
};

struct Admin admin[20];
int i=0;

void view (void)
{
    system("clear");
	while(1)
	{
	puts("1.添加管理员\n");
	puts("2.删除管理员\n");
	puts("3.重置管理员密码\n");
	puts("4.解锁管理员帐号\n");
	puts("5.显示所有管理员\n");
	puts("6.退出\n");
	return;
    }
}

int main()
{
	while(1)
	{
		view();   //显示主界面
	   switch(getch())
	   {
       case 49: add_admin(); break;
       case 50: del_admin(); break;
       case 51: reset_pass(); break;
       case 52: unlock_admin(); break;
       case 53: list_admin(); break;
	   case 54: return 0 ;  break;
	   }
	}
}

void add_admin(void)   //添加管理员
{
	if(i>=20)
	{
		printf("管理员人数已满\n");
		return;
		}
   printf("请输入工号：\n");
   scanf("%d",&admin[i].number);
   printf("请输入姓名：\n");
   scanf("%s",admin[i].name);
   printf("请入密码：\n");
   scanf("%s",admin[i].code);
   printf("请输入出生年份：\n");
   scanf("%d",&admin[i].year);
   printf("请输入入职年份：\n");
   scanf("%d",&admin[i].work_year);
   setbuf(stdin,NULL);  //使stdin输入流由默认缓冲区转为无缓冲区
   while(1)
   {
      printf("请选择性别（1表示男，2表示女）：\n");
      scanf("%c",&admin[i].sex);
      if(admin[i].sex==49||admin[i].sex==50)
	  	{
	 	  	 printf("%s\n",admin[i].sex==49?"男":"女");
	  	 	 break;
		}
      else
		 printf("性别输入错误！\n");
      	 continue;
   }
   	 	 puts("添加成功！");
		 getch();
   	 	 anykey_continue();
   	 	 i++;
}

void anykey_continue(void)
{
	puts("按任意键返回......");
	getch();
}
char get_cmd(char start,char end)
{
	while(1)
	{
	char cmd = getch();
	if(cmd >= start && cmd <= end)
	  {
	   printf("%c\n",cmd);
	   return cmd;
	  }
    }
}

void show_msg(char* msg,int sec)
{
	printf("\033[01;31m%s\n\033[00m",msg);
	sleep(sec);
}

int find_name(char* str)
{
	for(int i=0; admin[i].sex; i++)
	{
		if(admin[i].sex && 0 == strcmp(admin[i].name,str))
		{
		 return i;
	    }
	}
	return -1;
}

int find_number(int num)
{
	for(int i=0;admin[i].sex; i++)
	{
	  if(admin[i].sex && admin[i].number == num)
	  {
		return i;
      }
	}
    return -1;
}

void del_admin(void)   //删除管理员
{
   printf("请输入要删除的管理员工号:");
   int key = 0;
   scanf("%d",&key);
   int index = find_number(key);
   	if(-1 != index)
   {
       admin[index].sex = 0;
       show_msg("删除成功!",1);
	   return;
   }
   if(-1 == index)
   {
   show_msg("查无此人!",1);
   return;
   }
}

void reset_pass(void)   //重置管理员密码
{
    while(1)
	{
        printf("请输入要重置密码的管理员工号：\n");
    	int new_number = 0;
		scanf ("%d",&new_number);
		int index = find_number(new_number);
		if(-1 == index)
		{
			show_msg("查无此人!",1);
			return;
		}
		else
		{
			printf("确定重置密码请按1，取消请按2：\n");  
			 switch(get_cmd('1','2'))
			 {		
			 case '1': strcpy(admin[index].code,"123456");
                  	   printf("重置密码成功！初始密码为：123456\n");
					   anykey_continue();
			    	   return;
	 	     case '2': return;
	    	}
		}  
	}
	sleep(2);
}

void unlock_admin(void)   //解锁管理员帐号
{
  while(1)
    {
    printf("请输入要解锁的管理员工号：\n");
    int new_number = 0;
    scanf ("%d",&new_number);
	int index = find_number(new_number);
    if(-1 == index) 
       {
        show_msg("查无此人!",1);
	    return;
       }
    else
       {
	    printf("确认解锁帐号请按1，取消请按2: \n");
        switch(get_cmd('1','2'))
          {
           case '1': admin[index].state = '1';
		             printf("解锁帐号成功！\n");
                     anykey_continue();
			         return;
		   case '2': return;
         }
      }	
   }
}

void list_admin(void)   //显示所有管理员
{
  system("clear");
  for(int i=0; admin[i].sex; i++)
  {
   if(admin[i].sex)
    { 
		printf("姓名：%s，性别：%s，学号：%d\n",admin[i].name,'1'==admin[i].sex?"男":"女",admin[i].number);
    }
  }
  anykey_continue();
}


