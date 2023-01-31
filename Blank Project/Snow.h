#pragma once
#include "../nclgl/SceneNode.h"

struct Particle {
	Vector3 speed;
	Vector3 position;
	bool isAlive;
};

class Snow : public SceneNode {
public:
	Snow();
	void Update(float dt) override;
protected:
	float variant = 100;
	float base = 100;
	float numParticles = 350;
	vector<Particle> particle_list;
};