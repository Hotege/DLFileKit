//
// Created by dl on 2018/11/7.
//

#include <cstdio>
#include <DLFileKit.h>

int main()
{
	DLFileKit f1;
	f1.ReadFile("cube.fs");
	auto pData = (const char*)f1.GetData();
	printf("%s\n", pData);

	DLFileKit f2;
	f2.CreateFile("test.txt");
	f2.WriteFile(f1.GetData(), f1.GetSize(), 1);
	return 0;
}