
/*
演讲比赛、12人参加、比两轮、第一轮淘汰赛
第二轮决赛
选手编号10001~10012
分组比赛、每组6人
第一轮分为两个小组，整体按照选手编号抽签后顺序演讲
十个评委、去除最高最低分，求平均分
当小组演讲完后、淘汰排名最后的三名。前三晋级
第二轮决赛、前三胜出
每轮比赛后需要显示晋级选手信息
*/

/*
功能：
开始演讲比赛：完成比赛流程、每个阶段给用户提示、
按任意键后继续下一个
查看往届记录：查看之前比赛前三名结果、每次都会
记录在.csv文件中
清空比赛记录：将文件中的数据清空
退出比赛程序：退出
*/

#include"speechManager.h"
#include<ctime>

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	//测试12名选手创建
	/*for (auto m : sm.m_Speaker)
	{
		cout << "选手编号: " << m.first
			<< " 姓名： " << m.second.m_name
			<< " 成绩： " << m.second.m_Score << endl;
	}*/

	

	while (true)
	{
		sm.show_Menu();
		int choice = 0;
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: //开始比赛
			sm.startSpeech();
			break;
		case 2: //查看往届记录
			sm.showRecord();
			break;
		case 3:	//清空比赛记录
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}