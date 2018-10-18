#pragma once
#include "Map.hpp"
#include "VerseKey.h"
#include "Verse.h"

class Bible :
	public util::Map<VerseKey, Verse>
{
public:
	Bible();
	virtual ~Bible();

private:

};

