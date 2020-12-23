
// �ַ�������ĵ�һ��Ψһ�ַ�
/*
	����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���
	������������������������ڣ��򷵻� -1��
		s = "leetcode"
		���� 0

		s = "loveleetcode"
		���� 2
*/ 

int firstUniqChar(char * s){

    if (s == NULL) return -1;
    
    int len =strlen(s);
    if(len == 1) return 0;

    int Hash[26] = {0};
    for( int i = 0; i < len ; i++)
    {
        Hash[s[i] - 'a'] ++;
    }

    for( int j = 0; j < len; j++)
    {
        if(Hash[s[j]-'a'] == 1)
            return j;
    }
return -1;
}
