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

//����ݽ�������
/*
�ṩ�˵��������û�����
���ݽ��������̽��п���
���ļ��Ķ�д����
*/
class SpeechManager
{
public:
	SpeechManager();

	~SpeechManager();
	//�˵�
	void show_Menu();
	//�˳�
	void exitSystem();

	//��ʼ��
	void initSpeech();

	//����ѡ��
	void createSpeaker();

	//��ʼ�������ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ����ѡ����Ϣ
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ����
	void loadRecord();

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();
public:
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_Record;

	//����ѡ��  12��
	vector<int> v1;

	//��һ�ֽ��� 6��
	vector<int> v2;

	//ʤ��ǰ��������
	vector<int> vVictory;

	//��ű�ż�����ѡ������
	map<int, Speaker> m_Speaker;

	//��������
	int m_Index;
};