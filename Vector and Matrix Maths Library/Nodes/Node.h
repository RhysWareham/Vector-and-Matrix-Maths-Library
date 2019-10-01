 #pragma once
#include <set>

#include "mathlib.h"

//\===========================================================================================================
//\ Node -
//\   This is a small class that contains a matrix that is used to store rotation and positional data
//\ for an object. This node structure allows for parenting objects so that they can maintain a hierarchy for 
//\ matrix transformation detail, this permits easy parenting of objects like swords and other items onto a 
//\ character or in this scenario parenting a turret with a tank base.
//\ Original example by Jamie Stewart (2016), modified by Will Sayers (2018) to match framework updates
//\ and module alterations.
//\===========================================================================================================
class Node
{
public:
	// Constructor
	Node();

	// Destructor (virtual as we will use node as a base class)
	virtual ~Node();

	// Function to set this node's parent 
	void SetParent(Node* a_parent);

	// Function to add a child to the node
	void AddChild(Node* a_child);

	// Remove a child from our node hierarchy structure
	void RemoveChild(Node* a_child);

	// Where is this node in the world 
	// this requires us to transform (multiply) this node by any parents it may have (and their parents in turn).
	void GetWorldTransform(CMatrix3& transform);

	// Get the local transform for our point
	void GetLocalTransform(CMatrix3 a_m3Transform);

	// Set our translation
	void SetTranslation(CVector2 a_v2Translation);

	// Rotate this node around it's z axis
	// As it's 2D, we don't actually need functions for rotating around Y and Z
	void RotateZ(float a_fRotation);

	// Scale this node
	void Scale(float a_fScale);

protected:
	CMatrix3 m3PosRot;

private:
	Node * m_pParent;
	std::set<Node*>m_pChildren;
};
