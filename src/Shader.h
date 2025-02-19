#pragma once

#include "Math.h"
#include <GL/glew.h>
#include <string>

class Shader
{
private:
  // store the shader object IDs
  GLuint m_ShaderProgram;
  GLuint m_VertexShader;
  GLuint m_FragShader;
  std::string name;
public:
  Shader(std::string& name);
  ~Shader();

  // load vertex/ fragment shaders
  bool Load(const std::string& vertName, const std::string& fragName);
  void Unload();
  void SetActive();
  void SetMatrixUniform(const char* name, const Matrix4& matrix);
  void SetMatrixUniforms(const char* name, Matrix4* matrices, unsigned count);
  void SetVectorUniform(const char* name, const Vector3& vector);
  void SetFloatUniform(const char* name, float value);

  const std::string& GetShaderName() const;
private:
  // compile specified shader
  bool CompileShader(const std::string& fileName, GLenum shaderType, GLuint& outShader);
  // test if compiled successfully
  bool IsCompiled(GLuint shader);
  // tests whether vertex / fragment programs link
  bool IsValidProgram();
};
