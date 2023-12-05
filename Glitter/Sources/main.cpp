#define DEBUG 1
#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Headers/helper.h"
#include "../Headers/shader_s.h"
#include <stb_image.h>
#include <filesystem>
#include <iostream>

//jobs to run
Job newjob;

void render_Loop(GLFWwindow *w);
int createWindow();
void initShaders();
void initVertexData();
void initTextures();
void cleanup();

bool wireframe = false;
bool debug = true;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
unsigned int VBO, VAO, EBO;
unsigned int shaderProgram;
unsigned int texture1, texture2;
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
    initTextures();
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
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

// load and create a texture
void initTextures() {
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load("F:/cpp_projects/games/Glitter/Glitter/Textures/brick_wall.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    // texture 2
    // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load("F:/cpp_projects/games/Glitter/Glitter/Textures/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    shader.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
    // or set it via the texture class
    shader.setInt("texture2", 1);
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
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // draw our first triangle
        shader.use();
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 8);                       // Why does this make only the bottom right triangle render? 
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);  // why does this not do anything? 

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
    //glDeleteProgram(shaderProgram);
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}