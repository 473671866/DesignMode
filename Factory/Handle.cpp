#pragma once
#include<iostream>
#include<string>
#include"Factory.cpp"

class ExportHandle
{
public:
	bool export_data(std::string data)
	{
		ExportFileApi* lpFileApi = this->factory_method();
		return lpFileApi->export_data(data);
	}
protected:
	virtual ExportFileApi* factory_method() = 0;
};

class ExpotrTextHandle :public ExportHandle
{
protected:
	ExportFileApi* factory_method() override
	{
		return new ExportTextFile();
	}
};

class ExpotrCvsHandle :public ExportHandle
{
protected:
	ExportFileApi* factory_method() override
	{
		return new ExportCsvFile();
	}
};

class ExpotrExcelHandle :public ExportHandle
{
protected:
	ExportFileApi* factory_method() override
	{
		return new ExportExcelFile();
	}
};