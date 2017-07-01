#pragma once

#include "Window.h"
#include "OpenGL.h"
#include "Egl.h"

//#include <GLES2/gl2.h>


#include <map>

enum class SceneMode
{
    Cube = 0,
    Quad
};


class Scene
{
	WindowBase* window;
    GLuint yTexture = 0;
    //GLuint vuTexture = 0;
    int width = 0;
    int height = 0;
    int cropX;
    int cropY;
    int cropWidth;
    int cropHeight;
    GLint wvpUniformLocation = -1;
    GLint textureScaleUniform = -1;
    GLint textureOffsetUniform = -1;
    float rotX = 0;
    float rotY = 0;
    float rotZ = 0;
    SceneMode sceneMode = SceneMode::Quad; //SceneMode::Cube;

    static const float quadx[];
    static const float texCoords[];

    static const float quad[];
    static const float quadUV[];

	void* frame = nullptr;
	void* frame2 = nullptr;

	std::map<int, GLuint> dmabufMap;


	GLuint GetTexutreForDmabuf(int dmafd, int dmafd2);


public:

    SceneMode GetSceneMode() const
    {
        return sceneMode;
    }
    void SetSceneMode(SceneMode value)
    {
        sceneMode = value;
    }



    Scene(WindowBase* window)
		: window(window)
    {
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		OpenGL::CheckError();

		window->SwapBuffers();
    }
	


    void Load();
	
	void SetTextureProperties(int width, int height, int cropX, int cropY, int cropWidth, int cropHeight)
	{
		this->width = width;
		this->height = height;
		this->cropX = cropX;
		this->cropY = cropY;
		this->cropWidth = cropWidth;
		this->cropHeight = cropHeight;
	}
	
    void Draw(int yData, int vuData);

};

