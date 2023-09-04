#include <iostream>

class MakeOrder {
public:
	virtual void startOrder() = 0;
	virtual	void replayOrder() = 0;
	virtual	void finishOrder() = 0;

	//模板方法
	void make() {
		startOrder();
		replayOrder();
		finishOrder();
	}

protected:
	MakeOrder() {}
};

class Faunc : public MakeOrder {
public:
	void startOrder() override {
		std::cout << "Faunc接收订单\n";
	}

	void replayOrder() override {
		std::cout << "Faunc准备完成\n";
	}

	void finishOrder() override {
		std::cout << "Faunc订单完成\n";
	}
};

class Sinm : public MakeOrder {
public:
	void startOrder() override {
		std::cout << "Sinm接收订单\n";
	}

	void replayOrder() override {
		std::cout << "Sinm准备完成\n";
	}

	void finishOrder() override {
		std::cout << "Sinm订单完成\n";
	}
};

int main()
{
	MakeOrder* order = new Sinm;
	order->make();
	return 0;
}