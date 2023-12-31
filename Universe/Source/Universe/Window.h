// Abstract Window class. This is needed in order to support window from other systems as well, instead of just Windows Window.
// The Create function is implemented in a system dependent way, inside Universe/Platform.
#pragma once
#include "UEpch.h"
#include "Core.h"

namespace Universe {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const std::string& title = "Universe Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Abstract interface. The actual window object must be implemented system dependently
	class UE_API Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Must be implemented per platform
		static Window* Create(const WindowProps& props = WindowProps());
	};
}