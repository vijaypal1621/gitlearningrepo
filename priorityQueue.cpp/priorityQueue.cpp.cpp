#include<iostream>
#include<vector>
using namespace std;

class priorityqueue
{
	vector<int> pq;
public:

	priorityqueue()
	{

	}
	void insert(int data)
	{
		pq.push_back(data);

		// up heapify
		int ci = pq.size() - 1;
		int pi = (ci - 1) / 2;
		while (ci > 0)
		{
			if (pq[pi] > pq[ci])
			{
				swap(pq[pi], pq[ci]);
				ci = pi;
			}
			else
				break;

			pi = (ci - 1) / 2;

		}



	}


};



