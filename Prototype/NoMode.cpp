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

//订单接口
class OrderApi
{
protected:
	OrderApi() {}
public:
	virtual int GetProductNum() = 0;
	virtual void SetProductNum(int nProductNum) = 0;
	virtual std::string GetProductContents() = 0;
};

//订单类型1
class HomeOrder :public OrderApi
{
private:
	//订单数量
	int nProductNum;
	//订单编号
	int nProductId;
	//产品名字
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

//订单类型2
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

//业务
class OrderBussiness
{
public:
	//拆分订单
	void SaveOrder(OrderApi* o)
	{
		//如果订单数量>200
		while (o->GetProductNum() > 200)
		{
			OrderApi* lpNewOrder = nullptr;
			//复制订单类型1
			if (dynamic_cast<HomeOrder*>(o) != nullptr)
			{
				HomeOrder* src = dynamic_cast<HomeOrder*>(o);
				HomeOrder* dest = new HomeOrder;
				dest->SetProductNum(200);
				dest->SetCustomerName(src->GetCustomerName());
				dest->SetProductId(src->GetProductId());
				lpNewOrder = dest;
			}
			//复制订单类型2
			if (dynamic_cast<AboutOrder*>(o) != nullptr)
			{
				AboutOrder* src = dynamic_cast<AboutOrder*>(o);
				AboutOrder* dest = new AboutOrder;
				dest->SetProductNum(200);
				dest->SetCustomerName(src->GetCustomerName());
				dest->SetProductId(src->GetProductId());
				lpNewOrder = dest;
			}
			//数量减去200
			o->SetProductNum(o->GetProductNum() - 200);
			std::cout << "新订单是：" << lpNewOrder->GetProductContents() << std::endl;
		}
		std::cout << "最终订单是：" << o->GetProductContents() << std::endl;
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