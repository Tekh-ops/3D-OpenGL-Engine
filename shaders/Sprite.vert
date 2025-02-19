// Request GLSL 3.3
#version 330

// Uniforms for world transform and view-proj
uniform mat4 uWorldTransform;
uniform mat4 uViewProj;

// Vertex attributes
layout(location=0) in vec3 inPosition;
layout(location=1) in vec3 inNormal;
layout(location=2) in vec2 inTexCoord;

// Add texture coords as output
out vec2 fragTexCoord;

void main()
{
	vec4 pos = vec4(inPosition, 1.0);
	gl_Position = pos * uWorldTransform * uViewProj;
  fragTexCoord = inTexCoord;
}
