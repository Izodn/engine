#pragma once

class Renderer
{
	public:
		virtual void Flush() = 0;
		virtual void Cleanup() = 0;
};