/**
 * @file hellosdl2.c
 * @author Sebastian Bauer <mail@seastianbauer.info>
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL_ttf.h>

#include "game_state.h"
#include "pixel_font.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

/** The entire sdl render context */
struct game_sdl_context
{
  SDL_Renderer *renderer;
  TTF_Font *font;
};

/**
 * Render the state using the given SDL renderer.
 *
 * @param ctx specifies the sdl context
 * @param state the state that shall be  rendered
 */
void game_draw(struct game_sdl_context *ctx, const struct game_state *state)
{
    /* Clear background with red color */
    SDL_SetRenderDrawColor(ctx->renderer, 10, 10, 10, 255);
    SDL_RenderClear(ctx->renderer);

    /* Render blue rectangle */
    SDL_Rect r = {.x=state->x,.y=state->y,.w=50,.h=50};
    SDL_SetRenderDrawColor(ctx->renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(ctx->renderer, &r);

    /* Render text */
    char buf[30];
    static const SDL_Color White = {255, 255, 255};
    snprintf(buf, sizeof(buf), "x=%d, y=%d", state->x, state->y);
    SDL_Surface *text_surface = TTF_RenderText_Solid(ctx->font, buf, White); 
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(ctx->renderer, text_surface);
    SDL_RenderCopy(ctx->renderer, text_texture, NULL, &(struct SDL_Rect){.x=0,.y=10,.w=text_surface->w,.h=text_surface->h});
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);

    /* Present */
    SDL_RenderPresent(ctx->renderer);
}

/**
 * Runs the game on the given renderer.
 *
 * @param renderer specifies where the graphics is drawn to.
 */
void game(struct game_sdl_context *ctx)
{
    struct game_state state;
    game_state_init(&state);

    while (1) {
        SDL_Event event;
        Uint64 before = SDL_GetTicks64();

        game_state_update(&state);
        game_draw(ctx, &state);

        while (SDL_PollEvent(&event)) {  // poll until all events are handled!
            switch (event.type)
            {
                case SDL_QUIT:
                    goto quit;
            }
        }
        Uint64 now = SDL_GetTicks64();
        if (now - before < 20)
            SDL_Delay(20 -(now - before));
    }
quit:;

}

/**
 * The program's main entry point.
 * 
 * @param argc number of args
 * @param argv argument vector
 * @return int 
 */
int main (int argc, char** argv)
{
    struct game_sdl_context ctx = {0};

    /** Do some basic build up*/
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Failed to init SDL2\n!");
        return 1;
    }

    TTF_Init();

    SDL_Window *window = NULL;
    if (!(window = SDL_CreateWindow
    (
        "Hello, SDL2", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    )))
    {
        fprintf(stderr, "Failed to create window\n!");
        return 1;
    }

    if (!(ctx.renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)))
    {
        fprintf(stderr, "Failed to create renderer\n!");
        return 1;
    }

    if (!(ctx.font = TTF_OpenFontRW(SDL_RWFromMem(pixel_font, pixel_font_len), 1, 16)))
    {
        fprintf(stderr, "Failed to open internal font: %s\n!", SDL_GetError());
        return 1;
    }

    game(&ctx);

    TTF_CloseFont(ctx.font);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
