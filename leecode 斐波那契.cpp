/*
	斐波那契
	答案需要取模 1e9+7（1000000007），
	如计算初始结果为：1000000008，请返回 1。 
*/ 


int fib(int n){
    if(n == 0 || n ==1)
        return n;
    
    long long fibone = 1;
    long long fibtwo = 0;
    long long fibn = 0;

    for(unsigned int i = 2; i <= n; ++i)
    {
        fibn = (fibone + fibtwo) % 1000000007;

        fibtwo = fibone;
        fibone = fibn;
    }
   
   return fibn;
}
