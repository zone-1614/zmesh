#pragma once

#include <string>
#include <filesystem>
#include <sstream>
#include <fstream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <spdlog/spdlog.h>

namespace zmesh {
namespace gl {

class Shader {
public:
    Shader(
        std::filesystem::path vertex_shader_path,
        std::filesystem::path fragment_shader_path
    ) {
        if (!std::filesystem::exists(vertex_shader_path)) {
            auto abs = std::filesystem::absolute(vertex_shader_path).string();
            spdlog::error("path {} not exist", abs);
        }
        if (!std::filesystem::exists(fragment_shader_path)) {
            auto abs = std::filesystem::absolute(fragment_shader_path).string();
            spdlog::error("path {} not exist", abs);
        }
        std::ifstream vf(vertex_shader_path.string()), 
            ff(fragment_shader_path.string());
        std::stringstream vss, fss;
        vss << vf.rdbuf();
        fss << ff.rdbuf();
        vf.close();
        ff.close();
        auto vstr = vss.str(), fstr = fss.str();
        const char* vcstr = vstr.c_str(), *fcstr = fstr.c_str();
        // const char* v_cstr = vss.str().c_str();
        // const char* f_cstr = fss.str().c_str();

        unsigned int vs, fs;
        int success;
        char infoLog[512];

        vs = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vs, 1, &vcstr, nullptr);
        glCompileShader(vs);
        glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vs, 512, nullptr, infoLog);
            spdlog::error("compile vertex shader error. {}", std::string(infoLog));
        }

        fs = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fs, 1, &fcstr, nullptr);
        glCompileShader(fs);
        glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fs, 512, nullptr, infoLog);
            spdlog::error("compile fragment shader error. {}", std::string(infoLog));
        }

        program_id_ = glCreateProgram();
        glAttachShader(program_id_, vs);
        glAttachShader(program_id_, fs);
        glLinkProgram(program_id_);
        glGetProgramiv(program_id_, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program_id_, 512, nullptr, infoLog);
            spdlog::error("link shader program error. {}", std::string(infoLog));
        }

        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    void use() {
        glUseProgram(program_id_);
    }

    void set_bool(std::string name, bool value) const {
        glUniform1i(glGetUniformLocation(program_id_, name.c_str()), (int)value);
    }

    void set_int(std::string name, int value) const {
        glUniform1i(glGetUniformLocation(program_id_, name.c_str()), value);
    }

    void set_float(std::string name, float value) const {
        glUniform1f(glGetUniformLocation(program_id_, name.c_str()), value);
    }

    void set_vec2(std::string name, glm::vec2 value) const {
        glUniform2fv(glGetUniformLocation(program_id_, name.c_str()), 1, glm::value_ptr(value));
    }

    void set_vec3(std::string name, glm::vec3 value) const {
        glUniform3fv(glGetUniformLocation(program_id_, name.c_str()), 1, glm::value_ptr(value));
    }

    void set_vec4(std::string name, glm::vec4 value) const {
        glUniform4fv(glGetUniformLocation(program_id_, name.c_str()), 1, glm::value_ptr(value));
    }

    void set_mat3(std::string name, glm::mat3 value) const {
        glUniformMatrix3fv(glGetUniformLocation(program_id_, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

    void set_mat4(std::string name, glm::mat4 value) const {
        glUniformMatrix4fv(glGetUniformLocation(program_id_, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

private:
    unsigned int program_id_; //!< shader program id 
};

}
}