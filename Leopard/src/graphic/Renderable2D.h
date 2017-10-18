#pragma once

#include "Shader.h"
#include "Buffer/Buffer.h"
#include "Buffer/IndexBuffer.h"
#include "Buffer/VertexArray.h"
#include "Texture.h"
#include "Renderer2D.h"

namespace Leopard
{
	namespace Graphics
	{
		struct VertexData
		{
			Vector3f Vertex;
			Vector2f UV;
			float TID;
			unsigned int Color;
		};

		using namespace Math;

		class Renderable2D
		{
		protected:
			Vector3f m_Position; // TODO Move to PositionedObject class or turn this into one.
			Vector2f m_Size;
			Vector4f m_Color;
			std::vector<Vector2f> m_UV;
			Texture* m_Texture;

		public:
			Renderable2D(Vector3f position, Vector2f size, Vector4f color);
			virtual ~Renderable2D();

			virtual void Submit(Renderer2D* renderer)const ;

			inline const Vector3f& getPosition() const { return m_Position; }
			inline const Vector2f& getSize() const { return m_Size; }
			inline const std::vector<Vector2f>& getUV() const { return m_UV; }
			inline const Vector4f& getColor() const { return m_Color; }

			inline void setTexture(Texture * texture) { m_Texture = texture; }
			inline const Texture* getTexture() const { return m_Texture; }
			inline const GLuint getTID() const { return m_Texture == nullptr ? NULL : m_Texture->getID(); }
		protected:
			Renderable2D();
		private:
			void SetUVDefaults();
		};

	}
}