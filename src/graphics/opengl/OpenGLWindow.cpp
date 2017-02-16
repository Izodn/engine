#include "OpenGLWindow.hpp"

OpenGLWindow::OpenGLWindow(int width, int height, std::string title)
{
	m_Width = width;
	m_Height = height;
	m_Title = title;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
	if (m_Window == nullptr) {
		Logger() << "Failed to create GLFW window" << "\n";
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_Window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		Logger() << "Failed to initialize GLEW" << "\n";
	}

	glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
	glViewport(0, 0, m_Width, m_Height);
	glEnable(GL_DEPTH_TEST);

	glfwSwapInterval(0);

	OpenGLRenderer* renderer = new OpenGLRenderer();
	renderer->SetWindow(m_Window);
	SetRenderer(renderer);
}

void OpenGLWindow::SetRenderer(Renderer* renderer)
{
	m_Renderer = (OpenGLRenderer*)renderer;
}

Renderer* OpenGLWindow::GetRenderer()
{
	return m_Renderer;
}

GLFWwindow* OpenGLWindow::GetWindow()
{
	return m_Window;
}

void OpenGLWindow::SetResolution(int width, int height)
{
	m_Width = width;
	m_Height = height;
	glfwSetWindowSize(m_Window, m_Width, m_Height);
	glViewport(0, 0, m_Width, m_Height);
}

int OpenGLWindow::GetWidth()
{
	return m_Width;
}

int OpenGLWindow::GetHeight()
{
	return m_Height;
}

void OpenGLWindow::SetTitle(std::string title)
{
	m_Title = title;
	glfwSetWindowTitle(m_Window, m_Title.c_str());
}
