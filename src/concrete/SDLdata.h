/*
 * SDLdata.h
 *
 *  Created on: 7-mrt.-2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_SDLDATA_H_
#define CONCRETE_SDLDATA_H_
#include "SDL.h"
#include <vector>
#include <string>
namespace frogger_sdl
{
	class SDLdata
	{
		public:
			SDLdata();
			virtual ~SDLdata();
			void setBackground(SDL_Texture* texB);
			void updateScreen();
			SDL_Renderer* getRen();
			void setRen(SDL_Renderer* rende);
			void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int* w, int h, int angle, bool ratio);
			int getDW(SDL_Texture* tex, int h);
			void createTextures();
			std::vector<SDL_Texture*>* getBackTextures();
			void setScreenDimension(int* gameWidth, int* gameHeight);
			int* getScrH() const;
			void setScreenHeight(int* screenHeight);
			int* getScrW() const;
			void setScreenWidth(int* screenWidth);
			std::vector<SDL_Texture*>* getMenuTextures();
			SDL_Texture* getLine();
			void deleteTextures(std::vector<SDL_Texture*> textureVector);
			void fillTextureVectors(std::vector<SDL_Texture*>* textureVector,std::string prefix,int endNumber);
			std::vector<SDL_Texture*>* getTextureVector(char type);

		protected:
			int* screenWidth=nullptr;
			int* screenHeight=nullptr;
			SDL_Renderer* re=nullptr;
			SDL_Texture* line=nullptr;

			std::vector<SDL_Texture*> menu2Textures;
			std::vector<SDL_Texture*> backTex;
			std::vector<SDL_Texture*> playerTex;
			std::vector<SDL_Texture*> ObstTex;
			std::vector<SDL_Texture*> laneTex;
			std::vector<SDL_Texture*> itemTex;
			std::vector<SDL_Texture*> projTex;
	};
}

#endif /* SDLDATA_H_ */
