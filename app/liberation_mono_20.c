/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --font ./liberation-mono.regular.ttf --symbols ° --range 0x20-0x7F --size 20 --format lvgl --bpp 1 --no-compress -o ./app/liberation_mono_20.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LIBERATION_MONO_20
#define LIBERATION_MONO_20 1
#endif

#if LIBERATION_MONO_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xc3, 0xc0,

    /* U+0022 "\"" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0023 "#" */
    0x8, 0x81, 0x10, 0x22, 0x8, 0x47, 0xfe, 0x22,
    0x4, 0x40, 0x88, 0xff, 0xc4, 0x40, 0x88, 0x11,
    0x2, 0x20,

    /* U+0024 "$" */
    0x4, 0x0, 0x80, 0x7e, 0x3a, 0x66, 0x4c, 0xc8,
    0x1d, 0x1, 0xe0, 0xf, 0x80, 0xb8, 0x11, 0xa2,
    0x36, 0x46, 0xc9, 0x8f, 0xe0, 0x20, 0x4, 0x0,

    /* U+0025 "%" */
    0x78, 0x6c, 0xcc, 0xcc, 0x8c, 0xd8, 0xcd, 0x7,
    0xa0, 0x7, 0xe0, 0x73, 0xb, 0x31, 0xb3, 0x13,
    0x33, 0x33, 0x61, 0xe0,

    /* U+0026 "&" */
    0x1f, 0x6, 0x30, 0xc6, 0x18, 0xc3, 0x70, 0x38,
    0x1e, 0x13, 0x66, 0xc4, 0xd8, 0x53, 0xe, 0x31,
    0xc3, 0xee,

    /* U+0027 "'" */
    0xff, 0xf0,

    /* U+0028 "(" */
    0x18, 0xc3, 0x18, 0x63, 0x8c, 0x30, 0xc3, 0xc,
    0x30, 0xc1, 0x6, 0x18, 0x30, 0xc1, 0x80,

    /* U+0029 ")" */
    0x60, 0x83, 0x6, 0x18, 0x60, 0xc3, 0xc, 0x30,
    0xc3, 0xc, 0x61, 0x86, 0x30, 0x86, 0x0,

    /* U+002A "*" */
    0x10, 0x23, 0x5b, 0xe3, 0x85, 0x13, 0x0,

    /* U+002B "+" */
    0xc, 0x3, 0x0, 0xc0, 0x30, 0xff, 0xc3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0,

    /* U+002C "," */
    0x76, 0x6c, 0xc8, 0x80,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xfc,

    /* U+002F "/" */
    0x0, 0xc0, 0x60, 0x18, 0xc, 0x2, 0x1, 0x80,
    0x40, 0x30, 0x8, 0x6, 0x3, 0x0, 0xc0, 0x60,
    0x18, 0xc, 0x0,

    /* U+0030 "0" */
    0x1e, 0x18, 0x66, 0x1b, 0x3, 0xc0, 0xf3, 0x3c,
    0xcf, 0x3, 0xc0, 0xf0, 0x36, 0x19, 0x86, 0x1e,
    0x0,

    /* U+0031 "1" */
    0xc, 0xf, 0xe, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xff,
    0xc0,

    /* U+0032 "2" */
    0x3e, 0x31, 0xb0, 0x60, 0x30, 0x18, 0x18, 0x1c,
    0x1c, 0x1c, 0x18, 0x18, 0x18, 0xf, 0xf8,

    /* U+0033 "3" */
    0x3e, 0x31, 0xf0, 0x60, 0x30, 0x30, 0xe0, 0xc,
    0x3, 0x1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0034 "4" */
    0x7, 0x1, 0xc0, 0xf0, 0x2c, 0x13, 0xc, 0xc2,
    0x31, 0xc, 0xc3, 0x3f, 0xf0, 0x30, 0xc, 0x3,
    0x0,

    /* U+0035 "5" */
    0x7f, 0x98, 0x6, 0x1, 0x80, 0x7f, 0x1c, 0x60,
    0xc, 0x3, 0x0, 0xc0, 0x34, 0xd, 0x86, 0x3f,
    0x0,

    /* U+0036 "6" */
    0x1e, 0x31, 0x98, 0x18, 0xd, 0xe7, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xd8, 0x6c, 0x63, 0xe0,

    /* U+0037 "7" */
    0xff, 0x80, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x30,
    0x30, 0x18, 0x1c, 0xc, 0x6, 0x3, 0x0,

    /* U+0038 "8" */
    0x3e, 0x71, 0xf0, 0x78, 0x36, 0x30, 0xe1, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0039 "9" */
    0x3e, 0x31, 0xb0, 0x58, 0x3c, 0x1e, 0xd, 0x8e,
    0x7b, 0x1, 0x80, 0xf0, 0xcc, 0xe3, 0xc0,

    /* U+003A ":" */
    0xfc, 0x0, 0xfc,

    /* U+003B ";" */
    0x66, 0x60, 0x0, 0x0, 0x66, 0x4c, 0xc8, 0x80,

    /* U+003C "<" */
    0x0, 0x40, 0xf0, 0xf0, 0xe0, 0xe0, 0x30, 0xf,
    0x0, 0x70, 0x7, 0x80, 0x70,

    /* U+003D "=" */
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf0,

    /* U+003E ">" */
    0x80, 0x38, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x30,
    0x78, 0x78, 0x70, 0x30, 0x0,

    /* U+003F "?" */
    0x1f, 0x18, 0x66, 0xf, 0x3, 0x0, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x0, 0x0, 0x0, 0x30, 0xc,
    0x0,

    /* U+0040 "@" */
    0xf, 0x2, 0x10, 0x81, 0x20, 0x24, 0xeb, 0xb3,
    0x66, 0x6d, 0x8d, 0xb1, 0xb6, 0x26, 0xc4, 0xd9,
    0x9b, 0x35, 0xbb, 0x10, 0x2, 0x0, 0x31, 0x83,
    0xe0,

    /* U+0041 "A" */
    0x6, 0x0, 0xf0, 0xf, 0x0, 0x90, 0x19, 0x81,
    0x98, 0x30, 0xc3, 0xc, 0x3f, 0xc6, 0x6, 0x60,
    0x64, 0x2, 0xc0, 0x30,

    /* U+0042 "B" */
    0xfe, 0x30, 0xec, 0x1b, 0x6, 0xc3, 0x3f, 0x8c,
    0x1b, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x6, 0xff,
    0x0,

    /* U+0043 "C" */
    0x1f, 0x1c, 0x66, 0xf, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0x26, 0xc, 0xc6, 0x1f,
    0x0,

    /* U+0044 "D" */
    0xfc, 0x63, 0x30, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0xd8, 0xcf, 0xc0,

    /* U+0045 "E" */
    0xff, 0xb0, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xf,
    0xfb, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xff,
    0xc0,

    /* U+0046 "F" */
    0xff, 0xe0, 0x30, 0x18, 0xc, 0x6, 0x3, 0xff,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x0,

    /* U+0047 "G" */
    0x1f, 0x1c, 0x66, 0xf, 0x0, 0xc0, 0x30, 0xc,
    0x7f, 0x3, 0xc0, 0xf0, 0x36, 0xc, 0xc7, 0x1f,
    0x80,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1f, 0xff, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x18,

    /* U+0049 "I" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0xff,

    /* U+004A "J" */
    0x1f, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x43, 0xc3, 0x66, 0x3c,

    /* U+004B "K" */
    0xc1, 0x98, 0x63, 0x1c, 0x63, 0xc, 0xc1, 0xb0,
    0x3f, 0x7, 0x60, 0xc6, 0x18, 0x63, 0xe, 0x60,
    0xcc, 0xc,

    /* U+004C "L" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3, 0x1,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xf8,

    /* U+004D "M" */
    0xe1, 0xf8, 0x7f, 0x3f, 0x4b, 0xd2, 0xf7, 0xbc,
    0xcf, 0x33, 0xcc, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xc0,

    /* U+004E "N" */
    0xe1, 0xf0, 0xfc, 0x7e, 0x3d, 0x1e, 0xcf, 0x27,
    0x9b, 0xc5, 0xe3, 0xf1, 0xf8, 0x7c, 0x38,

    /* U+004F "O" */
    0x1e, 0x18, 0xe6, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x36, 0x19, 0xc6, 0x1e,
    0x0,

    /* U+0050 "P" */
    0xfe, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0xd,
    0xfc, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x0,

    /* U+0051 "Q" */
    0x1e, 0x18, 0xe6, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x36, 0x19, 0x86, 0x3f,
    0x3, 0x0, 0x60, 0x18, 0x3, 0xc0,

    /* U+0052 "R" */
    0xfe, 0x30, 0xcc, 0x1b, 0x6, 0xc1, 0xb0, 0xcf,
    0xe3, 0x30, 0xc6, 0x31, 0x8c, 0x33, 0xe, 0xc1,
    0x80,

    /* U+0053 "S" */
    0x1f, 0x86, 0x19, 0x81, 0xb0, 0x7, 0x0, 0x7c,
    0x7, 0xf0, 0xf, 0x0, 0x60, 0xd, 0x81, 0xb8,
    0x61, 0xf8,

    /* U+0054 "T" */
    0xff, 0xe1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18,
    0x3, 0x0, 0x60, 0xc, 0x1, 0x80, 0x30, 0x6,
    0x0, 0xc0,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0056 "V" */
    0xc0, 0x36, 0x6, 0x60, 0x66, 0x6, 0x30, 0xc3,
    0xc, 0x10, 0x81, 0x98, 0x19, 0x80, 0x90, 0xf,
    0x0, 0xf0, 0x6, 0x0,

    /* U+0057 "W" */
    0xc0, 0x3c, 0x3, 0xc0, 0x34, 0x2, 0x46, 0x26,
    0x66, 0x6f, 0x66, 0xf6, 0x69, 0x62, 0x96, 0x39,
    0xc3, 0x9c, 0x30, 0xc0,

    /* U+0058 "X" */
    0x60, 0x63, 0xc, 0x30, 0xc1, 0x98, 0xf, 0x0,
    0x60, 0x6, 0x0, 0xf0, 0x19, 0x81, 0x98, 0x30,
    0xc6, 0x6, 0x60, 0x60,

    /* U+0059 "Y" */
    0x60, 0x66, 0x6, 0x30, 0xc1, 0xc, 0x19, 0x80,
    0xf0, 0xf, 0x0, 0x60, 0x6, 0x0, 0x60, 0x6,
    0x0, 0x60, 0x6, 0x0,

    /* U+005A "Z" */
    0x7f, 0xc0, 0x18, 0x6, 0x1, 0x80, 0x70, 0xc,
    0x3, 0x0, 0xc0, 0x18, 0x6, 0x1, 0x80, 0x70,
    0xf, 0xfe,

    /* U+005B "[" */
    0xff, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf, 0xc0,

    /* U+005C "\\" */
    0xc0, 0x18, 0x6, 0x0, 0xc0, 0x10, 0x6, 0x0,
    0x80, 0x30, 0x4, 0x1, 0x80, 0x20, 0xc, 0x1,
    0x80, 0x60, 0xc,

    /* U+005D "]" */
    0xfc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x3f, 0xc0,

    /* U+005E "^" */
    0xc, 0x7, 0x81, 0x20, 0x48, 0x33, 0x8, 0x46,
    0x19, 0x2, 0xc0, 0x80,

    /* U+005F "_" */
    0xff, 0xf0,

    /* U+0060 "`" */
    0xc6, 0x30,

    /* U+0061 "a" */
    0x3e, 0xc, 0x61, 0x6, 0x0, 0xc3, 0xf8, 0xc3,
    0x30, 0x66, 0xc, 0xc3, 0x9c, 0xf1, 0xe3, 0x80,

    /* U+0062 "b" */
    0xc0, 0x60, 0x30, 0x18, 0xd, 0xe7, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1f, 0x1b,
    0x78,

    /* U+0063 "c" */
    0x1e, 0x30, 0xd0, 0x78, 0xc, 0x6, 0x3, 0x1,
    0x80, 0x41, 0xb0, 0xcf, 0x80,

    /* U+0064 "d" */
    0x1, 0x80, 0xc0, 0x60, 0x33, 0xdb, 0x1f, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0x1c,
    0xf6,

    /* U+0065 "e" */
    0x3e, 0x18, 0xc6, 0x1b, 0x6, 0xc0, 0xbf, 0xec,
    0x3, 0x0, 0x60, 0x18, 0x61, 0xe0,

    /* U+0066 "f" */
    0xf, 0xce, 0x3, 0x0, 0xc0, 0xff, 0x8c, 0x3,
    0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30,
    0xc, 0x3, 0x0,

    /* U+0067 "g" */
    0x3d, 0xb1, 0xf0, 0xf8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc3, 0xb1, 0xcf, 0x60, 0x32, 0x1b, 0x18,
    0xf8,

    /* U+0068 "h" */
    0xc0, 0x60, 0x30, 0x18, 0xd, 0xf7, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf,
    0x6,

    /* U+0069 "i" */
    0xc, 0x3, 0x0, 0x0, 0x0, 0x7c, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0xf, 0xfc,

    /* U+006A "j" */
    0x3, 0x3, 0x0, 0x0, 0x3f, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x6, 0xfc,

    /* U+006B "k" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x36, 0x33, 0x31,
    0x98, 0xd8, 0x7c, 0x3b, 0x19, 0x8c, 0x66, 0x1b,
    0x6,

    /* U+006C "l" */
    0x7c, 0x3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0xf, 0xfc,

    /* U+006D "m" */
    0xdb, 0xbb, 0xbc, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcf, 0x33, 0xcc, 0xf3, 0x3c, 0xcc,

    /* U+006E "n" */
    0xdf, 0x71, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x60,

    /* U+006F "o" */
    0x1f, 0x18, 0x66, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0x61, 0x98, 0x63, 0xe0,

    /* U+0070 "p" */
    0xde, 0x71, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xf1, 0xb7, 0x98, 0xc, 0x6, 0x3,
    0x0,

    /* U+0071 "q" */
    0x3d, 0xb1, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc3, 0xb1, 0xcf, 0x60, 0x30, 0x18, 0xc,
    0x6,

    /* U+0072 "r" */
    0x6f, 0xbc, 0x1c, 0xc, 0x6, 0x3, 0x1, 0x80,
    0xc0, 0x60, 0x30, 0x18, 0x0,

    /* U+0073 "s" */
    0x7c, 0xc2, 0xc2, 0xc0, 0xf8, 0x7e, 0xf, 0x3,
    0x83, 0xc6, 0x7c,

    /* U+0074 "t" */
    0x10, 0x30, 0xff, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x1f,

    /* U+0075 "u" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xf1, 0xdf, 0x60,

    /* U+0076 "v" */
    0xc0, 0xf0, 0x36, 0x19, 0x86, 0x61, 0x8c, 0xc3,
    0x30, 0x48, 0x1e, 0x7, 0x80, 0xc0,

    /* U+0077 "w" */
    0xc0, 0x3c, 0x3, 0x40, 0x24, 0x62, 0x66, 0x66,
    0xf6, 0x69, 0x66, 0x96, 0x39, 0xc3, 0xc, 0x30,
    0xc0,

    /* U+0078 "x" */
    0xc0, 0x98, 0x63, 0x30, 0x58, 0x1e, 0x3, 0x1,
    0xe0, 0xcc, 0x33, 0x18, 0x6c, 0xc,

    /* U+0079 "y" */
    0xc0, 0x68, 0x19, 0x83, 0x30, 0xc3, 0x18, 0x62,
    0x4, 0xc0, 0xd8, 0xa, 0x1, 0xc0, 0x30, 0x6,
    0x0, 0xc0, 0x30, 0x1c, 0x0,

    /* U+007A "z" */
    0x7f, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x60, 0x60,
    0x60, 0x70, 0x70, 0x3f, 0xe0,

    /* U+007B "{" */
    0xf, 0x8c, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x30, 0x60, 0xc, 0x3, 0x1, 0x80, 0xc0,
    0x60, 0x30, 0x18, 0xc, 0x3, 0xe0,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xf8, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60, 0x30,
    0x18, 0x6, 0x0, 0xc1, 0x81, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3e, 0x0,

    /* U+007E "~" */
    0xf8, 0x1, 0xf0,

    /* U+00B0 "°" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 192, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 192, .box_w = 2, .box_h = 13, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 192, .box_w = 6, .box_h = 6, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 10, .adv_w = 192, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 192, .box_w = 11, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 52, .adv_w = 192, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 192, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 192, .box_w = 2, .box_h = 6, .ofs_x = 5, .ofs_y = 9},
    {.bitmap_index = 92, .adv_w = 192, .box_w = 6, .box_h = 19, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 107, .adv_w = 192, .box_w = 6, .box_h = 19, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 122, .adv_w = 192, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 129, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 142, .adv_w = 192, .box_w = 4, .box_h = 7, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 146, .adv_w = 192, .box_w = 5, .box_h = 1, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 147, .adv_w = 192, .box_w = 2, .box_h = 3, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 192, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 192, .box_w = 2, .box_h = 11, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 192, .box_w = 4, .box_h = 15, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 336, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 349, .adv_w = 192, .box_w = 10, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 357, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 370, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 192, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 412, .adv_w = 192, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 192, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 192, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 192, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 192, .box_w = 10, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 690, .adv_w = 192, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 707, .adv_w = 192, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 192, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 192, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 758, .adv_w = 192, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 778, .adv_w = 192, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 192, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 818, .adv_w = 192, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 838, .adv_w = 192, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 192, .box_w = 6, .box_h = 19, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 871, .adv_w = 192, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 890, .adv_w = 192, .box_w = 6, .box_h = 19, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 905, .adv_w = 192, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 917, .adv_w = 192, .box_w = 12, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 919, .adv_w = 192, .box_w = 4, .box_h = 3, .ofs_x = 4, .ofs_y = 12},
    {.bitmap_index = 921, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 937, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 954, .adv_w = 192, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 967, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 984, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 998, .adv_w = 192, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1034, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 192, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 192, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1089, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 192, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1125, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1139, .adv_w = 192, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1152, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1166, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1183, .adv_w = 192, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1200, .adv_w = 192, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 192, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1224, .adv_w = 192, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1237, .adv_w = 192, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1250, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1264, .adv_w = 192, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1281, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1295, .adv_w = 192, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1316, .adv_w = 192, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1329, .adv_w = 192, .box_w = 9, .box_h = 19, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1351, .adv_w = 192, .box_w = 2, .box_h = 19, .ofs_x = 5, .ofs_y = -4},
    {.bitmap_index = 1356, .adv_w = 192, .box_w = 9, .box_h = 19, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1378, .adv_w = 192, .box_w = 10, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 1381, .adv_w = 192, .box_w = 6, .box_h = 6, .ofs_x = 3, .ofs_y = 8}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 1, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t liberation_mono_20 = {
#else
lv_font_t liberation_mono_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LIBERATION_MONO_20*/

