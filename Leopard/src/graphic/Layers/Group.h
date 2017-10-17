#pragma once

#include "..\Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Group : public Renderable2D
		{
		private:
			std::vector<Renderable2D*> m_Renderables;
			Matrix m_TransformationMatrix;

		public:
			Group(const Matrix& transform);
			~Group();

			void Add(Renderable2D* renderable);
			void Submit(Renderer2D* renderer) const override;
		};
	}
}