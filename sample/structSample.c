// https://www.sejuku.net/blog/24473
// http://www9.plala.or.jp/sgwr-t/c/sec15-3.html

#include <stdio.h>
#include <string.h>

typedef struct _item {
	int id;
	char name[64];
	int price;
} item;

void structSample()
{
	item kudamono[20];
	item* pkudamono;

	// 先頭アドレスをポインタに設定
	pkudamono = kudamono;

	int i = 0;

	// 値を参照する場合
	kudamono[i].id = i;
	strcpy_s(kudamono[i].name, sizeof(kudamono[i].name), "りんご");
	kudamono[i].price = 100;

	i++;

	// ポインタを参照する場合
	(pkudamono + i)->id = i;
	strcpy_s((pkudamono + i)->name, sizeof((pkudamono + i)->name), "みかん");
	(pkudamono + i)->price = 300;

	// 値を参照する場合
	printf("%s %d円\r\n", kudamono[0].name, kudamono[0].price);

	// ポインタを参照する場合
	printf("%s %d円\r\n", (pkudamono + 1)->name, (pkudamono + 1)->price);

	// ポインタのアドレスを変更しながら出力
	for (int i = 0; i < 2; i++)
	{
		printf("[%d]%s %d円\r\n", pkudamono->id, pkudamono->name, pkudamono->price);
		pkudamono++;
	}
}
