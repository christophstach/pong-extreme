// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_DEPRECATE

#pragma comment( lib, "OpenGL32.lib" )

#include "targetver.h"

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

// TODO: reference additional headers your program requires here


#include "TextureLoader.h"
#include "ObjectLoader.h"
#include "ShaderLoader.h"
#include "ThreeDimensionalObject.h"
#include "Triangle.h"
#include "Cube.h"
#include "LeftBar.h"
#include "RightBar.h"
#include "Game.h"
