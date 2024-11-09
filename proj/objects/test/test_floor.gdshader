shader_type spatial;

vec3 palette(float t) {
	vec3 a = vec3(0.5, 0.5, 0.5);
	vec3 b = vec3(0.5, 0.5, 0.5);
	vec3 c = vec3(1.0, 1.0, 1.0);
	vec3 d = vec3(0.263, 0.416, 0.557);

	return a + b * abs(TAU * (c * t + d));
}

void fragment() {
	vec2 uv = (UV - 0.5) * 2.0;

	uv *= 16.0;
	uv = fract(uv);

	float d = length(uv);

	vec3 col = palette(d);
	d = 0.01 / d;

	col *= d;

	SPECULAR = 0.0;
	METALLIC = 0.0;
	ROUGHNESS = 0.0;
	ALBEDO = vec3(0.1, 0.0, 0.0);
}

//void light() {
	// Called for every pixel for every light affecting the material.
	// Uncomment to replace the default light processing function with this one.
//}
