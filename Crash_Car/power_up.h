#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
#include"cars.h"
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
class power_up
{
public:

	int x = 0, y = 400, z = 1;
	boolean draw = false;
	power_up(int x, int y) {
		this->x = x;
		this->y = y;


	}

	void struct_power_up() {

		if (draw) {
			glPushMatrix();
			glTranslatef(x, y, 0);
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex2f(0, 10);
			glVertex2f(10, 10);
			glVertex2f(10, 0);
			glVertex2f(0, 0);
			glEnd();
			y -= 2;

			if (y < -290)
			{
				draw = false;
				y = 400;

			}
			if (z == 1) {
				if (rand() % 2 == 0)
				{
					x = -50;
				}
				else if (rand() % 3 == 0)
				{
					x = 0;
				}
				else
				{
					x = 50;
				}
				glTranslatef(x, y, 0);
				z = 0;
			}
			glPopMatrix();

		}



	};
	void draw_power_up(int score) {
		if (score % 25 == 0 | draw) {
			draw = true;
			struct_power_up();
			if (!draw) {
				z = 1;
			}

		}

	}
};

