#include <iostream>
#include <string>

class Handle {
public:
	void SetSuccessor(Handle* handle) {
		this->m_handle = handle;
	}

	virtual std::string request(double_t fee) = 0;

protected:
	Handle* m_handle;
};

class PrjManager : public Handle {
public:
	std::string request(double_t fee) {
		if (fee < 500) {
			return "项目经理同意" + std::to_string(fee);
		}
		else {
			return this->m_handle->request(fee);
		}
	}
};

class DepManager : public Handle {
public:
	std::string request(double_t fee) {
		if (fee > 500 && fee <= 1000) {
			return "部门经理同意" + std::to_string(fee);
		}
		else {
			return this->m_handle->request(fee);
		}
	}
};

class CEOManager : public Handle {
public:
	std::string request(double_t fee) {
		if (fee > 1000) {
			return "部门经理同意" + std::to_string(fee);
		}
		else {
			return "不可能事件";
		}
	}
};

int main() {
	Handle* h1 = new PrjManager;
	Handle* h2 = new DepManager;
	Handle* h3 = new CEOManager;
	h1->SetSuccessor(h2);
	h2->SetSuccessor(h3);
	std::string str = h1->request(1500);
	std::cout << str << "\n";
	return 0;
}