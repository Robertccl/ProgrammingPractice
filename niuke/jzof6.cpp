#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
	if(rotateArray.size() == 0)
		return 0;
	
	
	int start=0;
	int end=rotateArray.size()-1;
	if(rotateArray[0]<rotateArray[end])
		return rotateArray[0];
	else if(rotateArray[0]=rotateArray[end])
	{
		int k=rotateArray[0];
		for(int i=0; i<rotateArray.size(); i++)
		{
			if(k>rotateArray[i])
				k=rotateArray[i];
		}
		return k;
	}
	else
	{
		int index=(start+end)/2;
		while(start+1 != end)
		{
			if(rotateArray[index] >= rotateArray[start])
				start=index;
			else
			{
				end=index;
			}
		}
		return rotateArray[start]>rotateArray[end]?rotateArray[end]:rotateArray[start];
	}
	
	




	
        
}

int main()
{
	//int a[] = {6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335}; 
	int a[]={3,4,5,1,2};
	vector<int> v;
	
	for(int i=0; i<5; i++)
	{
		v.push_back(a[i]);
	}
	
	cout<<minNumberInRotateArray(v);
	
	
	return 0;
}
