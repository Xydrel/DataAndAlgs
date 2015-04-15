#include "LinkList.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"


// forward declarations
void TestOrderedArray();
void TestUnorderedArray();
void testUnorderdSort(UnorderedArray<int> unArr);

int main(void)
{
	// setting the main function up
	
	//TestOrderedArray();
	TestUnorderedArray();

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