/*1. ����������� ������ ������ ����������� (����������������) ������ (LinkedList<X>),
�������� �������� ������������� ����. ����� ������ ���������:
	* ������������� ������;					+
	* ���������� �������� � ������ ������;  +
	* ���������� �������� � ����� ������;   +
	* ����� ���� ��������� ������.			+

a)  * �������� ���� ��������� ������;				+
	* ����������� ���������� ��������� ������;		+
	* �������� ������ �� �������;					+
	* �������� ������� ��������;				    +
	* �������� ���������� ��������.                 + */


#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include <Windows.h>
#include <string>
#include <sstream>
#pragma once


using namespace std;


//������ ������ "���� ������������ ������"
template<class Data>

class Node{

	Data value; //������, �������� � ����
	Node* next; //����� ���������� ����

public:

	Node(Data v): value(v){} //�����������
	Data Value(){return value;} //������ � ������
	Node*& Next(){return next;} //������ � ������ ���������� ����
};

//������ ������ "����������� ������"
template<class Type>
class List1
{
	Node<Type> *begin; //����� ������� ���� ������
	Node<Type> *end; //����� ���������� ���� ������
	int size; //���������� ����� � ������

public:
	List1(): begin(0),end(0),size(0){} //�����������
	~List1(); //����������
	void Insert_begin(Type); //���������� �������� � ������ ������
	void Insert_end(Type); //���������� �������� � ����� ������
	void Delete_begin(); //�������� �������� �� ������ ������
	void Delete_end(); // �������� �������� � ����� ������
	void Display(); //����� ������ 
	void Clear_list(); //�������� ���� ��������� �� ������
	bool IsEmpty(); //�������� �� �������
	int Count(); // ���������� ���������
	
};

//������� ����������� �������� ������� ������� ������ List1

//���������� �������� � ������ ������

template<class Type>
void List1<Type>::Insert_begin(Type v)
{ Node<Type> *p=new Node<Type>(v);
if(!begin)
{
	begin=end=p;
	p->Next()=0;
}
else
	{p->Next()=begin;
	begin=p;
}
	size++;
}

//���������� �������� � ����� ������
template<class Type>
void List1<Type>::Insert_end(Type v)
{
	Node<Type> *p=new Node<Type>(v);
	if(!begin)
	{
		begin=end=p;
	}
	else
	{
		end->Next()=p;
		end=p;
	}
	p->Next()=0;
	size++;
}

//�������� �������� �� ������ ������
template<class Type>
void List1<Type>::Delete_begin()
{
	Node<Type>* p;
	if(begin)
{
	p=begin;
	begin=p->Next();
	size--;
	delete p;
}
}

//�������� �������� � ����� ������
template<class Type>
void List1<Type>::Delete_end()
{
	Node<Type> *p =  begin;
	if (end){
		while(p->Next()->Next()!= 0)
 {
	 p=p->Next();
 }
delete p->Next();
p->Next()=0;
size--;
	}
}


//����� ������
template<class Type>
void List1<Type>::Display()
{
	Node<Type> *p = begin;
	
	if (p==0) cout<<"\n\n\t������ ����";
	while(p != 0)
	{
		cout << p->Value()<<" ";
		p = p->Next();
	}
	cout<<"\n";
}

//�������� ���� ��������� �� ������
template<class Type>
void List1<Type>::Clear_list()
{
	Node<Type> *p,*p1;
	if(begin)
	{
		p=begin;
		while(p)
		{
			p1=p->Next();
			delete p;
			p=p1;
		}
	begin=end=0;
	size=0;
	}
}

//����������
template<class Type>
List1<Type>::~List1(){this->Clear_list();}

//�������� �� �������
template <class Type>
bool List1 <Type>::IsEmpty()
{
	if (size == 0) 
	{
		cout << "������ ����";
			return false;
	}
	else 
	{ 
		cout << "���������� ���������: " << size << endl;
		return true;
	}
}

//���������� ���������	
template <class Type>
int List1 <Type>::Count()
{
	cout  << size;
	return size;
}



//_______________________________________________________



template < typename T >
void ChangeMenu(List1 <T> L)
{
	T S;
	int number; 
	while(1)
	{ 
		system("cls");
		cout<<"\n\t 2. ���������� �������� � ������ ������";
		cout<<"\n\t 3. ���������� �������� � ����� ������  ";
		cout<<"\n\t 4. ����� ���� ��������� ������  ";
		cout<<"\n\t 5. �������� ���� ��������� ������  ";
		cout<<"\n\t 6. ����������� ���������� ��������� ������  ";
		cout<<"\n\t 7. �������� ������ �� �������  ";
		cout<<"\n\t 8. �������� ������� ��������  ";
		cout<<"\n\t 9. �������� ���������� ��������  ";
		cout<<"\n\t 10. �����  ";
		cout<<"\n\t ������� ����� ����: ";
		cin>>number;

switch(number)

{

case 2: cout<<"������� �������:";
cin>>S;
L.Insert_begin(S);
cout<<"\n\n\t\t������� �������� � ������ ������\n";
system("pause");
break;

case 3: cout<<"������� �������:";
cin>>S;
L.Insert_end(S);
cout<<"\n\n\t\t������� ������� � ����� ������\n";
system("pause");
break;

case 4: cout<<"\n\n\t\t������: ";
L.Display(); 
system("pause");
break;

case 5: L.Clear_list();
cout<<"\n\n\t\t��� �������� ������ �������\n";
system("pause");
break;

case 6: L.Count();
	system("pause");
	break;

case 7: L.IsEmpty();
	system("pause");
	break;

case 8: L.Delete_begin();
	system("pause");
	break;

case 9: L.Delete_end();
	system("pause");
	break;

case 10: exit(1);

default: break; } }

system("pause");

}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List1 <int> LInt;
	List1 <string> LStr;

	int it = -1;
	
	while (it != 0)
	{
		it = -1;
		cout << "�������� ��� ������" << endl;
		cout << "1 - ����� �����" << endl;
		cout << "2 - ������" << endl;
		cout << "0 - �����" << endl;

		while ((it < 0) || (it > 5))
			cin >> it;

		switch (it)
		{
			case 1:
				ChangeMenu(LInt);
				break;
			case 2:
				ChangeMenu(LStr);
				break;
			case 0:
				exit(1); 
				break;
			default: 
				cout << "����������� ���� " << endl;
				break;
		}
		getchar();
	}

}
