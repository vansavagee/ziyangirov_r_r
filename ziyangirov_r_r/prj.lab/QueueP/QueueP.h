#ifndef QUEUEP
#define QUEUEP

#include<memory>
class QueueP
{

public:

	void push(const int& element);
	void pop();
	const int& top() const;
	bool isEmpty() const;

	QueueP() = default;
	QueueP(const QueueP& t);
private:

	struct Node
	{
		std::unique_ptr<Node> next = nullptr;
		int data = 0;
		Node(const int& data);
		Node(const int& data, std::unique_ptr<Node> next);
		Node() = default;
	};

	std::unique_ptr<Node> head = nullptr;

};
#endif 