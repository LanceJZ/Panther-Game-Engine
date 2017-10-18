#include "Renderable2D.h"

namespace Leopard
{
	namespace Graphics
	{
		Renderable2D::Renderable2D(Vector3f position, Vector2f size, Vector4f color)
			: m_Position(position), m_Size(size), m_Color(color)
		{
			SetUVDefaults();
		}

		Renderable2D::Renderable2D()
		{
			SetUVDefaults();
		}

		void Renderable2D::SetUVDefaults()
		{
			m_UV.push_back(Vector2f(0, 0));
			m_UV.push_back(Vector2f(0, 1));
			m_UV.push_back(Vector2f(1, 1));
			m_UV.push_back(Vector2f(1, 0));
		}

		Renderable2D::~Renderable2D()
		{
		}

		void Renderable2D::Submit(Renderer2D * renderer) const
		{
			renderer->Submit(this);
		}

	}
}