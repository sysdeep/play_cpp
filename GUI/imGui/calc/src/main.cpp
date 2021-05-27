#include <cstdlib>
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include <GL/gl3w.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <GLFW/glfw3.h>

#include "main.h"
#include "main_menu/main_menu.h"
#include "share.h"
#include <iostream>



static void error_callback(int error, const char* description){
    fprintf(stderr, "Error %d: %s\n", error, description);
}

bool show_calc_window = false;
bool show_help_window = false;





int main(int argc, char** argv){


	


	// Setup window
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return 1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(800, 620, "Calc", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    gl3wInit();

	

	// Setup ImGui binding
    ImGui_ImplGlfwGL3_Init(window, true);


	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);



	int a=0;
	int b=0;
	int result=0;
	static bool show_app_main_menu_bar = true;


	// glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    while (!glfwWindowShouldClose(window)){

		// glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();

        // Use ImGui functions between here and Render()
        // ImGui::NewFrame();
		ImGui_ImplGlfwGL3_NewFrame();


		{
            static float f = 0.0f;
            ImGui::Text("Hello, world!");
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            // ImGui::ColorEdit3("clear color", (float*)&clear_color);
            if (ImGui::Button("Calc")) show_calc_window = true;

			if (ImGui::Button("Check")){
				std::cout<<show_calc_window<<std::endl;
			}
            // if (ImGui::Button("Another Window")) show_another_window ^= 1;
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }


        if(show_calc_window){
        // This creates a window
            ImGui::Begin("Simple calc");
			ImGui::InputInt("a", &a);
			ImGui::InputInt("b", &b);
			ImGui::InputInt("result", &result);
			// ImGui::BeginMenuBar();
			// if(ImGui::BeginMenuBar()){
			// 	if(ImGui::BeginMenu("File")){
			// 		if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
        	// 		if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
        	// 		// if (ImGui::MenuItem("Close", "Ctrl+W"))  { my_tool_active = false; }
			// 		ImGui::EndMenu();
			// 	}
			// 	ImGui::EndMenuBar();
			// }
            ImGui::Text("Hello, world!");
            ImGui::Text("Hello, world2!");
			
            if (ImGui::Button("Close")) show_calc_window = false;
            ImGui::End();
        }


		if(show_app_main_menu_bar){
			ShowExampleAppMainMenuBar();
		}

		if(show_help_window)	ShowHelpWindow();

		// Rendering
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        glfwSwapBuffers(window);

		result = a+b;

		// std::cout<<show_calc_window<<std::endl;

	}


	// Cleanup
    ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();

    exit(EXIT_SUCCESS);

}



