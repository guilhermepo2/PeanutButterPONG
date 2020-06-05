#include <PeanutButter.h>
#include "PaddleMovementComponent.h"
#include "BallMovementComponent.h"

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

		// Loading PONG assets
		Application::s_AssetManager->AddTexture(std::string("pong-ball"), std::string("assets/pong/fancy-ball.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-court"), std::string("assets/pong/fancy-court.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-paddle-grey"), std::string("assets/pong/fancy-paddle-grey.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-paddle-green"), std::string("assets/pong/fancy-paddle-green.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-paddle-blue"), std::string("assets/pong/fancy-paddle-blue.png"));

		// Loading Fonts
		Application::s_AssetManager->AddFont(std::string("arial-font"), std::string("assets/fonts/arial.ttf"), 14);
		Application::s_AssetManager->AddFont(std::string("charriot-font"), std::string("assets/fonts/charriot.ttf"), 42);
			
		// Court Entity
		Entity& CourtBackground(Application::s_EManager->AddEntity(std::string("court-background"), ELayerType::ELT_TilemapLayer));
		CourtBackground.AddComponentOfType<Transform>(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		CourtBackground.AddComponentOfType<Sprite>(std::string("pong-court"), Vector2(800.0f, 600.0f));

		// Ball
		Entity& BallEntity(Application::s_EManager->AddEntity(std::string("ball"), ELayerType::ELT_PlayerLayer));
		// TODO: Consider pivots when positioning the ball? Would have to change the Sprite Component
		BallEntity.AddComponentOfType<Transform>(Vector2(384.0f, 284.0f), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		BallEntity.AddComponentOfType<Sprite>(std::string("pong-ball"), Vector2(32.0f, 32.0f));
		BallEntity.AddComponentOfType<Collider2D>("ball", Vector2(384.0f, 284.0f), Vector2(32.0f, 32.0f));
		BallEntity.AddComponentOfType<BallMovementComponent>(Vector2(350.0f, 500.0f));

		// Left Paddle
		Entity& LeftPaddle(Application::s_EManager->AddEntity(std::string("left-paddle"), ELayerType::ELT_PlayerLayer));
		LeftPaddle.AddComponentOfType<Transform>(Vector2(50.0f, (300.0f - 64.0f)), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		LeftPaddle.AddComponentOfType<Sprite>(std::string("pong-paddle-blue"), Vector2(32.0f, 128.0f));
		LeftPaddle.AddComponentOfType<Collider2D>("paddle", Vector2(50.0f, (300.0f - 64.0f)), Vector2(32.0f, 128.0f));
		LeftPaddle.AddComponentOfType<PaddleMovementComponent>(750.0f);

		// Adding score points
		Entity& ScoreLabel(Application::s_EManager->AddEntity(std::string("score"), ELayerType::ELT_UILayer));
		ScoreLabel.AddComponentOfType<UIText>(Vector2(300, 25), std::string("Score: 0"), std::string("charriot-font"), PB_COLOR_WHITE);
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Pong(800, 600, "PONG");
}