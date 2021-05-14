#include"speechManager.h"

SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()
{
	cout << "***************************" << endl;
	cout << "**** 欢迎参加演讲比赛  ****" << endl;
	cout << "**** 1、开始演讲比赛   ****" << endl;
	cout << "**** 2、查看往届记录   ****" << endl;
	cout << "**** 3、清空比赛记录   ****" << endl;
	cout << "**** 0、退出比赛程序   ****" << endl;
	cout << "***************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//比赛轮数
	this->m_Index = 1;

	//清空记录容器
	this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_name = name;
		
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，放入v1
		this->v1.push_back(i + 10001);

		//选手编号及对应选手，放入map
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();
	//2、第二轮比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();

	//第二轮比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();
	//2、第二轮比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();
	//4、保存分数
	this->saveRecord();

	//重置比赛，获取记录
	//初始化容器和属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "第 <<" << this->m_Index << ">>轮选手正在抽签" << endl;
	cout << "---------------------------" << endl;
	cout << "抽签后的演讲顺序如下：" << endl;

	if (this->m_Index == 1)//第一轮
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end();it++)
		{
			cout << *it << endl;
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest()
{
	cout << "----------第" << this->m_Index << "轮比赛正式开始----------- " << endl;

	//准备一个临时容器 存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0; //记录人员个数  6人一组

	vector<int> v_Src; //比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin();it != v_Src.end();it++)
	{
		num++;

		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(),d.end(), greater<double>()); //排序
		d.pop_front();
		d.pop_back(); //去除最高最低

		double sum = accumulate(d.begin(), d.end(),0.0f);//总分
		double avg = sum / (double)d.size(); //平均分

		/*cout << " 编号： " << *it << " 姓名："
			<< this->m_Speaker[*it].m_name
			<< " 获取平均分： " << avg << endl;*/

		//将平均分放入map
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据放入临时小组容器
		groupScore.insert(make_pair(avg, *it)); // key得分  value编号
		//每6人取出前三
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次: " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号： " << it->second << " 姓名： "
					<< this->m_Speaker[it->second].m_name
					<< " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1]
					<< endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); 
				it != groupScore.end() && count < 3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "----------------第" << this->m_Index << "轮比赛完毕---------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "--------------第" << this->m_Index << "轮晋级选手信息如下---------------" << endl;

	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (auto it : v)
	{
		cout << "选手编号： " << it << " 姓名： " << this->m_Speaker[it].m_name
			<< " 得分： " << this->m_Speaker[it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	//this->show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out | ios::app); //写文件  追加

	//将每个选手数据 写入文件
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << " 记录已经保存" << endl;
	//更改文件不为空的状态
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in); //读文件
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch); //将上面读取的单个字符 放回来

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string> v; //存放6个sting字符串
		int pos = -1; //查到，的位置
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到的情况
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();

	/*for (auto m : m_Record)
	{
		cout << "第" << m.first << "届" << "冠军编号："
			<< m.second[0] << " 分数：" << m.second[1] << endl;
	}*/
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空，或不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size();i++)
		{
			cout << "第" << i + 1 << "届"
				<< " 冠军编号：" << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
				<< " 亚军编号：" << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
				<< " 季军编号：" << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "是否确定清空文件！" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化容器和属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();

		//加载往届记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

