#include "Sprite.h"

Sprite::Sprite(const char* a_fileName, const float *a_size, const float *a_origin, const float *a_UVCoords) {
	// Get Sprite ID
	m_iSpriteID = UG::CreateSprite(a_fileName, a_size, a_origin, a_UVCoords);

	// Initialise a float[16] to hold the 4x4 matrix returned from get sprite matrix
	float mat4x4[16] = {
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f
	};

	// Get the sprite matrix - does so by means of a pointer parameter (second param)
	UG::GetSpriteMatrix(m_iSpriteID, mat4x4);

	// Set our sprites matrix 3x3 up with the correct values from the returned matrix 4x4
	m3PosRot = CMatrix3(mat4x4[0], mat4x4[1], mat4x4[2], mat4x4[4], mat4x4[5], mat4x4[6], mat4x4[12], mat4x4[13], 1.f);

}

Sprite::~Sprite() {
	// When this object is destructed, free up sprite memory
	UG::DestroySprite(m_iSpriteID);
}

void Sprite::SetLayer(unsigned int a_uiLayer)
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}

void Sprite::Update(float a_fdt)
{
	//OpenGL which is the underlying rendering pipeline that is being used by the framework
	//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
	//from the 3x3 matrix that we are using internally
	//set the sprites matrix

	CMatrix3 worldTx = CMatrix3::Identity();
	GetWorldTransform(worldTx);

	//A 4x4 matrix is required for the setsprite matrix, we haven't covered these in
	//this class, but we know that we need a identity matrix (diagonal 1's) and we can
	//look up how the 3x3 matrix values map onto this, to create one.
	//In Jamie's module you will cover 4x4 matrices in more detail, as they are needed
	//for 3D work.
	float matrix4x4[] = {
		worldTx[0], worldTx[1], worldTx[2], 0.0f,
		worldTx[3], worldTx[4], worldTx[5], 0.0f,
		0.0f,		0.0f,		1.0f,		0.0f,
		worldTx[6], worldTx[7], 0.0f,		1.0f,
	};

	UG::SetSpriteMatrix(m_iSpriteID, matrix4x4);

}

void Sprite::MoveSprite(CVector3 a_movementVec)
{
	CVector3 pos = m3PosRot.GetRow(2);
	//Multiplying the movement vector by our local transform will put that vector in the local space of this object
	//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
	//of our worldspace matrix
	pos += a_movementVec * m3PosRot;

	m3PosRot.SetRow(2, pos);
}


void Sprite::Draw()
{
	UG::DrawSprite(m_iSpriteID);
}

void Sprite::SetPosition(CVector2 a_pos) {
	CVector3 np = CVector3(a_pos[0], a_pos[1], 1.f);
	m3PosRot.SetRow(2, np);
}