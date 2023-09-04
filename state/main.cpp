#include <iostream>
#include <string>
#include <map>

class DownloadState {
public:
	virtual void Down(std::string user, std::string item) = 0;
};

class NornalState : public DownloadState {
public:
	void Down(std::string user, std::string item) {
		std::cout << "正常下载\n";
	}
};

class RepeatState : public DownloadState {
public:
	void Down(std::string user, std::string item) {
		std::cout << "重复下载\n";
	}
};

class SpiteState : public DownloadState {
public:
	void Down(std::string user, std::string item) {
		std::cout << "恶意下载\n";
	}
};

class DownloadManager {
public:
	void Down(std::string user, std::string item) {
		int32_t count = 0;
		if (this->m_down_record.count(user) > 0) {
			count = this->m_down_record[user];
		}
		else {
			this->m_down_record[user] = 0;
		}
		count++;
		this->m_down_record[user] = count;

		if (count == 1) {
			this->m_state = new NornalState;
		}
		else if (count > 1 && count < 3) {
			this->m_state = new RepeatState;
		}
		else {
			this->m_state = new SpiteState;
		}

		this->m_state->Down(user, item);
	}
private:
	std::map<std::string, std::string>m_down_item;
	std::map<std::string, int32_t>m_down_record;
	DownloadState* m_state;
};

int main() {
	DownloadManager* manager = new DownloadManager;

	for (int i = 0; i < 6; i++) {
		manager->Down("dts", "项目");
	}

	system("pause");
	return 0;
}