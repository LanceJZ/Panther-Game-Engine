#pragma once

#include "Renderer2D.h"
#include "Sprite.h"

namespace Leopard
{
	namespace Graphics
	{
#define RENDERER_MAX_SPRITES 10000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

		using namespace Math;

		class BatchedRenderer2D// : Renderer2D
		{
		private:
			GLuint m_VAO;
			GLuint m_VBO;
			IndexBuffer* m_IBO;
			GLsizei m_IndexCount;
			VertexData* m_Buffer;
		public:
			BatchedRenderer2D();
			~BatchedRenderer2D();

			void Begin();
			void Submit(const Sprite* renderable);
			void End();
			void Flush();
		private:
			void Initialize();
		};

	}
}