#include "Group.h"

namespace Leopard
{
	namespace Graphics
	{
		Group::Group(const Matrix& transform)
			: m_TransformationMatrix(transform)
		{
		}

		Group::~Group()
		{
		}

		void Group::Add(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
		}

		void Group::Submit(Renderer2D * renderer) const
		{
			renderer->Push(m_TransformationMatrix);

			for (const Renderable2D* renderable : m_Renderables)
			{
				renderable->Submit(renderer);
			}

			renderer->Pop();
		}
	}
}