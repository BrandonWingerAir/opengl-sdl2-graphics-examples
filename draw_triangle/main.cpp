#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <vector>

// Globals
int gScreenWidth = 640;
int gScreenHeight = 480;

SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false;

GLuint gVertexArrayObject   =   0;
GLuint gVertexBufferObject  =   0;

// Vertex Shader:
// Execute once per vertex and set final position
const std::string gVertexShaderSource =
    "#version 410 core\n"
    "in vec4 position;\n"
    "void main(\n)"
    "{\n"
    "   gl_Position = vec4(position.x, position.y, position.x, position.z, position.w);\n"
    "}\n";

// Fragment Shader:
// Execute once per fragment (i.e. nearly every pixel that will be rasterized)
// and determine a final color sent to the screen
const std::string gFragmentShaderSource =
    "#version 410 core\n"
    "in vec4 color;\n"
    "void main(\n)"
    "{\n"
    "   color = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
    "}\n";

// Shader Program Object
GLuint gGraphicsPipelineShaderProgram   =   0;

GLuint CompileShader(GLuint type, const std::string& source) {
    GLuint shaderObject;

    if (type == GL_VERTEX_SHADER) {
        shaderObject = glCreateShader(GL_VERTEX_SHADER);
    } else if (type == GL_FRAGMENT_SHADER) {
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    const char* src = source.c_str();
    glShaderSource(shaderObject, 1, &src, nullptr);
    glCompileShader(shaderObject);

    return shaderObject;
}

GLuint CreateShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
    GLuint programObject = glCreateProgram();

    GLuint myVertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    glAttachShader(programObject, myVertexShader);
    glAttachShader(programObject, myFragmentShader);
    glLinkProgram(programObject);

    glValidateProgram(programObject);

    return programObject;
};

void CreateGraphicsPipeline() {
    gGraphicsPipelineShaderProgram = CreateShaderProgram(gVertexShaderSource, gFragmentShaderSource);
}

void VertexSpecification(){
    // Handled on CPU
    const std::vector<GLfloat> vertexPosition {
        // x, y, z
        -0.8f, -0.8f, 0.0f,
        0.8f, -0.8f, 0.0f,
        0.0f, 0.8f, 0.0f
    };

    // Handled on GPU
    glGenVertexArrays(1, &gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);

    // Generate Vertex Buffer Object
    glGenBuffers(1, &gVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER,
                 vertexPosition.size() * sizeof(GLfloat),
                 vertexPosition.data(),
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (void*)0
            );

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
}

void InitializeProgram() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL2 could not initialize video subsystem"
                  << std::endl;
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    gGraphicsApplicationWindow = SDL_CreateWindow("OpenGL SDL2 Demo - Window Test",
                                                  10, 35, 
                                                  gScreenWidth, gScreenHeight, 
                                                  SDL_WINDOW_OPENGL);

    if (gGraphicsApplicationWindow == nullptr) {
        std::cout << "SDL_Window was not able to be created" << std::endl;
        exit(1);
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

    if (gOpenGLContext == nullptr) {
        std::cout << "OpenGL context not available\n";
        exit(1);
    }

    // Initialize Glad Library
    if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        std::cout << "Glad was not initialized!" << std::endl;
        exit(1);
    }
}

void Input() {
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            std::cout << "Goodbye!" << std::endl;
            gQuit = true;
        }
    }
}

void PreDraw() {

}

void Draw() {

}

void MainLoop() {
    while (!gQuit) {
        Input();
        PreDraw();
        Draw();

        // Update Screen
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);
    }
}

void CleanUp() {
    SDL_DestroyWindow(gGraphicsApplicationWindow);
    SDL_Quit();
}

int main(int, char **) {
    InitializeProgram();

    VertexSpecification();
    CreateGraphicsPipeline();
    MainLoop();

    CleanUp();

    return 0;
}