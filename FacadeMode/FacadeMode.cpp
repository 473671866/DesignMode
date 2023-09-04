#include <iostream>

class Cramera
{
public:
	void on()
	{
		std::cout << "相机启动\r\n";
	}
	void off()
	{
		std::cout << "相机关闭\r\n";
	}
};

class Light
{
public:
	void light_on()
	{
		std::cout << "闪光灯启动\r\n";
	}

	void light_off()
	{
		std::cout << "闪光灯关闭\r\n";
	}
};

class Senor
{
public:
	void senor_on()
	{
		std::cout << "传感器启动\r\n";
	}
	void senor_off()
	{
		std::cout << "传感器关闭\r\n";
	}
};

class Facade
{
private:
	Cramera c;
	Light l;
	Senor s;
public:

	void on()
	{
		this->c.on();
		this->l.light_on();
		this->s.senor_on();
	}

	void off()
	{
		this->c.off();
		this->l.light_off();
		this->s.senor_off();
	}
};

int main()
{
	Facade facade;
	facade.on();

	std::cout << "off\r\n";

	facade.off();

	return 0;
}