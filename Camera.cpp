
# ifndef __INCLUDES465__
# include "../includes465/include465.hpp"
# define __INCLUDES465__
# endif

class Camera {
	
private:
	
	glm::vec3 eye, at, up;
	
public:
	
	Camera () {
		
		eye = glm::vec3(0.0f, 0.0f, 0.0f);
		at = glm::vec3(0.0f, 0.0f, 0.0f);
		up = glm::vec3(0.0f, 0.0f, 0.0f);
		
	}
	
	
	
};