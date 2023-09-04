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

class OrderApi
{
protected:
	OrderApi() {}
public:
	virtual int GetProductNum() = 0;
	virtual void SetProductNum(int nProductNum) = 0;
	virtual std::string GetProductContents() = 0;
	virtual OrderApi* CloneOrder() = 0;
};

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

	void SetCustomerName(std::string value)
	{
		this->csCustomerName = value;
	}

	void SetProductNum(int nProductNum)
	{
		this->nProductNum = nProductNum;
	}

	void SetProductId(int nProductId)
	{
		this->nProductId = nProductId;
	}
	std::string GetCustomerName()
	{
		return this->csCustomerName;
	}

	std::string GetProductContents()
	{
		return "Customter: " + this->csCustomerName + " ProductID: " + nToStr(this->nProductId) + " nProductNum: " + nToStr(this->nProductNum) + "\r\n";
	}

	OrderApi* CloneOrder()
	{
		HomeOrder* home = new HomeOrder;
		home->SetCustomerName(this->csCustomerName);
		home->SetProductId(this->nProductId);
		home->SetProductNum(this->nProductNum);
		return home;
	}
};

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

	void SetCustomerName(std::string value)
	{
		this->csCustomerName = value;
	}

	void SetProductNum(int nProductNum)
	{
		this->nProductNum = nProductNum;
	}

	void SetProductId(int nProductId)
	{
		this->nProductId = nProductId;
	}
	std::string GetCustomerName()
	{
		return this->csCustomerName;
	}

	std::string GetProductContents()
	{
		return "Customter: " + this->csCustomerName + " ProductID: " + nToStr(this->nProductId) + " nProductNum: " + nToStr(this->nProductNum) + "\r\n";
	}

	OrderApi* CloneOrder()
	{
		AboutOrder* about = new AboutOrder;
		about->SetCustomerName(this->csCustomerName);
		about->SetProductId(this->nProductId);
		about->SetProductNum(this->nProductNum);
		return about;
	}
};

class OrderBussiness
{
public:
	void SaveOrder(OrderApi* lpSrcOrder)
	{
		//如果订单数量>200
		while (lpSrcOrder->GetProductNum() > 200)
		{
			//复制对象
			OrderApi* lpDestOrder = lpSrcOrder->CloneOrder();
			lpDestOrder->SetProductNum(200);
			//原始订单数量-200
			lpSrcOrder->SetProductNum(lpSrcOrder->GetProductNum() - 200);
			std::cout << "新订单是：" << lpDestOrder->GetProductContents() << std::endl;
		}
		std::cout << "最终订单是：" << lpSrcOrder->GetProductContents() << std::endl;
	}
};

int main()
{
	HomeOrder* home = new HomeOrder;
	home->SetCustomerName("螺丝");
	home->SetProductId('home');
	home->SetProductNum(512);
	OrderBussiness* ob = new OrderBussiness;
	ob->SaveOrder(home);
	return 0;
}