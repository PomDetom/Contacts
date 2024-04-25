#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

void init_contacts(contacts* con)
{
	memset(con->data, 0, sizeof(con->data));
	con->count = 0;
}

void show_contacts(const contacts* con)
{
	int i = 0;

	if (con->count == 0)
	{
		printf("暂无信息，请添加联系人。\n");
	}
	else
	{
		printf("%-10s\t%-3s\t%-5s\t%-12s\t%-20s\n", "年龄", "性别", "姓名", "电话", "地址");
		for (i = 0; i < con->count; i++)
		{
			printf("%-10s\t%-3d\t%-5s\t%-12s\t%-20s\n",
				con->data[i].name,
				con->data[i].age,
				con->data[i].sex,
				con->data[i].tel,
				con->data[i].address);
		}
	}
}

void add_infor(contacts* con)
{
	if (con->count == max_data)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("这是第%d个联系人\n", con->count + 1);

		printf("请输入姓名：");
		scanf("%s", con->data[con->count].name);
		printf("请输入年龄：");
		scanf("%d", &con->data[con->count].age);
		printf("请输入性别：");
		scanf("%s", con->data[con->count].sex);
		printf("请输入电话：");
		scanf("%s", con->data[con->count].tel);
		printf("请输入地址：");
		scanf("%s", con->data[con->count].address);
		con->count++;
		printf("添加成功！\n");
	}
}

//查找姓名
int find_infor(const char input_name[], const contacts* con)
{
	int i = 0;

	for (i = 0; i < con->count + 1; i++)
	{
		if (strcmp(input_name, con->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//void del_infor(contacts* con)
//{
//	if (con->count == 0)
//	{
//		printf("暂无信息，请添加联系人。\n");
//	}
//	else
//	{
//		char input_name[max_name] = { 0 };
//		printf("请输入要删除联系人的姓名:");
//		scanf("%s", input_name);
//		int ret = find_infor(input_name, con);
//
//		if (ret == -1)
//		{
//			printf("联系人不存在。\n");
//		}
//		else
//		{
//			int i = 0;
//
//			con->count--;
//			for (i = ret; i < con->count + 1; i++)
//			{
//				con->data[i] = con->data[i + 1];
//			}
//			printf("删除成功！\n");
//			show_contacts(con);
//		}
//	}
//}