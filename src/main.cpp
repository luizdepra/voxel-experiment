#include <assert.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

int main(int argc, char **argv)
{
    uint32_t default_window_flags = SDL_WINDOW_OPENGL;

    SDL_Window *window = SDL_CreateWindow("Voxel Experiment", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, default_window_flags);
    assert(window);

    SDL_GLContext context = SDL_GL_CreateContext(window);

    bool is_running = true;
    bool is_fullscreen = false;
    while (is_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    is_running = false;
                    break;
                case SDLK_f:
                    is_fullscreen = !is_fullscreen;
                    if (is_fullscreen)
                    {
                        SDL_SetWindowFullscreen(window, default_window_flags | SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else
                    {
                        SDL_SetWindowFullscreen(window, default_window_flags);
                    }
                    break;
                default:
                    break;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
        }

        glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    return 0;
}
