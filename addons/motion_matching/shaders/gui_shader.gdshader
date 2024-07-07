shader_type canvas_item;
render_mode unshaded;

uniform vec4 scissor_test;

void vertex() {
}

void fragment() {
	if (FRAGCOORD.x < scissor_test.x || FRAGCOORD.x > scissor_test.z ||
		FRAGCOORD.y < scissor_test.y || FRAGCOORD.y > scissor_test.w) {
		discard;
	}
}