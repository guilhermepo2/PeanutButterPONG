#include <PeanutButter.h>

class Pong : public PeanutButter::Application {
public:
	Pong() {}
	Pong(const int& Width, const int& Height, const std::string Title) : Application(Width, Height, Title) {
		m_GameWidth = Width;
		m_GameHeight = Height;
	}

	~Pong() override {}

private:
	float m_GameWidth;
	float m_GameHeight;

public:
	void Start() override {
		PB_INFO("Starting Client");
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Pong(800, 600, "PONG");
}