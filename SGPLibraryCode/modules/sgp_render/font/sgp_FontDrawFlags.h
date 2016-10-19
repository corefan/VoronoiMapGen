#ifndef __SGP_FONTDRAWFLAGS_HEADER__
#define __SGP_FONTDRAWFLAGS_HEADER__

	//! Font render flags.
	enum SGP_FONT_DRAW_FLAG
	{
		SGPFDL_DEFAULT		= 0x1,
		SGPFDL_SHADOW		= 0x2,
		SGPFDL_UNDERLINE	= 0x4,

		SGPFDL_DRAWTEXT_MASK = 0x8 - 1,
	};

#endif		// __SGP_FONTDRAWFLAGS_HEADER__