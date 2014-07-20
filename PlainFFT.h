/*

	FFT libray
	Copyright (C) 2010 Didier Longueville

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
*/

#ifndef PlainFFT_h /* Prevent loading library twice */
#define PlainFFT_h

#if ARDUINO >= 100
	#include "Arduino.h";
#else
	#include "WProgram.h" /* This is where the standard Arduino code lies */
#endif

#define FFT_LIB_REV 0x02
/* Custom constants */
#define FFT_FORWARD 0x01
#define FFT_REVERSE 0x00
/* Windowing type */
#define FFT_WIN_TYP_RECTANGLE 0x00 /* rectangle (Box car) */
#define FFT_WIN_TYP_HAMMING 0x01 /* hamming */
#define FFT_WIN_TYP_HANN 0x02 /* hann */
#define FFT_WIN_TYP_TRIANGLE 0x03 /* triangle (Bartlett) */
#define FFT_WIN_TYP_BLACKMAN 0x04 /* blackmann */
#define FFT_WIN_TYP_FLT_TOP 0x05 /* flat top */
#define FFT_WIN_TYP_WELCH 0x06 /* welch */
	
class PlainFFT {
public:
	/* Constructor */
	PlainFFT(void);
	/* Destructor */
	~PlainFFT(void);
	/* Functions */
	void ComplexToMagnitude(double *vReal, double *vImag, uint16_t samples);
	void Compute(double *vReal, double *vImag, uint16_t samples, uint8_t dir);
	double MajorPeak(double *vD, uint16_t samples, double samplingFrequency);
	uint8_t Revision(void);
	void Windowing(double *vData, uint16_t samples, uint8_t windowType, uint8_t dir); 
	
private:
	/* Functions */
	uint8_t Exponent(uint16_t value);
	void Swap(double *x, double *y);
	
};

#endif
