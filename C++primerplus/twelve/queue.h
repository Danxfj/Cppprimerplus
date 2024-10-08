#pragma once
class Customer
{
private:
	long arrive;   //arrival time for customer
	int processtime;  //processing time for customer
public:
	Customer() { arrive = processtime = 0; }

	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node { Item item; struct Node* next; };
	enum {Q_SIZE = 10};

	Node* front;
	Node* rear;
	int items;
	const int qsize;

	Queue(const Queue& q): qsize(0) { }   //拷贝构造函数
	Queue& operator=(const Queue& q) { return *this; }  //重载赋值运算符ss
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};
