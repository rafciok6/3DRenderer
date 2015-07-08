#version 150 core

uniform mat4 modelview, projection;

in vec4 position;
in vec4 inColour;

out vec4 outColour;

void main()
{	
	gl_Position = projection*modelview*position;

	outColour = inColour;
}
