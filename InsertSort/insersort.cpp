#include <iostream>

using namespace std;

class InsertSort
{
public:
	InsertSort(){}
	void Input()
	{
		cout<<"Input the number of sequence:";
		cin>>m_iNum;
		m_ipSeq = new int[m_iNum];
		cout<<"Input the elements of the sequence:";
		for(int i=0;i<m_iNum;i++)
		{
			cin>>m_ipSeq[i];
		}
	}
	void Sort()
	{
		int temp;
		for(int i=1;i<m_iNum;i++)
		{
			temp=m_ipSeq[i];
			int j;
			for(j=i-1;j>=0;j--)
			{
				if(m_ipSeq[j]<temp)
				{
					break;
				}
				m_ipSeq[j+1]=m_ipSeq[j];
			}
			m_ipSeq[j+1]=temp;
		}
	}
	void print()
	{
		cout<<"The sequence after insert sort is :";
		for(int i=0;i<m_iNum;i++)
		{
			cout<<m_ipSeq[i]<<" ";
		}
		cout<<endl;
	}
private:
	int* m_ipSeq;
	int m_iNum;
};

int main()
{
	InsertSort inso;
	inso.Input();
	inso.Sort();
	inso.print();
	return 0;
}