#include "TestGL.hpp"

#include "SOIL/SOIL.h"


void TestGL::RenderStart(Renderer* renderer)
{
	if (dynamic_cast<OpenGLRenderer*>(renderer)) {
		OpenGLRenderer* glRenderer = (OpenGLRenderer*) renderer;

		if (dynamic_cast<OpenGLShader*>(m_Shader)) {
			OpenGLShader* glShader = (OpenGLShader*) m_Shader;

			// Set up vertex data (and buffer(s)) and attribute pointers
			GLfloat vertices[] = {
				// Positions         // Colors          // Texture Coords

				// Top Right
				0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  1.0f, 1.0f,

				// Bottom Right
				0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f,

				// Bottom Left
				-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,

				// Top Left
				-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f
			};
			GLuint indices[] = {
				// First Triangle
				0, 1, 3,

				// Second Triangle
				1, 2, 3
			};

			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);
			glGenBuffers(1, &m_EBO);

			glBindVertexArray(m_VAO);
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
				glBufferData(
					GL_ARRAY_BUFFER,
					sizeof(vertices),
					vertices,
					GL_STATIC_DRAW
				);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
				glBufferData(
					GL_ELEMENT_ARRAY_BUFFER,
					sizeof(indices),
					indices,
					GL_STATIC_DRAW
				);

				// Position attribute
				glVertexAttribPointer(
					0,
					3,
					GL_FLOAT,
					GL_FALSE,
					8 * sizeof(float),
					(GLvoid*)0
				);
				glEnableVertexAttribArray(0);

				// Color attribute
				glVertexAttribPointer(
					1,
					3,
					GL_FLOAT,
					GL_FALSE,
					8 * sizeof(float),
					(GLvoid*)(3 * sizeof(GLfloat))
				);
				glEnableVertexAttribArray(1);

				// TexCoord attribute
				glVertexAttribPointer(
					2,
					2,
					GL_FLOAT,
					GL_FALSE,
					8 * sizeof(float),
					(GLvoid*)(6 * sizeof(GLfloat))
				);
				glEnableVertexAttribArray(2);

			}
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			int width, height;
			unsigned char* image;

			// Texture 1
			glGenTextures(1, &m_Texture1);
			glBindTexture(GL_TEXTURE_2D, m_Texture1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_REPEAT);
			image = SOIL_load_image(
				"container.jpg",
				&width,
				&height,
				0,
				SOIL_LOAD_RGB
			);
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RGB,
				width,
				height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				image
			);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);

			// Texture 2
			glGenTextures(1, &m_Texture2);
			glBindTexture(GL_TEXTURE_2D, m_Texture2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			image = SOIL_load_image(
				"awesomeface.png",
				&width,
				&height,
				0,
				SOIL_LOAD_RGB
			);
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RGB,
				width,
				height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				image
			);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);

		} else {
			std::cout << "Unexpected shader type. Cannot render." << std::endl;
		}
	} else {
		std::cout << "Unexpected renderer type. Cannot render." << std::endl;
	}
}

void TestGL::RenderUpdate(Renderer* renderer)
{
	if (dynamic_cast<OpenGLRenderer*>(renderer)) {
		OpenGLRenderer* glRenderer = (OpenGLRenderer*) renderer;

		if (dynamic_cast<OpenGLShader*>(m_Shader)) {
			OpenGLShader* glShader = (OpenGLShader*) m_Shader;

			glUseProgram(glShader->GetId());

			// Texture 1
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_Texture1);
			glUniform1i(
				glGetUniformLocation(glShader->GetId(), "ourTexture1"),
				0
			);

			// Texture 2
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, m_Texture2);
			glUniform1i(
				glGetUniformLocation(glShader->GetId(), "ourTexture2"),
				1
			);

			glBindVertexArray(m_VAO);
			{
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			}
			glBindVertexArray(0);

		} else {
			std::cout << "Unexpected shader type. Cannot render." << std::endl;
		}
	} else {
		std::cout << "Unexpected renderer type. Cannot render." << std::endl;
	}
}