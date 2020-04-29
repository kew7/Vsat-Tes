#define T_0   0
#define T_90  1
#define T_180 2
#define T_270 3

void turn_faza_90_34(unsigned char *buf_inp, unsigned char *buf_out, unsigned int len, unsigned char reg)
{
static unsigned char tabl_cod_90_plus[256]={
0xaa, 0xa8, 0xab, 0xa9, 0xa2, 0xa0, 0xa3, 0xa1, 0xae, 0xac, 0xaf, 0xad, 0xa6, 
0xa4, 0xa7, 0xa5, 0x8a, 0x88, 0x8b, 0x89, 0x82, 0x80, 0x83, 0x81, 0x8e, 0x8c, 
0x8f, 0x8d, 0x86, 0x84, 0x87, 0x85, 0xba, 0xb8, 0xbb, 0xb9, 0xb2, 0xb0, 0xb3, 
0xb1, 0xbe, 0xbc, 0xbf, 0xbd, 0xb6, 0xb4, 0xb7, 0xb5, 0x9a, 0x98, 0x9b, 0x99, 
0x92, 0x90, 0x93, 0x91, 0x9e, 0x9c, 0x9f, 0x9d, 0x96, 0x94, 0x97, 0x95, 0x2a, 
0x28, 0x2b, 0x29, 0x22, 0x20, 0x23, 0x21, 0x2e, 0x2c, 0x2f, 0x2d, 0x26, 0x24, 
0x27, 0x25, 0x0a, 0x08, 0x0b, 0x09, 0x02, 0x00, 0x03, 0x01, 0x0e, 0x0c, 0x0f, 
0x0d, 0x06, 0x04, 0x07, 0x05, 0x3a, 0x38, 0x3b, 0x39, 0x32, 0x30, 0x33, 0x31, 
0x3e, 0x3c, 0x3f, 0x3d, 0x36, 0x34, 0x37, 0x35, 0x1a, 0x18, 0x1b, 0x19, 0x12, 
0x10, 0x13, 0x11, 0x1e, 0x1c, 0x1f, 0x1d, 0x16, 0x14, 0x17, 0x15, 0xea, 0xe8, 
0xeb, 0xe9, 0xe2, 0xe0, 0xe3, 0xe1, 0xee, 0xec, 0xef, 0xed, 0xe6, 0xe4, 0xe7, 
0xe5, 0xca, 0xc8, 0xcb, 0xc9, 0xc2, 0xc0, 0xc3, 0xc1, 0xce, 0xcc, 0xcf, 0xcd, 
0xc6, 0xc4, 0xc7, 0xc5, 0xfa, 0xf8, 0xfb, 0xf9, 0xf2, 0xf0, 0xf3, 0xf1, 0xfe, 
0xfc, 0xff, 0xfd, 0xf6, 0xf4, 0xf7, 0xf5, 0xda, 0xd8, 0xdb, 0xd9, 0xd2, 0xd0, 
0xd3, 0xd1, 0xde, 0xdc, 0xdf, 0xdd, 0xd6, 0xd4, 0xd7, 0xd5, 0x6a, 0x68, 0x6b, 
0x69, 0x62, 0x60, 0x63, 0x61, 0x6e, 0x6c, 0x6f, 0x6d, 0x66, 0x64, 0x67, 0x65, 
0x4a, 0x48, 0x4b, 0x49, 0x42, 0x40, 0x43, 0x41, 0x4e, 0x4c, 0x4f, 0x4d, 0x46, 
0x44, 0x47, 0x45, 0x7a, 0x78, 0x7b, 0x79, 0x72, 0x70, 0x73, 0x71, 0x7e, 0x7c, 
0x7f, 0x7d, 0x76, 0x74, 0x77, 0x75, 0x5a, 0x58, 0x5b, 0x59, 0x52, 0x50, 0x53, 
0x51, 0x5e, 0x5c, 0x5f, 0x5d, 0x56, 0x54, 0x57, 0x55 };
unsigned int	i;
	switch (reg) {
	
		case T_90 : for (i=0; i<len; i++)
				buf_out[i]=tabl_cod_90_plus[(buf_inp[i])&0xFF];
			    break;
		case T_180: for (i=0; i<len; i++)
				buf_out[i]=~buf_inp[i];
			    break;
		case T_270: for (i=0; i<len; i++)
				buf_out[i]=~(tabl_cod_90_plus[(buf_inp[i])&0xFF]);
			    break;
        case T_0: memcpy(buf_out, buf_inp, len);
			      break;
	}
}