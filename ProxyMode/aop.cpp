#include <iostream>
#include <memory>
#include <string>

class IHello
{
public:
	IHello() {}
	virtual ~IHello() {}
	virtual void output(const std::string s) {}
};

class Hello :public IHello
{
public:
	void output(const std::string s) override
	{
		std::cout << s << std::endl;
	}
};

template<class T>
class ProxyHello :public IHello
{
private:
	T* m_h;

public:
	ProxyHello(T* h) :m_h(h)
	{
	}

	~ProxyHello()
	{
		delete this->m_h;
		this->m_h = nullptr;
	}

	void output(const std::string s)
	{
		std::cout << "intercept" << std::endl;
		this->m_h->output(s);
		std::cout << "complete" << std::endl;
	}
};

int main()
{
	std::shared_ptr<IHello> h = std::make_shared<ProxyHello<Hello>>(new Hello());
	h->output("aop test");
	system("pause");
	return 0;
}