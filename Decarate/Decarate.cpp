#include <iostream>
#include <string>
#include <sstream>

template<typename T>
std::string to_string(T t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

//饮料接口
class Bevarage
{
protected:
	std::string m_description;

public:
	virtual std::string get_description() = 0;
	virtual double get_cost() = 0;
};

//调味料包装接口
class CondimentDecorate :public Bevarage
{
protected:
	CondimentDecorate() {}
public:
	virtual std::string get_description() = 0;
};

//装饰类1：酱油
class Soy :public CondimentDecorate
{
private:
	//持有被装饰的类
	Bevarage* m_bevarage;
public:
	Soy(Bevarage* b) :m_bevarage(b)
	{
	}

	std::string get_description()
	{
		return m_bevarage->get_description() + " 酱油";
	}

	double get_cost()
	{
		return m_bevarage->get_cost() + 0.2;
	}
};

//装饰类2：牛奶
class Milk :public CondimentDecorate
{
private:
	//持有被装饰的类
	Bevarage* m_bevarage;
public:
	Milk(Bevarage* b) :m_bevarage(b)
	{
	}

	std::string get_description()
	{
		return m_bevarage->get_description() + " 牛奶";
	}

	double get_cost()
	{
		return m_bevarage->get_cost() + 1;
	}
};

class Lattee :public Bevarage
{
public:
	Lattee()
	{
		this->m_description = "拿铁";
	}

	std::string get_description()
	{
		return this->m_description;
	}

	double get_cost()
	{
		return 15;
	}
};

class ice :public Bevarage
{
public:
	ice()
	{
		this->m_description = "冰萃";
	}

	std::string get_description()
	{
		return this->m_description;
	}

	double get_cost()
	{
		return 10;
	}
};

int main()
{
	Bevarage* b = new Lattee();
	std::cout << b->get_description() << " " << b->get_cost() << std::endl;
	b = new Soy(b);
	b->get_description();
	std::cout << b->get_description() << " " << b->get_cost() << std::endl;
	system("pause");
	return 0;
}