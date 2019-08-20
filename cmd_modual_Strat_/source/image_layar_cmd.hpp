/*
RGBA->RGB with SDL_SRCALPHA

The source is alpha-blended with the destination,
using the alpha channel. SDL_SRCCOLORKEY and the per-surface alpha are ignored.

RGBA->RGB without SDL_SRCALPHA

The RGB data is copied from the source.
The source alpha channel and the per-surface alpha value are ignored.
If SDL_SRCCOLORKEY is set, only the pixels not matching the colorkey value are copied.

RGB->RGBA with SDL_SRCALPHA

The source is alpha-blended with the destination using
the per-surface alpha value. If SDL_SRCCOLORKEY is set,
 only the pixels not matching the colorkey value are copied.
  The alpha channel of the copied pixels is set to opaque.

RGB->RGBA without SDL_SRCALPHA

The RGB data is copied from the source and the alpha value of the copied
pixels is set to opaque. If SDL_SRCCOLORKEY is set,
 only the pixels not matching the colorkey value are copied.

RGBA->RGBA with SDL_SRCALPHA

The source is alpha-blended with the destination using the source alpha channel.
 The alpha channel in the destination surface is left untouched. SDL_SRCCOLORKEY is ignored.

RGBA->RGBA without SDL_SRCALPHA

The RGBA data is copied to the destination surface.
 If SDL_SRCCOLORKEY is set, only the pixels not matching the colorkey value are copied.

RGB->RGB with SDL_SRCALPHA

The source is alpha-blended with the destination using the
per-surface alpha value. If SDL_SRCCOLORKEY is set, only the pixels not matching the colorkey value are copied.

RGB->RGB without SDL_SRCALPHA

The RGB data is copied from the source.
If SDL_SRCCOLORKEY is set, only the pixels not matching the colorkey value are copied.

*/
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "path_rez.hpp"
#include "define_typedef_cmdz_.h"
//class rez_path;

class wrap_sdl_texture
{
  private :
    SDL_Texture* sdl_texture;
    int t_width, t_hight;
    SDL_Surface* active_surface;
    size_t hashed_val;

  public :
   wrap_sdl_texture() : sdl_texture(NULL),t_width(0),t_hight(0){}
   wrap_sdl_texture(SDL_Texture* intexture,int w, int h) : sdl_texture(intexture), active_surface(nullptr),
                            t_width(w),t_hight(h)
                    {
                      //t_width(intexture->w),t_hight(intexture->h)

                    }

  ~wrap_sdl_texture()
  {
    SDL_FreeSurface(active_surface);
    destory_texture();
  };
  void set_id(size_t in_ID)
  {
    hashed_val= in_ID;
  }
  
  void destory_texture()
  {
    if(sdl_texture!=NULL);
    sdl_texture = NULL;
    t_width = 0;
    t_hight =0 ;
  }

  void set_texture_alphaz(uint8_t alpha_in)
  {
    SDL_SetTextureAlphaMod( sdl_texture, alpha_in );
  }

  int getWidth()
    {return t_width;}
  int getHeight()
    {return t_hight;}

  SDL_Surface* get_active_surface()
  {
    return active_surface;
  }

  void set_sufrace_overide(SDL_Surface* suf_ovr)
  {
    active_surface = suf_ovr;
  }
  SDL_Texture* scale_texture(SDL_Renderer* sdl_rednerz, int tar_width,
                             int tar_hight, SDL_Surface* rtr_scal_suf= nullptr )
  {
    SDL_Texture * scaled_texture = NULL;
    SDL_Rect sourceDimensions;
    sourceDimensions.x = 0;
    sourceDimensions.y = 0;
    sourceDimensions.w = t_width;
    sourceDimensions.h = t_hight;

    SDL_Rect targetDimensions;
    targetDimensions.x = 0;
    targetDimensions.y = 0;
    targetDimensions.w = tar_width;
    targetDimensions.h = tar_hight;


    SDL_Surface* prt_32bitBPPsurface = SDL_CreateRGBSurface(
        active_surface->flags,
        sourceDimensions.w,
        sourceDimensions.h,
        32,
        active_surface->format->Rmask,
        active_surface->format->Gmask,
        active_surface->format->Bmask,
        active_surface->format->Amask);

    if (SDL_BlitSurface(active_surface, NULL, prt_32bitBPPsurface, NULL) < 0) {
        printf("Error did not blit surface: %s\n", SDL_GetError());
    }


    SDL_Surface *Scaler_surface = SDL_CreateRGBSurface(
        active_surface->flags,
        targetDimensions.w,
        targetDimensions.h,
        active_surface->format->BitsPerPixel,
        active_surface->format->Rmask,
        active_surface->format->Gmask,
        active_surface->format->Bmask,
        active_surface->format->Amask);

    SDL_FillRect(Scaler_surface, &targetDimensions,
                 SDL_MapRGBA(active_surface->format, 20, 50, 100, 175));

if (SDL_BlitScaled(prt_32bitBPPsurface, NULL, Scaler_surface, NULL) < 0) {
                     printf("Error did not scale surface: %s\n", SDL_GetError());

                     SDL_FreeSurface(Scaler_surface);
                     Scaler_surface = NULL;
                 }

    //SDL_FreeSurface(active_surface);

    if(rtr_scal_suf != nullptr)
    {
      rtr_scal_suf = Scaler_surface;
    }
    t_width =active_surface->w;
    t_hight =active_surface->h;

     scaled_texture  = SDL_CreateTextureFromSurface(sdl_rednerz, Scaler_surface);
     // pehrpa soption return by refrence scaller sufrace to put in new nexture
     //wrapper!!!
     SDL_FreeSurface(Scaler_surface);
     SDL_FreeSurface(prt_32bitBPPsurface);
     prt_32bitBPPsurface= nullptr;
     Scaler_surface = nullptr;
     return scaled_texture;
  }

/*
 SDL_Surface* scale_texture(int band_size)
{
  SDL_Rect sourceDimensions;
  sourceDimensions.x = 0;
  sourceDimensions.y = 0;
  sourceDimensions.w = t_width;
  sourceDimensions.h = t_hight;

  float scaleW = (float)band_size / (float)t_width;
  float scaleH = (float)band_size / (float)t_hight;

  if (scaleH < scaleW) {
      scaleW = scaleH;
  }

  SDL_Rect targetDimensions;
  targetDimensions.x = 0;
  targetDimensions.y = 0;
  targetDimensions.w = (int)(t_width * scaleW);
  targetDimensions.h = (int)(t_hight * scaleH);

        SDL_FillRect(pScaleSurface, &targetDimensions, SDL_MapRGBA(pScaleSurface->format, 255, 0, 0, 255));

                      pSurface = pScaleSurface;
                      t_width = pSurface->w;
                      t_hight = pSurface->h;
                  }

   SDL_Surface *pScaleSurface = SDL_CreateRGBSurface(
    p32BPPSurface->flags,
    targetDimensions.w,
    targetDimensions.h,
    p32BPPSurface->format->BitsPerPixel,
    p32BPPSurface->format->Rmask,
    p32BPPSurface->format->Gmask,
    p32BPPSurface->format->Bmask,
    p32BPPSurface->format->Amask);
  }
*/

  bool load_texture_file(rez_path path, SDL_Renderer** sdl_rednerz)
   {
     SDL_Texture* newTexture = NULL;
     SDL_RWops *rwop;

     //active_surface = IMG_Load(path.ch_path);
    rwop = SDL_RWFromFile(path.ch_path, "rb");
    printf("FILE_OPEND: %s\n",path.ch_path);

    if(IMG_isPNM(rwop))
     {
      active_surface = IMG_LoadPNM_RW(rwop);

      if(!active_surface)
       {
        printf("IMG_LoadPNM_RW: %s\n", IMG_GetError());
        return false;
       }
      }
     else
     {
       printf("!NON PNM texture\n");

       //SDL_RWclose(rwop);

       int imgFlags = IMG_INIT_PNG;
       if( !( IMG_Init( imgFlags ) & imgFlags ) )
       {
         printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
         return false;
       }

       active_surface = IMG_Load_RW(rwop,0);

       if( active_surface == NULL )
      	{
      		printf( "Unable to load image %s! SDL_image Error: %s\n", path.ch_path, IMG_GetError() );
          return false;
        }

        printf("->non-PNM::loaded.file..\n");

      }

      SDL_SetColorKey(active_surface, SDL_TRUE, SDL_MapRGB(active_surface->format, 0, 0xFF, 0xFF ) );

      SDL_Renderer* temprt_render  = *sdl_rednerz;
      if (temprt_render == nullptr)
      {
        printf("nullptr of render.");
      }

      newTexture = SDL_CreateTextureFromSurface(temprt_render,active_surface);

      if( newTexture == NULL )
       {
        printf("Unable to create texture from %s! SDL Error: %s\n",path.ch_path, SDL_GetError());
       }

      else
       {
        t_width = active_surface->w;
        t_hight= active_surface->h;
       }

        SDL_RWclose(rwop);
        sdl_texture = newTexture;
        return sdl_texture != NULL;

    }

    int set_texture_mode();

	///void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0,
          //     SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void render(SDL_Renderer* prt_renderz, int x, int y, SDL_Rect* box_space = NULL,
                double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE )
     {
     	//Set rendering space and render to screen
     	SDL_Rect renderQuad = { x, y, t_width, t_hight };
     	//Set clip rendering dimensions
     	if( box_space != NULL )
     	{
     		renderQuad.w = box_space->w;
     		renderQuad.h = box_space->h;
     	}
     	//Render to screen
     	SDL_RenderCopyEx( prt_renderz, sdl_texture, box_space, &renderQuad, angle, center, flip );
     }
   };


    class pane
    {
      private :
      int posx, posy;

      //std::vector<wrap_sdl_texture> Pane_texture_collection;

    public:
      //	gButtonSpriteSheetTexture.render( mPosition.x, mPosition.y, &gSpriteClips[ mCurrentSprite ] );

      void render()
      {
        //Pane_texture_collection.
      //  render(posx,posy,)
      }

    };


/*
USEFUL FUCTIONZ TO KNOW IN SDL>
int SDL_RenderReadPixels(SDL_Renderer*   renderer,
                         const SDL_Rect* rect,
                         Uint32          format,
                         void*           pixels,
                         int             pitch)
formate :: SDL_PIXELFORMAT_NV21

/
SDL_bool SDL_IntersectRect(const SDL_Rect* A,
                           const SDL_Rect* B,
                           SDL_Rect*       result)
/
SDL_bool SDL_HasIntersection(const SDL_Rect* A,
                             const SDL_Rect* B)


.
int SDL_QueryTexture(SDL_Texture* texture,
                     Uint32*      format,
                     int*         access,
                     int*         w,
                     int*         h)

.
int SDL_SetSurfaceRLE(SDL_Surface* surface,
                      int          flag)
.SDL_LockSurface

SDL_UnlockSurface

*/


    //void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
