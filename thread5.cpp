#include<iostream>
#include<mutex>
#include<semaphore>
#include<condition_variable>
#include<thread>
#include<atomic>
#include<queue>
#include<list>
using namespace std;

//半同步半异步线程池
//类似于生产者消费者
template<class T>
class SyncQueue//同步队列
{
private:
	std::list<T> m_queue;//缓冲区
	std::mutex m_mutex;
	std::condition_variable m_notEmpty;
	std::condition_variable m_notFull;
	size_t m_maxSize;
	bool m_needStop;
	
	bool Is_Full() const
	{
		bool full = (m_queue.size() >= m_maxSize);
		if (full)
		{
			cout << "缓冲区满了，需要等待！  同步服务线程ID：" <<this_thread::get_id() << endl;
		}
		return full;
	}

	bool Is_Empty() const
	{
		bool empty = m_queue.empty();
		if (empty)
		{
			cout << "缓冲区空了，需要等待！ 异步服务的线程ID：" << this_thread::get_id() << endl;
		}
		return empty;
	}

	bool NotFull() const { return !Is_Full(); }
	bool NotEmpty() const { return !Is_Empty(); }

	template<class U>
	void Add(U&& x)
	{
		std::unique_lock<mutex> locker(m_mutex);
		while (!m_needStop && NotFull())
		{
			m_notFull.wait(locker);
		}
		if (m_needStop) return;
		m_queue.push_back(x);
		m_notEmpty.notify_one();
	}

public:
	SyncQueue(int maxSize) :m_maxSize(maxSize), m_needStop(false) {}
	void Put(const T& x)
	{
		Add(x);
	}
	void Put(T&& x)
	{
		Add(std::forward<T>(x));
	}

	void Take(std::list<T>& list)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		while (!m_needStop && Is_Empty())
		{
			m_notEmpty.wait(locker);
		}
		if (m_needStop) return;
		list = std::move(m_queue);
		m_notFull.notify_one();////
	}
	void Task(T& x)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		while (!m_needStop && Is_Empty())
		{
			m_notEmpty.wait(locker);
		}
		if (m_needStop) return;
		x = m_queue.front();
		m_queue.pop_front();
		m_notFull.notify_one();///
	}
	void Stop()
	{
		{
			std::unique_lock<std::mutex> locker(m_mutex);
			m_needStop = true;
		}

		m_notFull.notify_all();
		m_notEmpty.notify_all();
	}
	bool Empty() const
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		return m_queue.empty();
	}
	bool Full() const
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		return m_queue.size() >= m_maxSize;
	}
	bool Size() const
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		return m_queue.size();
	}
	int Count() const
	{
		return m_queue.size();
	}
};

class MyTask
{
public:
	virtual void run()
	{
		cout << "MyTask" << endl;
	}
};

const int MaxTaskCount = 10;

class ThreadPool //线程池
{
private:
	std::list<std::shared_ptr<std::thread> > m_threadgroup;
	SyncQueue<MyTask*> m_queue; // 同步队列
	atomic_bool m_running;
	std::once_flag m_flag;

	void Start(int numThreads)
	{
		m_running = true;
		for (int i = 0; i < numThreads; ++i)
		{
			m_threadgroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));

		}
	}
	void RunInThread()
	{
		while (m_running)
		{
			std::list<MyTask*> list;
			m_queue.Take(list);
			for (auto& x : list)
			{
				if (!m_running) return;
				x->run();
			}
		}
	}
	void StopThreadGroup()
	{
		m_queue.Stop();
		m_running = false;
		for (auto thread : m_threadgroup)
		{
			if (thread)
			{
				thread->join();
			}
		}
		m_threadgroup.clear();
	}
public:
	ThreadPool(int numThreads = std::thread::hardware_concurrency())
		:m_queue(MaxTaskCount)
	{
		Start(numThreads);
	}
	~ThreadPool()
	{
		Stop();
	}
	void Stop()
	{
		std::call_once(m_flag, [this] { StopThreadGroup(); });
	}
	void AddTask(MyTask*&& task)
	{
		m_queue.Put(task);
	}
	void AddTask(const MyTask*& task)
	{
		//m_queue.Put(task);
	}

};

//void task1() { cout << "task1 " << endl; }
//void task2() { cout << "task2 " << endl; }
void funa(ThreadPool& pool)
{
	for (int i = 0;i < 10;++i)
	{
		auto thdId = this_thread::get_id();
		cout << "同步线程1的ID：" << thdId << endl;
		pool.AddTask(new MyTask());
	}
}
void funb(ThreadPool& pool)
{
	for (int i = 0;i < 10;++i)
	{
		auto thdId = this_thread::get_id();
		cout << "同步线程2的ID：" << thdId << endl;
		pool.AddTask(new MyTask());
	}
}
int main()
{
	ThreadPool pool;
	std::thread thd1(funa, std::ref(pool));
	std::thread thd2(funb, std::ref(pool));

	this_thread::sleep_for(std::chrono::seconds(2));
	pool.Stop();
	thd1.join();
	thd2.join();
	return 0;
}

#if 0
// mutex & condition_variable cv 实现信号量
class Semaphore
{
private:
	int count;
	std::mutex mtx;
	std::condition_variable cv;
public:
	Semaphore(int value = 1) : count(value) {}
	~Semaphore() {}
	Semaphore(const Semaphore&) = delete;
	Semaphore& operator=(const Semaphore&) = delete;

	void P()
	{
		unique_lock<mutex> locker(mtx);
		if (--count < 0)
		{
			cv.wait(locker);
		}
	}
	void V()
	{
		unique_lock<mutex> locker(mtx);
		if (++count <= 0)
		{
			cv.notify_one();
		}
	}
};


int main()
{
	int x = 10;
	atomic<int*> a(&x);

	cout << a.load() << endl;
}

int main()
{
	atomic<int> a = 1;
	cout << a.load() << endl;
	int x = 10;
	a.compare_exchange_strong(x, 100);
	cout << a.load() << endl;

	return 0;
}



std::atomic<int> a = 0;

int main()
{
	int i = 0;

	a = i++;
	cout << a <<" "<< i << endl;

	return 0;
}


#endif