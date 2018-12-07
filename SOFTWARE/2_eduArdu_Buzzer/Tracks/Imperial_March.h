//Imperial march melody based on the data from Willyboielectro: https://forum.arduino.cc/index.php?topic=259450.0

#ifndef	_IMPERIAL_MARCH_H
#define	_IMPERIAL_MARCH_H
#include "../Notes.h"

int IM1_Tempo = 120;
const int   IM1_Note[] =     {_a4, _a4, _a4, _f4, _c5, _a4, _f4, _c5, _a4, _P , _e5, _e5, _e5, _f5, _c5, _gS4, _f4, _c5, _a4, _P, _END};
const float IM1_Duration[] = {_4 , _4 , _4 , _8D, _16, _4 , _8D, _16, _4 , _4 , _4 , _4 , _4 , _8D, _16, _4  , _8D, _16, _4 , _4, _END};

int IM2_Tempo = 120;
const int   IM2_Note[] =     {_a5, _a4, _a4, _a5, _gS5, _g5 , _fS5, _f5, _fS5, _P , _bB4, _eB5, _d5, _cS5, _c5, _b4, _c5, _P , _END};
const float IM2_Duration[] = {_4 , _8 , _16, _4 , _8D , _16D, _16 , _16, _8  , _8D, _8  , _4  , _8D, _16 , _16, _16, _8 , _8D, _END};

int IMV1_Tempo = 120;
const int   IMV1_Note[] =     {_f4, _gS4, _f4, _a4, _c5, _a4, _c5, _e5, _P, _END};
const float IMV1_Duration[] = {_8 , _4  , _8D, _16, _4 , _8D, _16, _4D, _4, _END};

int IMV2_Tempo = 120;
const int   IMV2_Note[] =     {_f4, _gS4, _f4, _c5, _a4, _f4, _c5, _a4, _P, _END};
const float IMV2_Duration[] = {_8 , _4  , _8D, _16, _4 , _8D, _16, _4D, _4, _END};

#endif
