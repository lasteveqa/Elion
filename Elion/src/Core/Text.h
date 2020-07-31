#pragma once
#include "SDL_ttf.h"
#include "Core/Core.h"
#include "Renderer/Renderer.h"

namespace Elion
{
	struct TextProperties
	{
		const char* Text, * Font;
		int FontSize;

		TextProperties(const char* font = "Backhill.ttf", const char* text = "Elion Text", int fontSize = 60) : Font(font),
			Text(text), FontSize(fontSize) {}
		
	};

	struct TextPosition
	{
		int Xpos, Ypos;

		TextPosition(int xpos = 100, int ypos = 100) : Xpos(xpos), Ypos(ypos) {}
	};

	struct TextSize
	{
		int Width, Height;

		TextSize(int width = 300, int height = 90) : Width(width), Height(height) {}
	};


	class ELION_API Text
	{
	private:

		TTF_Font* text_font;
		SDL_Surface* text_surface;
		SDL_Texture* text_texture;

		SDL_Color text_color;
		SDL_Rect text_message_rect;

		TextSize t_size;
		TextPosition t_position;
		TextProperties t_properties;

	public:
		Text();
		Text(const TextProperties& tprops);


		void set_properties(const TextProperties& tproperties);
		void set_color(const SDL_Color& color);
		void set_position(const TextPosition& tposition);
		void set_size(const TextSize& tsize);

		void surface_and_texture();

		void load(const TextProperties& , const SDL_Color& color , const TextPosition& , const TextSize&);
		void load();

		inline int get_red() const { return this->text_color.r; }
		inline int get_green() const { return this->text_color.g; }
		inline int get_blue() const { return this->text_color.b; }
		inline int get_X_position() const { return t_position.Xpos; }
		inline int get_Y_position() const { return  t_position.Ypos; }
		inline int get_width() const { return t_size.Width; }
		inline int get_height() const { return t_size.Height; }



		void render();
		void clear();
	};

}