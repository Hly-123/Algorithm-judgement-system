#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include<stdio.h>
#define random(a,b) (rand()%(b-a)+a)
using namespace std;

class algorithm
{
private:
	int ques_num;
	char opera;
	double range;
	int score;
	int right;
	int wrong;
	double pre_time;
	int ans;
	double consumeTime;
	double allTime;
	double thinkTime;

public:
	algorithm();
	clock_t timekeeper(int ans, double thinkTime, double allTime);
	//��ʱ���������������ǵ�δ�����̵�˼��ʱ��ͼ���ʱ������ʱ�䣩
	~algorithm();
};