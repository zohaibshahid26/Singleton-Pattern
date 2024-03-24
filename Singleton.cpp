#include <iostream>
using namespace std;
class Singleton
{

	int data;
	Singleton()
	{
		data = 0;
		cout << "Constructor called" << endl;
	}

	Singleton(const Singleton& rhs)
	{
		this->data = rhs.data;
		cout << "Copy constructor called" << endl;
	}
	Singleton& operator=(const Singleton& rhis)
	{
		this->data = rhis.data;
		cout << "Assignment operator called" << endl;
		return *this;
	}

	~Singleton()
	{
		cout << "Destructor called" << endl;
	}
public:
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}
	void setData(int data)
	{
		this->data = data;
	}
	int getData()
	{
		return data;
	}
};
int main()
{
	Singleton& s = Singleton::getInstance();
	s.setData(100);
	Singleton* s2 = &Singleton::getInstance(); //Will point to the same single instance
	cout << s2->getData() << endl; //Will print 100
	Singleton* s3 = &s;  //Will point to the same single instance
	cout << s3->getData() << endl; //Will print 100

	return 0;
}
