#pragma once

class Renderer
{
	public:
		enum Type {OPENGL, VULKAN};

	public:
		virtual void Cleanup() = 0;
};