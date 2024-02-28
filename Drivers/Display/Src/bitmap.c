/*
 * bitmap.c
 *
 *  Created on: Oct 9, 2021
 *      Author: catreggionpo
 */

#include "bitmap.h"

const unsigned char FHGR_LOGO_SW [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFC, 0x00, 0x07, 0x9F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x07, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x9F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x3F, 0x80, 0x00, 0x7F, 0xFC,
0x3F, 0xFC, 0x00, 0x3F, 0x80, 0x00, 0x7F, 0xFC, 0x3F, 0xFC, 0x00, 0x3F, 0x80, 0x00, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFC, 0x7F, 0xFF, 0x8F, 0xFE, 0x7F, 0xFC,
0x3F, 0xFC, 0x7F, 0xFF, 0x9F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xC0, 0x0F, 0xF0, 0x00, 0xFF, 0xFC, 0x3F, 0xFF, 0x00, 0x07, 0xF0, 0x00, 0x3F, 0xFC,
0x3F, 0xFE, 0x0F, 0x83, 0xF0, 0x00, 0x1F, 0xFC, 0x3F, 0xFC, 0x3F, 0xE3, 0xF1, 0xFF, 0x1F, 0xFC,
0x3F, 0xF8, 0x7F, 0xFF, 0xF1, 0xFF, 0x8F, 0xFC, 0x3F, 0xF8, 0xFF, 0xFF, 0xF1, 0xFF, 0x8F, 0xFC,
0x3F, 0xF1, 0xFF, 0xFF, 0xF1, 0xFF, 0x8F, 0xFC, 0x3F, 0xF1, 0xFF, 0xFF, 0xF1, 0xFF, 0x0F, 0xFC,
0x3F, 0xF3, 0xFF, 0xFF, 0xF1, 0xFF, 0x1F, 0xFC, 0x3F, 0xF3, 0xF8, 0x01, 0xF0, 0x00, 0x3F, 0xFC,
0x3F, 0xE3, 0xF8, 0x01, 0xF0, 0x00, 0x7F, 0xFC, 0x3F, 0xF3, 0xF8, 0x01, 0xF0, 0x00, 0xFF, 0xFC,
0x3F, 0xF3, 0xFF, 0xF1, 0xF1, 0xF1, 0xFF, 0xFC, 0x3F, 0xF1, 0xFF, 0xF1, 0xF1, 0xF8, 0xFF, 0xFC,
0x3F, 0xF1, 0xFF, 0xF1, 0xF1, 0xF8, 0xFF, 0xFC, 0x3F, 0xF8, 0xFF, 0xF1, 0xF1, 0xFC, 0x7F, 0xFC,
0x3F, 0xF8, 0x7F, 0xF1, 0xF1, 0xFC, 0x7F, 0xFC, 0x3F, 0xFC, 0x3F, 0xE1, 0xF1, 0xFE, 0x3F, 0xFC,
0x3F, 0xFE, 0x0F, 0x83, 0xF1, 0xFE, 0x3F, 0xFC, 0x3F, 0xFF, 0x00, 0x07, 0xF1, 0xFF, 0x1F, 0xFC,
0x3F, 0xFF, 0xC0, 0x0F, 0xF1, 0xFF, 0x1F, 0xFC, 0x3F, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char HERZ_PULS [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFE, 0x00, 0x00, 0x3F, 0xC0, 0x00,
0x00, 0x0F, 0xFF, 0x80, 0x00, 0xFF, 0xF8, 0x00, 0x00, 0x3F, 0x03, 0xE0, 0x03, 0xE0, 0x7E, 0x00,
0x00, 0x78, 0x00, 0xF0, 0x0F, 0x00, 0x0F, 0x00, 0x00, 0xE0, 0x00, 0x38, 0x1E, 0x00, 0x03, 0x80,
0x01, 0xC0, 0x00, 0x1C, 0x38, 0x00, 0x01, 0xC0, 0x03, 0x80, 0x00, 0x06, 0x70, 0x00, 0x00, 0xE0,
0x07, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x70, 0x0E, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x30,
0x0C, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x18,
0x1C, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x1C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
0x18, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x0C, 0x18, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0C,
0x18, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x1F, 0x00, 0x60, 0x00, 0x18,
0x0C, 0x00, 0x00, 0x1F, 0x00, 0xF0, 0x00, 0x18, 0x0C, 0x00, 0x00, 0x1F, 0x00, 0xF0, 0x00, 0x38,
0x0E, 0x00, 0x00, 0x3B, 0x00, 0xF8, 0x00, 0x30, 0x06, 0x00, 0x00, 0x33, 0x81, 0xD8, 0x00, 0x30,
0x02, 0x00, 0x00, 0x31, 0x81, 0x9C, 0x00, 0x20, 0x00, 0x00, 0x00, 0x31, 0x81, 0x8C, 0x00, 0x00,
0x00, 0x00, 0x38, 0x71, 0x83, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x61, 0xC3, 0x06, 0x00, 0x00,
0x00, 0x01, 0xEC, 0x60, 0xC3, 0x07, 0x80, 0x00, 0x00, 0x7F, 0xCE, 0x60, 0xC7, 0x03, 0xFF, 0x00,
0x00, 0x7F, 0x07, 0xE0, 0xE6, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x66, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0xC0, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x7C, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x3C, 0x00, 0x40, 0x00,
0x00, 0x03, 0x80, 0x00, 0x38, 0x00, 0xC0, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x10, 0x01, 0xC0, 0x00,
0x00, 0x00, 0xE0, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x0E, 0x00, 0x00,
0x00, 0x00, 0x3C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x38, 0x00, 0x00,
0x00, 0x00, 0x07, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x01, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xE0, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0F, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x3C, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x78, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char HERZ_PULS_KLEIN [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0x80, 0x03, 0xFE, 0x00, 0x00, 0x00, 0x01, 0xC0, 0xE0, 0x0E, 0x03, 0x80, 0x00,
0x00, 0x06, 0x00, 0x38, 0x18, 0x00, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0x0C, 0x30, 0x00, 0x20, 0x00,
0x00, 0x18, 0x00, 0x06, 0x60, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x03, 0xC0, 0x00, 0x18, 0x00,
0x00, 0x20, 0x00, 0x03, 0x80, 0x00, 0x0C, 0x00, 0x00, 0x60, 0x00, 0x01, 0x80, 0x00, 0x04, 0x00,
0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x40, 0x00, 0x0C, 0x00, 0x00, 0x06, 0x00,
0x00, 0x60, 0x00, 0x0E, 0x00, 0x00, 0x04, 0x00, 0x00, 0x60, 0x00, 0x0E, 0x03, 0x00, 0x04, 0x00,
0x00, 0x20, 0x00, 0x1A, 0x03, 0x80, 0x0C, 0x00, 0x00, 0x30, 0x00, 0x1B, 0x03, 0x80, 0x08, 0x00,
0x00, 0x10, 0x00, 0x13, 0x06, 0xC0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x11, 0x04, 0x40, 0x00, 0x00,
0x00, 0x00, 0x06, 0x31, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x31, 0x8C, 0x20, 0x00, 0x00,
0x00, 0x00, 0x73, 0x20, 0x88, 0x3C, 0x00, 0x00, 0x00, 0x03, 0xE1, 0x20, 0x88, 0x0F, 0xC0, 0x00,
0x00, 0x00, 0x01, 0xE0, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xD0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00,
0x00, 0x00, 0x30, 0x00, 0x20, 0x08, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x10, 0x00, 0x00,
0x00, 0x00, 0x0C, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x60, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x18, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0C, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char FINGER [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0xE0, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x06, 0x00, 0x00,
0x00, 0x00, 0xC0, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00,
0x00, 0x03, 0x00, 0x1F, 0xF8, 0x00, 0xC0, 0x00, 0x00, 0x06, 0x00, 0x70, 0x0E, 0x00, 0x60, 0x00,
0x00, 0x04, 0x01, 0x80, 0x01, 0x80, 0x20, 0x00, 0x00, 0x08, 0x06, 0x00, 0x00, 0x60, 0x10, 0x00,
0x00, 0x18, 0x0C, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x10, 0x18, 0x00, 0x00, 0x18, 0x08, 0x00,
0x00, 0x20, 0x30, 0x00, 0x00, 0x0C, 0x04, 0x00, 0x00, 0x20, 0x20, 0x0F, 0xF0, 0x04, 0x04, 0x00,
0x00, 0x60, 0x40, 0x3F, 0xFC, 0x02, 0x06, 0x00, 0x00, 0x40, 0x40, 0x7F, 0xFE, 0x02, 0x02, 0x00,
0x00, 0x40, 0x80, 0xFF, 0xFF, 0x01, 0x02, 0x00, 0x00, 0xC0, 0x80, 0xF0, 0x0F, 0x01, 0x03, 0x00,
0x00, 0x81, 0x81, 0xE0, 0x07, 0x81, 0x81, 0x00, 0x00, 0x81, 0x01, 0xC0, 0x03, 0x80, 0x81, 0x00,
0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00, 0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00,
0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00, 0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00,
0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00, 0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00,
0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00, 0x00, 0x81, 0x03, 0xC0, 0x03, 0xC0, 0x81, 0x00,
0x00, 0xC0, 0x03, 0xC0, 0x03, 0xC0, 0x03, 0x00, 0x00, 0x40, 0x03, 0xC0, 0x03, 0xC0, 0x02, 0x00,
0x00, 0x40, 0x03, 0xC0, 0x03, 0xC0, 0x02, 0x00, 0x00, 0x60, 0x03, 0xC0, 0x03, 0xC0, 0x06, 0x00,
0x00, 0x20, 0x03, 0xFF, 0xFF, 0xC0, 0x04, 0x00, 0x00, 0x30, 0x03, 0xFF, 0xFF, 0xC0, 0x0C, 0x00,
0x00, 0x10, 0x03, 0xFF, 0xFF, 0xC0, 0x08, 0x00, 0x00, 0x18, 0x03, 0xFF, 0xFF, 0xC0, 0x18, 0x00,
0x00, 0x08, 0x03, 0xFF, 0xFF, 0xC0, 0x10, 0x00, 0x00, 0x04, 0x03, 0xFF, 0xFF, 0xC0, 0x20, 0x00,
0x00, 0x02, 0x03, 0xC0, 0x03, 0xC0, 0x40, 0x00, 0x00, 0x03, 0x03, 0xC0, 0x03, 0xC0, 0xC0, 0x00,
0x00, 0x01, 0x03, 0xC0, 0x03, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x03, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xC0, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x03, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00
};
