
/*
�ݽ�������12�˲μӡ������֡���һ����̭��
�ڶ��־���
ѡ�ֱ��10001~10012
���������ÿ��6��
��һ�ַ�Ϊ����С�飬���尴��ѡ�ֱ�ų�ǩ��˳���ݽ�
ʮ����ί��ȥ�������ͷ֣���ƽ����
��С���ݽ������̭��������������ǰ������
�ڶ��־�����ǰ��ʤ��
ÿ�ֱ�������Ҫ��ʾ����ѡ����Ϣ
*/

/*
���ܣ�
��ʼ�ݽ���������ɱ������̡�ÿ���׶θ��û���ʾ��
��������������һ��
�鿴�����¼���鿴֮ǰ����ǰ���������ÿ�ζ���
��¼��.csv�ļ���
��ձ�����¼�����ļ��е��������
�˳����������˳�
*/

#include"speechManager.h"
#include<ctime>

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	//����12��ѡ�ִ���
	/*for (auto m : sm.m_Speaker)
	{
		cout << "ѡ�ֱ��: " << m.first
			<< " ������ " << m.second.m_name
			<< " �ɼ��� " << m.second.m_Score << endl;
	}*/

	

	while (true)
	{
		sm.show_Menu();
		int choice = 0;
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: //��ʼ����
			sm.startSpeech();
			break;
		case 2: //�鿴�����¼
			sm.showRecord();
			break;
		case 3:	//��ձ�����¼
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