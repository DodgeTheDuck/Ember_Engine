
#version 400

uniform sampler2D texture;
in vec4 colour;
in vec2 texCoord;
out vec4 frag_colour;

void main () {
    vec4 tex = texture2D( texture, texCoord );
	frag_colour = colour * tex;
}