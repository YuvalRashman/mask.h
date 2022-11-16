//
// Created by Yuval Rashman (Id: 214616161), Shaked Dror (Id: 326300548), Yanir Shmulevich (Id: 209952308) on 11/11/2022.
//

#include "definesLib.h"

#define FULL_NIBBLE 0xF
#define NIBBLE_SIZE 4

#define IS_ALL_BITS_OFF(mask) mask == ZERO
#define IS_ALL_BITS_ON(mask) IS_ALL_BITS_OFF(~mask)
#define TURN_ON_BIT(size) (ONE << (size - ONE))
#define NUMBER_OF_BITS sizeof(typ) * EIGHT
#define firstPlaceOfNibble NUMBER_OF_BITS - NIBBLE_SIZE

typedef unsigned int typ; // we chose max 32 bits can be change



void initMask(typ *mask, unsigned short usSize);

void turnOnUnusedBits(typ *mask, unsigned short usSize);

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


//--------------------------------------------------------------------------------------------------------------------
//                                                         initMask
//                                                         --------
//
// General : The function initialize mask (put 1 in all bits) by specific usSize.
//
// Parameters :
// mask - pointer to the mask we are going to initialize (In)
// usSize - the size of the mask (In)
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void initMask(typ *mask, unsigned short usSize) {
    //*mask = (1 << usSize) - 1; problem if usSize equal to typ size
    typ temp = TURN_ON_BIT(usSize);
    *mask = temp;
    temp = ~(~temp + ONE);
    *mask |= temp;
}

//--------------------------------------------------------------------------------------------------------------------
//                                                      turnOnUnusedBits
//                                                      ----------------
//
// General : The function turn on all the bits after the mask size.
//
// Parameters :
// mask - pointer to the mask we are going to change (In)
// usSize - the size of the mask (In)
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void turnOnUnusedBits(typ *mask, unsigned short usSize) {
    typ temp;
    initMask(&temp, usSize);
    *mask |= ~(temp);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        isIndexBitOn
//                                                        ------------
//
// General : The function check if  a bit is on.
//
// Parameters :
// mask - pointer to the mask we are going to initialize (In)
// usBitIndex - the index of the bit (In)
//
// Runtime function: none
//
// nesting level : 0

// Return Value : boolean that indicated if the bit is on or off.
//
//--------------------------------------------------------------------------------------------------------------------
BOOL isIndexBitOn(typ mask, unsigned short usBitIndex) {
    return mask & (TURN_ON_BIT(usBitIndex));
}

//--------------------------------------------------------------------------------------------------------------------
//                                                        combineMasks
//                                                        ------------
//
// General : The function combine to masks into one.
// for example: 0011 | 1101 =  1111
//
// Parameters :
// mask1 - first mask (In)
// mask2 - second mask (In)
// result - pointer to mask that we will save the result in (In)
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void combineMasks(typ mask1, typ mask2, typ *result) {
    *result = (mask1 | mask2);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                          andMaks
//                                                          -------
//
// General : The function do and operator between two masks.
// for example: 0011 & 1101 =  0001
//
// Parameters :
// mask1 - first mask (In)
// mask2 - second mask (In)
// result - pointer to mask that we will save the result in (In)
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None
//
//--------------------------------------------------------------------------------------------------------------------
void andMasks(typ mask1, typ mask2, typ *result) {
    *result = (mask1 & mask2);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                          turnOnBit
//                                                          --------
//
// General : this function will turn on the bit in the place of usBitIndex.
//
// Parameters :
// usBitIndex - the regular number
// mask - pointer to the mask
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None.
//--------------------------------------------------------------------------------------------------------------------
void turnOnBit(typ *mask, unsigned short usBitIndex) {
    *mask |= TURN_ON_BIT(usBitIndex);
}


//--------------------------------------------------------------------------------------------------------------------
//                                                         turnOffBit
//                                                         ----------
//
// General : this function will turn off the bit in the place of usBitIndex.
//
// Parameters :
// usBitIndex - the regular number
// mask - pointer to the mask
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None.
//--------------------------------------------------------------------------------------------------------------------
void turnOffBit(typ *mask, unsigned short usBitIndex) {
    *mask &= ~TURN_ON_BIT(usBitIndex);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                         changeBit
//                                                         ---------
//
// General : this function will change the value of the bit regardless if he on or off like xor.
//
// Parameters :
// usBitIndex - the bit index number
// mask - pointer to the mask
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : None.
//--------------------------------------------------------------------------------------------------------------------
void changeBit(typ *mask, unsigned short usBitIndex) {
    *mask ^= TURN_ON_BIT(usBitIndex);
}

//-------------------------------------------------------------------------------------------------------
//									   isBitsOn
//									   --------
//
// General : check if a given musk with his given size is on the right side of a given mask.
// example:
//	isBitsOn(767, 7, 2)
//	767 = 0000001011111111, 7 = 00000000000111
//	00000010111111[11] == 000000000001[11]
//
// Parameters :
// mask1 - mask to check if the second mask is in his start(In)
// mask2 - second mask(In)
// maskSize - size to check(In)
//
// Runtime function: none
//
// nesting level : 0
//
// Return Value : TRUE if mask on the right side of the number, FALSE if not
//
//-------------------------------------------------------------------------------------------------------
BOOL isBitsOn(typ mask1, typ mask2, unsigned short maskSize) {
    // Variable definition
    typ tempMask;

    // Code section
    tempMask = ONE;
    initMask(&tempMask, maskSize);
    mask1 &= tempMask;
    mask2 &= tempMask;

    return (mask1 == mask2);
}

//-------------------------------------------------------------------------------------------------------
//											 containMask
//											 -----------
//
// General : check if a given musk with his given size is in a given mask.
// example:
//	0000010111111110, -1 = 1111111111111111
//	00000101111[1111]0 == 111111111111[1111]
//
// Parameters :
// mask1 - mask to check if the second mask is in his start(In)
// mask2 - second mask(In)
// usMaskSize - size to check(In)
//
// Runtime function: t(n) = 4n + 1
//
// nesting level : 1
//
// Return Value : TRUE if mask in inside the number, FALSE if not
//
//-------------------------------------------------------------------------------------------------------
BOOL containMask(typ mask1, typ mask2, unsigned short usMaskSize) {
    // Variable definition
    BOOL bFlag;
    unsigned short usFirstMaskSize;

    // Code section
    bFlag = FALSE;
    usFirstMaskSize = EIGHT * sizeof(mask1);
    while (usFirstMaskSize-- && !bFlag) {
        mask1 >>= ONE;
        bFlag = isBitsOn(mask1, mask2, usMaskSize);
    }

    return (bFlag);
}

//------------------------------------------------------------------------------------------------------
//											 countMask
//											 ---------
//
// General : Count the number of occurrences of a given musk with his given size is in a given mask.
// example:
//	0000010111111110, 1111111111111111
//	0000010[1111][1111]0 == 11111111[1111][1111]
//
// Parameters :
// mask1 - mask to check if the second mask is in his start(In)
// mask2 - second mask(In)
// usMaskSize - size to check(In)
//
// Runtime function: t(n) = 4n + 2
//
// nesting level : 1
//
// Return Value : The amount of times the mask is inside the first mask
//------------------------------------------------------------------------------------------------------
unsigned short countMask(typ mask1, typ mask2, unsigned short usMaskSize) {
    // Variable definition
    unsigned short usCounter;
    unsigned short usFirstMaskSize;
    BOOL bFound;

    // Code section
    usCounter = ZERO;
    usFirstMaskSize = EIGHT * sizeof(mask1);
    while (usFirstMaskSize--) {
        bFound = isBitsOn(mask1, mask2, usMaskSize);
        usCounter += bFound;

        // If found the mask, will move by the mask size
        mask1 >>= bFound ? usMaskSize : ONE;
    }

    return (usCounter);
}

//------------------------------------------------------------------------------------------------------
//											 fixShiftLeft
//											 ------------
//
// General : Performing a cyclic left rotation n times.
//
// Parameters :
// mask - mask to performe on a cyclic left rotation(In/Out)
// usTimes - n times rotation(In)
// usMaskSize - rotation range(In)
//
// Runtime function: t(n) = 5n
//
// nesting level : 1
//
// Return Value : none
//------------------------------------------------------------------------------------------------------
void fixShiftLeft(typ *mask, unsigned short usTimes, unsigned short usMaskSize) {
    unsigned short usTemp;
    for (; usTimes; usTimes--) {
        usTemp = *mask & TURN_ON_BIT(usMaskSize);
        *mask <<= ONE;
        *mask += usTemp;
    }
}

//------------------------------------------------------------------------------------------------------
//											 fixShiftRight
//											 -------------
//
// General : Performing a cyclic right rotation n times.
//
// Parameters :
// mask - mask to performe on a cyclic right rotation(In/Out)
// usTimes - n times rotation(In)
// usMaskSize - rotation range(In)
//
// Runtime function: t(n) = 5n
//
// nesting level : 1
//
// Return Value : none
//------------------------------------------------------------------------------------------------------
void fixShiftRight(typ *mask, unsigned short usTimes, unsigned short usMaskSize) {
    unsigned short usTemp;
    for (; usTimes; usTimes--) {
        usTemp = *mask & ONE;
        *mask >>= ONE;
        usTemp ? turnOnBit(mask, usMaskSize) : turnOffBit(mask, usMaskSize);
    }
}

//------------------------------------------------------------------------------------------------------
//											 ShiftRight
//											 ----------
//
// General : Performing a right rotation n times and keeping the left bit.
//
// Parameters :
// mask - mask to performe on a cyclic right rotation(In/Out)
// usTimes - n times rotation(In)
// usMaskSize - rotation range(In)
//
// Runtime function: t(n) = 4n
//
// nesting level : 1
//
// Return Value : none
//------------------------------------------------------------------------------------------------------
void shiftRight(typ* mask, unsigned short usTimes, unsigned short usMaskSize) {
    unsigned short usTemp;
    for (; usTimes; usTimes--) {
        *mask >>= ONE;
        *mask & TURN_ON_BIT(usMaskSize - ONE) ? turnOnBit(mask, usMaskSize) : turnOffBit(mask, usMaskSize);
    }
}

//-------------------------------------------------------------------------------------------------------
//											 countOnOff
//											 ----------
//
// General : Count the amount of appearances of a given bit in a number.
// example:
//	countOnOff(1, 2, 1)
//  0000000[01] => 1
//
//  countOnOff(1, 8, 0)
//  0[00000001] => 7
//
// Parameters :
// mask - mask to count the bits(In)
// bBit - bit to check(In)
// usMaskSize - mask size(In)
//
// Runtime function: t(n) = 3n + 3
//
// nesting level : 1
//
// Return Value : the amount of the requested bits
//
//-------------------------------------------------------------------------------------------------------
unsigned short countOnOff(typ mask, unsigned short usMaskSize, BOOL bBit) {
    // Variable definition
    unsigned short usCounter;
    unsigned short usTempSize;

    // Code section
    usCounter = ZERO;
    usTempSize = usMaskSize;
    while (usTempSize--) {
        usCounter += mask & ONE;
        mask >>= ONE;
    }

    return (bBit ? usCounter : usMaskSize - usCounter);
}

//--------------------------------------------------------------------------------------------------------------------
//                                                    copyNibbleByTimes
//                                                    -----------------
//
// General : this function will copy the last nibble to the nibbles before him
// in the usTimes that we want
// for example:
// usNibble = 0xf (1111)
// usTimes = 3
// result = (1111 1111 1111 1111)
//
//
// Parameters :
// newNum - pointer to the result mask.
// usNibble - the number we will copy his last nibble
// usTimes - the usTimes that we want to copy
//
// Runtime function: t(n) = 4n + 1
//
// nesting level : 1
//
// Return Value : the new number with the nibble
//--------------------------------------------------------------------------------------------------------------------
void copyNibbleByTimes(typ *newNum, unsigned short usNibble, unsigned short usTimes) {
    // Code section
    *newNum = usNibble;
    for (; usTimes; usTimes--) {
        *newNum <<= NIBBLE_SIZE;
        *newNum += usNibble;
    }
}

//--------------------------------------------------------------------------------------------------------------------
//                                                      decimalAsHex
//                                                      ------------
//
// General : this function will convert a decimal number to hex number
// this means that each decimal digit will be relocated into a nibble
//
// for example:
// nNum = 1234 (0100 1101 0010) or 0x4D2
// will turn to: 4660 (0001 0010 0011 0100 ) or 0x1234
//
// Parameters :
// nNum - the number we relocated
//
// Runtime function: t(n) = 4n + 1
//
// nesting level : 1
//
// Return Value : the relocated number / the new number
//--------------------------------------------------------------------------------------------------------------------
unsigned int decimalAsHex(int nNum) {
    // Variable definition
    unsigned int numBin;

    // Code section
    numBin = ZERO;
    while (!(numBin & FULL_NIBBLE)) // while the last nibble is bigger than 0, represent the number in hex.
    {
        numBin >>= NIBBLE_SIZE;
        numBin |= ((nNum % TEN) << (firstPlaceOfNibble));
        nNum /= TEN;
    }
    return numBin;
}
