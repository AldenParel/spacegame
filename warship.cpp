
# ifndef __INCLUDES465__
# include "../includes465/include465.hpp"
# define __INCLUDES465__
# endif

class Warship {

public:
	
	char * modelFile;
	float boundingRadius;
	const GLuint nVertices = 1752;
	bool controllable = false;
	
	//glm::vec4 vertex[nVertices];
	//glm::vec3 normal[nVertices];
	//glm::vec4 diffuseColorMaterial[nVertices];
	//GLsizeiptr allocSize;
	
	glm::mat4 position;
	glm::mat4 rotation;
	glm::mat4 orientation;
	glm::mat4 bCam = glm::mat4();
	glm::mat4 tCam = glm::mat4();
	
	Warship (char * given) {
		
		modelFile = given;
		position = glm::mat4();
		//allocSize = sizeof(vertex) + sizeof(normal) + sizeof(diffuseColorMaterial);
		
		bCam[3][1] = 300.0f;
		bCam[3][2] = -1000.0f;
		
		tCam[3][1] = 300.0f;
		
	}
	
	void update() {
		
		orientation = position * rotation;
		
	}
	
	glm::mat4 getModelMatrix() {
		
		return (position * rotation);
		
	}
	
	void setLocation(float x, float y, float z) {
		
		position[3][0] = x;
		position[3][1] = y;
		position[3][2] = z;
		
	}
	
	float getX () {
		
		return position[3][0];
		
	}
	
	float getY() {
		
		return position[3][1];
		
	}
	
	float getZ() {
		
		return position[3][2];
		
	}
	
	glm::vec3 getEye() {
		
		return getPosition(orientation * bCam);
		
	}
	
	glm::vec3 getEyeAlt() {
		
		return getPosition(orientation * tCam);
		
	}
	
	glm::vec3 getAt() {
		
		return glm::vec3(getX(), getY(), getZ());
		
	}
	
	glm::vec3 getUp() {
		
		glm::vec3 temp = getEye();
		temp[1] += 1.0f;
		
		return temp;
		
	}
	
	glm::vec3 getForward() {
		
		return getOut(orientation);
		
	}
	
};