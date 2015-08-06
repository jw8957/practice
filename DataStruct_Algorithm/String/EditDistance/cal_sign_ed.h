#ifndef _CAL_SIGN_ED_H_
#define _CAL_SIGN_ED_H_
#include "ul_strdict.h"
#include "def.h"

bool cal_pre_sign(const char* str,u_int* sign1, u_int* sign2);
bool cal_suf_sign(const char* str,u_int* sign1, u_int* sign2);
int cal_ed(const char *str1, const char *str2, int len1, int len2,unsigned char *op);
bool cal_py_sign(const char* str,u_int* sign1, u_int* sign2);
int cal_num_ed(int *ary1, int *ary2, int &ary_len_1, int &ary_len_2);
void py2int(const char* str, int *arr, int *len);
void pinyin_init();
#endif
