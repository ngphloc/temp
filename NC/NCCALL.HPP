#ifndef _NCCALL_HPP
#define _NCCALL_HPP

#include "Public.hpp"
#include "Screen.hpp"
#include "Dir&File.hpp"
#include "Disk.hpp"
#include "include\tv.h"
int Copy();
int Rename();
int MakeDir();
int Delete();
int Attrib();
void DrawItem(int x, int y, char ground_color, char text_color, int name_width, ffblk f,char mode);
void DrawItem(char ground_color, char text_color);
void Display(int Mode);
void Display();
char IncRow(int inc);
void NCWindow(char Mode);
void ChangeDir();
void View();
void Edit();

#endif