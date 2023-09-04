#include <iostream>
#include <string>

class AbstructService
{
protected:
	AbstructService() {}

public:
	virtual void request() = 0;
};

class ServiceImpl :public AbstructService
{
public:

	void request() override
	{
		std::cout << "ServiceImpl" << std::endl;
	}
};

class ProxyService :public AbstructService
{
private:
	std::string m_name;
	std::string m_pwd;
	AbstructService* m_service;

public:

	ProxyService(std::string name, std::string pwd) :m_name(name), m_pwd(pwd)
	{
		this->m_service = new ServiceImpl;
	}

	void request() override
	{
		if ("admin" == m_name && "pwd" == m_pwd)
		{
			std::cout << "succcess" << std::endl;
			this->m_service->request();
		}
		else
		{
			std::cout << "failed\r\n";
		}
	}
};

//int main()
//{
//	AbstructService* p = new ProxyService("admin", "pwd");
//	p->request();
//	return 0;
//}