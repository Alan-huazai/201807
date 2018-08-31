 ///
 /// @file    circle_reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 23:21:58
 ///
 
#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
class Child;
class Parent
{
public:
	Parent()
	{
		cout<<"Parent()"<<endl;
	}
	~Parent()
	{
		cout<<"~Parent()"<<endl;
	}
	shared_ptr<Child> _pChild;
};
class Child
{
public:
	Child()
	{
		cout<<"Child()"<<endl;
	}
	~Child()
	{
		cout<<"~Child()"<<endl;
	}
	shared_ptr<Parent> _pParent;
};

int main(void)
{
	shared_ptr<Parent> parent(new Parent);
	shared_ptr<Child> child(new Child);
	cout<<"sizeof(shared_ptr)="<<sizeof(parent)<<endl;
	cout<<"parent's use_count="<<parent.use_count()<<endl;
	cout<<"child's use_count="<<child.use_count()<<endl;

	parent->_pChild=child;
	child->_pParent=parent;
	cout<<"parent's use_count="<<parent.use_count()<<endl;
	cout<<"child's use_count="<<child.use_count()<<endl;
	return 0;
}

