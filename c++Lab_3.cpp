/*1. Реализовать шаблон класса односвязный (однонаправленный) список (LinkedList<X>),
хранящий элементы произвольного типа. Класс должен содержать:
	* Инициализация списка;					+
	* Добавление элемента в начало списка;  +
	* Добавление элемента в конец списка;   +
	* Показ всех элементов списка.			+

a)  * Удаление всех элементов списка;				+
	* Определение количества элементов списка;		+
	* Проверка списка на пустоту;					+
	* Удаление первого элемента;				    +
	* Удаление последнего элемента.                 + */


#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include <Windows.h>
#include <string>
#include <sstream>
#pragma once


using namespace std;


//Шаблон класса "Узел односвязного списка"
template<class Data>

class Node{

	Data value; //Данные, хранимые в узле
	Node* next; //Адрес следующего узла

public:

	Node(Data v): value(v){} //Конструктор
	Data Value(){return value;} //Доступ к данным
	Node*& Next(){return next;} //Доступ к адресу следующего узла
};

//Шаблон класса "Односвязный список"
template<class Type>
class List1
{
	Node<Type> *begin; //Адрес первого узла списка
	Node<Type> *end; //Адрес последнего узла списка
	int size; //Количество узлов в списке

public:
	List1(): begin(0),end(0),size(0){} //Конструктор
	~List1(); //Деструктор
	void Insert_begin(Type); //Добавление элемента в начало списка
	void Insert_end(Type); //Добавление элемента в конец списка
	void Delete_begin(); //Удаление элемента из начала списка
	void Delete_end(); // Удаление элемента в конце списка
	void Display(); //Вывод списка 
	void Clear_list(); //Удаление всех элементов из списка
	bool IsEmpty(); //Проверка на пустоту
	int Count(); // Количество элементов
	
};

//Внешнее определение шаблонов методов шаблона класса List1

//Добавление элемента в начало списка

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

//Добавление элемента в конец списка
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

//Удаление элемента из начала списка
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

//Удаление элемента в конце списка
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


//Вывод списка
template<class Type>
void List1<Type>::Display()
{
	Node<Type> *p = begin;
	
	if (p==0) cout<<"\n\n\tСписок пуст";
	while(p != 0)
	{
		cout << p->Value()<<" ";
		p = p->Next();
	}
	cout<<"\n";
}

//Удаление всех элементов из списка
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

//Деструктор
template<class Type>
List1<Type>::~List1(){this->Clear_list();}

//Проверка на пустоту
template <class Type>
bool List1 <Type>::IsEmpty()
{
	if (size == 0) 
	{
		cout << "Список пуст";
			return false;
	}
	else 
	{ 
		cout << "Количество элементов: " << size << endl;
		return true;
	}
}

//Количество элементов	
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
		cout<<"\n\t 2. Добавление элемента в начало списка";
		cout<<"\n\t 3. Добавление элемента в конец списка  ";
		cout<<"\n\t 4. Показ всех элементов списка  ";
		cout<<"\n\t 5. Удаление всех элементов списка  ";
		cout<<"\n\t 6. Определение количества элементов списка  ";
		cout<<"\n\t 7. Проверка списка на пустоту  ";
		cout<<"\n\t 8. Удаление первого элемента  ";
		cout<<"\n\t 9. Удаление последнего элемента  ";
		cout<<"\n\t 10. Выход  ";
		cout<<"\n\t Введите пункт меню: ";
		cin>>number;

switch(number)

{

case 2: cout<<"Введите элемент:";
cin>>S;
L.Insert_begin(S);
cout<<"\n\n\t\tЭлемент добавлен в начало списка\n";
system("pause");
break;

case 3: cout<<"Введите элемент:";
cin>>S;
L.Insert_end(S);
cout<<"\n\n\t\tЭлемент добален в конец списка\n";
system("pause");
break;

case 4: cout<<"\n\n\t\tСписок: ";
L.Display(); 
system("pause");
break;

case 5: L.Clear_list();
cout<<"\n\n\t\tВсе элементы списка удалены\n";
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
		cout << "Выберите тип списка" << endl;
		cout << "1 - Целое число" << endl;
		cout << "2 - Строка" << endl;
		cout << "0 - Выход" << endl;

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
				cout << "Некорретный ввод " << endl;
				break;
		}
		getchar();
	}

}
