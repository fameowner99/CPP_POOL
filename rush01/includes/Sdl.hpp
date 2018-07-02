#ifndef SDL_HPP

# define SDL_HPP


#include <vector>
#include "../includes/CPUInfoModule.hpp"
#include "../includes/DateTimeModule.hpp"
#include "../includes/HostnameUsernameModule.hpp"
#include "../includes/NetworkThroughputModule.hpp"
#include "../includes/OSInfoModule.hpp"
#include "../includes/RAMInfoModule.hpp"
#include <SDL.h>
#include "../SDL_LIBRARY/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <string>
#include "Graphic.hpp"
#include "IMonitorDisplay.hpp"

#define	window_width 330
#define window_height 650
#define Y_HOSTNAME 			30
#define	Y_TIME				80
#define Y_OSINFO			120
#define Y_GRAPHIC_CPU 		220
#define Y_CPU				260
#define Y_GRAPHIC_RAM		360
#define Y_RAM				400
#define Y_GRAPHIC_NETWORK	460
#define Y_NETWORK			500
#define Y_LAST				540

class Sdl : public IMonitorDisplay
{
	private:
		SDL_Window *window;
		bool running;
		SDL_Surface *screen;
		TTF_Font *times;
		SDL_Surface *message;
		SDL_Event event;
		Graphic graphicCpu;
		Graphic graphicRam;
		Graphic	graphicNetwork;
		CPUInfoModule cpu;
		DateTimeModule time;
		HostnameUsernameModule hostname;
		NetworkThroughputModule network;
		OSInfoModule			os;
		RAMInfoModule			ramInfoModule;
		Uint32 gray;
		Uint32 red ;
		Uint32 green;
		Uint32 starting_tick;
		void	loop();
		void	print_text();
		SDL_Rect Message_rect;
		void	freeSurface(SDL_Surface *surface);
		std::vector<SDL_Surface*> messageVector;
		void	splitIntoSections();
		void	printGraphics(Graphic &CPU, Uint32 color);
		void	drawObject(int y, Uint32 color, int objHeight, int objWidth);
		void	printGraphic_RAM(Graphic &CPU, Uint32 color);
		void	printGraphic_Network(Graphic &RAM, Uint32 color);


	public:
		void show();
		Sdl();
		~Sdl();
		void	createWindow();

};

#endif
