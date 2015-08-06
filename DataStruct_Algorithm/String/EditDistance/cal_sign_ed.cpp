#include "cal_sign_ed.h"
#include "string.h"
#include "algorithm"
#include  <map>
#include "string"
using namespace std;

// func:
//	tanslate string to int array. Ascii , Chinese or Japanese characters map to 1 int 
// @para:
//	str: string 
//	array: int arrray ( size should >= RS_MAX_QUERY_LEN )
// @return:
//	0  -  failed
//      >0 -  element number in array
static int parse_char(const char* p) {
	if(p == 0 || *p == 0) 
	{
		return -1;
	}
	unsigned char c1 = *p;
	if(c1 > 0 && c1 <= 127)
	{
		return 1;
	}
	unsigned char c2 = *(p + 1);
	if(c1 >= 0x81 && c1 <= 0xFE && c2 >= 0x40 && c2 <= 0xFE) 
	{
		return 2;
	}
}

int tran_str2intarray(const char *str, unsigned int *array) {
	if(str == 0  || *str == '\0')
	{
		return 0;
	}
	char *p = (char*) str;
	int len;
	unsigned int code;
	int idx = 0;	
	while(p != 0 && *p != '\0')
	{
		len = parse_char(p);
		switch(len)
		{
			case 1:
				code = (unsigned char)(*p);
				p++;
				array[idx++] = code;
				break;
			case 2:
				code = ((unsigned char)(*p) << 8) + (unsigned char)(*(p + 1));
				p += 2;
				array[idx++] = code;
				break;
			case 0:
				//break;
				idx = 0;
				goto quit;
			default:
				//break;
				idx = 0;
				goto quit;
		}
	}
quit:
	return idx;
}


int cal_ed(const char *str1, const char *str2, int len1, int len2,unsigned char *op) {
	*op = 0;
	if(len1 <= 0 || len2 <= 0) {
		return 5;
	}
	int matrix[RS_MAX_QUERY_LEN + 1][RS_MAX_QUERY_LEN + 1];   
	unsigned char path[RS_MAX_QUERY_LEN+1][RS_MAX_QUERY_LEN+1];
	int ary_len_1 = 0, ary_len_2 = 0;
	u_int ary1[STRLENGTH]; 
	u_int ary2[STRLENGTH]; 
	ary_len_1 = tran_str2intarray(str1, ary1);
	if( ary_len_1 == 0 ) {
		return 5;
	}
	ary_len_2 = tran_str2intarray(str2, ary2);
	if( ary_len_2 == 0 ) {
		return 5;
	}	
	for(int i = 0; i <= ary_len_1; i++) {
		matrix[i][0] = i;
		path[i][0] = ZX_OP_DEL;
	}
	for(int i = 0; i <= ary_len_2; i++) {
		matrix[0][i] = i;
		path[0][i] = ZX_OP_ADD;
	}
	path[0][0] = 0;
	for(int i = 1; i <= ary_len_1; i++) {
		for(int j = 1; j <= ary_len_2; j++) {
			matrix[i][j] = matrix[i - 1][j - 1] + (ary1[i - 1] == ary2[j - 1] ? 0 : 1);
			if(ary1[i-1] != ary2[j-1]) {
				path[i][j] = path[i-1][j-1] | ZX_OP_MOD;
			} else {
				path[i][j] = path[i-1][j-1];
			}
			if(matrix[i][j - 1] < matrix[i][j]) {
				matrix[i][j] = matrix[i][j - 1] + 1;
				path[i][j] = path[i][j-1] | ZX_OP_ADD;
			}
			if(matrix[i - 1][j] < matrix[i][j]) {
				matrix[i][j] = matrix[i - 1][j] + 1;
				path[i][j] = path[i-1][j] | ZX_OP_DEL;
			}
			if(i >= 2 && j >= 2 && ary1[i - 2] == ary2[j - 1] && ary1[i - 1] == ary2[j - 2] && matrix[i - 2][j - 2] < matrix[i][j])
			{
				matrix[i][j] = matrix[i - 2][j - 2] + 1;
				path[i][j] = path[i-2][j-2] | ZX_OP_SWP;
			}
		}
	}
	*op = path[ary_len_1][ary_len_2];
	return matrix[ary_len_1][ary_len_2];
}

int cal_num_ed(int *ary1, int *ary2, int &ary_len_1, int &ary_len_2) {
	int matrix[RS_MAX_QUERY_LEN + 1][RS_MAX_QUERY_LEN + 1];   
	if(ary_len_1 <= 0 || ary_len_2 <= 0 || ary1 == NULL || ary2 == NULL) {
		return 5;	// ??
	}
	for(int i = 0; i <= ary_len_1; i++) {
		matrix[i][0] = i;
	}
	for(int i = 0; i <= ary_len_2; i++) {
		matrix[0][i] = i;   
	} 
	for(int i = 1; i <= ary_len_1; i++) {
		for(int j = 1; j <= ary_len_2; j++) {
			matrix[i][j] = matrix[i - 1][j - 1] + (ary1[i - 1] == ary2[j - 1] ? 0 : 1);
			if(matrix[i][j - 1] < matrix[i][j]) {
				matrix[i][j] = matrix[i][j - 1] + 1;
			}
			if(matrix[i - 1][j] < matrix[i][j]) {          
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			if(i >= 2 && j >= 2 && ary1[i - 2] == ary2[j - 1] && ary1[i - 1] == ary2[j - 2] && matrix[i - 2][j - 2] < matrix[i][j]) {
				matrix[i][j] = matrix[i - 2][j - 2] + 1;
			}
		}
	}
	return matrix[ary_len_1][ary_len_2];
}
