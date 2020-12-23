
// 字符串里面的第一个唯一字符
/*
	给定一个字符串，找到它的第一个不重复的字符，
	并返回它的索引。如果不存在，则返回 -1。
		s = "leetcode"
		返回 0

		s = "loveleetcode"
		返回 2
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
