#include <iostream>
#include <string>
#include <math.h>
 
using namespace std;

class GrayCode
{
public:
	GrayCode(){}
	~GrayCode(){delete []m_spGrayCode;}
	void SetOrder()
	{
		cout<<"Input the order of the graycode :";
		cin>>m_iOrder;
		m_iGrayNum=(int)pow(2.,m_iOrder);
	}
	void CreatGray()
	{
		m_spGrayCode = ReCreatGray(m_iOrder);
	}
	
	void Print()
	{
		cout<<"The GrayCode is :"<<endl;
		for(int i=0;i<m_iGrayNum;i++)
		{
			cout<<m_spGrayCode[i]<<endl;
		}
	}

private:
	string * ReCreatGray(int order)
	{
		int num = (int)pow(2.,order);
		string * gray = new string[num];
		if(order==1)
		{
			gray[0]="0";
			gray[1]="1";
			return gray;
		}
		string *temp = ReCreatGray(order-1);
		for(int i=0;i<num/2;i++)
		{
			gray[i] = "0" + temp[i];
			gray[num-1-i] = "1" + temp[i];
		}
		delete []temp;
		return gray;
	}

	string * m_spGrayCode;
	int m_iGrayNum;
	int m_iOrder;
};

int main()
{
	GrayCode grayCode;
	grayCode.SetOrder();
	grayCode.CreatGray();
	grayCode.Print();
	return 0;
}