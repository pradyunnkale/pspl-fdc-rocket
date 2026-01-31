#include <stdint.h>

#define BASE_ADDR 

#define PSR ((volatile PSR_t *)(BASE_ADDR + 0x00))
#define TMP ((volatile TMP_t *)(BASE_ADDR + 0x03))

typedef union
{
	uint32_t PSR_value; // full 32-bit register
	uint8_t byte[4];
}
PSR_t;

typedef union
{
	uint32_t TMP_value; // full 32-bit register
	uint8_t byte[4];
}
TMP_t;


