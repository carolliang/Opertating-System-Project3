#include <iostream>
#include "memory_manager.h"
using namespace std;

void test(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA, unsigned long long start, unsigned long long end, unsigned long long diff){
	memory_manager vmi(p, pS, nF, vA);	

	for (unsigned long long i = start; i <= end;i =i +diff){
		if (i == 10)
		{
			diff = 0 - diff;
		}
		cout << "Physical Address at " << i << "is " << vmi.memoryAccess(i) << endl;;
		cout <<"Number of swaps at " << i << "is " <<vmi.numberPageSwaps()<<endl;
		cout << endl << endl;
	}
	vmi.frames.clear();
	vmi.counter = 0;
	vmi.counter = 0;
	vmi.mymap.clear();

}


int main()
{
	ReplacementPolicy p = FIFO;
	//memory_manager vmi(p, 2, 2, 4);
	//test(FIFO, 1, 2, 20, 1,5,1);//policy, N,nFrame, vas, start, end, increase by
	test(LRU, 2, 2, 20, 1,20, 3);

	system("pause");
}