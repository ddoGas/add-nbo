#include <stdint.h>
#include "my_htonl.h"

uint32_t my_htonl(uint32_t n){
	//works same as htonl
	uint32_t n1 = (n & 0xff000000)>>24;
	uint32_t n2 = (n & 0x00ff0000)>>8;
	uint32_t n3 = (n & 0x0000ff00)<<8;
	uint32_t n4 = (n & 0x000000ff)<<24;
	return n1|n2|n3|n4;
}