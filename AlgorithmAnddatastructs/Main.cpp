#include "LinkList.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "HashTable.h"


// forward declarations
void TestOrderedArray();
void TestUnorderedArray();
void testUnorderdSort(UnorderedArray<int> unArr);
void TestUnorderedSelectionSort(UnorderedArray<int> unArr);
void TestLinkedList();
void TestLinkedListFrontFunctionality(DoublyLinkList<int>* lList);
void TestingMoreDoubLinkedListFunctionality();
void TestOverloadedLLPushMethod();
void TestStackContainerFunctionality();
void TestPrioQueue();

int main(void)
{
	std::string testType = "";
	printf("Which test would you care to run? \n");
	bool runMenu = true;
	while (runMenu)
	{
		printf("\nPlease select an option from the list: \n");
		printf("Test Options: \norderedarr\nunorderedarr\nlinkedlist\nstacktest\nprioqueue\nend\n");
		std::cin >> testType;

		// Should this menu stop once an option has been selected?
		if		(testType == "orderedarr")		{ TestOrderedArray(); }
		else if (testType == "unorderedarr")	{ TestUnorderedArray(); }
		else if (testType == "linkedlist")		{ TestLinkedList(); }
		else if (testType == "stacktest")		{ TestStackContainerFunctionality(); }
		else if (testType == "prioqueue")		{ TestPrioQueue(); }
		else if (testType == "e" || testType == "q" || testType == "quit" || testType == "end") { runMenu = false; }
		else {} // perform no-op and loop through again
	}

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

	if (unArr.capacity() != 0)	
	{ 
		testUnorderdSort(unArr); 
	}

	unArr.clear();

	UnorderedArray<int> unArr2(10, 6);
	unArr2.push(66);
	unArr2.push(33);
	unArr2.push(59);
	unArr2.push(80);
	unArr2.push(60);
	unArr2.push(91);

	if (unArr2.capacity() != 0) 
	{ 
		TestUnorderedSelectionSort(unArr2); 
	}

	unArr.clear();
}	// leaving this function causes an assert? why?

void testUnorderdSort(UnorderedArray<int> unArr )
{
	// there is an assert happening within this function

	std::cout << "\nBefore the sort";

	for (int i = 0; i <= unArr.capacity() - 1; i++)
	{
		std::cout << " " << unArr[i];
	}

	unArr.bubbleSort();

	std::cout << "\nAfter the sort";

	for (int i = 0; i <= unArr.capacity() - 1 ; i++)
	{
		std::cout << " " << unArr[i];
	}
}

void TestUnorderedSelectionSort(UnorderedArray<int> unArr)
{
	std::cout << "\nBefore the sort";

	for (int i = 0; i <= unArr.capacity() - 1; i++)
	{
		std::cout << " " << unArr[i];
	}

	unArr.SelectionSort();

	std::cout << "\nAfter the sort";

	for (int i = 0; i <= unArr.capacity() - 1; i++)
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

	// Implement this test with a initialized dllist
	// perhaps below this function would be appropriate
	//TestLinkedListFrontFunctionality(&lList);

	std::cout << "\nTesting push_front on linked list" << std::endl;
	LinkIterator<int> it2;
	for (it2 = lList.Begin(); it2 != lList.End(); it2++)
	{
		std::cout << *it2 << std::endl;
	}

	std::cout << "\nEnd Linked List Test" << std::endl;
}

void TestLinkedListFrontFunctionality(DoublyLinkList<int>* dlList)
{
	dlList->push_front(1001);
	dlList->push_front(1002);
}

void TestingMoreDoubLinkedListFunctionality()
{
	DoublyLinkList<int> dlList;

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

	smsg = (aStack.isEmpty()) ? "true" : "false";
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

int* GetNewId(int& id)
{
	++id;
	return &id;
}

void TestPrioQueue()
{
	typedef less_cmp<NetMessage> CMP;
	PriorityQueue<NetMessage, CMP> pQueue;
	int id = -1;

	NetMessage nmsg0(100, *GetNewId(id));
	pQueue.Push(nmsg0);
	NetMessage nmsg1(101, *GetNewId(id));
	pQueue.Push(nmsg1);
	NetMessage nmsg2(200, *GetNewId(id));
	pQueue.Push(nmsg2);
	NetMessage nmsg3(201, *GetNewId(id));
	pQueue.Push(nmsg3);
	NetMessage nmsg4(300, *GetNewId(id));
	pQueue.Push(nmsg4);
	NetMessage nmsg5(102, *GetNewId(id));
	pQueue.Push(nmsg5);


	// correct value not being assigned here
	// step in here and follow the code path
	// something causing size to be 17?
	int queueSize = printf("prio queue size: ", pQueue.GetSize());

	// loop on and print the values in the pQueue
	
	
}
