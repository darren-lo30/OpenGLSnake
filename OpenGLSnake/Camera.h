#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const float FOV = 45.0f;

enum class Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class Camera {
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 worldUp;

	glm::vec3 up;
	glm::vec3 right;

	float fov = FOV;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f));
	Camera(float posX, float posY, float posZ, float frontX, float frontY, float frontZ, float upX, float upY, float upZ);

	glm::mat4 getViewMatrix() const;
private:
	void updateVectors();
};
