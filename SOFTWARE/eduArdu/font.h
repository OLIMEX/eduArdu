#ifndef	_FONT_H
#define	_FONT_H

#define	_8X5
//#define	_8X8

#if defined _8X8 && defined _8X5
#error Only one of the fonts must be selected.
#endif

#if	!defined _8X8 && !defined _8X5
#error No font selected.
#endif

#if	defined	_8X5
#define	CHAR_WIDTH	6
extern const unsigned char  FontLookup [][5];
#elif	defined	_8X8
#define	CHAR_WIDTH	8
extern const unsigned char  FontLookup [][8];
#endif

#endif
