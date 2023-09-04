#include<iostream>
#include<string>
#include<vector>

class ExportHeader
{
private:
	std::string m_csDeptId;
	std::string m_csContent;
public:
	ExportHeader(std::string&& csDeptId, std::string&& csContent) :m_csDeptId(csDeptId), m_csContent(csContent) {}

	~ExportHeader() { std::cout << "ExportHeader Destory\r\n"; }

	std::string GetHeaderDeptId()
	{
		return this->m_csDeptId;
	}

	std::string GetHeaderContent()
	{
		return this->m_csContent;
	}
};

class ExportBody
{
private:
	std::string m_csTransId;
	std::string m_csSumOfMoney;

public:

	ExportBody(std::string&& csTransId, std::string&& csSumOfMoney) :m_csTransId(csTransId), m_csSumOfMoney(csSumOfMoney) {}

	~ExportBody() { std::cout << "ExportBody Destory\r\n"; }

	std::string GetTransId()
	{
		return this->m_csTransId;
	}

	std::string GetSumOfMoney()
	{
		return this->m_csSumOfMoney;
	}
};

class ExportFoot
{
private:
	std::string m_csHandleBy;
public:
	ExportFoot(std::string&& csdHandleBy) :m_csHandleBy(csdHandleBy) {}

	~ExportFoot() { std::cout << "ExportFoot Destory\r\n"; }

	std::string GetHandleBy()
	{
		return this->m_csHandleBy;
	}
};

class Builder
{
protected:
	std::string m_csResult;
protected:
	Builder() { this->m_csResult = ""; }

public:

	~Builder() { std::cout << "Builder Destory\r\n"; }

	virtual void BuilderHeader(ExportHeader* lpHeader) = 0;
	virtual void BuilderBody(std::vector<ExportBody*> BodyContainer) = 0;
	virtual void BuilderFoot(ExportFoot* lpFoot) = 0;
	virtual std::string GetResult() = 0;
};

class TextBuilder :public Builder
{
public:
	TextBuilder() :Builder() {}

	~TextBuilder() { std::cout << "TextBuilder Destory\r\n"; }

	void BuilderHeader(ExportHeader* lpHeader)
	{
		this->m_csResult += lpHeader->GetHeaderDeptId() + ", " + lpHeader->GetHeaderContent() + "\r\n";
	}
	void BuilderBody(std::vector<ExportBody*> BodyContainer)
	{
		for (ExportBody* lpBody : BodyContainer)
		{
			this->m_csResult += lpBody->GetTransId() + ", " + lpBody->GetSumOfMoney() + "\r\n";
		}
	}
	void BuilderFoot(ExportFoot* lpFoot)
	{
		this->m_csResult += lpFoot->GetHandleBy() + "\r\n";
	}

	std::string GetResult()
	{
		return this->m_csResult;
	}
};

class XmlBuilder :public Builder
{
public:
	XmlBuilder() :Builder() {}

	~XmlBuilder() { std::cout << "XmlBuilder Destory\r\n"; }

	void BuilderHeader(ExportHeader* lpHeader)
	{
		this->m_csResult += "Xml: " + lpHeader->GetHeaderDeptId() + ", " + lpHeader->GetHeaderContent() + "\r\n";
	}
	void BuilderBody(std::vector<ExportBody*> BodyContainer)
	{
		for (ExportBody* lpBody : BodyContainer)this->m_csResult += "Xml: " + lpBody->GetTransId() + ", " + lpBody->GetSumOfMoney() + "\r\n";
	}
	void BuilderFoot(ExportFoot* lpFoot)
	{
		this->m_csResult += "Xml: " + lpFoot->GetHandleBy() + "\r\n";
	}

	std::string GetResult()
	{
		return this->m_csResult;
	}
};

class Dircetory
{
private:
	Builder* m_lpBuilder;
public:
	Dircetory(Builder* lpBuilder) :m_lpBuilder(lpBuilder) {}

	~Dircetory()
	{
		std::cout << "Dircetory Destory\r\n";
		delete this->m_lpBuilder;
	}

	std::string PackExport(ExportHeader* lpHeader, std::vector<ExportBody*>& BodyContainer, ExportFoot* lpFoot)
	{
		this->m_lpBuilder->BuilderHeader(lpHeader);
		this->m_lpBuilder->BuilderBody(BodyContainer);
		this->m_lpBuilder->BuilderFoot(lpFoot);

		delete lpHeader;
		for (auto lpBody : BodyContainer)
		{
			delete lpBody;
		}
		delete lpFoot;
		return this->m_lpBuilder->GetResult();
	}
};

int main()
{
	std::vector<ExportBody*>v{ new ExportBody("1111", "1000.22"), new ExportBody("2222", "2222.33"), new ExportBody("3333", "3333.44") };
	auto dir = Dircetory(new TextBuilder());
	auto res = dir.PackExport(new ExportHeader("广州支行", "1月1日"), v, new ExportFoot("小明"));
	std::cout << res << std::endl;
	return 0;
}