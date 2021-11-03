#include<iostream>
#include"algorithm.h"
using namespace std;

algorithm::algorithm()
{
	score = 0;	right = 0; wrong = 0;
	cout << "欢迎您来到算术计算测试系统！\n\n"
		<< "请选择测试的题数：";
	cin >> ques_num;
	cout << "测试的算法（可供输入有：“+”、“-”、“*”或“/”）：";

	//在用户输入的测试算法有误时，及时进行提醒，逐个字符的提取使得提醒效率提升
	opera = char(_getch());
	cout << opera << endl;
	while (true)
	{
		if (opera == '+' || opera == '-' || opera == '*' || opera == '/')
		{
			cout << "测试算法输入正确！" << endl;
			break;
		}
		else
		{
			cout << "请从提供的算法中选择噢！" << endl;
			opera = char(_getch());
			cout << opera << endl;
		}
	}

	cout << "请输入进行几位数以内的运算（输入数字）：";
	cin >> range;
	cout << "请您输入此次考试计划完成的时间（以秒为单位）：" << endl;
	cin >> pre_time;
	cout << "\n本次测试即将开始，满分为" << ques_num * 10
		<< "，每道题分值为10。\n请您做好准备，输入ok进入考试" << endl;
	char*s1 = new char[5];
	cin >> s1;
	//当输入的提示语不是ok时将提醒用户重新输入
	while (true)
	{
		if (!strcmp(s1, "ok"))
		{
			cout << "\n**************************考试开始*****************************" << endl;
			break;
		}
		else
		{
			cout << "请输入正确提示语“ok”进入考试" << endl;
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
			//调用成员函数进行计时，若超出计划时长未作答则清屏
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}
			if (ans == num1 + num2)
			{
				cout << "恭喜您答对了！加10分" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "很遗憾答错了！不得分" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "该题用时" << consumeTime << "s" << endl;
			if (allTime >= pre_time)
			{
				system("cls");
				cout << "很遗憾，考试时间已到！" << endl;
				break;
			}
		}break;

	case '-':
		for (int i = 1; i <= ques_num; i++)
		{
			num1 = random(0, int(pow(10, range)));
			num2 = random(0, int(pow(10, range)));
			cout << '\n' << num1 << "-" << num2 << "=";
			//调用成员函数进行计时，若超出计划时长未作答则清屏
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}

			if (ans == num1 - num2)
			{
				cout << "恭喜您答对了！加10分" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "很遗憾答错了！不得分" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "该题用时" << consumeTime << "s" << endl;
			if (thinkTime < pre_time && allTime >= pre_time)
			{
				system("cls");
				cout << "很遗憾，考试时间已到！" << endl;
				break;
			}
		}break;

	case '*':
		for (int i = 1; i <= ques_num;i++)
		{
			num1 = random(0, int(pow(10, range)));
			num2 = random(0, int(pow(10, range)));
			cout << '\n' << num1 << "*" << num2 << "=";
			//调用成员函数进行计时，若超出计划时长未作答则清屏
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}
			if (ans == num1 * num2)
			{
				cout << "恭喜您答对了！加10分" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "很遗憾答错了！不得分" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "该题用时" << consumeTime << "s" << endl;
			if (allTime >= pre_time)
			{
				system("cls");
				cout << "很遗憾，考试时间已到！" << endl;
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
			//调用成员函数进行计时，若超出计划时长未作答则清屏
			clock_t start = timekeeper(ans, allTime, thinkTime);
			clock_t end = clock();
			if (allTime + thinkTime >= pre_time)
			{
				allTime += thinkTime;
				break;
			}
			if (ans == num2 / num1)
			{
				cout << "恭喜您答对了！加10分" << endl;
				score += 10;
				right += 1;
			}
			else
			{
				cout << "很遗憾答错了！不得分" << endl;
				wrong += 1;
			}
			consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
			allTime += consumeTime;
			cout << "该题用时" << consumeTime << "s" << endl;
			if (allTime >= pre_time)
			{
				system("cls");
				cout << "很遗憾，考试时间已到！" << endl;
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
	//一定程度上解决了无按键回车时cin会堵塞程序的情况，实现超时则立刻清屏
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
			cout << "很遗憾，考试时间已到！" << endl;
			break;
		}
	}
	this->ans = ans;
	this->thinkTime = thinkTime;
	return start;
};

algorithm::~algorithm()
{
	cout << "\n您本次测试总分为：" << score
		<< "分\n答对了" << right << "题，答错了" << wrong
		<< "题\n用时" << allTime << "s\n" << "计划时长" << pre_time << "s" << endl;
};