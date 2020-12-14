void Snakedrop(SDL_Renderer *renderer, int x, int y)
{
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;
    bitmapSurface = SDL_LoadBMP("assets/images/smile.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    SDL_Rect bitmapTex_rect;

    bitmapTex_rect.x = x;
    bitmapTex_rect.y = y;
    bitmapTex_rect.w = 50;
    bitmapTex_rect.h = 50;
    SDL_RenderCopy(renderer, bitmapTex, NULL, &bitmapTex_rect);
 	
    SDL_DestroyTexture(bitmapTex);
}

int Snakeload(SDL_Renderer *renderer, int load)
{
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;

    if(load % 2 == 0){
    bitmapSurface = SDL_LoadBMP("assets/images/snakeload0.bmp");
    }else{
    bitmapSurface = SDL_LoadBMP("assets/images/snakeload1.bmp");
    }
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    SDL_Rect bitmapTex_rect;

    bitmapTex_rect.x = 0;
    bitmapTex_rect.y = 0;
    bitmapTex_rect.w = 1300;
    bitmapTex_rect.h = 740;

    SDL_RenderCopy(renderer, bitmapTex, NULL, 0);
    SDL_DestroyTexture(bitmapTex);
}

int Gameon(SDL_Renderer *renderer)
{
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;
    bitmapSurface = SDL_LoadBMP("assets/images/gameby.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    SDL_Rect bitmapTex_rect;

    bitmapTex_rect.x = 500;
    bitmapTex_rect.y = 0;
    bitmapTex_rect.w = 200;
    bitmapTex_rect.h = 80;
    SDL_RenderCopy(renderer, bitmapTex, NULL, &bitmapTex_rect);

    SDL_DestroyTexture(bitmapTex);
}

int updatePos(SDL_Renderer *renderer, int x, int y, int typeP, int mod_img)
{
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;

    if(mod_img < 15){
        bitmapSurface = SDL_LoadBMP("assets/images/front.bmp");
    }else if(mod_img > 14 && mod_img < 25){
        bitmapSurface = SDL_LoadBMP("assets/images/front-ling.bmp");
    }else if(mod_img > 24 && mod_img < 50){
         bitmapSurface = SDL_LoadBMP("assets/images/front.bmp");
    }else if(mod_img > 49 && mod_img < 70){
        bitmapSurface = SDL_LoadBMP("assets/images/front-ling.bmp");
    }else if(mod_img > 69){
        bitmapSurface = SDL_LoadBMP("assets/images/front.bmp");
    }
    bitmapTex =  SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

    int dec;
    int deg = 0;
    if (typeP == 0)
    {
        dec = y - 50;
    }
    else if (typeP == 1)
    {
        dec = y + 50;
        deg = 180;
    }

    SDL_Rect bitmapTex_rect;
    bitmapTex_rect.x = x;
    bitmapTex_rect.y = dec;
    bitmapTex_rect.w = 50;
    bitmapTex_rect.h = 50;
    //SDL_RenderCopy(renderer, bitmapTex, NULL, &bitmapTex_rect);
    //SDL_RenderClear(renderer);
    SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
    SDL_RenderCopyEx(renderer, bitmapTex, NULL, &bitmapTex_rect, deg, NULL, flip);
    SDL_DestroyTexture(bitmapTex);
}

int updatePosX(SDL_Renderer *renderer, int y, int x, int typeP, int cont, int mod_img)
{
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;
   if(mod_img < 15){
        bitmapSurface = SDL_LoadBMP("assets/images/front.bmp");
    }else if(mod_img > 14 && mod_img < 25){
        bitmapSurface = SDL_LoadBMP("assets/images/front-ling.bmp");
    }else if(mod_img > 24 && mod_img < 50){
         bitmapSurface = SDL_LoadBMP("assets/images/front.bmp");
    }else if(mod_img > 49 && mod_img < 70){
        bitmapSurface = SDL_LoadBMP("assets/images/front-ling.bmp");
    }else if(mod_img > 69){
        bitmapSurface = SDL_LoadBMP("assets/images/front.bmp");
    }
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    SDL_Rect bitmapTex_rect;
    int dec;
    int deg = 0;
    if (typeP == 2)
    {
        dec = x - 50;
        deg = 90;
    }
    else if (typeP == 4)
    {
        dec = x + 50;
        deg = -90;

    }
    bitmapTex_rect.x = dec;
    bitmapTex_rect.y = y;
    bitmapTex_rect.w = 50;
    bitmapTex_rect.h = 50;
    //SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, bitmapTex, NULL, &bitmapTex_rect);
    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer, bitmapTex, NULL, &bitmapTex_rect, deg, NULL, flip);
    SDL_DestroyTexture(bitmapTex);
}


void PlusSnake(SDL_Renderer *renderer, int x, int y, int cont, int typeM)
{
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;
    bitmapSurface = SDL_LoadBMP("assets/images/snake1.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    SDL_Rect bitmapTex_rect;

    bitmapTex_rect.y = y;
    bitmapTex_rect.x = x;
    bitmapTex_rect.w = 50;
    bitmapTex_rect.h = 50;
    SDL_RenderCopy(renderer, bitmapTex, NULL, &bitmapTex_rect);
    SDL_DestroyTexture(bitmapTex);

}
