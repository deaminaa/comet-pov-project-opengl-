#include <GL/glut.h>
#include <cmath>

// Function to draw a wireframe sphere
void drawWireSphere(GLfloat radius, int slices, int stacks) {
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glutWireSphere(radius, slices, stacks);
  glPopMatrix();
}

// Global variables for animation
static int year = 0, day = 0;
static GLfloat u = 0.0;
static GLfloat du = 0.1;

// Display callback function
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  // Draw sun: a yellow sphere of radius 1 centered at the origin
  glColor3f(1.0, 1.0, 0.0);
  drawWireSphere(1.0, 15, 15);

  // Draw planet: a blue sphere of radius 0.2, 2 units away from the sun,
  // with a white "pole" for its axis
  glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
  glTranslatef(2.0, 0.0, 0.0);
  glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 1.0);
  drawWireSphere(0.2, 15, 15);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex3f(0, -0.3, 0);
  glVertex3f(0, 0.3, 0);
  glEnd();

  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

// Timer callback function for animation
void timer(int v) {
  u += du;
  day = (day + 10) % 360; // Modify the increment to achieve the desired spinning motion
  year = (year + 5) % 360; // Modify the increment to achieve the desired revolving motion

  glLoadIdentity();
  gluLookAt(20 * cos(u / 8.0) + 12, 5 * sin(u / 8.0) + 1, 10 * cos(u / 8.0) + 2, 0, 0, 0, 0, 1, 0);

  glutPostRedisplay();
  glutTimerFunc(1000 / 60, timer, v);
}

// Reshape callback function
void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("On a Comet");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(100, timer, 0);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}
