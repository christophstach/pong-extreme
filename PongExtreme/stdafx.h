// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#define STB_IMAGE_IMPLEMENTATION

#pragma comment( lib, "OpenGL32.lib" )

#include "targetver.h"

#include <new>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <fstream>

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "corecrt_math_defines.h"


// TODO: reference additional headers your program requires here

//

#include "Vao.h"
#include "Texture.h"
#include "ObjectDefinition.h"
#include "ObjectLoader.h"
#include "TextureLoader.h"
#include "ShaderLoader.h"
#include "ThreeDimensionalObject.h"
#include "ThreeDimensional.h"
#include "Triangle.h"
#include "Cube.h"
#include "Lamp.h"
#include "Arena.h"
#include "LeftBar.h"
#include "RightBar.h"
#include "Sphere.h"
#include "Ball.h"
#include "Game.h"
