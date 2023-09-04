#include <iostream>

class FlyBehavior {
public:
	virtual void fly() = 0;

protected:
	FlyBehavior() {}
};

class FlyWithRocket : public FlyBehavior {
public:
	void fly() {
		std::cout << "»ð¼ý\n";
	}
};

class FlyWithWings : public FlyBehavior {
public:
	void fly() override {
		std::cout << "³á°ò\n";
	}
};

class Duck {
public:
	Duck(FlyBehavior* fb) {
		this->m_fb = fb;
	}
	void display() {
		this->performFly();
	}

	void performFly() {
		this->m_fb->fly();
	}

protected:
	FlyBehavior* m_fb;
};

int main() {
	Duck* duck = new Duck(new FlyWithRocket);
	duck->display();

	duck = new Duck(new FlyWithWings);
	duck->display();
	return 0;
}