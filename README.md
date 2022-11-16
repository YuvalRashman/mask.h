# mask.h
this is a library for mask created apart from college work (ort singalovski)

## Macros Of the Libary


### #define IS_ALL_BITS_OFF(mask)
this macro check if all bits in mask are off
### #define IS_ALL_BITS_ON(mask)
this macro check if all bits in mask are on
### #define TURN_ON_BIT(size)
this macro create number that only one bit is on


## Functions of the libary

### void initMask(typ *mask, unsigned short usSize)
  this functions inisialize mask from given size for exemple for size 5 the mask will be: 00011111 

### void turnOnUnusedBits(typ *mask, unsigned short usSize);
  this functions turn on all the unused bits in mask for size 5 the mask will look like: 11100000

### BOOL isIndexBitOn(typ mask, unsigned short usBitIndex);
  this function check if the bit by the index is on(1). for mask = 10000, usBitIndex = 3 will return FALSE
  
### void combineMasks(typ mask1, typ mask2, typ *result);
  this function combine two masks using | operator. for 100010, 000001 result will be 100011

### void andMasks(typ mask1, typ mask2, typ *result);
  this function perform & on two mask and put the answer in result. for 100010, 000010 result will be 000010

### void turnOnBit(typ *mask, unsigned short usBitIndex);
  this function turn on bit in a mask by a given index. for 10000, 1 mask will be 10001

### void turnOffBit(typ *mask, unsigned short usBitIndex);
  this function turn off bit in a mask by a given index. for 10001, 1 mask will be 10000

### void changeBit(typ *mask, unsigned short usBitIndex);
  this function will change the bit(0 to 1 or 1 to 0) in a bit by the index. 
  for example:
    changeBit(10001, 1)
    10000

### unsigned short countOnOff(typ mask, unsigned short usMaskSize, BOOL bBit);
  this function count the amount of appearances of a given bit in a number. 
  for example:
    countOnOff(1, 2, 1)
    0000000[01] => 1

### void copyNibbleByTimes(typ *newNum, unsigned short usNibble, unsigned short usTimes);
  this function will copy the last nibble to the nibbles before him by the usTimes that we want and save the calculation in newNum 

### unsigned int decimalAsHex(int nNum);
  this function will convert a decimal number to hex number, but will keep the numbers value. for 1234 will return 0X1234

### BOOL isBitsOn(typ mask1, typ mask2, unsigned short maskSize);
  this function check if two given musks have the same bits by mask size
  for example:
    isBitsOn(767, 7, 2)
    767 = 0000001011111111, 7 = 00000000000111
    00000010111111[11] == 000000000001[11]

### BOOL containMask(typ mask1, typ mask2, unsigned short usMaskSize);
  this function check if a given musk with his given size is inside a given mask.
  for example:
    0000010111111110, -1 = 1111111111111111
    00000101111[1111]0 == 111111111111[1111]

### unsigned short countMask(typ mask1, typ mask2, unsigned short usMaskSize);
  this function count the number of occurrences of a given musk with his given size is in a given mask.
  for example:
    0000010111111110, 1111111111111111
    0000010[1111][1111]0 == 11111111[1111][1111]

### void fixShiftLeft(typ *mask, unsigned short usTimes, unsigned short usMaskSize);
  this function performing a cyclic left rotation n times
  for example:
    10001 -> 00011
### void fixShiftRight(typ *mask, unsigned short usTimes, unsigned short usMaskSize);
this function performing a cyclic right rotation n times
  for example:
    10001 -> 00011

### void shiftRight(typ* mask, unsigned short usTimes, unsigned short usMaskSize);
  this function performing a right rotation n times and keeping the left bit
  for example:
    1[10000] -> 1[11000]
