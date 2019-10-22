#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void tFunc1(int _amt)
{
	for (int i = 0; i < _amt; i++)
	{
		mtx.lock();
		std::cout << "Thread 1 ticking: " << i << std::endl;
		mtx.unlock();
	}
}

void tFunc2(int _amt)
{
	for (int i = 0; i < _amt; i++)
	{
		mtx.lock();
		std::cout << "Thread 2 ticking: " << i << std::endl;
		mtx.unlock();
	}
}

void tFunc3(int _amt)
{
	for (int i = 0; i < _amt; i++)
	{
		mtx.lock();
		std::cout << "Thread 3 ticking: " << i << std::endl;
		mtx.unlock();
	}
}

void tFunc4(int _amt)
{
	for (int i = 0; i < _amt; i++)
	{
		mtx.lock();
		std::cout << "Thread 4 ticking: " << i << std::endl;
		mtx.unlock();
	}
}

int main()
{

	std::thread thread1(tFunc1, 250000);
	std::thread thread2(tFunc2, 250000);
	std::thread thread3(tFunc3, 250000);
	std::thread thread4(tFunc4, 250000);

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();

	std::cin.get();

	return 0;
}