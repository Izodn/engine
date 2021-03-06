#include "TestGL.hpp"

#include "SOIL/SOIL.h"

#include "../GameObject.hpp"

void TestGL::RenderStart(Renderer* renderer)
{
	// Window dimensions
	m_Window = m_GameObject->GetLevel()->GetGame()->GetWindow();

	// Reference the GameObject's position
	m_Position = m_Transform->GetPosition();

	// Reference the quaternion in the form of angle & axis for GL
	m_Rotation = m_Transform->GetRotation();

	if (dynamic_cast<OpenGLRenderer*>(renderer)) {
		OpenGLRenderer* glRenderer = (OpenGLRenderer*) renderer;

		if (dynamic_cast<OpenGLShader*>(m_Shader)) {
			OpenGLShader* glShader = (OpenGLShader*) m_Shader;

			// Set up vertex data (and buffer(s)) and attribute pointers
			GLfloat vertices[] = {
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
				 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
			};

			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
				glBufferData(
					GL_ARRAY_BUFFER,
					sizeof(vertices),
					vertices,
					GL_STATIC_DRAW
				);

				// Position attribute
				glVertexAttribPointer(
					0,
					3,
					GL_FLOAT,
					GL_FALSE,
					5 * sizeof(float),
					(GLvoid*)0
				);
				glEnableVertexAttribArray(0);

				// TexCoord attribute
				glVertexAttribPointer(
					1,
					2,
					GL_FLOAT,
					GL_FALSE,
					5 * sizeof(float),
					(GLvoid*)(3 * sizeof(GLfloat))
				);
				glEnableVertexAttribArray(1);

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

			// Transformations
			glm::mat4 view;
			m_View = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
			m_Projection = glm::perspective(
				45.0f,
				(GLfloat)m_Window->GetWidth() / (GLfloat)m_Window->GetHeight(),
				0.1f,
				100.0f
			);

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
			GLuint shader = ((OpenGLShader*) m_Shader)->GetId();
			Vector3 axis = m_Rotation->GetAxis();
			double angle = m_Rotation->Angle();

			glUseProgram(shader);

			// Texture 1
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_Texture1);
			glUniform1i(
				glGetUniformLocation(shader, "ourTexture1"),
				0
			);

			// Texture 2
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, m_Texture2);
			glUniform1i(
				glGetUniformLocation(shader, "ourTexture2"),
				1
			);


			// Get their uniform location
			GLint modelLoc = glGetUniformLocation(shader, "model");
			GLint viewLoc = glGetUniformLocation(shader, "view");
			GLint projLoc = glGetUniformLocation(shader, "projection");

			// Pass the matrices to the shader
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(m_View));

			glUniformMatrix4fv(
				projLoc,
				1,
				GL_FALSE,
				glm::value_ptr(m_Projection)
			);

			glBindVertexArray(m_VAO);
			{
				/*
				 * Calculate the model matrix for each object and pass it to
				 * shader before drawing
				 */
				glm::mat4 model;
				model = glm::translate(
					model,
					glm::vec3(
						(GLdouble)m_Position->GetX(),
						(GLdouble)m_Position->GetY(),
						(GLdouble)m_Position->GetZ()
					)
				);
				model = glm::rotate(
					model,
					(GLfloat)angle,
					glm::vec3(
						(GLfloat)axis.GetX(),
						(GLfloat)axis.GetY(),
						(GLfloat)axis.GetZ()
					)
				);
				glUniformMatrix4fv(
					modelLoc,
					1,
					GL_FALSE,
					glm::value_ptr(model)
				);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			glBindVertexArray(0);

		} else {
			std::cout << "Unexpected shader type. Cannot render." << std::endl;
		}
	} else {
		std::cout << "Unexpected renderer type. Cannot render." << std::endl;
	}
}