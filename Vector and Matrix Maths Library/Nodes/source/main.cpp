#include "UGFW.h"
#include "UG_Defines.h"
#include "mathlib.h"

#include "Sprite.h"

#include <math.h>
#include <iostream>


int main(int argv, char* argc[])
{
	if (!UG::Create(1440, 800, false, "Nodes Demo", 100, 100))
	{
		return 1;
	}

	int iScreenWidth = 0, iScreenHeight = 0;
	UG::GetScreenSize(iScreenWidth, iScreenHeight);

	UG::SetBackgroundColor(UG::SColour(0x2A, 0x57, 0x66, 0xFF));

	//Create a sprite for our tank's base - this one is using magic numbers - which it shouldn't be
	// x1, y1, x2, y2
	float UVCoords1[] = { 0.0f, 0.5f, 0.5f, 0.99f };
	Sprite* pTank = new Sprite(
		"./images/tanks.png",
		CVector2(85.0f, 84.0f).GetPointer(),
		CVector2(0.5f, 0.5f).GetPointer(),
		UVCoords1
	);

	pTank->SetPosition(CVector2(iScreenWidth * 0.5f, iScreenHeight * 0.5f));
	pTank->SetLayer(0);

	//Create a sprite for our tank's turret
	// x1, y1, x2, y2
	float UVCoords2[] = { 0.5f, 0.0f, 0.99f, 0.5f };
	Sprite* pTurret = new Sprite(
		"./images/tanks.png",
		CVector2(85.0f, 84.0f).GetPointer(),
		CVector2(0.5f, 0.4f).GetPointer(),
		UVCoords2
	);

	pTurret->SetParent(pTank);
	pTurret->SetLayer(1);

	//We will be using some simple physics to move our tank
	//Lets use a value for max speed for our tank to be 100
	//our cut off speed can be set to 5 so if we are below that then don't move
	float fCurrentVelocity = 0.f;
	float fMaxVelocity = 10.f;
	float fDrag = 0.03f;

	do
	{
		float dt = UG::GetDeltaTime();

		//Create a vector to store our movement
		CVector3 movementVector = CVector3(0.0f, 1.0f, 0.0f);

		//We're going to be treating moving forward and backward as traversing along the sprite's Y axis
		//If our sprite was rotated 90 degrees on the sprite sheet then we would treat that direction as forward.
		float fAccelleration = 0.f;

		if (UG::IsKeyDown(UG::KEY_W))
		{
			fAccelleration += 3.f;
			fDrag = 0.f;
		}
		if (UG::IsKeyDown(UG::KEY_S))
		{
			fAccelleration -= 2.f;
			fDrag = 0.f;
		}
		if (!UG::IsKeyDown(UG::KEY_S) && !UG::IsKeyDown(UG::KEY_W))
		{
			fDrag = 0.08f;
		}

		fCurrentVelocity += fAccelleration * dt;
		fCurrentVelocity -= fCurrentVelocity * fDrag;
		if (fCurrentVelocity > fMaxVelocity)
		{
			fCurrentVelocity = fMaxVelocity;
		}
		else if (fCurrentVelocity < -fMaxVelocity)
		{
			fCurrentVelocity = -fMaxVelocity;
		}

		if (fabs(fCurrentVelocity) > FLT_EPSILON)
		{
			movementVector *= fCurrentVelocity;
			pTank->MoveSprite(movementVector);
		}

		//Tank Rotation
		if (UG::IsKeyDown(UG::KEY_A))
		{
			pTank->RotateZ(-0.05f);
		}
		if (UG::IsKeyDown(UG::KEY_D))
		{
			pTank->RotateZ(0.05f);
		}

		//Turret Rotation
		if (UG::IsKeyDown(UG::KEY_Q))
		{
			pTurret->RotateZ(-0.085f);
		}
		if (UG::IsKeyDown(UG::KEY_E))
		{
			pTurret->RotateZ(0.085f);
		}

		// quit our application when escape is pressed
		if (UG::IsKeyDown(UG::KEY_ESCAPE))
			UG::Close();

		UG::ClearScreen();

		pTank->Update(dt);
		pTurret->Update(dt);
		pTank->Draw();
		pTurret->Draw();

		//Top and Bottom lines
		UG::DrawLine(0.0f, (float)(iScreenHeight - 40), (float)iScreenWidth, (float)(iScreenHeight - 40));

		UG::DrawLine(0.0f, 40.0f, (float)iScreenWidth, 40.0f);

	} while (UG::Process());

	UG::Dispose();

	return 0;
}
