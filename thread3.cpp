#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

//当有好几个生产者和消费者的时候如何解决？

std::mutex mtx;
std::condition_variable cv;
int isReady = 1;

void ThreadA()
{
	std::unique_lock<std::mutex> locker(mtx);
	while(isReady <= 100)
	{
		while (!(isReady % 3 == 1))
		{
			cv.wait(locker);
		}
		cout << isReady << " ";
		isReady++;
		cv.notify_all();
	}
}

void ThreadB()
{
	std::unique_lock<std::mutex> locker(mtx);
	while (isReady <= 100)
	{
		while (!(isReady % 3) == 2)
		{
			cv.wait(locker);
		}
		cout << isReady << " ";
		isReady++;
		cv.notify_all();
	}
}

void ThreadC()
{
	std::unique_lock<std::mutex> locker(mtx);
	while (isReady <= 100)
	{
		while (!(isReady % 3 == 0))
		{
			cv.wait(locker);
		}
		cout << isReady << " ";
		isReady++;
		cv.notify_all();
	}
}

int main()
{
	std::thread t1(ThreadA);
	std::thread t2(ThreadB);
	std::thread t3(ThreadC);

	t1.join();
	t2.join();
	t3.join();

	return 0;

}

#if 0
//ABC ABC ABC....
std::mutex mtx;
std::condition_variable cv;
int isReady = 0;

void print_a()
{
	std::unique_lock<std::mutex> locker(mtx);
	for (int i = 0; i < 10; ++i)
	{
		while (isReady != 0)
		{
			cv.wait(locker);				
		}
		cout << "A";
		isReady = 1;
		cv.notify_all();
	}
}

void print_b()
{
	std::unique_lock<std::mutex> locker(mtx);
	for (int i = 0; i < 10; ++i)
	{
		while (isReady != 1)
		{
			cv.wait(locker);
			
		}
		cout << "B";		
		isReady = 2;
		cv.notify_all();
	}
}

void print_c()
{
	std::unique_lock<std::mutex> locker(mtx);
	for (int i = 0; i < 10; ++i)
	{
		while (isReady != 2)
		{
			cv.wait(locker);
		}
		cout << "C";
		isReady = 0;
		
		cv.notify_all();
	}
}

int main()
{
	std::thread t1(print_a);
	std::thread t2(print_b);
	std::thread t3(print_c);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}


class Queue
{
private:
	queue<int> qu;
	size_t maxsize;
public:
	Queue(size_t sz) :maxsize(sz) {}
	~Queue() {}
	bool is_full() const{ return qu.size() == maxsize; }
	bool is_emply() const { return qu.size() == 0; }
	void put(int val) { qu.push(val); }
	int get()
	{
		int val = qu.front();
		qu.pop();
		return val;
	}
};

const int MAX_ITEM = 5;
const int Producer_MAX = MAX_ITEM * 50;

std::mutex mtx;
std::condition_variable cv;
int num = 0;
Queue qu(MAX_ITEM);

void Producer_thread()
{
	for (int i = 0; i < Producer_MAX; i++)
	{
		std::unique_lock<std::mutex> locker(mtx);
		while (qu.is_full())
		{
			cv.wait(locker);
		}
		cout << "producer: " << i << endl;
		qu.put(i);
		cv.notify_all();

	}
}

void Consumer_thread()
{
	for (int i = 0; i < Producer_MAX; ++i)
	{
		std::unique_lock<std::mutex> locker(mtx);
		while (qu.is_emply())
		{
			cv.wait(locker);
		}
		int val = qu.get();
		cout << "Consumer: " << i << endl;
		cv.notify_all();
	}
}

int main()
{
	std::thread proda(Producer_thread);
	std::thread consa(Consumer_thread);

	//std::thread proda1(Producer_thread);
	//std::thread consa1(Consumer_thread);

	proda.join();
	consa.join();

	return 0;
}


//生产者消费者
std::mutex mtx;
std::condition_variable cv;
bool lable = false;

int number = 0;
const int n = 10;
void producer_thread()
{
	cout << "Producer fun run" << endl;
	std::unique_lock<std::mutex> locker(mtx);
	for (int i = 0;i < n;i++)
	{
		while (lable)
		{
			cv.wait(locker);
		}
		
		number = i;//生产	
		lable = true;	
		cout << "producer: " << number << endl;
		
		cv.notify_one();
	}
}

void consumer_thread()
{
	cout << "Consumer fun run" << endl;
	std::unique_lock<std::mutex> locker(mtx);
	for (int i = 0;i < n;++i)
	{
		while (!lable)
		{
			cv.wait(locker);
		}
		
		cout << "consuner:" << number << endl;
		lable = false;
		cv.notify_one();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

int main()
{
	std::thread prod(producer_thread);
	std::thread cons(consumer_thread);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	cv.notify_all();
	prod.join();
	cons.join();

	return 0;
}


std::mutex g_mtx;
const int n = 5;
void funa(char ch)
{
	//g_mtx.lock();
	lock_guard<std::mutex> locker(g_mtx);
	//std::lock(g_mtx);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0;j < 10;++j)
		{
			cout << ch;
		}
		cout << endl;
	}
	//g_mtx.unlock();
}
int main()
{
	std::thread arth[n];

	for (int i = 0;i < n;++i)
	{
		arth[i] = std::thread(funa, i + 'a');
	}
	for (auto& x : arth)
	{
		x.join();
	}
	cout << "main end" << endl;
	return 0;
}

#endif