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
		printf("错误原因： %s\n",mysql_error(&mysql));
		printf("连接失败！\n");
		exit(-1);
	}

	int ret = mysql_query(&mysql,"select * from student;");
	printf("ret: %d\n",ret);

	res = mysql_store_result(&mysql);

	while (row = mysql_fetch_row(res)) {
		printf(" %s ",row[0]); //打印ID
		printf(" %s ",row[1]); //打印姓名
		printf(" %s ",row[2]); //打印性别
		printf(" %s \n", row[3]); //打印年龄
	}

	mysql_free_result(res);

	mysql_close(&mysql);

	system("pause");
	return 0;
}