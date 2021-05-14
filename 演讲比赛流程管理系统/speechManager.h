#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

using namespace std;

//设计演讲管理类
/*
提供菜单界面与用户交互
对演讲比赛流程进行控制
与文件的读写交互
*/
class SpeechManager
{
public:
	SpeechManager();

	~SpeechManager();
	//菜单
	void show_Menu();
	//退出
	void exitSystem();

	//初始化
	void initSpeech();

	//创建选手
	void createSpeaker();

	//开始比赛控制函数
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示晋级选手信息
	void showScore();

	//保存记录
	void saveRecord();

	//读取数据
	void loadRecord();

	//显示往届得分
	void showRecord();

	//清空记录
	void clearRecord();
public:
	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_Record;

	//比赛选手  12人
	vector<int> v1;

	//第一轮晋级 6人
	vector<int> v2;

	//胜利前三名容器
	vector<int> vVictory;

	//存放编号及具体选手容器
	map<int, Speaker> m_Speaker;

	//比赛轮数
	int m_Index;
};