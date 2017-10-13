#pragma once

#include <deque>
#include <GL\glew.h>

#include "Static_Sprite.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Simple2DRenderer
		{
		private:
			std::deque<const Static_Sprite*> m_RenderQueue;
		public:
			Simple2DRenderer();
			~Simple2DRenderer();

			void Submit(const Static_Sprite* renderable);
			void Flush();

		};

	}
}