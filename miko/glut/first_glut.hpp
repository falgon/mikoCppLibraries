#ifndef INCLUDED_FIRST_GLUT_HPP
#define INCLUDED_FIRST_GLUT_HPP
#include<GL/glut.h>
namespace miko{
struct gluting{
	gluting(const int MODE,const int MODE1,const int MODE2)
	{
		glutInitDisplayMode (MODE|MODE1|MODE2);
	}

	void my_Init()
	{
		GLfloat light_position[]={100.0,100.0,100.0,1.0};
		glLightfv(GL_LIGHT0,GL_POSITION,light_position);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
	}

	static void disp_sq()
	{
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(40.0,10.0,20.0,0.0,0.0,0.0,0.0,1.0,0.0);
	}

	static void Reshape(const int w,const int h)
	{
		glViewport(0,0,w,h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(10.0,
				static_cast<GLfloat>(w)/static_cast<GLfloat>(h),
				1.0,
				100.0);
		glMatrixMode(GL_MODELVIEW);
	}
};
}
#endif
