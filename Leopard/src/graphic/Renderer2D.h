#pragma once

#include <deque>
#include <GL/glew.h>
#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Renderer2D
		{
		protected:
			std::vector<Matrix> m_TransformationStack;
			const Matrix* m_TransformationBack;
		public:
			~Renderer2D();

			void Push(const Matrix& matrix, bool override = false);
			void Pop();
			virtual void Begin() {};
			virtual void Submit(const Renderable2D* renderable) = 0;
			virtual void End() {};
			virtual void Flush() = 0;

		protected: //Inherited class only.
			Renderer2D();
		};

	}
}