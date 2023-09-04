#include <iostream>

class MakeOrder {
public:
	virtual void startOrder() = 0;
	virtual	void replayOrder() = 0;
	virtual	void finishOrder() = 0;

	//ģ�巽��
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
		std::cout << "Faunc���ն���\n";
	}

	void replayOrder() override {
		std::cout << "Faunc׼�����\n";
	}

	void finishOrder() override {
		std::cout << "Faunc�������\n";
	}
};

class Sinm : public MakeOrder {
public:
	void startOrder() override {
		std::cout << "Sinm���ն���\n";
	}

	void replayOrder() override {
		std::cout << "Sinm׼�����\n";
	}

	void finishOrder() override {
		std::cout << "Sinm�������\n";
	}
};

int main()
{
	MakeOrder* order = new Sinm;
	order->make();
	return 0;
}