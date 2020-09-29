#include<string>
#include<iostream>
#include<vector>


class Link
{
public:
	virtual void PrintLink() = 0;

	std::string Name;
};

template <typename T>
class SingleLink : public Link
{
public:
	SingleLink() 
	{
		this->Name = "SingleLink";
		this->NxtPtr = NULL;
	}
	std::string getName() {return this->Name;}
	void PrintLink()
	{
		//void *this_address = &this;
		std::cout << "@" << (void*)this << std::endl;
		std::cout << "Value:" << this->Value << std::endl;
		std::cout << "NxtPtr:" << this->NxtPtr << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	SingleLink<T>* NxtPtr;
	T Value;
};

template <typename T>
class DoubleLink : public Link
{
public:
	DoubleLink() 
	{
		this->Name = "DoubleLink";
		this->NxtPtr = NULL;
	}
	std::string getName() {return this->Name;}
	void PrintLink()
	{
		std::cout << "PrePtr:" << this->*PrePtr << std::endl;
		std::cout << "Value:" << this->Value << std::endl;
		std::cout << "NxtPtr:" << *this->NxtPtr << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	DoubleLink<T>* PrePtr;
	T Value;
};


template <typename T>
class LinkedList
{
public:
	void setName(std::string name) {this->Name = name;}
	std::string getName() {return this->Name;}
	virtual void Insert(int pos, T value) = 0;
	
	virtual void StartInsert(T value) = 0;

	virtual void EndInsert(T value) = 0;
	
	virtual void ReadALink(int pos) = 0;
	
	virtual void Delete(int pos) = 0;

	virtual void ResetLinkedList() = 0;

	virtual void PrintLinkedList() = 0;
 
	std::string Name;
	enum type {Single,Double};
	type LinkType;

};

template <typename T>
class SingleLinkedList : public LinkedList<T>
{
public:
	SingleLinkedList(std::string);
	void Insert(int pos, T value);
	void StartInsert(T value);
	void EndInsert(T value);
	void ReadALink(int pos);
	void Delete(int pos);
	void PrintLinkedList();
	void ResetLinkedList();

	SingleLink<T>* Link_;
	SingleLink<T>* Start;
	SingleLink<T>* End;

};

template <typename T>
class DoubleLinkedList : public LinkedList<T>
{
public:
	DoubleLinkedList(std::string);	
	void Insert(int pos, T value);
	void StartInsert(T value);
	void EndInsert(T value);
	void ReadALink(int pos);
	void Delete(int pos);
	void PrintLinkedList();
	void ResetLinkedList();

	DoubleLink<T>* Link_;
	DoubleLink<T>* Start;
	DoubleLink<T>* End;
};
