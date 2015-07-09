#version 150 core

uniform sampler2D tex; 
uniform vec2 screenSize; 

in vec4 outColour;
out vec4 outFrag;

void main()
{
	outFrag = texture(tex, (gl_FragCoord.xy / screenSize)) * outColour;
}
