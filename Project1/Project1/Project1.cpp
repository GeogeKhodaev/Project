﻿#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int file_dis=0, count=0, sum=0;
	setlocale(LC_ALL, "Russian");
	
	char buffer[1024];
	if ((file_dis = _open("Test.txt", O_RDONLY)) == -1) 
	{
		printf("файл не найден\n");
		exit(1);
	}
	count = _read(file_dis, buffer, 1024);
	while (count > 0)
	{
		sum += count*4;
		if (sum > 1024) 
		{
			cout << "размер файла привысил 1024 байта"; 
			return 0;
		}
			for (int i = 0; i < count; i++)
			cout << buffer[i];
		count= _read(file_dis, buffer, 1024);
	}
	cout << "\n" << "\nКол-во байт = " << sum << "\n";
	return 0;
}