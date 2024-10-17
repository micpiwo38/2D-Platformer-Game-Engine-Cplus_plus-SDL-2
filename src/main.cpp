
#include "../headers/engine.h"
#include "../headers/texture_manager.h"
#include <iostream>

int main(int argc, char* argv[]) {

	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning()) {
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
	}


	Engine::GetInstance()->Clean();

	std::cout << "Test de c " << std::endl;
	return 0;
}