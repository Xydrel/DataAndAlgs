#include "LinkList.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"


// forward declarations
void TestOrderedArray();
void TestUnorderedArray();
void testUnorderdSort(UnorderedArray<int> unArr);
void TestLinkedList();
void TestLinkedListFrontFunctionality(LinkList<int>* lList);

int main(void)
{
	// setting the main function up
	
	//TestOrderedArray();	// broken
	//TestUnorderedArray(); // broken
	TestLinkedList();

	system("PAUSE");
	return 0;
}

void TestOrderedArray()
{
	// The int s are not being added correctly
	int testVal = 100;
	OrderedArray<int> arr(5, 5);
	arr.push(5);
	arr.push(2);
	arr.push(7);
}

void TestUnorderedArray()
{
	UnorderedArray<int> unArr(10, 5);
	unArr.push(6);
	unArr.push(3);
	unArr.push(5);
	unArr.push(8);
	unArr.push(9);

	testUnorderdSort(unArr);
}

void testUnorderdSort(UnorderedArray<int> unArr )
{
	// there is an assert happening within this function

	std::cout << "Before the sort";

	for (int i = 0; i <= unArr.capacity(); i++)
	{
		std::cout << " " << unArr[i];
	}

	unArr.bubbleSort();

	std::cout << "After the sort";

	for (int i = 0; i <= unArr.capacity(); i++)
	{
		std::cout << " " << unArr[i];
	}
}

void TestLinkedList()
{
	std::cout << "Testing a Linked List" << std::endl;
	std::cout << "Chapter 5" << std::endl;
	std::cout << std::endl;

	LinkList<int> lList;
	lList.push(101);
	lList.push(201);
	lList.push(301);
	lList.push(401);
	lList.push(501);
	lList.push(601);

	lList.pop();

	lList.push(701);
	lList.push(801);
	lList.push(901);

	lList.pop();

	std::cout << "Contents of the Linked List" << std::endl;
	LinkIterator<int> it;
	for (it = lList.Begin(); it != lList.End(); it++)
	{
		std::cout << *it << std::endl;
	}

	TestLinkedListFrontFunctionality(&lList);

	std::cout << "\nTesting push_front on linked list" << std::endl;
	LinkIterator<int> it2;
	for (it2 = lList.Begin(); it2 != lList.End(); it2++)
	{
		std::cout << *it2 << std::endl;
	}

	std::cout << "\nEnd Linked List Test" << std::endl;
}

void TestLinkedListFrontFunctionality(LinkList<int>* lList)
{
	lList->push_front(1001);
	lList->push_front(1002);
}
