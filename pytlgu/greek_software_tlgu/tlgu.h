#ifndef TLGU_H
#define TLGU_H
/* tlgu.h
 *
 * This is part of the tlgu utility
 * Copyright (C) 2004, 2005, 2011 Dimitri Marinakis
 * see the file tlgu.c for copying conditions
 *
 * Hellenic character codes
 * Relevant Unicode standard tables:
 * Greek and Coptic: 0370 - 03FF
 * Greek Extended: 1F00 - 1FFF
 * 
 * 22-Apr-2006 dm -- added includes to satisfy picky gcc
 * 02-Oct-2011 dm -- added unistd.h to get STDOUT_FILENO
 * 16-Oct-2011 dm -- corrected lower case phi code to 03c6 (was phi symbol 3d5)
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define INRECSIZE 0x2000
#define OUTRECSIZE 0xFFFFF

/* Beta code escapes and state processing codes */
#define HELLENIC 1
#define ROMAN 2
#define PUNCTUATION 3
#define QUOTATION 4
#define PAGE 5
#define BRACKET 6
#define QUASIBRACKET 7
#define NONTEXT 8
#define SYMBOL 9
#define HELLENIC_UPPER 0xa
#define HELLENIC_SELECT 0xb
#define HELLENIC_SIGMA 0xc
/* Accent is an existing code above 0x1f */
#define ACCENT 0x2f
#define HELLENIC_SIGMA_UPPER 0x10
#define TABHALF 0x11
#define ROMAN_SELECT 0x16
#define PUNCTUATION_SELECT 0x1f
#define QUOTATION_SELECT 0x29
#define PAGE_SELECT 0x33
#define BRACKET_SELECT 0x3d
#define QUASIBRACKET_SELECT 0x47
#define NONTEXT_SELECT 0x51
#define SYMBOL_SELECT 0x5b
#define TABHALF_SELECT 0x61

/* code defines */
#define SIGMEDIAL 0x3c3
#define SIGMEDIALUPPER 0x3a3
#define SIGFINAL 0x3c2
#define SIGFINALUPPER 0x3a3
#define SIGLUNATE 0x3f2
#define SIGLUNATEUPPER 0x3f9

/* accents */
#define PSILI 0x313
#define DASIA 0x314
#define DIALYTIKA 0x308
#define VARIA 0x300
#define OXIA 0x301
#define PERISPOMENI 0x342
#define YPOGEGRAMMENI 0x345
#define CARET 0x302


/****************** PROTOTYPES FROM THE TOP DOWN *******************/

int tlgu (char * input_file, char * output_file);
void output_utf(int ucode);
void output_string(char *outstr);
int process_beta (int input_count);
void beta_code(int input_count);
int id_code(int input_count);
void store_accents(unsigned char bufferchar);
const char *resolve_cite_format(const char *cformat);

/****************** COMMAND LINE OPTIONS  **************************/
extern int opt_roman;
extern int opt_page;
extern int opt_blank;
extern int opt_acit;
extern int opt_bcit;
extern int opt_ccit;
extern int opt_dcit;
extern int opt_cit_id;
extern int opt_vcit;
extern int opt_wcit;
extern int opt_xcit;
extern int opt_ycit;
extern int opt_cprefix;
extern char cformat[253];
extern int opt_ecit_blank;
extern char ecite[253];
extern int opt_zcit;
extern int opt_verbose;
extern int opt_debug_bracket;
extern int opt_debug_cit;
extern int opt_debug_special;
extern int opt_multiple;
extern int opt_ebook_cit_x;
extern int opt_ebook_cit_y;
extern int opt_nospace;

#endif /* ifndef TLGU_H */
