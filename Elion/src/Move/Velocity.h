#pragma once

namespace Elion
{

	

	class Movement
	{
	private:
		float Xpos = 0.0f;
		float Ypos = 0.0f;

	public:
		void set_Xpos(float xpos)
		{
			this->Xpos = xpos;
		}

		void set_Ypos(float ypos)
		{
			this->Ypos = ypos;
		}
		float x_pos() { return this->Xpos; }
		float y_pos() { return this->Ypos; }
	};

}
