#include "stdafx.h"
#include "lorenzMachine.h"

lorenzMachine::lorenzMachine(wheelGroup chi, wheelGroup psi, wheel m37, wheel m61)
{
	this->chi = chi;
	this->psi = psi;
	//Bug 8
	this->m37 = m37;
	this->m61 = m61;
}

int lorenzMachine::encryptChar(int baudotChar)
{
	int key = makeKey();
	rotateWheels();
	return (key ^ baudotChar);
}

void lorenzMachine::rotateWheels()
{
	//Bug 6
	chi.rotate();
	if(m37.getCurrentPin() == 1)
		psi.rotate();
	if(m61.getCurrentPin() == 1)
		m37.rotate();
	m61.rotate();
}

int lorenzMachine::makeKey()
{
	return chi.getCurrentPins() ^ psi.getCurrentPins();
}