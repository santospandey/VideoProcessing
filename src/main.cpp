#include<iostream>
#include<GLFW/glfw3.h>

int main(int argc, char** argv){
    GLFWwindow* window;

    if(!glfwInit()){
        std::cout<<"Couldnot initialize glfw"<<std::endl;
        return 1;
    }

    window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
    if(!window){
        std::cout<<"Couldnot open window"<<std::endl;
        return 1;
    }

    unsigned char* data = new unsigned char[100*100*3];
    for(int x=0; x<100; x++){
        for(int y=0; y<100; y++){
            data[x*100*3 + y*3] = 0xff;
            data[x*100*3 + y*3 + 1] = 0x00;
            data[x*100*3 + y*3 + 2] = 0x00;
        }
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    
    return 0;
}