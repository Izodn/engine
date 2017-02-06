#include "TextureOpenGLShader.hpp"

GLuint TextureOpenGLShader::CompileShader()
{
	const char* vertex_shader =
	"#version 400\n"
	"layout (location = 0) in vec3 position;"
	"layout (location = 1) in vec3 color;"
	"layout (location = 2) in vec2 texCoord;"
	"out vec3 ourColor;"
	"out vec2 TexCoord;"
	"void main()"
	"{"
	"	gl_Position = vec4(position, 1.0f);"
	"	ourColor = color;"
	"	TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);"
	"}";
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, nullptr);
	glCompileShader(vs);

	const char* fragment_shader =
	"#version 400\n"
	"in vec3 ourColor;"
	"in vec2 TexCoord;"
	"out vec4 color;"
	"uniform sampler2D ourTexture1;"
	"uniform sampler2D ourTexture2;"
	"void main()"
	"{"
	"	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);"
	"}";
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, nullptr);
	glCompileShader(fs);

	GLuint shaderId = glCreateProgram();
	glAttachShader(shaderId, vs);
	glAttachShader(shaderId, fs);
	glLinkProgram(shaderId);
	Logger() << "shaderId: " << shaderId << "\n";
	return shaderId;
}