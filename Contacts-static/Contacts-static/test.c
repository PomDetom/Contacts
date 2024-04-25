#define _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//通讯录
//1.添加 2.删除 3.修改 4.查找 5.排序
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
		printf("请选择：");
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
			printf("选择错误，重新选择。\n");
			break;
		}
	} while (input);


	return 0;
}