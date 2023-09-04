#include<iostream>

//----------------------------------------------------------------------
class FrameApi
{
protected:
	int m_pins;
protected:
	FrameApi(int pins) :m_pins(pins) {}
public:
	virtual void Draw() = 0;
};

class ComputerFarme :public FrameApi
{
public:
	ComputerFarme(int pins) :FrameApi(pins) {}

	void Draw()
	{
		std::cout << "ComputerFarme pins: " << this->m_pins << std::endl;
	}
};

class MobileFrame :public FrameApi
{
public:
	MobileFrame(int pins) :FrameApi(pins) {}

	void Draw()
	{
		std::cout << "MobileFrame pins: " << this->m_pins << std::endl;
	}
};

//----------------------------------------------------------------------

class LayoutApi
{
protected:
	int m_frame_adapter_pins;
protected:
	LayoutApi(int frame_adapter_pins) :m_frame_adapter_pins(frame_adapter_pins) {}
public:
	virtual void InstallFrame() = 0;
};

class HightLayout :public LayoutApi
{
public:
	HightLayout(int frame_adapter_pins) :LayoutApi(frame_adapter_pins) {}
	void InstallFrame()
	{
		std::cout << "HightLayout frame_adapter_pins: " << this->m_frame_adapter_pins << std::endl;
	}
};

class LowLayout :public LayoutApi
{
public:
	LowLayout(int frame_adapter_pins) :LayoutApi(frame_adapter_pins) {}
	void InstallFrame()
	{
		std::cout << "LowLayout frame_adapter_pins: " << this->m_frame_adapter_pins << std::endl;
	}
};

//----------------------------------------------------------------------

class AbstructFactory
{
protected:
	AbstructFactory() {}
public:
	virtual FrameApi* CreateFrame() = 0;
	virtual LayoutApi* CreateLayout() = 0;
};

class Make1 :public AbstructFactory
{
public:
	FrameApi* CreateFrame()
	{
		return new ComputerFarme(1920);
	}
	LayoutApi* CreateLayout()
	{
		return new HightLayout(1080);
	}
};

class Make2 :public AbstructFactory
{
public:
	FrameApi* CreateFrame()
	{
		return  new MobileFrame(1280);
	}
	LayoutApi* CreateLayout()
	{
		return new LowLayout(720);
	}
};

class GuiConfig
{
private:
	FrameApi* m_lpFrame;
	LayoutApi* m_lpLayout;
	AbstructFactory* m_lpMake;
public:
	GuiConfig(AbstructFactory* lpMake) :m_lpMake(lpMake)
	{
		this->m_lpFrame = lpMake->CreateFrame();
		this->m_lpLayout = lpMake->CreateLayout();
	}

	~GuiConfig()
	{
		delete this->m_lpFrame;
		delete this->m_lpLayout;
		delete this->m_lpMake;
	}

	void Execute()
	{
		this->m_lpFrame->Draw();
		this->m_lpLayout->InstallFrame();
	}
};

//----------------------------------------------------------------------

int main()
{
	GuiConfig(new Make2()).Execute();
	system("pause");
	return 0;
}