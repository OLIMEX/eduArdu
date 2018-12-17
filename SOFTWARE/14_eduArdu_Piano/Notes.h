#ifndef	_NOTES_H
#define	_NOTES_H

// https://www.seventhstring.com/resources/notefrequencies.html
enum NoteFrequency
{
	_P = 0,	// pause
	_c0 =   16, _cS0 =   17, _d0 =   18, _eB0 =   19, _e0 =   21, _f0 =   22, _fS0 =   23, _g0 =   25, _gS0=   26, _a0 =   28, _bB0 =   29, _b0 =   31,
	_c1 =   33, _cS1 =   35, _d1 =   37, _eB1 =   39, _e1 =   41, _f1 =   44, _fS1 =   46, _g1 =   49, _gS1=   52, _a1 =   55, _bB1 =   58, _b1 =   62,
	_c2 =   65, _cS2 =   70, _d2 =   73, _eB2 =   78, _e2 =   82, _f2 =   87, _fS2 =   93, _g2 =   98, _gS2=  104, _a2 =  110, _bB2 =  117, _b2 =  124,
	_c3 =  131, _cS3 =  139, _d3 =  147, _eB3 =  156, _e3 =  165, _f3 =  175, _fS3 =  185, _g3 =  196, _gS3=  208, _a3 =  220, _bB3 =  233, _b3 =  247,
	_c4 =  261, _cS4 =  277, _d4 =  294, _eB4 =  311, _e4 =  329, _f4 =  349, _fS4 =  370, _g4 =  392, _gS4=  415, _a4 =  440, _bB4 =  466, _b4 =  494,
	_c5 =  523, _cS5 =  554, _d5 =  587, _eB5 =  622, _e5 =  659, _f5 =  699, _fS5 =  740, _g5 =  784, _gS5=  831, _a5 =  880, _bB5 =  932, _b5 =  988,
	_c6 = 1047, _cS6 = 1109, _d6 = 1175, _eB6 = 1245, _e6 = 1319, _f6 = 1397, _fS6 = 1480, _g6 = 1568, _gS6= 1661, _a6 = 1760, _bB6 = 1865, _b6 = 1976,
	_c7 = 2093, _cS7 = 2217, _d7 = 2349, _eB7 = 2489, _e7 = 2637, _f7 = 2794, _fS7 = 2960, _g7 = 3136, _gS7= 3322, _a7 = 3520, _bB7 = 3729, _b7 = 3951,
	_c8 = 4186, _cS8 = 4435, _d8 = 4699, _eB8 = 4978, _e8 = 5274, _f8 = 5588, _fS8 = 5920, _g8 = 6272, _gS8= 6645, _a8 = 7040, _bB8 = 7459, _b8 = 7902,
};

// note durations multiplied by the time for one quarter 60/tempo seconds; (60000/tempo milliseconds)
#define	_8T		0.166	// eigth note triplet (must be used in set of 3 to equal an eight note)
#define	_16		0.25	// sixteenth note
#define	_4T		0.333	// quarter note triplet (must be used in set of 3 to equal a quarter note)
#define	_16D	0.375	// sixteenth note dotted
#define	_8		0.5		// eigth note
#define	_8D		0.75	// eigth note dotted
#define	_4		1		// quarter note
#define	_4D		1.5		// quarter note dotted
#define	_2		2		// half note
#define	_2D		3		// half note dotted
#define	_1		4		// whole note
#define	_1D		6		// whole note dotted

#define	_END	-1

#endif
