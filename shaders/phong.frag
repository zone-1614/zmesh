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

void main() {
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
    frag_color = vec4(all_color, 1.0);
}
