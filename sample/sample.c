
// malloc free
#include <stdlib.h>

#include "sample.h"

// メイン プログラムはここから実行される
int main(int argc, char* argv[])
{
	int ret = -1;

	// ファイル指定
	// 絶対パスを指定する場合、\は\\にする必要がある
	//char* pOutFilePath = "C:\\work\\sample\\sample\\test.csv";
	char* pOutFilePath = "test.csv";
	char* pInFilePath = "test.csv";


	ret = printCurrentDir();
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		return ret;
	}

	ret = filewriteSample(pOutFilePath);
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		return ret;
	}

	ret = filereadSample(pInFilePath);
	if (ret != 0) {
		// 失敗した場合、後続処理を行わずにreturn
		return ret;
	}

	// 正常終了
	return ret;
}
