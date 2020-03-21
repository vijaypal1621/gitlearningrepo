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

	int removeMin()
	{
		if (pq.size() != 0)
		{
			int n = pq.size() - 1;
			int ans = pq[0];
			swap(pq[0], pq[n]);
			
			//deletion 
			pq.pop_back();
			n--; // just to use it furthur
			int pi = 0;
			int c1 = 2 * pi + 1;
			int c2 = 2 * pi + 2;
			while (c1 <= n)
			{
				if (pq[pi] > pq[c2] && pq[c2] < pq[c1] && c2 <= n)
				{
					swap(pq[pi], pq[c2]);
					pi = c2;
				}
				else if (pq[pi] > pq[c1])
				{
					swap(pq[pi], pq[c1]);
					pi = c1;
				}
				else
					break;

				c1 = 2 * pi + 1;
				c2 = 2 * pi + 2;
			}

			return ans;

		}
		else
			return -1;
	}


};



