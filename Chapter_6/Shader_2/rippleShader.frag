#version 110

//varying attributes from the vertex shader
varying vec4 vColor;
varying vec2 vTexCoord;

//declare uniforms
uniform sampler2D uTexture;
uniform float uPositionFreq;
uniform float uSpeed;
uniform float uStrength;
uniform float uTime;

void main() {
	vec2 texCoord = vTexCoord;
	float coef = sin(gl_FragCoord.x * uPositionFreq + uSpeed * uTime);
	texCoord.y +=  coef * uStrength;
	gl_FragColor = vColor * texture2D(uTexture, texCoord);
}

