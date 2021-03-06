// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#define STB_IMAGE_IMPLEMENTATION

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "winmm.lib")

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
#include <chrono>

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <playsoundapi.h>

#include "corecrt_math_defines.h"


// TODO: reference additional headers your program requires here

//

#include "Vao.h"
#include "Tao.h"
#include "WaveSound.h"
#include "BoundingBox.h"
#include "ObjectDefinition.h"
#include "ObjectLoader.h"
#include "TextureLoader.h"
#include "ShaderLoader.h"
#include "ThreeDimensionalObject.h"
#include "GameObject.h"
#include "Text.h"
#include "NumberLeft.h"
#include "NumberRight.h"
#include "ArenaBoundaryTop.h"
#include "ArenaBoundaryRight.h"
#include "ArenaBoundaryBottom.h"
#include "ArenaBoundaryLeft.h"
#include "Floor.h"
#include "LeftBar.h"
#include "RightBar.h"
#include "Ball.h"
#include "Game.h"
