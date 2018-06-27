#include "stdafx.h"
#include "Text.h"
#define STB_TRUETYPE_IMPLEMENTATION  // force following include to generate implementation
#include "lib/stb/stb_truetype.h"

/*
Text::Text(const char * text, int x, int y, int size, TextureLoader * textureLoader, ShaderLoader * shaderLoader)
{
	this->text = text;
	this->x = x;
	this->y = y;
	this->size = size;
	// Initialize texture
	this->vao = this->textureLoader->loadDds("./resources/fonts/holstein.dds");

	// Initialize VBO
	glGenBuffers(1, &this->vertexBuffer);
	glGenBuffers(1, &this->uvBuffer);

	// Initialize Shader
	this->shaderId = this->shaderLoader->load("./resources/shaders/TextVertexShader.vs", "./resources/shaders/TextVertexShader.fs");

	// Initialize uniforms' IDs
	this->uniformId = glGetUniformLocation(this->shaderId, "myTextureSampler");
}
*/

/*
Text * Text::draw()
{
	unsigned int length = strlen(this->text);

	std::vector<glm::vec2> vertices;
	std::vector<glm::vec2> uvs;
	for (unsigned int i = 0; i < length; i++) {

		glm::vec2 vertex_up_left = glm::vec2(this->x + i * this->size, this->y + this->size);
		glm::vec2 vertex_up_right = glm::vec2(this->x + i * this->size + this->size, this->y + this->size);
		glm::vec2 vertex_down_right = glm::vec2(this->x + i * this->size + this->size, this->y);
		glm::vec2 vertex_down_left = glm::vec2(this->x + i * this->size, this->y);

		vertices.push_back(vertex_up_left);
		vertices.push_back(vertex_down_left);
		vertices.push_back(vertex_up_right);

		vertices.push_back(vertex_down_right);
		vertices.push_back(vertex_up_right);
		vertices.push_back(vertex_down_left);

		char character = text[i];
		float uv_x = (character % 16) / 16.0f;
		float uv_y = (character / 16) / 16.0f;

		glm::vec2 uv_up_left = glm::vec2(uv_x, uv_y);
		glm::vec2 uv_up_right = glm::vec2(uv_x + 1.0f / 16.0f, uv_y);
		glm::vec2 uv_down_right = glm::vec2(uv_x + 1.0f / 16.0f, (uv_y + 1.0f / 16.0f));
		glm::vec2 uv_down_left = glm::vec2(uv_x, (uv_y + 1.0f / 16.0f));
		uvs.push_back(uv_up_left);
		uvs.push_back(uv_down_left);
		uvs.push_back(uv_up_right);

		uvs.push_back(uv_down_right);
		uvs.push_back(uv_up_right);
		uvs.push_back(uv_down_left);
	}
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, this->uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	// Bind shader
	glUseProgram(this->shaderId);

	// Bind texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->vao);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(this->uniformId, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// 2nd attribute buffer : uvs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->uvBuffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Draw call
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisable(GL_BLEND);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	//glBindTexture(GL_TEXTURE_2D, 0);

	return this;
}
*/

unsigned char ttf_buffer[1 << 20];
unsigned char temp_bitmap[512 * 512];

stbtt_bakedchar cdata[96]; // ASCII 32..126 is 95 glyphs
GLuint ftex;

Text::Text()
{
	fread(ttf_buffer, 1, 1 << 20, fopen("./resources/fonts/arial.ttf", "rb"));
	stbtt_BakeFontBitmap(ttf_buffer, 0, 32.0, temp_bitmap, 512, 512, 32, 96, cdata); // no guarantee this fits!
																					 // can free ttf_buffer at this point
	glGenTextures(1, &ftex);
	glBindTexture(GL_TEXTURE_2D, ftex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512, 512, 0, GL_ALPHA, GL_UNSIGNED_BYTE, temp_bitmap);
	// can free temp_bitmap at this point
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

Text * Text::print(float x, float y, const char *text)
{
	// assume orthographic projection with units = screen pixels, origin at top left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ftex);
	glBegin(GL_QUADS);
	while (*text) {
		if (*text >= 32 && *text < 128) {
			stbtt_aligned_quad q;
			stbtt_GetBakedQuad(cdata, 512, 512, *text - 32, &x, &y, &q, 1);//1=opengl & d3d10+,0=d3d9
			glTexCoord2f(q.s0, q.t1); glVertex2f(q.x0, q.y0);
			glTexCoord2f(q.s1, q.t1); glVertex2f(q.x1, q.y0);
			glTexCoord2f(q.s1, q.t0); glVertex2f(q.x1, q.y1);
			glTexCoord2f(q.s0, q.t0); glVertex2f(q.x0, q.y1);
		}
		++text;
	}
	glEnd();

	return this;
}
