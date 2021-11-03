#include<iostream>
#include"algorithm.h"
using namespace std;

algorithm::algorithm()
{
	score = 0;	right = 0; wrong = 0;
	cout << "��ӭ�����������������ϵͳ��\n\n"
		<< "��ѡ����Ե�������";
	cin >> ques_num;
	cout << "���Ե��㷨���ɹ������У���+������-������*����/������";

	//���û�����Ĳ����㷨����ʱ����ʱ�������ѣ�����ַ�����ȡʹ������Ч������
	opera = char(_getch());
	cout << opera << endl;
	while (true)
	{
		if (opera == '+' || opera == '-' || opera == '*' || opera == '/')
		{
			cout << "�����㷨������ȷ��" << endl;
			break;
		}
		else
		{
			cout << "����ṩ���㷨��ѡ���ޣ�" << endl;
			opera = char(_getch());
			cout << opera << endl;
		}
	}

	cout << "��������м�λ�����ڵ����㣨�������֣���";
	cin >> range;
	cout << "��������˴ο��Լƻ���ɵ�ʱ�䣨����Ϊ��λ����" << endl;
	cin >> pre_time;
	cout << "\n���β��Լ�����ʼ������Ϊ" << ques_num * 10
		<< "��ÿ�����ֵΪ10��\n��������׼��������ok���뿼��" << endl;
	char*s1 = new char[5];
	cin >> s1;
	//���������ʾ�ﲻ��okʱ�������û���������
	while (true)
	{
		if (!strcmp(s1, "ok"))
		{
			cout << "\n**************************���Կ�ʼ*****************************" << endl;
			break;
		}
		else
		{
			cout << "��������ȷ��ʾ�ok�����뿼��" << endl;
			cin >> s1;
		}
	}
	delete[] s1;
	this->ques_num = ques_num;
	this->opera = opera;
	this->range = range;

	int num1, num2;
	allTime = 0;
	srand((int)time(0));

	switch (opera)
	{
	case'+':
		for (int i = 1; i <= ques_num; i++)
		{
			num1 = random(0, int(pow(10, range)));
			num2 = random(0, int(pow(10, range)));
			cout << '\n' << num1 << "+" << num2 << "=";
			//���ó�Ա�������м�ʱ���������ƻ�ʱ��δ����������
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}
			if (ans == num1 + num2)
			{
				cout << "��ϲ������ˣ���10��" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "���ź�����ˣ����÷�" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "������ʱ" << consumeTime << "s" << endl;
			if (allTime >= pre_time)
			{
				system("cls");
				cout << "���ź�������ʱ���ѵ���" << endl;
				break;
			}
		}break;

	case '-':
		for (int i = 1; i <= ques_num; i++)
		{
			num1 = random(0, int(pow(10, range)));
			num2 = random(0, int(pow(10, range)));
			cout << '\n' << num1 << "-" << num2 << "=";
			//���ó�Ա�������м�ʱ���������ƻ�ʱ��δ����������
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}

			if (ans == num1 - num2)
			{
				cout << "��ϲ������ˣ���10��" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "���ź�����ˣ����÷�" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "������ʱ" << consumeTime << "s" << endl;
			if (thinkTime < pre_time && allTime >= pre_time)
			{
				system("cls");
				cout << "���ź�������ʱ���ѵ���" << endl;
				break;
			}
		}break;

	case '*':
		for (int i = 1; i <= ques_num;i++)
		{
			num1 = random(0, int(pow(10, range)));
			num2 = random(0, int(pow(10, range)));
			cout << '\n' << num1 << "*" << num2 << "=";
			//���ó�Ա�������м�ʱ���������ƻ�ʱ��δ����������
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}
			if (ans == num1 * num2)
			{
				cout << "��ϲ������ˣ���10��" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "���ź�����ˣ����÷�" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "������ʱ" << consumeTime << "s" << endl;
			if (allTime >= pre_time)
			{
				system("cls");
				cout << "���ź�������ʱ���ѵ���" << endl;
				break;
			}
		}break;
	case '/':
		for (int i = 1; i <= ques_num;i++)
		{
			num1 = random(0, int(pow(10, range)));
			while (true)
			{
				if (num1 == 0)
				{
					num1 = random(0, int(pow(10, range)));
				}
				else break;
			}
			num2 = num1 * random(0, int(pow(10, range)));
			cout << '\n' << num2 << "/" << num1 << "=";
			//���ó�Ա�������м�ʱ���������ƻ�ʱ��δ����������
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}
			if (ans == num2 / num1)
			{
				cout << "��ϲ������ˣ���10��" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "���ź�����ˣ����÷�" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "������ʱ" << consumeTime << "s" << endl;
			if (allTime >= pre_time)
			{
				system("cls");
				cout << "���ź�������ʱ���ѵ���" << endl;
				break;
			}
		}break;
	default:
		break;
	}
};

clock_t algorithm::timekeeper(int ans, double thinkTime, double allTime)
{
	clock_t start = clock();
	//һ���̶��Ͻ�����ް����س�ʱcin���������������ʵ�ֳ�ʱ����������
	while (true)
	{
		if (_kbhit())
		{
			cin >> ans;
			break;
		}
		clock_t end1 = clock();
		thinkTime = (double)(end1 - start) / CLOCKS_PER_SEC;

		if ((this->allTime + thinkTime) >= pre_time)//ques_num
		{
			system("cls");
			cout << "���ź�������ʱ���ѵ���" << endl;
			break;
		}
	}
	this->ans = ans;
	this->thinkTime = thinkTime;
	return start;
};

algorithm::~algorithm()
{
	cout << "\n�����β����ܷ�Ϊ��" << score
		<< "��\n�����" << right << "�⣬�����" << wrong
		<< "��\n��ʱ" << allTime << "s\n" << "�ƻ�ʱ��" << pre_time << "s" << endl;
};