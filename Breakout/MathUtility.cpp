#include "StdAfx.h"
#include "MathUtility.h"

int MathUtility::abs(int value)
{
	return (int)abs((double)value);
}

double MathUtility::abs(double value)
{
	return value * ((value>0) - (value<0));
}