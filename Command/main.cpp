#include <iostream>

class Light {
public:
	void on() {
		std::cout << "¿ª\n";
	}

	void off() {
		std::cout << "¹Ø\n";
	}
};

class Command {
public:
	virtual void execute() = 0;
};

class LightOnCommand : public Command {
public:
	LightOnCommand(Light* light) {
		this->m_light = light;
	}

	void execute() {
		this->m_light->on();
	}

private:
	Light* m_light;
};

class SimpleRemoteControl {
public:
	SimpleRemoteControl(Command* command) {
		this->m_command = command;
	}

	void launcher() {
		this->m_command->execute();
	}

private:
	Command* m_command;
};

int main() {
	Light* light = new Light;
	Command* command = new LightOnCommand(light);
	SimpleRemoteControl* control = new SimpleRemoteControl(command);
	control->launcher();
	system("pause");
	return 0;
}