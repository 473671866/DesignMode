#pragma once

//��������
template<class T>
class HungrySingleton
{
public:
	HungrySingleton() = delete;

	virtual ~HungrySingleton() = default;

	static T* GetInstance()
	{
		static T instance;
		return &instance;
	}
};