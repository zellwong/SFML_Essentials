#version 110

//varying attributes from the vertex shader
varying vec4 vColor;
varying vec2 vTexCoord;

//declare uniforms
uniform sampler2D uTexture;
uniform vec2 uTextureSize;
uniform float uPixelSize;

void main() {
	vec2 pixelSizeNorm = uPixelSize / uTextureSize;
	vec2 texCoord = vTexCoord - mod(vTexCoord, pixelSizeNorm);
	gl_FragColor = vColor * texture2D(uTexture, texCoord);
}

