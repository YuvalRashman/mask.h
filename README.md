# mask.h
this is a library for mask created apart from college work (ort singalovski)

#Macros Of the Libary#

#define IS_ALL_BITS_OFF(mask) - this macro check if all bits in mask are off
#define IS_ALL_BITS_ON(mask) - this macro check if all bits in mask are on
#define TURN_ON_BIT(size) - this macro create number that only one bit is on


#Functions of the libary

void initMask(typ *mask, unsigned short usSize)
  this functions inisialize mask from given size for exemple for size 5 the mask will be: 00011111 

void turnOnUnusedBits(typ *mask, unsigned short usSize);
  this functions turn on all the unused bits in mask for size 5 the mask will look like: 11100000

BOOL isIndexBitOn(typ mask, unsigned short usBitIndex);

void combineMasks(typ mask1, typ mask2, typ *result);

void andMasks(typ mask1, typ mask2, typ *result);

void turnOnBit(typ *mask, unsigned short usBitIndex);

void turnOffBit(typ *mask, unsigned short usBitIndex);

void changeBit(typ *mask, unsigned short usBitIndex);

unsigned short countOnOff(typ mask, unsigned short usMaskSize, BOOL bBit);

void copyNibbleByTimes(typ *newNum, unsigned short usNibble, unsigned short usTimes);

unsigned int decimalAsHex(int nNum);

BOOL isBitsOn(typ mask1, typ mask2, unsigned short maskSize);

BOOL containMask(typ mask1, typ mask2, unsigned short usMaskSize);

unsigned short countMask(typ mask1, typ mask2, unsigned short usMaskSize);

void fixShiftLeft(typ *mask, unsigned short usTimes, unsigned short usMaskSize);

void fixShiftRight(typ *mask, unsigned short usTimes, unsigned short usMaskSize);

void shiftRight(typ* mask, unsigned short usTimes, unsigned short usMaskSize);
