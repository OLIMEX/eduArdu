#ifndef	_FONT_H
#define	_FONT_H

#define	_8X5
//#define	_8X7

#if defined _8X7 && defined _8X5
#error Only one of the fonts must be selected.
#endif

#if	!defined _8X7 && !defined _8X5
#error No font selected.
#endif

extern const unsigned char BitReverseTable256[];

// CHAR_WIDTH is 1 larger than the actual font itself so we can create a small space between characters
#if	defined	_8X5
#define	CHAR_WIDTH	6
extern const unsigned char  FontLookup [][5];
#elif	defined	_8X7
#define	CHAR_WIDTH	8
extern const unsigned char  FontLookup [][7];
#endif

#endif

