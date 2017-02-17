#include "TextureOpenGLShader.hpp"

GLuint TextureOpenGLShader::CompileShader()
{
	const char* vertex_shader =
	"#version 400\n"
	"layout (location = 0) in vec3 position;\n"
	"layout (location = 1) in vec2 texCoord;\n"
	"out vec2 TexCoord;\n"
	"uniform mat4 model;\n"
	"uniform mat4 view;\n"
	"uniform mat4 projection;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = projection * view * model * vec4(position, 1.0f);\n"
	"	TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);\n"
	"}";
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, nullptr);
	glCompileShader(vs);

	const char* fragment_shader =
	"#version 400\n"
	"in vec3 ourColor;\n"
	"in vec2 TexCoord;\n"
	"out vec4 color;\n"
	"uniform sampler2D ourTexture1;\n"
	"uniform sampler2D ourTexture2;\n"
	"void main()\n"
	"{\n"
	"	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);\n"
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