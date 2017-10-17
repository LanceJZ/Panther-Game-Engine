#pragma once

#include <vector>
#include <deque>
#include <GL/glew.h>
#include "../Math/Math.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Renderable2D;

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