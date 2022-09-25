#include <Queuep/Queuep.h>
#include <iostream>
int main()
{
	QueueP rrr;
	std::cout << "вывод очереди 1 с элементами -1,0,1,2" << std::endl;
	for (int i = -1; i < 3; i++)
	{
		rrr.push(i);
		std::cout << rrr.top() << std::endl;
	}
	std::cout << "проверка функции pop() на очереди 1" << std::endl;
	rrr.pop();
	std::cout << rrr.top() << std::endl;
	QueueP RRR = rrr;
	std::cout << "вывод новой очереди, равной очереди 1" << std::endl;
	while (!RRR.isEmpty())
	{
		std::cout << RRR.top() << std::endl;
		RRR.pop();		
	}
	return 0;
}