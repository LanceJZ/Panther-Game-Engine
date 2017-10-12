#pragma once

#include <deque>
#include <GL\glew.h>
#include "Buffer\Buffer.h"
#include "Buffer\IndexBuffer.h"
#include "Buffer\VertexArray.h"
#include "..\Math\Math.h"
#include "Renderer2D.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Simple2DRenderer : public Renderer2D
		{
		private:
			std::deque<const Renderable2D*> m_RenderQueue;
		public:
			Simple2DRenderer();
			~Simple2DRenderer();

			void Submit(const Renderable2D* renderable) override;
			void Flush() override;

		};

	}
}