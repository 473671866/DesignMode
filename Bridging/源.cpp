#include <iostream>

class IOS {
public:
	virtual void run() = 0;
};

class CWindows : public IOS {
public:
	virtual void run() {
		std::cout << "windows\n";
	}
};

class CLinux : public IOS {
public:
	virtual void run() {
		std::cout << "linux\n";
	}
};

class CMac : public IOS {
public:
	virtual void run() {
		std::cout << "mac\n";
	}
};

class Computer {
public:
	virtual void install(IOS* i) = 0;
};

class CLenovo : public Computer {
public:
	virtual void install(IOS* i) {
		std::cout << "Lenovo\n";
		i->run();
	}
};

class CAsus :public Computer {
public:
	virtual void install(IOS* i) {
		std::cout << "asus\n";
		i->run();
	}
};

int main() {
	CLenovo* l = new CLenovo;
	l->install(new CLinux);
	system("pause");
	return 0;
}