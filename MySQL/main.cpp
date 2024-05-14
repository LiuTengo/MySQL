#include <stdio.h>
#include <mysql.h>

int main(void) 
{
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	mysql_init(&mysql);

	mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"gbk");

	if (mysql_real_connect(&mysql,"127.0.0.1","root","root1234","jwgl",3306,nullptr,0) == nullptr) {
		printf("����ԭ�� %s\n",mysql_error(&mysql));
		printf("����ʧ�ܣ�\n");
		exit(-1);
	}

	int ret = mysql_query(&mysql,"select * from student;");
	printf("ret: %d\n",ret);

	res = mysql_store_result(&mysql);

	while (row = mysql_fetch_row(res)) {
		printf(" %s ",row[0]); //��ӡID
		printf(" %s ",row[1]); //��ӡ����
		printf(" %s ",row[2]); //��ӡ�Ա�
		printf(" %s \n", row[3]); //��ӡ����
	}

	mysql_free_result(res);

	mysql_close(&mysql);

	system("pause");
	return 0;
}