#include "LinkList.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"


// forward declarations
void TestOrderedArray();
void TestUnorderedArray();
void testUnorderdSort(UnorderedArray<int> unArr);
void TestLinkedList();
void TestLinkedListFrontFunctionality(LinkList<int>* lList);
void TestingMoreDoubLinkedListFunctionality();
void TestOverloadedLLPushMethod();
void TestStackContainerFunctionality();

int main(void)
{
	// setting the main function up
	
	//TestOrderedArray();	// broken
	//TestUnorderedArray(); // broken
	TestLinkedList();
	TestOverloadedLLPushMethod();
	TestStackContainerFunctionality();

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

void TestingMoreDoubLinkedListFunctionality()
{
	LinkList<int> dlList;

	dlList.push( 101 );
	dlList.push_front( 201 );
	dlList.push( 301 );
	dlList.push_front( 401 );
	dlList.push( 501 );

	dlList.pop();
	dlList.push( 601 );
	dlList.pop_front();

	std::cout << "Contents of the list forward: " << std::endl;
	for ( auto iter = dlList.Begin(); iter != dlList.End(); iter++ )
	{
		//std::cout << " " << *iter;
	}

	std::cout << "Contents of the list reverse: " << std::endl;
	for ( auto iter2 = dlList.End(); iter2 != NULL; iter2-- )
	{
		//std::cout << " " << *iter2;
	}
}

void TestOverloadedLLPushMethod()
{
	std::cout << "Testing overloaded push" << std::endl;
	std::cout << "Chapter 6" << std::endl;
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

	lList.push(10001, 5);

	std::cout << "Contents of the Linked List" << std::endl;
	LinkIterator<int> it;
	for (it = lList.Begin(); it != lList.End(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void TestStackContainerFunctionality()
{
	std::cout << "Testing Stack Types" << std::endl;
	std::cout << "Chapter 6" << std::endl;
	std::cout << std::endl;

	std::cout << "AStack Testing" << std::endl;
	const char* msg;
	AStack<int> aStack(8);

	msg = (aStack.isEmpty()) ? "true" : "false";
	std::cout << "isEmpty(): " << msg << std::endl;

	aStack.Push(101);
	std::cout << aStack.Top() << std::endl;
	aStack.Push(102);
	std::cout << aStack.Top() << std::endl;
	aStack.Push(103);
	std::cout << aStack.Top() << std::endl;
	aStack.Push(104);
	std::cout << aStack.Top() << std::endl;

	aStack.Pop();
	std::cout << aStack.Top() << std::endl;

	aStack.Push(105);
	std::cout << aStack.Top() << std::endl;

	msg = (aStack.isEmpty()) ? "true" : "false";
	std::cout << "isEmpty(): " << msg << std::endl;


	std::cout << "LLStack Testing" << std::endl;
	const char* smsg;
	LLStack<int> llStack;	

	msg = (aStack.isEmpty()) ? "true" : "false";
	std::cout << "isEmpty(): " << smsg << std::endl;

	// Top() causing build error
	llStack.Push(101);
	//std::cout << llStack.Top() << std::endl;
	llStack.Push(102);
	//std::cout << llStack.Top() << std::endl;
	llStack.Push(103);
	//std::cout << llStack.Top() << std::endl;
	llStack.Push(104);
	//std::cout << llStack.Top() << std::endl;

	llStack.Pop();
	//std::cout << llStack.Top() << std::endl;

	llStack.Push(105);
	//std::cout << llStack.Top() << std::endl;

	msg = (llStack.isEmpty()) ? "true" : "false";
	std::cout << "isEmpty(): " << smsg << std::endl;
}
