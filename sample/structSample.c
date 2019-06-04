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

	// �擪�A�h���X���|�C���^�ɐݒ�
	pkudamono = kudamono;

	int i = 0;

	// �l���Q�Ƃ���ꍇ
	kudamono[i].id = i;
	strcpy_s(kudamono[i].name, sizeof(kudamono[i].name), "���");
	kudamono[i].price = 100;

	i++;

	// �|�C���^���Q�Ƃ���ꍇ
	(pkudamono + i)->id = i;
	strcpy_s((pkudamono + i)->name, sizeof((pkudamono + i)->name), "�݂���");
	(pkudamono + i)->price = 300;

	// �l���Q�Ƃ���ꍇ
	printf("%s %d�~\r\n", kudamono[0].name, kudamono[0].price);

	// �|�C���^���Q�Ƃ���ꍇ
	printf("%s %d�~\r\n", (pkudamono + 1)->name, (pkudamono + 1)->price);

	// �|�C���^�̃A�h���X��ύX���Ȃ���o��
	for (int i = 0; i < 2; i++)
	{
		printf("[%d]%s %d�~\r\n", pkudamono->id, pkudamono->name, pkudamono->price);
		pkudamono++;
	}
}
