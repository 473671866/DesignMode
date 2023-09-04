#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
	virtual void update(std::string temp, std::string humi) = 0;

protected:
	Observer() { }
};

class Subject {
public:
	virtual void subscribe(Observer* ob) = 0;
	virtual void cencel(Observer* ob) = 0;
	virtual void notify() = 0;

protected:
	Subject() {}
};

class WeacherData : public Subject {
public:
	WeacherData(std::string temp, std::string humi) :m_temp(temp), m_humi(humi) {}

	void subscribe(Observer* ob) {
		this->m_observers.push_back(ob);
	}

	void cencel(Observer* ob) {
		std::erase(this->m_observers, ob);
	}

	void notify() {
		for (Observer* ob : this->m_observers) {
			ob->update(m_temp, m_humi);
		}
	}

private:
	std::vector<Observer*>m_observers;
	std::string m_temp;
	std::string m_humi;
};

class PCDisplay : public Observer {
public:
	PCDisplay(WeacherData* data) {
		this->m_data = data;
		this->m_data->subscribe(this);
	}

	void update(std::string temp, std::string humi) {
		std::cout << "PCDisplay: " << temp << humi << "\n";
	}
private:
	WeacherData* m_data;
};

class MobileDisplay : public Observer {
public:
	MobileDisplay(WeacherData* data) {
		this->m_data = data;
		this->m_data->subscribe(this);
	}

	void update(std::string temp, std::string humi) {
		std::cout << "MobileDisplay: " << temp << humi << "\n";
	}
private:
	WeacherData* m_data;
};

int main() {
	WeacherData* data = new WeacherData("33 ", "66");
	PCDisplay* pc = new PCDisplay(data);
	MobileDisplay* mo = new MobileDisplay(data);
	data->notify();
	return 0;
}