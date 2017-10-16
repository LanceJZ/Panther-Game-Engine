#include "Renderer2D.h"

namespace Leopard
{
	namespace Graphics
	{
		Renderer2D::Renderer2D()
		{
			m_TransformationStack.push_back(Matrix::Identity());
			m_TransformationBack = &m_TransformationStack.back();
		}

		Renderer2D::~Renderer2D()
		{

		}

		void Renderer2D::Push(const Matrix& matrix, bool override)
		{
			if (override)
				m_TransformationStack.push_back(matrix);
			else
				m_TransformationStack.push_back(m_TransformationStack.back() * matrix);

			m_TransformationBack = &m_TransformationStack.back();
		}

		void Renderer2D::Pop()
		{
			if (m_TransformationStack.size() > 1)
				m_TransformationStack.pop_back();

			m_TransformationBack = &m_TransformationStack.back();
		}
	}
}