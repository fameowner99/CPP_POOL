#include "Sdl.hpp"

void Sdl::show()
{
	SDL_Init( SDL_INIT_EVERYTHING );
	createWindow();
	screen = SDL_GetWindowSurface(window);
	TTF_Init();
	gray = SDL_MapRGB(screen->format, 136, 136, 136);
	red = SDL_MapRGB(screen->format, 255, 0, 0);
	green = SDL_MapRGB(screen->format, 57, 255, 20);
	times = TTF_OpenFont("/Library/Fonts/Arial.ttf", 12);

	loop();
}


Sdl::Sdl():window(NULL), running(true), screen(NULL), times(NULL), message(NULL)
{
}

Sdl::~Sdl()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}

void	Sdl::createWindow()
{
	window = SDL_CreateWindow("info", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		std::cout << "There was error initializing the window!" << std::endl
				  << SDL_GetError() << std::endl;
	}
}

void	Sdl::loop()
{

	while (running)
	{
		starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}

		SDL_FillRect(screen, NULL, 0x000000);
		SDL_FillRect(screen, NULL, gray);
		splitIntoSections();


		printGraphics(graphicCpu, green);
		printGraphic_RAM(graphicRam, green);
		printGraphic_Network(graphicNetwork, green);
		print_text();
		SDL_UpdateWindowSurface(window);

	}
}

void	Sdl::freeSurface(SDL_Surface *surface)
{

	surface = 0;
	for (std::vector<SDL_Surface *>::iterator it = messageVector.begin() ; it != messageVector.end(); ++it)
	{
		if (*it) {
			SDL_FreeSurface(*it);
			*it = nullptr;
		}
	}
}

void	Sdl::print_text()
{
	Message_rect.w = 500;
	Message_rect.h = 500;
	SDL_Color white = {255, 255, 255, 0};



	freeSurface(message);
//hostname
	std::string str = "username: " + hostname.get_username();
	message = TTF_RenderText_Solid(times, (str).c_str(), white);
	Message_rect.x = -window_width / 4;
	Message_rect.y = 0;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);

	Message_rect.x = -window_width / 4 + 2;
	Message_rect.y = -16;

	message = TTF_RenderText_Solid(times, (" hostname: " +  hostname.get_hostname()).c_str(), white);
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);

	//hostname


	//OS info
	message = TTF_RenderText_Solid(times, os.get_macOS_version().c_str(), white);
	Message_rect.x = -window_width / 4;
	Message_rect.y = -31;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);

	message = TTF_RenderText_Solid(times, os.get_kernel_info().c_str(), white);
	Message_rect.x = -window_width / 4;
	Message_rect.y = -48;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);
	message = TTF_RenderText_Solid(times, os.get_kernel_date().c_str(), white);
	Message_rect.x = -window_width / 4;
	Message_rect.y = -67;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);

	//OS info


	//time

	message = TTF_RenderText_Solid(times, time.get_date().c_str(), white);
	Message_rect.x = -window_width / 4;
	Message_rect.y = -83;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);



	message = TTF_RenderText_Solid(times, time.get_time().c_str(), white);
	Message_rect.x = -window_width / 4;
	Message_rect.y = -105;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);

	//time


	//CPU

	message = TTF_RenderText_Solid(times, cpu.get_cpu_load().c_str(), white);
	Message_rect.x = -5;
	Message_rect.y = -233;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);

	//CPU


	//RAM
	message = TTF_RenderText_Solid(times, ramInfoModule.get_ram_info().c_str(), white);
	Message_rect.x = -5;
	Message_rect.y = -373;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);
	//RAM



	//Network
	message = TTF_RenderText_Solid(times, network.get_network_throughput().c_str(), white);
	Message_rect.x = 0;
	Message_rect.y = -489;
	SDL_BlitSurface(message, &Message_rect, screen, NULL);
	messageVector.push_back(message);
	//Network


}


void	Sdl::splitIntoSections()
{



	Uint32 orange = SDL_MapRGB(screen->format, 252, 102, 0);
	Uint32 lightGrey = SDL_MapRGB(screen->format, 119,136,153);
	//LINES
	drawObject(0,orange, 2, window_width);

	drawObject(Y_HOSTNAME, orange, 2, window_width);

	drawObject(Y_TIME, orange, 2, window_width);

	drawObject(Y_OSINFO, orange,  2, window_width);

	drawObject(Y_GRAPHIC_CPU, orange,  2, window_width);

	drawObject(Y_CPU, orange,  2, window_width);

	drawObject(Y_GRAPHIC_RAM, orange, 2, window_width);

	drawObject(Y_RAM, orange,  2, window_width);

	drawObject(Y_GRAPHIC_NETWORK, orange,  2, window_width);

	drawObject(Y_NETWORK, orange,  2, window_width);

	drawObject(Y_LAST, orange,  2, window_width);
	//LINES

	//BACKGROUND FOR GRAPHICS

	drawObject(Y_OSINFO + 2, lightGrey,  Y_GRAPHIC_CPU - Y_OSINFO - 2, window_width);

	drawObject(Y_CPU + 2, lightGrey,  Y_GRAPHIC_RAM - Y_CPU - 2, window_width);

	drawObject(Y_RAM + 2, lightGrey,  Y_GRAPHIC_NETWORK - Y_GRAPHIC_RAM  - 2, window_width);
	//BACKGROUND FOR GRAPHICS
}


void	Sdl::printGraphics(Graphic &CPU, Uint32 color)
{
	float x;
	x = Y_GRAPHIC_CPU  - 10 - cpu.fgetInfo();
	CPU.addPoint(0, x, (int)(Y_GRAPHIC_CPU - x));
	CPU.moveAllPoints();
	CPU.printAllPoints(color, screen, 10);
}


void	Sdl::printGraphic_RAM(Graphic &RAM, Uint32 color)
{
	ramInfoModule.get_ram_info();

	float x;
	x = Y_GRAPHIC_RAM  -  (float)ramInfoModule.fgetInfo() / 80. + 20;
	RAM.addPoint(0, x, Y_GRAPHIC_RAM - x);
	RAM.moveAllPoints();
	RAM.printAllPoints(color, screen, +10);

}



void	Sdl::printGraphic_Network(Graphic &NETWORK, Uint32 color)
{
	float x;

	network.get_network_throughput();
	x = Y_GRAPHIC_NETWORK - network.fgetInfo();
	if (x < 350 )
		x = 420;
	NETWORK.addPoint(0, x, (int)(Y_GRAPHIC_NETWORK - x));

	x /= 4;

	NETWORK.moveAllPoints();
	NETWORK.printAllPoints(color, screen, -20);

}


void	Sdl::drawObject(int y, Uint32 color, int objHeight, int objWidth)
{
	SDL_Surface	*image;
	SDL_Rect	rect;
	image = SDL_CreateRGBSurface (0, objWidth, objHeight, 32, 0, 0, 0, 0);
	SDL_FillRect(image, NULL, color);
	rect = image->clip_rect;
	rect.x = 0;
	rect.y = y;
	SDL_BlitSurface(image, NULL, screen, &rect);
}