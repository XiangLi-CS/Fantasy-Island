#pragma once
#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Mesh.h"
#include <vector>
#include"MeshAnimation.h"
#include"MeshMaterial.h"



class SceneNode {
public:
	//T6
	SceneNode(Mesh * m = NULL, Vector4 colour = Vector4(1, 1, 1, 1));
	~SceneNode(void);
	
	void SetTransform(const Matrix4 & matrix) { transform = matrix; }
	const Matrix4 & GetTransform() const { return transform; }
	Matrix4 GetWorldTransform() const { return worldTransform; }
	
	Vector4 GetColour() const { return colour; }
	void SetColour(Vector4 c) { colour = c; }
	
	Vector3 GetModelScale() const { return modelScale; }
	void SetModelScale(Vector3 s) { modelScale = s; }
	
	Mesh * GetMesh() const { return mesh; }
	void SetMesh(Mesh * m) { mesh = m; }
	
	void AddChild(SceneNode * s);

	virtual void Update(float dt);
	virtual void Draw(const OGLRenderer & r);
	
	std::vector <SceneNode*>::const_iterator GetChildIteratorStart() {
		return children.begin();
	}
	
	std::vector <SceneNode*>::const_iterator GetChildIteratorEnd() {
		return children.end();
	}

	//T7
	float GetBoundingRadius() const { return boundingRadius; }
	void SetBoundingRadius(float f) { boundingRadius = f; }
	
	float GetCameraDistance() const { return distanceFromCamera; }
	void SetCameraDistance(float f) { distanceFromCamera = f; }
	
	void SetTexture(GLuint tex) { texture = tex; }
	GLuint GetTexture() const { return texture; }
	
	static bool CompareByCameraDistance(SceneNode * a, SceneNode * b) {
		return (a->distanceFromCamera < b->distanceFromCamera) ? true : false;
		
	}

	void SetAniTexture(vector<GLuint> tex) { matTextures = tex; }
	vector<GLuint> GetAniTexture() const { return matTextures; }

	int GetCurrentFrame() const { return currentFrame; }
	void SetCurrentFrame(int c) { currentFrame = c; }

	float GetframTime() const { return frameTime; }
	void SetframeTime(float c) { frameTime = c; }

	MeshAnimation* GetAnimation() const { return anim; }
	void SetAnimation(MeshAnimation* anim) { anim = anim; }

protected:
	//T6
	SceneNode * parent;
	Mesh * mesh;
	Matrix4 worldTransform;
	Matrix4 transform;
	Vector3 modelScale;
	Vector4 colour;
	std::vector <SceneNode*> children;

	//T7
	float distanceFromCamera;
	float boundingRadius;
	GLuint texture;

	MeshAnimation* anim;
	//MeshMaterial* material;
	vector <GLuint > matTextures;

	int currentFrame;
	float frameTime;

};