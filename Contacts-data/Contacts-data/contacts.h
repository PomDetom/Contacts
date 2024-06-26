#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

enum INFOR
{
	max_name = 10,
	max_sex = 5,
	max_tel = 12,
	max_address = 20,
	max_data = 100
};

//个人信息	
typedef struct infor
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tel[max_tel];
	char address[max_address];
}infor;

//通讯录
typedef struct contacts
{
	infor* data;
	int count;
	int capacity;
}contacts;

//初始化通讯录
void init_contacts(contacts* con);

//打印通讯录
void show_contacts(const contacts* con);

//添加联系人
void add_infor(contacts* con);

//删除联系人
void del_infor(contacts* con);

//修改联系人
void modify_infor(contacts* con);

//查找联系人
void search_contacts(contacts* con);

//排序联系人
void sort_contacts(contacts* con);

//销毁通讯录
void destory_contacts(contacts* con);

//保存数据
void save_contacts(contacts* con);
