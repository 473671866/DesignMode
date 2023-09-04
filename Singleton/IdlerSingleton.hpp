#pragma once

//��������
template<class T>
class IdlerSingleton
{
protected:
	Singleton() {}
public:
	static T* GetInstance()
	{
		static T* instance;
		if (instance == nullptr)
		{
			instance = new T;
		}
		return instance;
	}

	virtual ~Singleton() {}
};