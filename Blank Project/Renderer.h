#pragma once
#include "../nclgl/OGLRenderer.h"
#include "../nclgl/Camera.h"
#include "../nclgl/HeightMap.h"
#include "../nclgl/Light.h"
#include "../nclgl/SceneNode.h"
#include "../nclgl/MeshAnimation.h"
#include "../nclgl/MeshMaterial.h"
#include "Snow.h"


class Renderer :public OGLRenderer
{
public:
	Renderer(Window& parent);
	~Renderer(void);

	//Scene
	void RenderScene() override;
	void RederDeferredScene();

	void UpdateScene(float dt) override;
	void AutoUpdateCamera(float dt);

protected:
	//Scene Management
	void BuildNodeLists(SceneNode* from);
	void SortNodeLists();
	void ClearNodeLists();
	void DrawNodes(Camera* camera);
	void DrawNode(Camera* camera, SceneNode* n);

	//HeightMap Functions
	void DrawHeightmap();
	void DrawWater();
	void DrawSkybox();

	//deferred shading
	void DrawScene();
	void DrawPointLights();
	void CombineBuffers();
	void GenerateScreenTexture(GLuint& into, bool depth = false);

	//Scene
	SceneNode* root;
	SceneNode* npcNode;

	HeightMap* heightMap;
	Camera* camera;
	Light* light;
	Light* pointLights;

	//Mesh
	Mesh* quad;		//Skybox
	Mesh* palmtree;
	Mesh* npc;
	Mesh* sphere;

	//Shader
	Shader* lightShader;	//lighting terrain shader
	Shader* reflectShader;
	Shader* skyboxShader;
	Shader* sceneShader;
	Shader* npcShader;
	Shader* pointlightShader;
	Shader* combineShader;

	//FBO
	GLuint bufferFBO;
	GLuint bufferDepthTex;
	GLuint bufferNormalTex;
	GLuint bufferColourTex[2];

	GLuint pointLightFBO;
	GLuint lightDiffuseTex;
	GLuint lightSpecularTex;


	//Texture
	GLuint cubeMap;
	GLuint waterTex;
	GLuint earthTex;	//Terrain texture
	GLuint earthBump;
	GLuint waterBump;
	GLuint treeTex;
	GLuint nodeTex;

	//Animation
	MeshAnimation* anim;
	MeshMaterial* material;
	vector <GLuint > matTextures;

	//Anim frame
	int currentFrame;
	float frameTime;

	vector<SceneNode*> transparentNodeList;
	vector<SceneNode*> nodeList;

	//Water
	float waterRotate;
	float waterCycle;

	//Snow
	Snow* snow;

};
