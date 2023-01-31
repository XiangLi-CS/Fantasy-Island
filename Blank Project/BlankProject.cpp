#include "../nclgl/window.h"
#include "Renderer.h"

/*
Press 1:	Normal Camera
Press 2:	Automatic Camera
Press 3:	Default Rendered Scene
Press 4:	Deferred Rendering
*/

int main() {
	Window w("Render success!", 1280, 720, true);
	if (!w.HasInitialised()) {
		return -1;
	}

	Renderer renderer(w);
	if (!renderer.HasInitialised()) {
		return -1;
	}

	w.LockMouseToWindow(true);
	w.ShowOSPointer(false);
	

	int camera = 2;
	int scene = 1;

	while (w.UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_1)) {
			camera = 1;
		}
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_2)) {
			camera = 2;
		}
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_3)) {
			scene = 1;
		}
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_4)) {
			scene = 2;
		}

		float timestep = w.GetTimer()->GetTimeDeltaSeconds();

		//Select Camera
		if (camera == 1)
		{
			renderer.UpdateScene(timestep);
		}
		else if (camera == 2)
		{
			renderer.AutoUpdateCamera(timestep);

		}

		//Select Scene
		if (scene == 1)
		{
			renderer.RenderScene();
			renderer.SwapBuffers();
			if (Window::GetKeyboard()->KeyDown(KEYBOARD_F5)) {
				Shader::ReloadAllShaders();
			}
		}
		else if (scene == 2)
		{
			renderer.RederDeferredScene();
			renderer.SwapBuffers();
			if (Window::GetKeyboard()->KeyDown(KEYBOARD_F5)) {
				Shader::ReloadAllShaders();
			}
		}

	}
	return 0;
}