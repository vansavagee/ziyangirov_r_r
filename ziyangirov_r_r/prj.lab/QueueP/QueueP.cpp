#include <Queuep/Queuep.h>
QueueP::Node::Node(const int& data)
{
	this->data = data;
};
QueueP::Node::Node(const int& data, std::unique_ptr<Node> next)
{
	this->data = data;
	this->next = std::move(next);
};

bool QueueP::isEmpty() const
{
	return (head == nullptr);
};
void QueueP::pop()
{
	if (head != nullptr)
	{
		head = std::move(head->next);
	}
}
const int& QueueP::top() const
{
	return (head->data);
}
void QueueP::push(const int& element)
{
	if (head == nullptr)
	{
		head = std::unique_ptr<Node>(new Node(element));
	}
	else {

		if (element <= head->data)
		{
			head = std::unique_ptr<Node>(new Node(element, std::move(head)));
		}
		else
		{
			Node* ptr = head.get();
			Node* ptra = ptr;
			while (element >= ptr->data)
			{
				if ((ptr->next) != nullptr)
				{
					ptra = ptr;
					ptr = ptr->next.get();
				}
				else
				{
					ptr->next = std::unique_ptr<Node>(new Node(element));
					ptra = nullptr;
					break;
				}

			}
			if (ptra != nullptr)
			{
				std::unique_ptr<Node> t = std::unique_ptr<Node>(new Node(element, std::move(ptra->next)));
				ptra->next = std::move(t);
			}
		}
	}
}
QueueP::QueueP(const QueueP& t)
{
	Node* ptr = t.head.get();
	while (ptr != nullptr)
	{
		push(ptr->data);
		ptr = ptr->next.get();
	}

}
QueueP::~QueueP()
{
	while (head != nullptr)
	{
		head = std::move(head->next);
	}
}