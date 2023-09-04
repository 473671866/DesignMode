#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

//std::map<int, std::vector<std::string>> logs;
//
////切分log
//std::vector <std::string > get_bugs(std::string s)
//{
//	std::vector<std::string> result;
//	std::istringstream ss(s);
//	while (!ss.eof())
//	{
//		std::string log;
//		getline(ss, log, '|');
//		result.push_back(log);
//	}
//	return result;
//}
//
////读取文件
//bool get_logs()
//{
//	std::ifstream in("D://log.txt");
//	if (!in)
//	{
//		std::cout << "文件打开失败" << std::endl;
//		return false;
//	}
//
//	std::string line;
//	int i = 0;
//	while (getline(in, line))
//	{
//		logs.emplace(i, get_bugs(line));
//		i++;
//	}
//	in.close();
//	return true;
//}
//
//int main()
//{
//	get_logs();
//	for (auto logs_iter = logs.begin(); logs_iter != logs.end(); logs_iter++)
//	{
//		for (auto log_iter = logs_iter->second.begin(); log_iter != logs_iter->second.end(); log_iter++)
//		{
//			std::cout << "log: " << *log_iter << std::endl;
//		}
//	}
//
//	std::cout << "Hello World!\n";
//}

std::map<int, std::vector<std::string>> cache;

class BugManage
{
public:
	virtual void get_bug() = 0;
};

class RealBugMode
{
private:
	std::vector<std::string> get_cache(std::string word)
	{
		std::vector<std::string> result;
		std::istringstream ss(word);
		while (!ss.eof())
		{
			std::string log;
			getline(ss, log, '|');
			result.push_back(log);
		}
		return result;
	}

public:
	void get_bugs()
	{
		std::ifstream in("D://log.txt");
		if (!in)
		{
			std::cout << "文件打开失败" << std::endl;
		}

		std::string line;
		int i = 0;
		while (getline(in, line))
		{
			cache.emplace(i, this->get_cache(line));
			i++;
		}
		in.close();
	}
};

class ProxyBugMode
{
private:
	bool m_reload;

	void show_bugs()
	{
		for (auto logs_iter = cache.begin(); logs_iter != cache.end(); logs_iter++)
		{
			for (auto log_iter = logs_iter->second.begin(); log_iter != logs_iter->second.end(); log_iter++)
			{
				std::cout << "log: " << *log_iter << std::endl;
			}
		}
	}

public:
	ProxyBugMode() :m_reload(false)
	{
	}

	void get_bugs()
	{
		if (this->m_reload)
		{
			std::cout << "从缓存中获取\n";
			this->show_bugs();
		}
		else
		{
			std::cout << "从文件中获取\n";
			(new RealBugMode())->get_bugs();
			this->show_bugs();
			this->m_reload = true;
		}
	}
};

//int main()
//{
//	ProxyBugMode* p = new ProxyBugMode();
//	for (int i = 0; i < 10; i++)
//	{
//		p->get_bugs();
//	}
//	return 0;
//}