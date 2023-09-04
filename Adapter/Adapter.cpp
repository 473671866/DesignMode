#include <iostream>

class Three
{
public:
	void plugin()
	{
		std::cout << "三项接口" << std::endl;
		return;
	}
};

class ObjectAdapter :public Three
{
private:
	Three* a;
public:
	ObjectAdapter(Three* AA) :a(AA) {}
	~ObjectAdapter() { delete a; }

	void adpater()
	{
		std::cout << "适配三项接口" << std::endl;
		a->plugin();
	}
};

int main()
{
	ObjectAdapter* adpater = new ObjectAdapter(new Three);
	adpater->adpater();
	delete adpater;
	return 0;
}