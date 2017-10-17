#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		Renderable2D::Renderable2D(Vector3f position, Vector2f size, Vector4f color)
			: m_Position(position), m_Size(size), m_Color(color)
		{
		}

		Renderable2D::~Renderable2D()
		{
		}

		void Renderable2D::Submit(Renderer2D * renderer) const
		{
			renderer->Submit(this);
		}

		Renderable2D::Renderable2D()
		{
		}
	}
}