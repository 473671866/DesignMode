#pragma once
#include"Handle.cpp"
#include<memory>

int main()
{
	std::unique_ptr<ExportHandle> handle = std::make_unique<ExpotrTextHandle>();
	handle->export_data("Text");

	handle = std::make_unique<ExpotrCvsHandle>();
	handle->export_data("Csv");

	handle = std::make_unique<ExpotrExcelHandle>();
	handle->export_data("Excel");
	return 0;
}