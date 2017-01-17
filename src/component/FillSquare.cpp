#include "FillSquare.hpp"

void FillSquare::RenderUpdate(Renderer* renderer)
{
	if (dynamic_cast<OpenGLRenderer*>(renderer)) {
		OpenGLRenderer* glRenderer = (OpenGLRenderer*) renderer;

		if (dynamic_cast<OpenGLShader*>(m_Shader)) {
			OpenGLShader* glShader = (OpenGLShader*) m_Shader;

			// Vertex vertices
			float vertices[] = {
				-0.5f,  0.5f,  0.0f, // Top-left
				 0.5f,  0.5f,  0.0f, // Top-right
				 0.5f, -0.5f,  0.0f, // Bottom-right
				-0.5f, -0.5f,  0.0f  // Bottom-left
			};
			GLuint indices[] = {
				0, 1, 2, // First triangle
				0, 2, 3  // Second triangle
			};

			GLuint VBO, VAO, EBO;
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			glBindVertexArray(VAO);
			{
				glBindBuffer(GL_ARRAY_BUFFER, VBO);
				glBufferData(
					GL_ARRAY_BUFFER,
					sizeof(vertices),
					vertices,
					GL_STATIC_DRAW
				);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
				glBufferData(
					GL_ELEMENT_ARRAY_BUFFER,
					sizeof(indices),
					indices,
					GL_STATIC_DRAW
				);

				glVertexAttribPointer(
					0,
					3,
					GL_FLOAT,
					GL_FALSE,
					3 * sizeof(float),
					(GLvoid*)0
				);
				glEnableVertexAttribArray(0);
			}
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			glBindVertexArray(VAO);
			{
				glUseProgram(glShader->GetId());
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			}
			glBindVertexArray(0);

			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);

		} else {
			std::cout << "Unexpected shader type. Cannot render." << std::endl;
		}
	} else {
		std::cout << "Unexpected renderer type. Cannot render." << std::endl;
	}
}