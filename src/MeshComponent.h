#pragma once

#include "Component.h"
#include <cstddef>
#include <string>

class MeshComponent : public Component
{
public:
  MeshComponent(class Actor* owner, bool isSkinned = false);
  ~MeshComponent();

  // draw this mesh with provided shader
  virtual void Draw(class Shader* shader);

  // set the mesh/ texture index used by the mesh comp
  virtual void SetMesh(class Mesh* mesh);
  void SetTextureIndex(size_t index);
  const std::string& GetShaderName() const;

  void SetVisible(bool visible) { m_Visible = visible; }
	bool GetVisible() const { return m_Visible; }

  bool IsSkeletal() const;
protected:
  class Mesh* m_Mesh;
  size_t m_TextureIndex;
private:
  bool m_IsSkeletal;
  bool m_Visible;
};
