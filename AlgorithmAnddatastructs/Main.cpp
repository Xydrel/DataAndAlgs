#include "LinkList.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"

// forward declarations
void TestOrderedArray();
void TestUnorderedArray();

int main(void)
{
	// setting the main function up
	
	//TestOrderedArray();
	TestUnorderedArray();

	return 0;
}

void TestOrderedArray()
{
	// The ints are not being added correctly
	int testVal = 100;
	OrderedArray<int> arr(5, 5);
	arr.push(5);
	arr.push(2);
	arr.push(7);
}

void TestUnorderedArray()
{
	UnorderedArray<int> unArr(5, 5);
	unArr.push(6);
	unArr.push(3);
	unArr.push(5);
	unArr.push(8);
	unArr.push(9);
}