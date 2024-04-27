#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//��ʼ��
void init_contacts(contacts* con)
{
	
	con->count = 0;
	con->capacity = 3;
}

//��ӡ
void show_contacts(const contacts* con)
{
	int i = 0;

	if (con->count == 0)
	{
		printf("������Ϣ����������ϵ�ˡ�\n");
	}
	else
	{
		printf("%-3s\t%-10s\t%-3s\t%-5s\t%-12s\t%-20s\n", "���", "����", "����", "�Ա�", "�绰", "��ַ");
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

//����
void add_infor(contacts* con)
{
	if (con->count == max_data)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("��ʼ���ӵ�%d����ϵ��\n", con->count + 1);

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
		printf("���ӳɹ���\n");
	}
}

//��������
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

//ɾ��
void del_infor(contacts* con)
{
	if (con->count == 0)
	{
		printf("������Ϣ����������ϵ�ˡ�\n");
	}
	else
	{
		char input_name[max_name] = { 0 };
		printf("������Ҫɾ����ϵ�˵�����:");
		scanf("%s", input_name);
		int ret = find_infor(input_name, con);

		if (ret == -1)
		{
			printf("��ϵ�˲����ڡ�\n");
		}
		else
		{
			int i = 0;

			con->count--;
			for (i = ret; i < con->count; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			printf("ɾ���ɹ���\n");
		}
	}
}

//�޸�
void modify_infor(contacts* con)
{
	if (con->count == 0)
	{
		printf("������Ϣ����������ϵ�ˡ�\n");
	}
	else
	{
		char input_name[max_name] = { 0 };
		printf("������Ҫ�޸���ϵ�˵�����:");
		scanf("%s", input_name);
		int ret = find_infor(input_name, con);

		if (ret == -1)
		{
			printf("��ϵ�˲����ڡ�\n");
		}
		else
		{
			printf("��ʼ�޸�\n");
			printf("������������");
			scanf("%s", con->data[ret].name);
			printf("���������䣺");
			scanf("%d", &con->data[ret].age);
			printf("�������Ա�");
			scanf("%s", con->data[ret].sex);
			printf("������绰��");
			scanf("%s", con->data[ret].tel);
			printf("�������ַ��");
			scanf("%s", con->data[ret].address);

			printf("�޸ĳɹ���\n");
		}
	}
}

//����
void search_contacts(contacts* con)
{
	if (con->count == 0)
	{
		printf("������Ϣ����������ϵ�ˡ�\n");
	}
	else
	{
		char input_name[max_name] = { 0 };
		printf("������Ҫ������ϵ�˵�����:");
		scanf("%s", input_name);
		int ret = find_infor(input_name, con);

		if (ret == -1)
		{
			printf("��ϵ�˲����ڡ�\n");
		}
		else
		{
			printf("���ҵ����ǵ�%d����ϵ�ˡ�\n", ret + 1);
			printf("%-10s\t%-3s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-10s\t%-3d\t%-5s\t%-12s\t%-20s\n",
				con->data[ret].name,
				con->data[ret].age,
				con->data[ret].sex,
				con->data[ret].tel,
				con->data[ret].address);
		}
	}
}

//����������
int compar_name(const void* a, const void* b)
{
	return strcmp(((infor*)a)->name, ((infor*)b)->name);
}

//����������
int compar_age(const void* a, const void* b)
{
	return (((infor*)a)->age - ((infor*)b)->age);
}

//����
void sort_contacts(contacts* con)
{
	if (con->count == 0)
	{
		printf("������Ϣ����������ϵ�ˡ�\n");
	}
	else
	{
		int input = 0;
		printf("1.���� 2.���� 0.������\n");
		printf("��ѡ�����򷽷� :");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			qsort(con->data, con->count, sizeof(infor), compar_name);
			printf("������ɣ�\n");
			break;
		case 2:
			qsort(con->data, con->count, sizeof(infor), compar_age);
			printf("������ɣ�\n");
			break;
		case 0:
			break;
		}
	}
}