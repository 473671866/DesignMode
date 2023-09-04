#pragma once
#include<iostream>
#include<string>

class ExportFileApi
{
public:
	virtual bool export_data(std::string data) = 0;

protected:
	ExportFileApi() {}
};

class ExportTextFile :public ExportFileApi
{
public:

	bool export_data(std::string data) override
	{
		std::cout << "ExportTextFile: " << data << "\n";
		return true;
	}
};

class ExportCsvFile :public ExportFileApi
{
public:

	bool export_data(std::string data) override
	{
		std::cout << "ExportCsvFile: " << data << "\n";
		return true;
	}
};

class ExportExcelFile :public ExportFileApi
{
public:

	bool export_data(std::string data) override
	{
		std::cout << "ExportExcelFile: " << data << "\n";
		return true;
	}
};