#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//����
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
		printf("���ݳɹ�!\n");
	}
}

//��������
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

//��ʼ��
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

//��ӡ
void show_contacts(const contacts* con)
{
	int i = 0;

	if (con->count == 0)
	{
		printf("������Ϣ���������ϵ�ˡ�\n");
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

//���
void add_infor(contacts* con)
{

	expansion(con);
	printf("��ʼ��ӵ�%d����ϵ��\n", con->count + 1);

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
		printf("������Ϣ���������ϵ�ˡ�\n");
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
		printf("������Ϣ���������ϵ�ˡ�\n");
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
		printf("������Ϣ���������ϵ�ˡ�\n");
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
		printf("������Ϣ���������ϵ�ˡ�\n");
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

//��������
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


//����
void destory_contacts(contacts* con)
{
	free(con->data);
	con->data = NULL;
}