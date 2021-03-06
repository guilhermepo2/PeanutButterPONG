#pragma once
#include <PeanutButter.h>
using namespace PeanutButter;

class PaddleMovementComponent : public PeanutButter::Component {
public:
	float Velocity;
	PaddleMovementComponent() : Velocity(0.0f) {}
	PaddleMovementComponent(float InVelocity, PB_Keycode InUpKey, PB_Keycode InDownKey) : Velocity(InVelocity), m_UpKey(InUpKey), m_DownKey(InDownKey) {}

private:
	Transform* OwnerTransform;
	PB_Keycode m_UpKey;
	PB_Keycode m_DownKey;

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
		if (PeanutButter::Input::IsKeyPressed(m_UpKey)) {
			// TODO: Remove the 0 magic number from here, ideally we would check for collisions
			if (OwnerTransform->Position->y - (Velocity * DeltaTime) >= 0) {
				OwnerTransform->Position->y -= Velocity * DeltaTime;
			}
		}
	
		if (PeanutButter::Input::IsKeyPressed(m_DownKey)) {
			// TODO: Remove the (600 - 128) magic number from here, ideally we would check for collisions
			// 600 = screen height
			// 128 = paddle height
			if (OwnerTransform->Position->y + (Velocity * DeltaTime) <= (600 - 128)) {
				OwnerTransform->Position->y += Velocity * DeltaTime;
			}
		}
	}

	void Render() override {}
};
