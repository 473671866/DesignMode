#include <iostream>
#include<string>
#include<sstream>

template <typename T>
std::string nToStr(T value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

//�����ӿ�
class OrderApi
{
protected:
	OrderApi() {}
public:
	virtual int GetProductNum() = 0;
	virtual void SetProductNum(int nProductNum) = 0;
	virtual std::string GetProductContents() = 0;
};

//��������1
class HomeOrder :public OrderApi
{
private:
	//��������
	int nProductNum;
	//�������
	int nProductId;
	//��Ʒ����
	std::string csCustomerName;

public:

	int GetProductNum()
	{
		return this->nProductNum;
	}

	int GetProductId()
	{
		return this->nProductId;
	}

	std::string GetCustomerName()
	{
		return this->csCustomerName;
	}

	void SetProductNum(int nProductNum)
	{
		this->nProductNum = nProductNum;
	}

	void SetProductId(int nProductId)
	{
		this->nProductId = nProductId;
	}

	void SetCustomerName(std::string value)
	{
		this->csCustomerName = value;
	}

	std::string GetProductContents()
	{
		return "Customter: " + this->csCustomerName + " ProductID: " + nToStr(this->nProductId) + " nProductNum: " + nToStr(this->nProductNum) + "\r\n";
	}
};

//��������2
class AboutOrder :public OrderApi
{
private:
	int nProductNum;
	int nProductId;
	std::string csCustomerName;

public:
	int GetProductNum()
	{
		return this->nProductNum;
	}

	int GetProductId()
	{
		return this->nProductId;
	}

	std::string GetCustomerName()
	{
		return this->csCustomerName;
	}

	void SetProductId(int nProductId)
	{
		this->nProductId = nProductId;
	}

	void SetProductNum(int nProductNum)
	{
		this->nProductNum = nProductNum;
	}

	void SetCustomerName(std::string value)
	{
		this->csCustomerName = value;
	}

	std::string GetProductContents()
	{
		return "Customter: " + this->csCustomerName + " ProductID: " + nToStr(this->nProductId) + " nProductNum: " + nToStr(this->nProductNum) + "\r\n";
	}
};

//ҵ��
class OrderBussiness
{
public:
	//��ֶ���
	void SaveOrder(OrderApi* o)
	{
		//�����������>200
		while (o->GetProductNum() > 200)
		{
			OrderApi* lpNewOrder = nullptr;
			//���ƶ�������1
			if (dynamic_cast<HomeOrder*>(o) != nullptr)
			{
				HomeOrder* src = dynamic_cast<HomeOrder*>(o);
				HomeOrder* dest = new HomeOrder;
				dest->SetProductNum(200);
				dest->SetCustomerName(src->GetCustomerName());
				dest->SetProductId(src->GetProductId());
				lpNewOrder = dest;
			}
			//���ƶ�������2
			if (dynamic_cast<AboutOrder*>(o) != nullptr)
			{
				AboutOrder* src = dynamic_cast<AboutOrder*>(o);
				AboutOrder* dest = new AboutOrder;
				dest->SetProductNum(200);
				dest->SetCustomerName(src->GetCustomerName());
				dest->SetProductId(src->GetProductId());
				lpNewOrder = dest;
			}
			//������ȥ200
			o->SetProductNum(o->GetProductNum() - 200);
			std::cout << "�¶����ǣ�" << lpNewOrder->GetProductContents() << std::endl;
		}
		std::cout << "���ն����ǣ�" << o->GetProductContents() << std::endl;
	}
};

//int main()
//{
//	HomeOrder* home = new HomeOrder;
//	home->SetCustomerName("aaaa");
//	home->SetProductId('home');
//	home->SetProductNum(512);
//	OrderBussiness* ob = new OrderBussiness;
//	ob->SaveOrder(home);
//	return 0;
//}