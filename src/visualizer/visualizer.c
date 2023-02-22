
#include "visualizer.h"

#define FONT_PATH "src/visualizer/PIXEAB__.TTF"
#define FONT_POINT_SIZE 15
#define BACKGROUND_COLOR 0x80, 0x80, 0x80
#define BLOCK_COLOR 0x00, 0x00, 0x00
#define TEXT_COLOR 0xb0, 0xb0, 0xb0
#define STATS_INITIAL_XY 15
#define STATS_OFFSET PT2PX(FONT_POINT_SIZE)
#define STATS_PADDING 2

#define ABS(X) ((X) < 0 ? -(X) : (X))
#define PT2PX(Pt) ((int)((Pt)*96.0 / 72.0))
#define Y(Level) (STATS_INITIAL_XY + Level * (STATS_OFFSET + STATS_PADDING))

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static TTF_Font *font = NULL;
static const SDL_Color bkcolor = { TEXT_COLOR };
static char buffer[50];
static float hcoeff = 0.0f;

static void __visualize_stats_field(char *name, int value, int x, int y)
{
  sprintf(buffer, "%s: %d", name, value);
  SDL_Surface *surface = TTF_RenderText_Solid(font, buffer, bkcolor);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

  int w = 0;
  int h = 0;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);

  SDL_Rect rect = { x, y, w, h };
  SDL_RenderCopy(renderer, texture, NULL, &rect);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
}

static void __visualize(int *array, int size, struct state *state)
{
  SDL_Rect rect;
  SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR, 0xff);
  SDL_RenderClear(renderer);

  for (int i = 0; i < size; ++i)
  {
    rect.x = i * WIDTH / size;
    rect.w = WIDTH / size;
    rect.h = (Uint16)(ABS(array[i]) * hcoeff);
    rect.y = (HEIGHT >> 1);

    if (array[i] > 0)
      rect.y -= rect.h;

    SDL_SetRenderDrawColor(renderer, BLOCK_COLOR, 0xff);
    SDL_RenderFillRect(renderer, &rect);
  }

  __visualize_stats_field("accesses", state->accesses, STATS_INITIAL_XY, Y(0));
  __visualize_stats_field("comparisons", state->comparisons, STATS_INITIAL_XY, Y(1));
  __visualize_stats_field("size", size, STATS_INITIAL_XY, Y(2));
  __visualize_stats_field("swaps", state->swaps, STATS_INITIAL_XY, Y(3));
  SDL_RenderPresent(renderer);
}

static void __next(int *array, struct state *state)
{
  if (state->swap_src >= 0)
    swap(array + state->swap_src, array + state->swap_dst);
}

static float __compute_height_coeff(int *array, int size)
{
  int m = ABS(array[0]);

  for (int i = 1; i < size; ++i)
    if (ABS(array[i]) > m)
      m = ABS(array[i]);

  if (m <= (HEIGHT >> 1))
    return 0.66f;

  return 1.0f * (HEIGHT >> 1) / m;
}

static int __prepare(int *array, int size)
{
  if (WIDTH < size)
  {
    fprintf(stderr, "visualizer: __prepare: WIDTH < size\n");
    return 1;
  }

  if (SDL_Init(SDL_INIT_VIDEO) || TTF_Init())
  {
    fprintf(stderr, "visualizer: __prepare: %s\n", SDL_GetError());
    return 1;
  }

  if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer))
  {
    fprintf(stderr, "visualizer: __prepare: %s\n", SDL_GetError());
    return 1;
  }

  font = TTF_OpenFont(FONT_PATH, FONT_POINT_SIZE);
  hcoeff = __compute_height_coeff(array, size);

  if (font == NULL)
    fprintf(stderr, "visualizer: __prepapre: font == NULL\n");

  return font == NULL;
}

void visualize(int *array, int size, struct queue *states)
{
  if (__prepare(array, size))
    return;

  while (42)
  {
    SDL_Event event;
    Uint32 start = SDL_GetTicks();

    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        goto quit;

    if (states->head == NULL)
      continue;

    struct state *state = NULL;
    queue_pop(states, (void **)&state);

    __visualize(array, size, state);
    __next(array, state);

    state_free(&state);

    if (1000 / FPS > SDL_GetTicks() - start)
      SDL_Delay(1000 / FPS - SDL_GetTicks() + start);
  }

quit:
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(font);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  SDL_Quit();
}