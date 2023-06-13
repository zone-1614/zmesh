#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <spdlog/spdlog.h>

namespace zmesh {
namespace gl {

class Shader {
public:
    Shader(
        const std::string& name, 
        const std::string& vertex_path, 
        const std::string& frag_path
    ) : name_(name) {
        std::ifstream vf(vertex_path), ff(frag_path);
        std::stringstream vss, fss;
        vss << vf.rdbuf();
        fss << ff.rdbuf();
        std::string vstr(vss.str()), fstr(fss.str());

        vf.close();
        ff.close();

        // C_STR of vertex string and fragment string
        const char* vcstr = vstr.c_str();
        const char* fcstr = fstr.c_str(); 

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

        ID_ = glCreateProgram();
        glAttachShader(ID_, vs);
        glAttachShader(ID_, fs);
        glLinkProgram(ID_);
        glGetProgramiv(ID_, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID_, 512, nullptr, infoLog);
            spdlog::error("link shader program error. {}", std::string(infoLog));
        }

        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    void use() {
        glUseProgram(ID_);
    }

    unsigned int ID() {
        return ID_;
    }

    std::string& name() {
        return name_;
    }

    void setBool(const std::string& name, bool value) const {
        glUniform1i(glGetUniformLocation(ID_, name.c_str()), (int)value);
    }
    void setInt(const std::string& name, int value) const {
        glUniform1i(glGetUniformLocation(ID_, name.c_str()), value);
    }
    void setFloat(const std::string& name, float value) const {
        glUniform1f(glGetUniformLocation(ID_, name.c_str()), value);
    }
    void setVec2(const std::string& name, const glm::vec2& value) const {
        glUniform2fv(glGetUniformLocation(ID_, name.c_str()), 1, glm::value_ptr(value));
    }
    void setVec2(const std::string& name, float x, float y) const {
        glUniform2f(glGetUniformLocation(ID_, name.c_str()), x, y);
    }
    void setVec3(const std::string& name, const glm::vec3& value) const { 
        glUniform3fv(glGetUniformLocation(ID_, name.c_str()), 1, glm::value_ptr(value)); 
    }
    void setVec3(const std::string& name, float x, float y, float z) const { 
        glUniform3f(glGetUniformLocation(ID_, name.c_str()), x, y, z); 
    }
    void setVec4(const std::string& name, const glm::vec4& value) const { 
        glUniform4fv(glGetUniformLocation(ID_, name.c_str()), 1, glm::value_ptr(value)); 
    }
    void setVec4(const std::string& name, float x, float y, float z, float w) const { 
        glUniform4f(glGetUniformLocation(ID_, name.c_str()), x, y, z, w); 
    }
    void setMat2(const std::string& name, const glm::mat2& mat) const {
        glUniformMatrix2fv(glGetUniformLocation(ID_, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
    }
    void setMat3(const std::string& name, const glm::mat3& mat) const {
        glUniformMatrix3fv(glGetUniformLocation(ID_, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
    }
    void setMat4(const std::string& name, const glm::mat4& mat) const {
        glUniformMatrix4fv(glGetUniformLocation(ID_, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
    }
private:
    unsigned int ID_; //!< the shader program ID
    std::string name_; //!< the name of shader
};

}
}