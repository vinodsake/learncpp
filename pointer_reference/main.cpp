#include<iostream>
#include<string>

class car 
{
private:
	std::string name;
public:
	void setName(std::string name) {this->name = name;}
	std::string getName() {return this->name;}	
};

void Pointer(int* a, int* b, int* result)
{
	*result = *a + *b;
}

void Reference(int &a, int &b, int& result)
{
	result = a - b;
}

car* ClassObj(std::string name)
{
	car* car_t = new car();
	car_t->setName(name);
	return car_t;
}

double& Mul(double a,double b, double& result)
{
	result = a*b;
	return result;
}

int main()
{
	int a,b,result;
	double x,y, result_d;
	double& result_rf = result_d;
	a = 5; b = 3;
	car* car_t;
	Pointer(&a, &b, &result);
	std::cout << a << "+" << b << "=" << result << std::endl; 
	a = 7; b = 9;
	Reference(a,b,result);
	std::cout << a << "-" << b << "=" << result << std::endl;
	car_t = ClassObj("mustang");
	std::cout << "car name:" << car_t->getName() << std::endl;
	x=10; y=3;
	result_rf = Mul(x,y,result_d);
	std::cout << "mul=" << result_rf << std::endl;
	Mul(x,y,result_d) = 45;
	std::cout << "result_rf = " << result_rf << std::endl;
	return 0;
}
