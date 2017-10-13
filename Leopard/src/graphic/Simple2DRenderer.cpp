#include "Simple2DRenderer.h"

namespace Leopard
{
	namespace Graphics
	{
		Simple2DRenderer::Simple2DRenderer()
		{
		}

		Simple2DRenderer::~Simple2DRenderer()
		{
		}

		void Simple2DRenderer::Submit(const Static_Sprite * renderable)
		{
			m_RenderQueue.push_back(renderable);
		}

		void Simple2DRenderer::Flush()
		{
			while (!m_RenderQueue.empty())
			{
				const Static_Sprite* renderable = m_RenderQueue.front();
				renderable->getVAO()->Bind();
				renderable->getIBO()->Bind();

				renderable->getShader().setUniformMatrix("ml_matrix", Math::Matrix::Translate(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable->getIBO()->Unbind();
				renderable->getVAO()->Unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}