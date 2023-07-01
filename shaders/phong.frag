#version 330 core

out vec4 frag_color;

in vec3 frag_pos;
in vec3 normal;

uniform float ambient;
uniform float diffuse;
uniform float specular;

uniform vec3 light_pos;
uniform vec3 light_color;
uniform vec3 object_color;
uniform vec3 view_pos;

// 是否开启phongshading, 画点云和wireframe的时候设置为false
uniform bool enable_shading;
// 点的颜色
uniform vec4 point_color;
// wireframe的颜色
uniform vec4 wireframe_color;

void main() {
    if (enable_shading) {
        vec3 ambient_ = ambient * light_color;

        vec3 norm = normalize(normal);
        vec3 light_dir = normalize(light_pos - frag_pos);
        float diff = max(dot(norm, light_dir), 0.0);
        vec3 diffuse_ = diffuse * diff * light_color;

        vec3 view_dir = normalize(view_pos - frag_pos);
        vec3 reflect_dir = reflect(-light_dir, norm);
        float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
        vec3 specular_ = specular * spec * light_color;

        vec3 all_color = ambient_ + diffuse_ + specular_;
        all_color = all_color * object_color;
        frag_color = vec4(all_color, 1.0);
    } else {
        frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }
}
