#include<iostream>
#include<stdlib.h>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<semaphore>
#include<stdio.h>
using namespace std;

std::counting_semaphore  sm(0);

void threadProc()
{
	sm.acquire(); //P
	cout << "thread got the signal" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	cout << "thread send the signal " << endl;
	sm.release();//V
}

int main()
{
	std::thread tw(threadProc);
	cout << "main send the signal" << endl;
	sm.release();
	cout << sm.max() << endl;
	this_thread::sleep_for(std::chrono::milliseconds(200));
	cout << "main got the signal \n" << endl;
	tw.join();
	return 0;
}

#if 0
//用三个线程打印0...100
std::mutex g_mtx;
std::condition_variable cv;
int number = 0;

void fun0() //0   3
{
	unique_lock<std::mutex> locker(g_mtx);
	while (number <= 100)
	{
		while (number % 3 == 0 && number <= 100)
		{
			cout << number << " ";
			number += 1;
			cv.notify_all();
		}
		cv.wait(locker);
	}
}

void fun1() //1    4
{
	unique_lock<std::mutex> locker(g_mtx);
	while (number <= 100)
	{
		while (number % 3 == 1 && number <= 100)
		{
			cout << number << " ";
			number += 1;
			cv.notify_all();
		}
		cv.wait(locker);
	}
}

void fun2()  //2   5
{
	unique_lock<std::mutex> locker(g_mtx);
	while (number <= 100)
	{
		while (number % 3 == 2 && number <= 100)
		{
			cout << number << " ";
			number += 1;
			cv.notify_all();
		}
		cv.wait(locker);
	}
	cv.notify_all();
}

int main()
{
	std::thread t1(fun0);
	std::thread t2(fun1);
	std::thread t3(fun2);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}


#endif