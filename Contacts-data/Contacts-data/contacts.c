#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//扩容
void expansion(contacts* con)
{
	if (con->count == con->capacity)
	{
		infor* str = (infor*)realloc(con->data, (con->capacity + 2) * sizeof(infor));
		if (str == NULL)
		{
			printf("expansion::%s\n", strerror(errno));
			return;
		}
		con->data = str;
		con->capacity += 2;
		printf("扩容成功!\n");
	}
}

//加载数据
void load_contacts(contacts* con)
{
	FILE* pfile = fopen("data.txt", "rb");
	if (pfile == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}

	infor swp = { 0 };

	while (fread(&swp, sizeof(infor), 1, pfile) == 1)
	{
		expansion(con);
		con->data[con->count] = swp;
		con->count++;
	}

	fclose(pfile);
	pfile = NULL;
}

//初始化
void init_contacts(contacts* con)
{
	con->data = (infor*)calloc(3, sizeof(infor));
	if (con->data == NULL)
	{
		printf("init_contacts::%s\n", strerror(errno));
		return;
	}
	con->count = 0;
	con->capacity = 3;

	load_contacts(con);
}

//打印
void show_contacts(const contacts* con)
{
	int i = 0;

	if (con->count == 0)
	{
		printf("暂无信息，请添加联系人。\n");
	}
	else
	{
		printf("%-3s\t%-10s\t%-3s\t%-5s\t%-12s\t%-20s\n", "序号", "姓名", "年龄", "性别", "电话", "地址");
		for (i = 0; i < con->count; i++)
		{
			printf("%-3d\t%-10s\t%-3d\t%-5s\t%-12s\t%-20s\n",
				i + 1,
				con->data[i].name,
				con->data[i].age,
				con->data[i].sex,
				con->data[i].tel,
				con->data[i].address);
		}
	}
}

//添加
void add_infor(contacts* con)
{

	expansion(con);
	printf("开始添加第%d个联系人\n", con->count + 1);

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

//查找姓名
int find_infor(const char input_name[], const contacts* con)
{
	int i = 0;

	for (i = 0; i < con->count; i++)
	{
		if (strcmp(input_name, con->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除
void del_infor(contacts* con)
{
	if (con->count == 0)
	{
		printf("暂无信息，请添加联系人。\n");
	}
	else
	{
		char input_name[max_name] = { 0 };
		printf("请输入要删除联系人的姓名:");
		scanf("%s", input_name);
		int ret = find_infor(input_name, con);

		if (ret == -1)
		{
			printf("联系人不存在。\n");
		}
		else
		{
			int i = 0;

			con->count--;
			for (i = ret; i < con->count; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			printf("删除成功！\n");
		}
	}
}

//修改
void modify_infor(contacts* con)
{
	if (con->count == 0)
	{
		printf("暂无信息，请添加联系人。\n");
	}
	else
	{
		char input_name[max_name] = { 0 };
		printf("请输入要修改联系人的姓名:");
		scanf("%s", input_name);
		int ret = find_infor(input_name, con);

		if (ret == -1)
		{
			printf("联系人不存在。\n");
		}
		else
		{
			printf("开始修改\n");
			printf("请输入姓名：");
			scanf("%s", con->data[ret].name);
			printf("请输入年龄：");
			scanf("%d", &con->data[ret].age);
			printf("请输入性别：");
			scanf("%s", con->data[ret].sex);
			printf("请输入电话：");
			scanf("%s", con->data[ret].tel);
			printf("请输入地址：");
			scanf("%s", con->data[ret].address);

			printf("修改成功！\n");
		}
	}
}

//查找
void search_contacts(contacts* con)
{
	if (con->count == 0)
	{
		printf("暂无信息，请添加联系人。\n");
	}
	else
	{
		char input_name[max_name] = { 0 };
		printf("请输入要查找联系人的姓名:");
		scanf("%s", input_name);
		int ret = find_infor(input_name, con);

		if (ret == -1)
		{
			printf("联系人不存在。\n");
		}
		else
		{
			printf("已找到，是第%d个联系人。\n", ret + 1);
			printf("%-10s\t%-3s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-10s\t%-3d\t%-5s\t%-12s\t%-20s\n",
				con->data[ret].name,
				con->data[ret].age,
				con->data[ret].sex,
				con->data[ret].tel,
				con->data[ret].address);
		}
	}
}

//按名称排序
int compar_name(const void* a, const void* b)
{
	return strcmp(((infor*)a)->name, ((infor*)b)->name);
}

//按年龄排序
int compar_age(const void* a, const void* b)
{
	return (((infor*)a)->age - ((infor*)b)->age);
}

//排序
void sort_contacts(contacts* con)
{
	if (con->count == 0)
	{
		printf("暂无信息，请添加联系人。\n");
	}
	else
	{
		int input = 0;
		printf("1.姓名 2.年龄 0.不排序\n");
		printf("请选择排序方法 :");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			qsort(con->data, con->count, sizeof(infor), compar_name);
			printf("排序完成！\n");
			break;
		case 2:
			qsort(con->data, con->count, sizeof(infor), compar_age);
			printf("排序完成！\n");
			break;
		case 0:
			break;
		}
	}
}

//保存数据
void save_contacts(contacts* con)
{
	FILE* pfile = fopen("data.txt", "w");
	if (pfile == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}

	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		fwrite(con->data + i, sizeof(infor), 1, pfile);
	}

	fclose(pfile);
	pfile = NULL;
}


//销毁
void destory_contacts(contacts* con)
{
	free(con->data);
	con->data = NULL;
}