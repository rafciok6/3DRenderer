#version 150 core

uniform sampler2D tex; 

in vec4 outColour;
out vec4 outFrag;

void main()
{
	outFrag = texture(tex, ivec2(gl_FragCoord.xy), 0);
}
