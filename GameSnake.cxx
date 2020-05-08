#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "assets/libs/objectMove.h"

int main(int argc, char *argv[])
{
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;

    int posX = 10, posY = 20, width = 700, height = 500, initLoad = 0;
    int loadSnake;
    srand(time_t(NULL));
    loadSnake = rand() % 10;
    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Snake Game by Ser3n0s group", posX, posY, width, height, SDL_RENDERER_PRESENTVSYNC);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
   //init game load wallpaper
   while(initLoad < 3){
        Snakeload(renderer, loadSnake);
        SDL_RenderPresent(renderer);
        initLoad++;
        sleep(1);
    }
    //end wallpaper
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    int cont = 0, y = 400, x = 300, typeM, xx =300, yy =500;
    int setc, contdrop = 0, inc = 0, posx = 0, posy = 0;
    double gTime = 250000;
    int vetX[300], vetY[300];
    bool run = true;
    bool goRand = true;
    //load icon on window
    SDL_Surface* bitmapSurface = SDL_LoadBMP("front.bmp");
    SDL_Texture* bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_SetWindowIcon(win, bitmapSurface);

    SDL_StartTextInput();
    SDL_Event event;

    while (run == true)
    {

        SDL_RenderClear(renderer);
        Snakedrop(renderer, xx, yy); //drop insert
        Gameon(renderer); //create by renderer
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
                {
                    if(setc != 3){
                    setc = 0; }
                }
                else if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
                {
                    if(setc != 2){
                    setc = 1; }
                }
                else if (event.key.keysym.sym ==SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
                {
                    if(setc != 1){
                    setc = 2; }
                }
                else if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
                {
                    if(setc != 0){
                    setc = 3; }
                }else if (event.key.keysym.sym == SDLK_p)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);
                }else if (event.key.keysym.sym == SDLK_b)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
                }else if (event.key.keysym.sym == SDLK_v)
                {
                    SDL_SetRenderDrawColor(renderer, 37, 174, 0, 1);
    SDL_RenderClear(renderer);
                }

                break;

            case SDL_MOUSEMOTION:
                SDL_StopTextInput();
                break;
            }
        }

       //generate new drop
       if(contdrop != 0 && contdrop == 4000000){

           xx =0;
           yy = 0;
           int plusPX, plusPY, plusX = 0, plusY = 0;
           
           plusPX = rand() % 14; //new rand range X
           plusPY = rand() % 10; //new rand range Y
           while(plusX < plusPX){

               xx += 50; //add + 50 each loop
               plusX++; //count 1+ each loop at < new rand pos

             }
             while(plusY < plusPY){

               yy += 50; //add + 50 each loop
               plusY++; //count 1+ each loop at < new rand pos

             }

           contdrop = 0;
       }

       if(yy > 700){
          yy = 700;
        }

       // Snakedrop(renderer, xx, yy); //drop insert
        if (y == yy && x == xx)
        {
            cont++; //new snake -> size
            gTime -= 15000;
        }
       //stop new pos in x y (limits)
       if(x >= 700){
            SDL_Delay(1);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(win);
            system("color 1F");
            printf("=============================================\n========GAME OVER JOGUE OUTRA VEZz========\n=============================================");
            return 0;
       }else if(x < 0){
            SDL_Delay(1);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(win);
            system("color 1F");
            printf("=============================================\n========GAME OVER JOGUE OUTRA VEZ========\n=============================================");
            return 0;
        }
       if(y >= 500){
            SDL_Delay(1);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(win);
            system("color 1F");
            printf("=============================================\n========GAME OVER JOGUE OUTRA VEZ========\n=============================================");
            return 0;
       }else if(y < 0){
            SDL_Delay(1);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(win);
            system("color 1F");
            printf("=============================================\n========GAME OVER JOGUE OUTRA VEZ========\n=============================================");
            return 0;
       }
       //end top new pos
        vetY[inc] = y; /*vetor y all steps maped*/
        vetX[inc] = x; /*vetor x all steps maped*/
        inc++; //new step x, y

        if (setc == 0)
        {
            //up typem = 0; 
             typeM = 0;
           
            updatePos(renderer, x, y, typeM, inc);

            y -= 50;
        }
        else if (setc == 1)
        {
            //left typem = 0   
            typeM = 2;
           
            updatePosX(renderer, y, x, typeM, cont, inc);
            x -= 50;
        }
        else if (setc == 2)
        {
            //right typem = 1
            typeM =  4;
            
            updatePosX(renderer, y, x, typeM, cont, inc);
            x += 50;
        }
        else if (setc == 3)
        {
            //down typeM =1
            typeM = 1;
            
            updatePos(renderer, x, y, typeM, inc);
            y += 50;
        }

        //snake return att next positions.
        if(cont > 0){ //total body snake

            //begin clean and recover pos x y (vetor postions)
            if(inc > 0 && inc % 30 == 0){ //each 30 pos x y recover body and replace for first positions -> vetor x y

                int set_rec, get_rec = 1;
                //set_rec = units body snake - 1 && get_rec increments 1 ++ for recover positions x y
                for(set_rec = cont - 1; set_rec >= 0; set_rec--){

                    vetX[set_rec] = vetX[inc-get_rec]; //clear and add new vals x
                    vetY[set_rec] = vetY[inc-get_rec]; //clear and add new vals y
                    get_rec++;
                }

                inc = cont;//inc receive total body snake
            }
            //end clean and recover pos x y (vetor positions)
            int pcont;
            int vp = 1; //pos vetor - vp init 1
            pcont = cont; //qtd snake
            while(pcont != 0){ //move (vp start with 1) positions on loop

                posx = vetX[inc-vp]; //pos vetor - vp
                posy = vetY[inc-vp]; //pos vetor - vp
                if(posx == x && posy == y){ //break game if shock with body snake
                    SDL_Delay(1);
                    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
                }
                PlusSnake(renderer, posx, posy, cont, typeM); //return body in pos x y
                vp++; //inc pos vetor ++ (units snake body)
                pcont--; //dec loop -- (loop moviments);

            }
        }else if(cont == 0){ //body snake == 0
            if(inc > 0 && inc % 50 == 0){

                inc = 0; //inc receive inc - vp -> num snake body
            }
        }


        posx = 0;
        posy = 0;

        contdrop += 100000;
        SDL_RenderPresent(renderer);
        usleep(gTime);
        //gTime -= 150;

    }
    // calculates to 60 fps
    //SDL_Delay(100000000 / 60);
    //SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
