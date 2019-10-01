#pragma once
#include <set>

#include "mathlib.h"
#include "UGFW.h"
#include "Node.h"


//A very simple sprite class that extends from node allowing us to have a sprite hierarchy tree in our game
struct Sprite : public Node {

public:
	//Constructor -- makes a UG Sprite object for us to use
	Sprite(const char* a_fileName, const float *a_size, const float *a_origin, const float *a_UVCoords);

	// Destructor
	// Making the destructor virtual ensures that even if we're using inheritance heirarchies (which we are)
	// the destructors will all be called in the correct order.
	virtual ~Sprite();

	// Set our sprite layer
	void SetLayer(unsigned int a_uiLayer);

	// An update function to call each frame to update our sprites data
	void Update(float a_fdt);

	//Function to move our spritec
	// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
	void MoveSprite(CVector3 a_movementVec);

	void Draw();

	void SetPosition(CVector2 a_pos);

private:
	int m_iSpriteID;
};