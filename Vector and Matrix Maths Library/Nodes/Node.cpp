#include "Node.h"

Node::Node() {
	m_pParent = nullptr;
	m3PosRot = CMatrix3::Identity();
}

Node::~Node() {
	// Replaced with range based for loop
	for (auto &iter : m_pChildren)
	{
		RemoveChild(iter);
	}

	// Set parent to null
	m_pParent = nullptr;
}

// Function to set this node's parent 
void Node::SetParent(Node* a_parent)
{
	// If the user has tried to set this as parented to itself,
	// do nothing and exit.
	if (a_parent == this)
		return;

	// If we already have a parent, then before we execute
	// remove ourself as a child from that parent.
	if (m_pParent != nullptr)
	{
		m_pParent->RemoveChild(this);
	}

	// Set the parent variable in this object, and add this as
	// a child to the parent object
	m_pParent = a_parent;
	m_pParent->AddChild(this);
}

void Node::AddChild(Node* a_child)
{
	auto iter = m_pChildren.find(a_child);
	// Children are stored in a set. One of the features of a set is easy searching for an item
	// this allows us to see if the child already exists in the set of children. 
	// If it exists already we will not add it to the set multiple times.
	if (iter == m_pChildren.end())
	{
		m_pChildren.emplace(a_child);
	}
}

void Node::RemoveChild(Node* a_child)
{
	// if we can find the child remove it, a successful find returns an iterator to the object
	// we are looking for. An unsuccessful find returns an iterator that is one item past the end of the set
	auto iter = m_pChildren.find(a_child);
	if (iter != m_pChildren.end())
	{
		m_pChildren.erase(iter);
	}
}

void Node::GetWorldTransform(CMatrix3& transform)
{
	if (m_pParent)
	{
		m_pParent->GetWorldTransform(transform);
		transform = m3PosRot * transform;
	}
	else
	{
		transform = m3PosRot;
	}
}

void Node::GetLocalTransform(CMatrix3 a_m3Transform)
{
	a_m3Transform = m3PosRot;
}

void Node::SetTranslation(CVector2 a_v2Translation)
{
	m3PosRot.SetRow(2, CVector3(a_v2Translation));
}

void Node::RotateZ(float a_fRotation)
{
	CMatrix3 m3Rotation = CMatrix3::Identity();
	m3Rotation = m3Rotation.RotateZ(a_fRotation);
	m3PosRot = m3Rotation * m3PosRot;
}

void Node::Scale(float a_fScale)
{
	CVector3 translation = m3PosRot.GetRow(2);

	CMatrix3 identity = CMatrix3::Identity();
	m3PosRot = (identity * a_fScale) * m3PosRot;
	m3PosRot.SetRow(2, translation);
}