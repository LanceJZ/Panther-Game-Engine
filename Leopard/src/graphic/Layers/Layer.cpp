#include "Layer.h"

namespace Leopard
{
	namespace Graphics
	{
		Layer::Layer()
		{
		}

		Layer::Layer(Renderer2D * renderer, Shader* shader, Matrix projectionMatrix)
			: m_Renderer(renderer), m_Shader(shader), m_PMatrix(projectionMatrix)
		{
			//m_Shader->Enable();
			m_Shader->setUniformMatrix("pr_matrix", m_PMatrix);
			//m_Shader->Disable();
		}

		Layer::~Layer()
		{
			//delete m_Shader;
			delete m_Renderer;

			for (int i = 0; i < m_Renderables.size(); i++)
			{
				delete m_Renderables[i];
			}
		}

		void Layer::Add(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
		}
		void Layer::Draw()
		{
			//m_Shader->Enable();
			m_Renderer->Begin();


			for (const Renderable2D* renderable : m_Renderables)
			{
				m_Renderer->Submit(renderable);
			}

			m_Renderer->End();
			m_Renderer->Flush();
		}
	}
} // done at Ep 11 24:50