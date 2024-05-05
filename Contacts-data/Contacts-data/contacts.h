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

//������Ϣ	
typedef struct infor
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tel[max_tel];
	char address[max_address];
}infor;

//ͨѶ¼
typedef struct contacts
{
	infor* data;
	int count;
	int capacity;
}contacts;

//��ʼ��ͨѶ¼
void init_contacts(contacts* con);

//��ӡͨѶ¼
void show_contacts(const contacts* con);

//�����ϵ��
void add_infor(contacts* con);

//ɾ����ϵ��
void del_infor(contacts* con);

//�޸���ϵ��
void modify_infor(contacts* con);

//������ϵ��
void search_contacts(contacts* con);

//������ϵ��
void sort_contacts(contacts* con);

//����ͨѶ¼
void destory_contacts(contacts* con);

//��������
void save_contacts(contacts* con);
