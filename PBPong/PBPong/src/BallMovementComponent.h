#pragma once
#include <PeanutButter.h>
using namespace PeanutButter;

class BallMovementComponent : public PeanutButter::Component {
public:
	Vector2 BallVelocity;
	BallMovementComponent() : BallVelocity(100.0f, 100.0f) {}
	BallMovementComponent(const Vector2& InBallVelocity) : BallVelocity(InBallVelocity) {}

private:
	Transform* OwnerTransform;
	ParticleProps MyParticle;

public:
	void Initialize() override {
		MyParticle.LifeTime = 0.5f;
		MyParticle.SizeBegin = 16.0f;
		MyParticle.SizeEnd = 0.0f;
		MyParticle.Color = PB_COLOR_WHITE;
	}

	void BeginPlay() override {
		if (owner->HasComponentOfType<Transform>()) {
			OwnerTransform = owner->GetComponentOfType<Transform>();
		}

		if (owner->HasComponentOfType<Collider2D>()) {
			// Bind Process Collision on Collider 2D
			Collider2D* ColliderComponent = owner->GetComponentOfType<Collider2D>();
			ColliderComponent->HandleCollision = std::bind(&BallMovementComponent::ProcessCollision, this, std::placeholders::_1);
		}
	}

	void Update(float DeltaTime) override {
		OwnerTransform->Position->x += BallVelocity.x * DeltaTime;
		OwnerTransform->Position->y += BallVelocity.y * DeltaTime;

		// TODO: Remove magic numbers from here
		if ((OwnerTransform->Position->x <= 0 && BallVelocity.x < 0) ||
			(OwnerTransform->Position->x >= (800 - 16) && BallVelocity.x > 0)) {
			BallVelocity.x *= -1.0f;
		}
		else if ((OwnerTransform->Position->y <= 0 && BallVelocity.y < 0) ||
			(OwnerTransform->Position->y >= (600 - 16) && BallVelocity.y > 0)) {
			BallVelocity.y *= -1.0f;
		}

	}

	void Render() override {}

	void ProcessCollision(PeanutButter::Collider2D* Other) {
		// PB_WARNING("BALL HANDLING COLLISION!");
		if (Other->ColliderTag.compare("left-paddle") == 0 && BallVelocity.x < 0) {
			BallVelocity.x *= -1;

			// Instantiating Particles
			for (int i = 0; i < 15; i++) {
				MyParticle.Position = { 
					OwnerTransform->Position->x, 
					OwnerTransform->Position->y + PeanutButter::Random::Float() 
				};

				MyParticle.Velocity = { 
					BallVelocity.x + (PeanutButter::Random::Float() * 45.0f),
					PeanutButter::Random::Float() * 45.0f 
				};
				Application::s_ParticleSystem.Emit(MyParticle);
			}
		}
	}
};