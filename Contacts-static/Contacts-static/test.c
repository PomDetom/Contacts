#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//ͨѶ¼
//1.��� 2.ɾ�� 3.�޸� 4.���� 5.����
enum menu
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,
	SORT,
	SHOW
};

void menu()
{
	printf("***********************************\n");
	printf("******* 1.add       2.del *********\n");
	printf("******* 3.modify    4.search ******\n");
	printf("******* 5.sort      6.show ********\n");
	printf("******* 0.exit             ********\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	contacts con;

	init_contacts(&con);

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			add_infor(&con);
			break;
		case DEL:
			//del_infor(&con);
			break;
		case MODIFY:
			break;
		case SEARCH:
			break;
		case SORT:
			break;
		case SHOW:
			show_contacts(&con);
			break;
		case EXIT:
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);


	return 0;
}