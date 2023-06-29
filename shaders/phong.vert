#version 330 core
layout (location = 0) in vec3 in_pos; // 顶点坐标
layout (location = 1) in vec3 in_normal; // 顶点法向

out vec3 frag_pos;
out vec3 normal;

// uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

uniform float point_size;

void main() {
    gl_PointSize = point_size;
    vec4 pos = P * V * vec4(in_pos, 1.0f);
    frag_pos = vec3(pos);
    gl_Position = pos;
}
