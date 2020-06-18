#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#pragma warning(disable:4996)
unsigned int counting(const char* [], float Lsum);
int main()
{
	setlocale(LC_ALL, "ukr");
	const char* number[] = { "один", "два", "три", "чотири", "п'ять", "шість","сім","вісім", "дев'ять", 
		                     "десять", "одинадцять",/*10*/ "дванадцять", "тринадцять","чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять", 
		                     "двадцять"/*19*/, "тридцять", "сорок", "п’ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто", 
		                     "сто","двісті","триста","чотириста"/*30*/,"п'ятсот","шістсот","сімсот","вісімсот","дев'ятсот", 
		                     "тисяча","дві","тисячі","тисячь","одна"/*40*/};
	char sum[10];
	fgets(sum, 10, stdin);
	float lsum = atof(sum);
	counting(number, lsum);
}
unsigned int counting(const char* Number[], float Lsum)
{
	void* number_two(const char* wwNumber[], const float Num);
	void* number_three(const char* wwNumber[], const float Num);
	void* number_four(const char* wwNumber[], const float Num);
	void* number_five(const char* wwNumber[], const float Num);
	void* number_six(const char* wwNumber[], const float Num);
	int  num = Lsum;
	int counter = 0;//количество знаков до запятой
	while (Lsum >= 1)//блок считает количество знаков до запятой
	{
		Lsum /= 10;
		counter++;
	}
	if (num == 0)
	{
		printf("нуль\n");
	}
	while (counter > 0)
	{
		if (counter == 2 || counter == 1)
		{
			number_two(Number, num);
			break;
		}
		if (counter == 3)
		{
			number_three(Number, num);
			num = num - (int(num / 100) * 100);
			counter--;
		}
		if (counter == 4)
		{
			number_four(Number, num);
			num = num - (int(num / 1000) * 1000);
			counter--;
		}
		if (counter == 5)
		{
			number_five(Number, num);
			if (int(num / 10000) == 1)
			{
				counter -= 2;
				num -= (int(num / 10000) * 10000);
				num -= (int(num / 1000) * 1000);
			}
			else
			{
				counter--;
				num = num - (int(num / 10000) * 10000);
			}
		}
		if (counter == 6)
		{
			number_six(Number, num);
			counter--;
			num = num - (int(num / 100000) * 100000);
		}
	}
	return counter;
}
//ЕСЛИ 2 ФУНКЦИЯ ОБРАБАТЫВАЕТ И ПЕЧАТАЕТ 1 И 2-ЗНАЧНЫЕ ЧИСЛА
void* number_two(const char* wwNumber[], const float Num)
{
	float num = Num;
	switch (int(num / 10))
	{
	case 0:printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);break;//ОТРАБОТКА ЧИСЛА ДО 9
	case 1:printf("%s", wwNumber[9 + int(num - int(num / 10) * 10)]);break;//ОТРАБОТКА ЧИСЛА ДО 19
	case 2:printf("%s ", wwNumber[19]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break;//ОТРАБОТКА ЧИСЛА ОТ 20 ДО 29
	case 3:printf("%s ", wwNumber[20]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break; //ОТРАБОТКА ЧИСЛА ОТ 30 ДО 39
	case 4:printf("%s ", wwNumber[21]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break;//ОТРАБОТКА ЧИСЛА ОТ 40 ДО 49
	case 5:printf("%s ", wwNumber[22]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break;//ОТРАБОТКА ЧИСЛА ОТ 50 ДО 59
	case 6:printf("%s ", wwNumber[23]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break;//ОТРАБОТКА ЧИСЛА ОТ 60 ДО 69
	case 7:printf("%s ", wwNumber[24]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break; //ОТРАБОТКА ЧИСЛА ОТ 70 ДО 79
	case 8:printf("%s ", wwNumber[25]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break;//ОТРАБОТКА ЧИСЛА ОТ 80 ДО 89
	case 9:printf("%s ", wwNumber[26]);
		if (int(num - int(num / 10) * 10) > 0)
		{
			printf("%s", wwNumber[int(num - int(num / 10) * 10) - 1]);
		}
		break;//ОТРАБОТКА ЧИСЛА ОТ 90 ДО 99
	}
	return 0;
}
//ЕСЛИ 3 ФУНКЦИЯ ОБРАБАТЫВАЕТ И ПЕЧАТАЕТ 3-ЗНАЧНЫЕ ЧИСЛА
void* number_three(const char* wwNumber[], const float Num)
{
	float num = Num;
	switch (int(num / 100))
	{
	case 1:printf("%s ", wwNumber[27]); break;
	case 2:printf("%s ", wwNumber[28]); break;
	case 3:printf("%s ", wwNumber[29]); break;
	case 4:printf("%s ", wwNumber[30]); break;
	case 5:printf("%s ", wwNumber[31]); break;
	case 6:printf("%s ", wwNumber[32]); break;
	case 7:printf("%s ", wwNumber[33]); break;
	case 8:printf("%s ", wwNumber[34]); break;
	case 9:printf("%s ", wwNumber[35]); break;
	}
	return 0;
}
//ЕСЛИ 4 ФУНКЦИЯ ОБРАБАТЫВАЕТ И ПЕЧАТАЕТ 4-ЗНАЧНЫЕ ЧИСЛА
void* number_four(const char* wwNumber[], const float Num)
{
	float num = Num;
	switch (int(num / 1000))
	{
	case 0:printf("%s ", wwNumber[39]); break;
	case 1:printf("%s %s ",wwNumber[40], wwNumber[36]); break;
	case 2:printf("%s %s ", wwNumber[37], wwNumber[38]); break;
	case 3:printf("%s %s ", wwNumber[2], wwNumber[38]); break;
	case 4:printf("%s %s ", wwNumber[3], wwNumber[38]); break;
	case 5:printf("%s %s ", wwNumber[4], wwNumber[39]); break;
	case 6:printf("%s %s ", wwNumber[5], wwNumber[39]); break;
	case 7:printf("%s %s ", wwNumber[6], wwNumber[39]); break;
	case 8:printf("%s %s ", wwNumber[7], wwNumber[39]); break;
	case 9:printf("%s %s ", wwNumber[8], wwNumber[39]); break;
	}
	return 0;
}
//ЕСЛИ 5 ФУНКЦИЯ ОБРАБАТЫВАЕТ И ПЕЧАТАЕТ 5-ЗНАЧНЫЕ ЧИСЛА
void* number_five(const char* wwNumber[], const float Num)
{
	float num = Num;
	switch (int(num / 10000))
	{
	case 1://НАДО СДЕЛАТЬ ОБРАБОТЧИК ЧИСЕЛ ОТ 10 ДО 19
		switch (int(num / 1000))
		{
		case 10:printf("%s %s ", wwNumber[9], wwNumber[39]); break;
		case 11:printf("%s %s ", wwNumber[10], wwNumber[39]); break;
		case 12:printf("%s %s ", wwNumber[11], wwNumber[39]); break;
		case 13:printf("%s %s ", wwNumber[12], wwNumber[39]); break;
		case 14:printf("%s %s ", wwNumber[13], wwNumber[39]); break;
		case 15:printf("%s %s ", wwNumber[14], wwNumber[39]); break;
		case 16:printf("%s %s ", wwNumber[15], wwNumber[39]); break;
		case 17:printf("%s %s ", wwNumber[16], wwNumber[39]); break;
		case 18:printf("%s %s ", wwNumber[17], wwNumber[39]); break;
		case 19:printf("%s %s ", wwNumber[18], wwNumber[39]); break;
		}
		break;
	case 2:printf("%s ", wwNumber[19]); break;
	case 3:printf("%s ", wwNumber[20]); break;
	case 4:printf("%s ", wwNumber[21]); break;
	case 5:printf("%s ", wwNumber[22]);	break;
	case 6:printf("%s ", wwNumber[23]); break;
	case 7:printf("%s ", wwNumber[24]); break;
	case 8:printf("%s ", wwNumber[25]); break;
	case 9:printf("%s ", wwNumber[26]); break;
	}
	return 0;
}
//ЕСЛИ 6 ФУНКЦИЯ ОБРАБАТЫВАЕТ И ПЕЧАТАЕТ 6-ЗНАЧНЫЕ ЧИСЛА
void* number_six(const char* wwNumber[], const float Num)
{
	float num = Num;
	switch (int(num / 100000))
	{
	case 1:printf("%s ", wwNumber[27]); break;
		switch (int(num / 10000))
		{
		case 10:printf("%s ", wwNumber[9]); break;
		case 11:printf("%s ", wwNumber[10]); break;
		case 12:printf("%s ", wwNumber[11]); break;
		case 13:printf("%s ", wwNumber[12]); break;
		case 14:printf("%s ", wwNumber[13]); break;
		case 15:printf("%s ", wwNumber[14]); break;
		case 16:printf("%s ", wwNumber[15]); break;
		case 17:printf("%s ", wwNumber[16]); break;
		case 18:printf("%s ", wwNumber[17]); break;
		case 19:printf("%s ", wwNumber[18]); break;
		}
		break;
	case 2:printf("%s ", wwNumber[28]); break;
	case 3:printf("%s ", wwNumber[29]); break;
	case 4:printf("%s ", wwNumber[30]); break;
	case 5:printf("%s ", wwNumber[31]); break;
	case 6:printf("%s ", wwNumber[32]); break;
	case 7:printf("%s ", wwNumber[33]); break;
	case 8:printf("%s ", wwNumber[34]); break;
	case 9:printf("%s ", wwNumber[35]); break;
	}
	return 0;
}
