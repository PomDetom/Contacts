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
		printf("������Ϣ���������ϵ�ˡ�\n");
	}
	else
	{
		printf("%-10s\t%-3s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("���ǵ�%d����ϵ��\n", con->count + 1);

		printf("������������");
		scanf("%s", con->data[con->count].name);
		printf("���������䣺");
		scanf("%d", &con->data[con->count].age);
		printf("�������Ա�");
		scanf("%s", con->data[con->count].sex);
		printf("������绰��");
		scanf("%s", con->data[con->count].tel);
		printf("�������ַ��");
		scanf("%s", con->data[con->count].address);
		con->count++;
		printf("��ӳɹ���\n");
	}
}

//��������
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
//		printf("������Ϣ���������ϵ�ˡ�\n");
//	}
//	else
//	{
//		char input_name[max_name] = { 0 };
//		printf("������Ҫɾ����ϵ�˵�����:");
//		scanf("%s", input_name);
//		int ret = find_infor(input_name, con);
//
//		if (ret == -1)
//		{
//			printf("��ϵ�˲����ڡ�\n");
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
//			printf("ɾ���ɹ���\n");
//			show_contacts(con);
//		}
//	}
//}