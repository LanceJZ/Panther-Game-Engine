#pragma once

#include <GL\glew.h>
#include "Buffer\Buffer.h"
#include "Buffer\IndexBuffer.h"
#include "Buffer\VertexArray.h"
#include "..\Math\Math.h"
#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Renderer2D
		{
		public:
			Renderer2D();
			~Renderer2D();

			virtual void Submit(const Renderable2D* renderable) = 0;
			virtual void Flush() = 0;
		};

	}
}