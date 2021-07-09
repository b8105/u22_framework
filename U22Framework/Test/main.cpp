#include "U22.h"
#include "GameApplicaion.h"


#ifdef _CONSOLE
int main(int argc, char* argv[]) {
#elif _NCONSOLE
int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev, LPSTR command_line, int show) {
#endif // CONSOLE
    auto framework = new u22::Framework();
    auto app = std::make_shared<u22::GameApplication>();
    auto info = u22::ApplicationInfo();

    info.window_width = 1024;
    info.window_height = 768;
    info.window_position_x = 40;
    info.window_position_y = 40;
    info.full_screen_mode = false;

    framework->Setup(app, &info);
    int result = framework->Run();
    framework->Cleanup();


    delete framework;
    framework = nullptr;
    return result;
}