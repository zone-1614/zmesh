#version 330 core

out vec4 frag_color;

in vec3 frag_pos;
in vec3 normal;

uniform float ambient;
uniform float diffuse;
uniform float specular;

uniform vec3 front_light_pos;
uniform vec3 back_light_pos;
uniform vec3 front_light_color;
uniform vec3 back_light_color;
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
        vec3 front_ambient_ = ambient * front_light_color;
        vec3 back_ambient_ = ambient * back_light_color;

        vec3 norm = normalize(normal);
        vec3 front_light_dir = normalize(front_light_pos - frag_pos);
        vec3 back_light_dir = normalize(back_light_pos - frag_pos);
        float front_diff = max(dot(norm, front_light_dir), 0.0);
        float back_diff = max(dot(norm, back_light_dir), 0.0);
        vec3 front_diffuse_ = diffuse * front_diff * front_light_color;
        vec3 back_diffuse_ = diffuse * back_diff * back_light_color;

        vec3 view_dir = normalize(view_pos - frag_pos);
        vec3 front_reflect_dir = reflect(-front_light_dir, norm);
        vec3 back_reflect_dir = reflect(-back_light_dir, norm);
        float front_spec = pow(max(dot(view_dir, front_reflect_dir), 0.0), 32);
        float back_spec = pow(max(dot(view_dir, back_reflect_dir), 0.0), 32);
        vec3 front_specular_ = specular * front_spec * front_light_color;
        vec3 back_specular_ = specular * back_spec * back_light_color;

        vec3 front_light_color = front_ambient_ + front_diffuse_ + front_specular_;
        front_light_color = front_light_color * object_color;

        vec3 back_light_color = back_ambient_ + back_diffuse_ + back_specular_;
        back_light_color = back_light_color * object_color;

        frag_color = vec4(front_light_color, 1.0);
    } else {
        frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }
}
