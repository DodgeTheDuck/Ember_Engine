
#version 400
#extension GL_ARB_explicit_uniform_location : require

layout(location = 0) in vec4 vertex_position;
layout(location = 1) in vec4 vertex_colour;

uniform mat4 MVP;

out vec4 colour;
out vec2 texCoord;
in vec2 vertTexCoord;

void main () {
	colour = vertex_colour;
	texCoord = vertTexCoord;
	gl_Position = vertex_position * MVP;
}