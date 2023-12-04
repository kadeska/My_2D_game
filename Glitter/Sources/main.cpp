#define DEBUG 1
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Headers/helper.h"
#include "../Headers/shader_s.h"
#include <filesystem>
#include <iostream>

//jobs to run
Job newjob;

void render_Loop(GLFWwindow *w);
int createWindow();
void initShaders();
void initVertexData();
void cleanup();

bool wireframe = true;
bool debug = true;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
unsigned int VBO, VAO, EBO;
unsigned int shaderProgram;
GLFWwindow* window;

myShader shader;

//namespace fs = std::filesystem; why cant i use this?

int main()
{
#ifdef DEBUG
    Timer timer;
#endif // DEBUG
    if (debug) {
        print_C(":DEBUG: ");
        print("Starting\n");
    }
    
    print_C("Starting main thread id=");
    std::cout << std::this_thread::get_id() << "\n";

    newjob = Job();
    startThreadedJob(newjob);

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    createWindow();
    initShaders();
    initVertexData();
    // draw in wireframe polygons.
    if (wireframe) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
    render_Loop(window);
    cleanup();
    
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw window creation
int createWindow() {
#ifdef DEBUG
    Timer timer;
#endif // DEBUG
    if (debug) {
        print_C(":DEBUG: ");
        print("Creating window\n");
    }
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
}
//namespace fs = std::filesystem;
// build and compile our shader program
void initShaders() {
#ifdef DEBUG
    Timer timer;
#endif // DEBUG
    if (debug) {
        print_C(":DEBUG: ");
        print("Setting up shaders\n");
    }
    //std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    //fs::current_path(fs::temp_directory_path()); // (3)
    //std::cout << "Current path is " << fs::current_path() << '\n';
    shader = myShader("F:/cpp_projects/games/Glitter/Glitter/Shaders/vertShader.vert", "F:/cpp_projects/games/Glitter/Glitter/Shaders/fragShader.frag");
}
// set up vertex data (and buffer(s)) and configure vertex attributes
void initVertexData() {
#ifdef DEBUG
    Timer timer;
#endif // DEBUG
    if (debug) {
        print_C(":DEBUG: ");
        print("Setting up vertex data and buffer(s) and configuring vertex attributes\n");
    }
    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };
 //   unsigned int indices[] = {  // note that we start from 0!
 //       0, 1, 3,  // first Triangle
 //       1, 2, 3   // second Triangle
 //   };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    //glBindVertexArray(0);
}



// render loop
void render_Loop(GLFWwindow *w) {
#ifdef DEBUG
    Timer timer;
#endif // DEBUG

    if (debug) {
        print_C(":DEBUG: ");
        print("Entering render loop...\n");
    }
    while (!glfwWindowShouldClose(w))
    {
        // input
        processInput(w);

        // render
        glClearColor(0.2f, 0.2f, 0.3f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        //glUseProgram(shaderProgram);
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(w);
        glfwPollEvents();
    }
}

// de-allocate all resources once they've outlived their purpose, 
// and clearing all previously allocated GLFW resources.
void cleanup() {
#ifdef DEBUG
    Timer timer;
#endif // DEBUG
    if (debug) {
        print_C(":DEBUG: ");
        print("Cleaning up\n");
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}