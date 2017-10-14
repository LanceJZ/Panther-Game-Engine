#pragma once

#include "..\Renderable2D.h"
#include "..\BatchedRenderer2D.h"
#include "..\..\Math\Math.h"

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Layer
		{
		protected:
			Renderer2D * m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			Matrix m_PMatrix;

		public:
			Layer();
			virtual void Add(Renderable2D* renderable);
			virtual void Draw();
		protected:
			Layer(Renderer2D* renderer, Shader* shader, Matrix projectionMatrix);
			virtual ~Layer();


		};

	}
}