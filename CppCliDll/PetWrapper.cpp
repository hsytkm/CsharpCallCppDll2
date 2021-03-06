#include "stdafx.h"
#include "PetWrapper.h"

using namespace CppCliDll;

PetWrapper::PetTypeWrap PetWrapper::GetPetType()
{
	Pet::Type pt = pet->GetType();
	PetTypeWrap ptw;

	switch (pt)
	{
	case Pet::Dog:
		ptw = PetTypeWrap::WDog;
		break;
	case Pet::Cat:
		ptw = PetTypeWrap::WCat;
		break;
	default:
		ptw = PetTypeWrap::WUnknown;
		break;
	}
	return ptw;
}
