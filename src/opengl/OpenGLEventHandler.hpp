#pragma once

#include <iostream>
#include <unordered_map>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "../core/Input.hpp"
#include "../EventHandler.hpp"
#include "../Game.hpp"

class EventHandler;
class Game;
class Input;

class OpenGLEventHandler : public EventHandler
{
	private:
		GLFWwindow* m_Window = NULL;
		Game* m_Game = NULL;
		const std::unordered_map<uint64_t, Input::Key> m_MouseButtonPairs = {
			{0, Input::Key::MOUSE_ONE},
			{1, Input::Key::MOUSE_TWO}
		};
		const std::unordered_map<uint64_t, Input::Key> m_KeyPairs = {
			{32, Input::Key::KEY_SPACE},

			{340, Input::Key::KEY_LSHIFT},
			{341, Input::Key::KEY_LCTRL},
			{342, Input::Key::KEY_LALT},
			{345, Input::Key::KEY_RCTRL},
			{346, Input::Key::KEY_RALT},

			{262, Input::Key::KEY_RIGHT},
			{263, Input::Key::KEY_LEFT},
			{264, Input::Key::KEY_DOWN},
			{265, Input::Key::KEY_UP},
			{256, Input::Key::KEY_ESCAPE},
			{257, Input::Key::KEY_ENTER},
			{258, Input::Key::KEY_TAB},
			{259, Input::Key::KEY_BACKSPACE},

			{48, Input::Key::KEY_0},
			{49, Input::Key::KEY_1},
			{50, Input::Key::KEY_2},
			{51, Input::Key::KEY_3},
			{52, Input::Key::KEY_4},
			{53, Input::Key::KEY_5},
			{54, Input::Key::KEY_7},
			{55, Input::Key::KEY_7},
			{56, Input::Key::KEY_8},
			{57, Input::Key::KEY_9},

			{65, Input::Key::KEY_A},
			{66, Input::Key::KEY_B},
			{67, Input::Key::KEY_C},
			{68, Input::Key::KEY_D},
			{69, Input::Key::KEY_E},
			{70, Input::Key::KEY_F},
			{71, Input::Key::KEY_G},
			{72, Input::Key::KEY_H},
			{73, Input::Key::KEY_I},
			{74, Input::Key::KEY_J},
			{75, Input::Key::KEY_K},
			{76, Input::Key::KEY_L},
			{77, Input::Key::KEY_M},
			{78, Input::Key::KEY_N},
			{79, Input::Key::KEY_O},
			{80, Input::Key::KEY_P},
			{81, Input::Key::KEY_Q},
			{82, Input::Key::KEY_R},
			{83, Input::Key::KEY_S},
			{84, Input::Key::KEY_T},
			{85, Input::Key::KEY_U},
			{86, Input::Key::KEY_V},
			{87, Input::Key::KEY_W},
			{88, Input::Key::KEY_X},
			{89, Input::Key::KEY_Y},
			{90, Input::Key::KEY_Z}
		};

	public:
		static OpenGLEventHandler* Self();
		static void stMouseButtonCallback(GLFWwindow*, int, int, int);
		static void stKeyCallback(GLFWwindow*, int, int, int, int);

	public:
		void MouseButtonCallback(int, int);
		void KeyCallback(int, int);
		void SetWindow(GLFWwindow*);
		void SetGame(Game*);
		void Register();
		void PollEvents();
};