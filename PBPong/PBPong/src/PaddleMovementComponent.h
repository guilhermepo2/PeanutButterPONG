#pragma once
#include <PeanutButter.h>
using namespace PeanutButter;

class PaddleMovementComponent : public PeanutButter::Component {
public:
	float Velocity;
	PaddleMovementComponent() : Velocity(0.0f) {}
	PaddleMovementComponent(float InVelocity) : Velocity(InVelocity) {}

private:
	Transform* OwnerTransform;

public:
	void Initialize() override {}

	void BeginPlay() override {
		if (owner->HasComponentOfType<Transform>()) {
			OwnerTransform = owner->GetComponentOfType<Transform>();
		}
		else {
			PB_WARNING("Trying to initialize Paddle Movement Component but Entity doesn't have a transform!");
		}
	}

	void Update(float DeltaTime) override {
		if (PeanutButter::Input::IsKeyPressed(PB_KEYCODE_W)) {
			OwnerTransform->Position->y -= Velocity * DeltaTime;
		}

		if (PeanutButter::Input::IsKeyPressed(PB_KEYCODE_S)) {
			OwnerTransform->Position->y += Velocity * DeltaTime;
		}
	}

	void Render() override {}
};