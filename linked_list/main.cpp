#include "linkedlist.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList(std::string name)
{
	this->Name = name;
	this->LinkType = LinkedList<T>::type::Single;
	this->Link_ = NULL;
	SingleLinkedList::ResetLinkedList();
}	

template <typename T>
void SingleLinkedList<T>::Insert(int pos, T value)
{	
	SingleLink<T>* CurPos = Start;
	SingleLink<T>* PrePos = CurPos;
	this->Link_ = new SingleLink<T>();
	Link_->Value = value;
	int cur_pos = pos; 
	if(pos == 0)
	{
		Link_->NxtPtr = CurPos;
		Start = Link_;
		return;
	}

	if(Start == NULL && pos != 0)
	{
		std::cout << "Err: cannot insert @" << pos << " as " 
			<< this->Name << "is empty" << std::endl;
		return;
	}
	while(cur_pos)
	{
		if(CurPos->NxtPtr != NULL)
		{
			PrePos = CurPos;
			CurPos = CurPos->NxtPtr;	
			cur_pos--;
			continue;
		}
		break;
	}
	if(cur_pos != 0)
	{
		std::cout << "Err: Trying to insert @" << pos 
			<< " but the size of Linked List is smaller" << std::endl;
	       return;	
	}
	else
	{
		Link_->NxtPtr = CurPos;
		PrePos->NxtPtr = Link_;
	}
}

template <typename T>
void SingleLinkedList<T>::StartInsert(T value)
{	
	SingleLink<T>* CurPos = Start;
	this->Link_ = new SingleLink<T>();
	Link_->Value = value;
	if(CurPos == NULL)
	{
		Start = Link_;
	}

	else
	{
		Link_->NxtPtr = CurPos;
		Start = Link_;
	}
}

template <typename T>
void SingleLinkedList<T>::EndInsert(T value)
{	
	SingleLink<T>* CurPos = Start;
	SingleLink<T>* PrePos;
	this->Link_ = new SingleLink<T>();
	Link_->Value = value;
	if(CurPos == NULL)
		Start = CurPos;
	else
	{
		while(CurPos->NxtPtr != NULL)
		{
			PrePos = CurPos;
			CurPos = CurPos->NxtPtr;
		}
		CurPos->NxtPtr = Link_;
	}
}

template <typename T>
void SingleLinkedList<T>::ReadALink(int pos)
{

}

template <typename T>
void SingleLinkedList<T>::Delete(int pos)
{

}

template <typename T>
void SingleLinkedList<T>::ResetLinkedList()
{
}


template <typename T>
void SingleLinkedList<T>::PrintLinkedList()
{
	SingleLink<T>* CurPos = Start;
	if(CurPos == NULL)
	{
		std::cout << this->Name << " List is empty" << std::endl;
		return;
	}

	do
	{
		CurPos->PrintLink();
		CurPos = CurPos->NxtPtr;
	}
	while(CurPos != NULL);

}


template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(std::string name)
{
	this->Name = name;
	this->LinkType = LinkedList<T>::type::Double;
	this->Link_ = NULL;
	DoubleLinkedList::ResetLinkedList();
}	

template <typename T>
void DoubleLinkedList<T>::Insert(int pos, T value)
{

}

template <typename T>
void DoubleLinkedList<T>::StartInsert(T value)
{	

}

template <typename T>
void DoubleLinkedList<T>::EndInsert(T value)
{	

}

template <typename T>
void DoubleLinkedList<T>::ReadALink(int pos)
{

}

template <typename T>
void DoubleLinkedList<T>::Delete(int pos)
{

}

template <typename T>
void DoubleLinkedList<T>::ResetLinkedList()
{

}

template <typename T>
void DoubleLinkedList<T>::PrintLinkedList()
{

}

int main()
{
	SingleLink<int>* startLink = NULL;
	SingleLinkedList<int> intSingleLinkedList("intSingleLinkedList");
	intSingleLinkedList.Start = startLink; 
	for(int i=0; i<5; i++)
		intSingleLinkedList.StartInsert(i);
	for(int i=10; i<13; i++)
		intSingleLinkedList.EndInsert(i);
	intSingleLinkedList.StartInsert(0);
	intSingleLinkedList.Insert(0,111);
	intSingleLinkedList.Insert(1,222);
	intSingleLinkedList.Insert(15,555);
	intSingleLinkedList.PrintLinkedList();

	SingleLink<std::string>* stringstartLink = NULL;
	SingleLinkedList<std::string> stringSingleLinkedList("stringSingleLinkedList");
	stringSingleLinkedList.Start = stringstartLink; 
	std::string value = "VINODSAKE";
	std::string val_char;
	for(int i=0; i<5; i++)
	{
		val_char = value[i];	
		stringSingleLinkedList.StartInsert(val_char);
	}
	stringSingleLinkedList.Insert(3,"TEST");
	stringSingleLinkedList.EndInsert("END");
	stringSingleLinkedList.PrintLinkedList();

	return 0;
}
