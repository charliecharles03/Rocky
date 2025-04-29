#include <iostream>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>  
#include <math.h>

const char *vertexShaderSource ="#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"   ourColor = aColor;\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0);\n"
"}\n\0";


float myFloat = 0.5f;

typedef struct{
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
} dummy;



GLFWwindow* windowMaker(){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "dumb triangle", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    return window;
}

GLuint createVertexShader(){
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    return vertexShader;
}

GLuint createFragmentShader(){
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    return fragmentShader;
}

dummy bufferCreator(float vertices[], int verticesArraySize, unsigned int indices[], int indicesArraySize){
    dummy buffers;

    glGenVertexArrays(1, &buffers.vao);
    glGenBuffers(1, &buffers.vbo);
    glGenBuffers(1, &buffers.ebo);
    glBindVertexArray(buffers.vao);

    glBindBuffer(GL_ARRAY_BUFFER,buffers.vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesArraySize , vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesArraySize ,indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    return buffers;
}


int main()
{

    // creating GLFW window 
    GLFWwindow* window = windowMaker();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }
    glViewport(0, 0, 800, 800);


    GLuint vertexShader = createVertexShader();
    GLuint fragmentShader = createFragmentShader();


    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        0.0f,  0.0f, 0.0f,  0.0f, 0.0f, 1.0f,      //0
        +0.5f, +0.5f, 0.0f,  0.0f, 1.0f, 0.0f,    // 2
        -0.5f, +0.5f, 0.0f,  1.0f, 0.0f, 0.0f,    //1
        -0.5f,  -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    //3
        +0.5f,  -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    //4
    };   

    unsigned int indices[] = {  
        0, 1, 2,  
        1, 0, 4   
    };

    dummy bufferResponse =  bufferCreator(vertices,sizeof(vertices),indices,sizeof(indices));

    glBindVertexArray(0); 
    double previousTime = glfwGetTime();
    int frameCount = 0;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(bufferResponse.vao);
        glDrawArrays(GL_TRIANGLES,0,6);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }



    glDeleteVertexArrays(1, &bufferResponse.vao);
    glDeleteBuffers(1, &bufferResponse.vbo);
    glDeleteBuffers(1,&bufferResponse.ebo);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate(); return 0;
}
