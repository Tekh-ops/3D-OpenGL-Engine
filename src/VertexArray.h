#pragma once

class VertexArray
{
public:
  enum Layout { PosNormTex, PosNormSkinTex };

  VertexArray(const void* verts
    , unsigned int numVerts
    , const unsigned int* indices
    , unsigned int numIndices
    , Layout layout
  );
  ~VertexArray();

  // activate this vertex array so it can be drawn
  void SetActive();
  unsigned int GetNumIndices() const;
  unsigned int GetNumVertices() const;

private:
  unsigned int m_NumVerts;
  unsigned int m_NumIndices;
  unsigned int m_VertexBuffer; // OpenGL ID of vertex buffer
  unsigned int m_IndexBuffer;  // OpenGL ID of index buffer
  unsigned int m_VertexArray;  // OpenGL ID of vertex array obj
};
