#version 330 core

layout (location = 0) out vec4 color;
layout (location = 1) out vec4 colorA;

uniform vec4 setcolor;
uniform vec3 light_pos;

in DATA
{
	vec4 position;
	vec4 color;
} fs_in;

void main()
{
	float intensity = 10.0 / length(fs_in.position.xyz - light_pos);
	colorA = setcolor;
	color = fs_in.color * intensity;
}