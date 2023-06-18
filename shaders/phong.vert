#version 330 core
layout (location = 0) in vec3 in_pos; // 顶点坐标
layout (location = 1) in vec3 in_normal; // 顶点法向

out vec3 frag_pos;
out vec3 normal;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

void main() {
    frag_pos = vec3(M * vec4(in_pos, 1.0));
    normal = mat3(transpose(inverse(M))) * normal;
    gl_Position = P * V * vec4(frag_pos, 1.0);
}
