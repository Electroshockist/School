#pragma once

#ifndef SAMPLE_H
#define SAMPLE_H

#include "IData.h"

class Sample : public IData{
public:
	int A, B;

	Sample(){ A = 1; B = 2; }

	~Sample(){}

};

#endif // !SAMPLE_H
