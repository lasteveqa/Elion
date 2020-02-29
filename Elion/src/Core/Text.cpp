#include "Text.h"


namespace Elion
{
	Text::Text()
	{
		if (!TTF_WasInit()) TTF_Init();
		this->t_properties = TextProperties();
		this->t_size = TextSize();
		this->t_position = TextPosition();
	}


	Text::Text(const TextProperties& tprops) : t_properties(tprops)
	{
		this->t_size = TextSize();
		this->t_position = TextPosition();
		if (!TTF_WasInit()) TTF_Init();

		this->text_font = TTF_OpenFont(tprops.Font, tprops.FontSize);
		
	}

	void Text::set_properties(const TextProperties& tproperties)
	{
		this->t_properties.Font = tproperties.Font;
		this->t_properties.Text = tproperties.Text;
		this->t_properties.FontSize = tproperties.FontSize;

		surface_and_texture();
	}

	void Text::set_color(const SDL_Color& color)
	{
		this->text_color = { color.r , color.g , color.b };

		surface_and_texture();
	}

	void Text::set_position(const TextPosition& tposition)
	{
		this->t_position.Xpos = tposition.Xpos;
		this->t_position.Ypos = tposition.Ypos;

		text_message_rect.x = this->get_X_position();
		text_message_rect.y = this->get_X_position();

	}

	void Text::set_size(const TextSize& tsize)
	{
		this->t_size.Width = tsize.Width;
		this->t_size.Height = tsize.Height;

		text_message_rect.w = this->get_width();
		text_message_rect.h = this->get_height();

	}

	void Text::surface_and_texture()
	{
		this->text_surface = TTF_RenderText_Solid(this->text_font, this->t_properties.Text, this->text_color);

		this->text_texture = SDL_CreateTextureFromSurface(Renderer::get_renderer(), this->text_surface);
	}

	void Text::load(const TextProperties& tprops, const SDL_Color& color, const TextPosition& tposition, const TextSize& tsize)
	{

		this->t_properties.Font = tprops.Font;
		this->t_properties.Text = tprops.Text;
		this->t_properties.FontSize = tprops.FontSize;

		this->text_font = TTF_OpenFont(this->t_properties.Font, this->t_properties.FontSize);
		this->text_color = { color.r , color.g , color.b };

		surface_and_texture();

		this->t_position.Xpos = tposition.Xpos;
		this->t_position.Ypos = tposition.Ypos;

		text_message_rect.x = this->get_X_position();
		text_message_rect.y = this->get_X_position();

		this->t_size.Width = tsize.Width;
		this->t_size.Height = tsize.Height;

		text_message_rect.w = this->get_width();
		text_message_rect.h = this->get_height();
	}

	void Text::load()
	{
		surface_and_texture();
	}

	void Text::render()
	{
		SDL_RenderCopy(Renderer::get_renderer(), this->text_texture, NULL, &this->text_message_rect);
	}

	void Text::clear()
	{
		TTF_CloseFont(this->text_font);
		SDL_FreeSurface(this->text_surface);
		SDL_DestroyTexture(this->text_texture);
	}

}