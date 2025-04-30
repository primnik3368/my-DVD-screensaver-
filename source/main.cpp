#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include <chrono>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main() 
{
    float vertices[] = {
    // позиция (x, y, z)
        0.029440f, -0.030222f, 0.000000f,
        0.000000f, -0.030222f, 0.000000f,
        0.000000f, 0.000000f, 0.000000f,
        0.029440f, 0.000000f, 0.000000f,
        0.147201f, -0.030222f, 0.000000f,
        0.117761f, -0.030222f, 0.000000f,
        0.117761f, 0.000000f, 0.000000f,
        0.147201f, 0.000000f, 0.000000f,
        -0.088321f, -0.151109f, -0.000000f,
        -0.117761f, -0.151109f, -0.000000f,
        -0.117761f, -0.120887f, -0.000000f,
        -0.088321f, -0.120887f, -0.000000f,
        0.147201f, -0.151109f, 0.000000f,
        0.117761f, -0.151109f, 0.000000f,
        0.117761f, -0.120887f, 0.000000f,
        0.147201f, -0.120887f, 0.000000f,
        -0.088321f, 0.090665f, -0.000000f,
        -0.117761f, 0.090665f, -0.000000f,
        -0.117761f, 0.120887f, -0.000000f,
        -0.088321f, 0.120887f, -0.000000f,
        0.147201f, 0.090665f, 0.000000f,
        0.117761f, 0.090665f, 0.000000f,
        0.117761f, 0.120887f, 0.000000f,
        0.147201f, 0.120887f, 0.000000f,
        -0.029440f, 0.090665f, -0.000000f,
        -0.058881f, 0.090665f, -0.000000f,
        -0.058881f, 0.120887f, -0.000000f,
        -0.029440f, 0.120887f, -0.000000f,
        -0.029440f, -0.151109f, -0.000000f,
        -0.058881f, -0.151109f, -0.000000f,
        -0.058881f, -0.120887f, -0.000000f,
        -0.029440f, -0.120887f, -0.000000f,
        -0.147201f, -0.151109f, -0.000000f,
        -0.176642f, -0.151109f, -0.000000f,
        -0.176642f, -0.120887f, -0.000000f,
        -0.147201f, -0.120887f, -0.000000f,
        -0.147201f, -0.030222f, -0.000000f,
        -0.176642f, -0.030222f, -0.000000f,
        -0.176642f, -0.000000f, -0.000000f,
        -0.147201f, -0.000000f, -0.000000f,
        0.088321f, 0.090665f, 0.000000f,
        0.058881f, 0.090665f, 0.000000f,
        0.058881f, 0.120887f, 0.000000f,
        0.088321f, 0.120887f, 0.000000f,
        0.088321f, -0.151109f, 0.000000f,
        0.058881f, -0.151109f, 0.000000f,
        0.058881f, -0.120887f, 0.000000f,
        0.088321f, -0.120887f, 0.000000f,
        0.206082f, -0.151109f, 0.000000f,
        0.176642f, -0.151109f, 0.000000f,
        0.176642f, -0.120887f, 0.000000f,
        0.206082f, -0.120887f, 0.000000f,
        0.206082f, -0.030222f, 0.000000f,
        0.176642f, -0.030222f, 0.000000f,
        0.176642f, 0.000000f, 0.000000f,
        0.206082f, 0.000000f, 0.000000f,
        0.147201f, 0.030222f, 0.000000f,
        0.117761f, 0.030222f, 0.000000f,
        0.117761f, 0.060443f, 0.000000f,
        0.147201f, 0.060443f, 0.000000f,
        -0.088321f, 0.030222f, -0.000000f,
        -0.117761f, 0.030222f, -0.000000f,
        -0.117761f, 0.060443f, -0.000000f,
        -0.088321f, 0.060443f, -0.000000f,
        0.088321f, -0.090665f, 0.000000f,
        0.058881f, -0.090665f, 0.000000f,
        0.058881f, -0.060443f, 0.000000f,
        0.088321f, -0.060443f, 0.000000f,
        -0.029440f, -0.090665f, -0.000000f,
        -0.058881f, -0.090665f, -0.000000f,
        -0.058881f, -0.060443f, -0.000000f,
        -0.029440f, -0.060443f, -0.000000f,
        -0.088321f, -0.090665f, -0.000000f,
        -0.117761f, -0.090665f, -0.000000f,
        -0.117761f, -0.060443f, -0.000000f,
        -0.088321f, -0.060443f, -0.000000f,
        0.147201f, -0.090665f, 0.000000f,
        0.117761f, -0.090665f, 0.000000f,
        0.117761f, -0.060443f, 0.000000f,
        0.147201f, -0.060443f, 0.000000f,
        0.029440f, -0.090665f, 0.000000f,
        0.000000f, -0.090665f, 0.000000f,
        0.000000f, -0.060443f, 0.000000f,
        0.029440f, -0.060443f, 0.000000f,
        0.088321f, -0.211552f, 0.000000f,
        0.058881f, -0.211552f, 0.000000f,
        0.058881f, -0.181330f, 0.000000f,
        0.088321f, -0.181330f, 0.000000f,
        -0.029440f, -0.211552f, -0.000000f,
        -0.058881f, -0.211552f, -0.000000f,
        -0.058881f, -0.181330f, -0.000000f,
        -0.029440f, -0.181330f, -0.000000f,
        0.029440f, -0.211552f, 0.000000f,
        0.000000f, -0.211552f, 0.000000f,
        0.000000f, -0.181330f, 0.000000f,
        0.029440f, -0.181330f, 0.000000f,
        0.147201f, -0.211552f, 0.000000f,
        0.117761f, -0.211552f, 0.000000f,
        0.117761f, -0.181330f, 0.000000f,
        0.147201f, -0.181330f, 0.000000f,
        -0.088321f, -0.211552f, -0.000000f,
        -0.117761f, -0.211552f, -0.000000f,
        -0.117761f, -0.181330f, -0.000000f,
        -0.088321f, -0.181330f, -0.000000f,
        0.235522f, 0.030222f, 0.000000f,
        0.206082f, 0.030222f, 0.000000f,
        0.206082f, 0.060443f, 0.000000f,
        0.235522f, 0.060443f, 0.000000f,
        0.235522f, -0.151109f, 0.000000f,
        0.235522f, -0.120887f, 0.000000f,
        0.235522f, 0.090665f, 0.000000f,
        0.206082f, 0.090665f, 0.000000f,
        0.206082f, 0.120887f, 0.000000f,
        0.235522f, 0.120887f, 0.000000f,
        0.058881f, 0.030222f, 0.000000f,
        0.029440f, 0.030222f, 0.000000f,
        0.029440f, 0.060443f, 0.000000f,
        0.058881f, 0.060443f, 0.000000f,
        -0.000000f, 0.030222f, 0.000000f,
        -0.029440f, 0.030222f, -0.000000f,
        -0.029440f, 0.060443f, -0.000000f,
        -0.000000f, 0.060443f, 0.000000f,
        -0.117761f, -0.030222f, -0.000000f,
        -0.117761f, -0.000000f, -0.000000f,
        -0.176642f, 0.030222f, -0.000000f,
        -0.206082f, 0.030222f, -0.000000f,
        -0.206082f, 0.060443f, -0.000000f,
        -0.176642f, 0.060443f, -0.000000f,
        -0.176642f, 0.090665f, -0.000000f,
        -0.206082f, 0.090665f, -0.000000f,
        -0.206082f, 0.120887f, -0.000000f,
        -0.176642f, 0.120887f, -0.000000f,
        -0.206082f, -0.151109f, -0.000000f,
        -0.206082f, -0.120887f, -0.000000f,
        -0.206082f, -0.030222f, -0.000000f,
        -0.206082f, -0.000000f, -0.000000f,
        -0.147201f, -0.181330f, -0.000000f,
        0.000000f, -0.151109f, 0.000000f,
        0.029440f, -0.151109f, 0.000000f,
        0.176642f, -0.181330f, 0.000000f,
        0.206082f, -0.181330f, 0.000000f,
        -0.176642f, -0.181330f, -0.000000f,
        -0.147201f, -0.090665f, -0.000000f,
        0.000000f, -0.120887f, 0.000000f,
        0.029440f, -0.120887f, 0.000000f,
        0.176642f, -0.090665f, 0.000000f,
        -0.176642f, -0.090665f, -0.000000f,
        0.206082f, -0.090665f, 0.000000f,
        -0.029440f, -0.000000f, -0.000000f,
        0.058881f, 0.000000f, 0.000000f,
        0.235522f, 0.000000f, 0.000000f,
        -0.088321f, -0.000000f, -0.000000f,
        0.088321f, 0.060443f, 0.000000f,
        -0.058881f, 0.060443f, -0.000000f,
        -0.206082f, 0.151109f, -0.000000f,
        -0.176642f, 0.151109f, -0.000000f,
        -0.147201f, 0.120887f, -0.000000f,
        -0.147201f, 0.151109f, -0.000000f,
        -0.117761f, 0.151109f, -0.000000f,
        0.176642f, 0.120887f, 0.000000f,
        0.147201f, 0.151109f, 0.000000f,
        0.176642f, 0.151109f, 0.000000f,
        0.117761f, 0.151109f, 0.000000f,
        -0.058881f, 0.151109f, -0.000000f,
        -0.029440f, 0.151109f, -0.000000f,
        0.058881f, 0.151109f, 0.000000f,
        0.088321f, 0.151109f, 0.000000f,
        0.206082f, 0.151109f, 0.000000f   
    };
	
	unsigned int indices[] = {
        
        0, 1, 2,
        0, 2, 3,
        4, 5, 6,
        4, 6, 7,
        8, 9, 10,
        8, 10, 11,
        12, 13, 14,
        12, 14, 15,
        16, 17, 18,
        16, 18, 19,
        20, 21, 22,
        20, 22, 23,
        24, 25, 26,
        24, 26, 27,
        28, 29, 30,
        28, 30, 31,
        32, 33, 34,
        32, 34, 35,
        36, 37, 38,
        36, 38, 39,
        40, 41, 42,
        40, 42, 43,
        44, 45, 46,
        44, 46, 47,
        48, 49, 50,
        48, 50, 51,
        52, 53, 54,
        52, 54, 55,
        56, 57, 58,
        56, 58, 59,
        60, 61, 62,
        60, 62, 63,
        64, 65, 66,
        64, 66, 67,
        68, 69, 70,
        68, 70, 71,
        72, 73, 74,
        72, 74, 75,
        76, 77, 78,
        76, 78, 79,
        80, 81, 82,
        80, 82, 83,
        84, 85, 86,
        84, 86, 87,
        88, 89, 90,
        88, 90, 91,
        92, 93, 94,
        92, 94, 95,
        96, 97, 98,
        96, 98, 99,
        100, 101, 102,
        100, 102, 103,
        104, 105, 106,
        104, 106, 107,
        108, 48, 51,
        108, 51, 109,
        110, 111, 112,
        110, 112, 113,
        49, 12, 15,
        49, 15, 50,
        53, 4, 7,
        53, 7, 54,
        97, 84, 87,
        97, 87, 98,
        77, 64, 67,
        77, 67, 78,
        13, 44, 47,
        13, 47, 14,
        85, 92, 95,
        85, 95, 86,
        65, 80, 83,
        65, 83, 66,
        114, 115, 116,
        114, 116, 117,
        93, 88, 91,
        93, 91, 94,
        81, 68, 71,
        81, 71, 82,
        118, 119, 120,
        118, 120, 121,
        89, 100, 103,
        89, 103, 90,
        69, 72, 75,
        69, 75, 70,
        29, 8, 11,
        29, 11, 30,
        122, 36, 39,
        122, 39, 123,
        9, 32, 35,
        9, 35, 10,
        124, 125, 126,
        124, 126, 127,
        128, 129, 130,
        128, 130, 131,
        33, 132, 133,
        33, 133, 34,
        37, 134, 135,
        37, 135, 38,
        102, 136, 32,
        102, 32, 9,
        90, 103, 8,
        90, 8, 29,
        94, 91, 28,
        94, 28, 137,
        86, 95, 138,
        86, 138, 45,
        98, 87, 44,
        98, 44, 13,
        139, 99, 12,
        139, 12, 49,
        140, 139, 49,
        140, 49, 48,
        87, 86, 45,
        87, 45, 44,
        136, 141, 33,
        136, 33, 32,
        91, 90, 29,
        91, 29, 28,
        95, 94, 137,
        95, 137, 138,
        99, 98, 13,
        99, 13, 12,
        103, 102, 9,
        103, 9, 8,
        10, 35, 142,
        10, 142, 73,
        30, 11, 72,
        30, 72, 69,
        143, 31, 68,
        143, 68, 81,
        46, 144, 80,
        46, 80, 65,
        14, 47, 64,
        14, 64, 77,
        50, 15, 76,
        50, 76, 145,
        144, 143, 81,
        144, 81, 80,
        15, 14, 77,
        15, 77, 76,
        11, 10, 73,
        11, 73, 72,
        31, 30, 69,
        31, 69, 68,
        35, 34, 146,
        35, 146, 142,
        47, 46, 65,
        47, 65, 64,
        51, 50, 145,
        51, 145, 147,
        38, 135, 125,
        38, 125, 124,
        2, 148, 119,
        2, 119, 118,
        149, 3, 115,
        149, 115, 114,
        150, 55, 105,
        150, 105, 104,
        151, 123, 61,
        151, 61, 60,
        7, 6, 57,
        7, 57, 56,
        127, 126, 129,
        127, 129, 128,
        107, 106, 111,
        107, 111, 110,
        152, 117, 41,
        152, 41, 40,
        120, 153, 25,
        120, 25, 24,
        59, 58, 21,
        59, 21, 20,
        63, 62, 17,
        63, 17, 16,
        131, 130, 154,
        131, 154, 155,
        18, 156, 157,
        18, 157, 158,
        159, 23, 160,
        159, 160, 161,
        23, 22, 162,
        23, 162, 160,
        27, 26, 163,
        27, 163, 164,
        156, 131, 155,
        156, 155, 157,
        43, 42, 165,
        43, 165, 166,
        112, 159, 161,
        112, 161, 167
    };
	
	const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "DVD screensaver", NULL, NULL);
    if (window == NULL)
	{
    	std::cout<<"GLFWwindow error"<<std::endl;
        glfwTerminate();
	    return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
	    std::cout<<"GLAD error"<<std::endl;
	    return -1;
    }
	
	
	unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO); // Создание VAO
    glGenBuffers(1, &VBO);     	// Создание VBO
	glGenBuffers(1, &EBO);
	
	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	const char *vertexShaderSource = "#version 330 core\n"
	    "layout (location = 0) in vec3 aPos;\n"
	    "void main() {\n"
	    "	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	    "}\n";

    const char *fragmentShaderSource = "#version 330 core\n"
	    "out vec4 FragColor;\n"
		"uniform vec3 u_Color;\n"
		"void main() {\n"
		"FragColor = vec4(u_Color, 1.0f);\n"
		"}\n";
	
	
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout<<"vertex shaider error /n"<<infoLog<<std::endl;
	}
	
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout<<"fragment shaider error \n"<<infoLog<<std::endl;
	}
	
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	    return -1;
	}
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glfwSwapInterval(0);
	float angle_deg = -45.0f;
	float speed = 0.0001f;
    
	float RGB_c[] {
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.5f,
		1.0f, 0.5f, 1.0f,
		1.0f, 0.5f, 0.5f,
		0.5f, 1.0f, 1.0f,
		0.5f, 1.0f, 0.5f,
		0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.0f,
		0.5f, 0.0f, 0.5f,
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,
		0.0f, 0.5f, 0.0f
	};
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);
	int cx = 0;
	bool start_col = true;
	glUseProgram(shaderProgram);
    while (!glfwWindowShouldClose(window)) {
		processInput(window);
		int size = sizeof(vertices) / 4;
        int otr_x = 0;
		int otr_y = 0;
		bool color_swap = false;
		for (int i = 0; i < size; ++i) {
            if (vertices[i] >= 1 || vertices[i] <= -1) { 
                if (i % 3 == 1) {
                    otr_y = 1;
					color_swap = true;
                } else if (i % 3 == 0) {
                    otr_x = 1;
					color_swap = true;
                }
            }
            
        }
        if (color_swap == true || start_col == true) {
			start_col = false;
			if (cx >= 38) {
				cx = 0;
			}
			int colorLocation = glGetUniformLocation(shaderProgram, "u_Color");
            glUniform3f(colorLocation, RGB_c[cx], RGB_c[1 + cx], RGB_c[2 + cx]);
            cx += 3;			
		}
		if (otr_x == 1) {
	    	angle_deg = 180.0f - angle_deg;
		}
		if (otr_y == 1) {
			angle_deg = -(angle_deg);
		}
		
		if (angle_deg >= 360.0f) angle_deg -= 360.0f;
        if (angle_deg < 0.0f)    angle_deg += 360.0f;
		float angle_rad = angle_deg * 3.14159265f / 180.0f;
		
		int y_adr = 1;
		int x_adr = 0;
		for (int i = 0; i < size; ++i) {
            vertices[y_adr] += sin(angle_rad) * speed;
            vertices[x_adr] += cos(angle_rad) * speed;
			y_adr += 3;
			x_adr += 3;
        } 

		glClear(GL_COLOR_BUFFER_BIT);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        
        glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	    glfwSwapBuffers(window);
	    glfwPollEvents();
    }
    glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window) 
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

	
	
	
	