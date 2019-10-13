#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include "cuboid.h"

#define WIDTH 800
#define HEIGHT 600
#define PIX 3

#define FOV 80
#define SPEED 5

#define STEP 3
#define N_STEP 100

#define N_SHAPES 1

void init();

void draw(SDL_Surface *surf);

Vector origin, direction;

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "SDL init error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Window *win = SDL_CreateWindow("Raytracing",
                                       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                       WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    init();

    SDL_Event event;
    int run = 1;
    while (run) {
        draw(surf);
        SDL_UpdateWindowSurface(win);

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                run = 0;
            else if (event.type == SDL_KEYDOWN) {
                int keyCode = event.key.keysym.sym;
                if (keyCode == SDLK_UP) {
                    origin = v_add(origin, v_mul(direction, SPEED));
                } else if (keyCode == SDLK_DOWN) {
                    origin = v_add(origin, v_mul(direction, -SPEED));
                }
            }
        }
    }

    SDL_DestroyWindow(win);
    SDL_Quit();
    exit(EXIT_SUCCESS);
}

Cuboid shapes[N_SHAPES];

void init() {
    origin = vector(0, 0, 0);
    direction = vector(0, 0, 1);

    shapes[0] = cuboid(vector(10, 10, 40), vector(30, 30, 80));
}

void draw(SDL_Surface *surf) {
    // Loop through pixels
    for (int x = 0; x < WIDTH; x += PIX) {
        for (int y = 0; y < HEIGHT; y += PIX) {
            Vector point = vector(x / 10.0, y / 10.0, FOV),
                    dir = v_mul(v_norm(point), STEP),
                    ray = v_add(v_add(origin, point), dir);

            double distance = 0;
            // Cast the ray
            for (int i = 0; i < N_STEP && distance == 0; i++) {
                // Loop through shapes
                for (int n = 0; n < N_SHAPES; n++) {
                    if (c_inside(shapes[n], ray))
                        distance = i * STEP;
                }
                ray = v_add(ray, dir);
            }

            SDL_Rect rect = {x, y, PIX, PIX};
            SDL_FillRect(surf, &rect, SDL_MapRGB(surf->format, distance * 3, distance * 3, distance * 3));
        }
    }
}