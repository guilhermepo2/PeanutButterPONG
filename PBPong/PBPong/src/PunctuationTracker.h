#pragma once
#include <PeanutButter.h>
#include "BallMovementComponent.h"
using namespace PeanutButter;

class PunctuationTracker : public PeanutButter::Component {
public:
	PunctuationTracker(UIText* InLeftScore, UIText* InRightScore, BallMovementComponent* InBallComponent) : m_LeftScore(InLeftScore), m_RightScore(InRightScore), m_BallComponent(InBallComponent) {}

private:
	UIText* m_LeftScore;
	UIText* m_RightScore;
	BallMovementComponent* m_BallComponent;

public:

	void Initialize() override {}
	void BeginPlay() override {}
	
	void Update(float DeltaTime) override {
		m_LeftScore->UpdateLabelText(std::string("Score: ") + std::to_string(m_BallComponent->TimesHitRight));
		m_RightScore->UpdateLabelText(std::string("Score: ") + std::to_string(m_BallComponent->TimesHitLeft));
	}

	void Render() override {}
};