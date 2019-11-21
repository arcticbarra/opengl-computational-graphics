//
//  main.cpp
//  OpenGLTest
//
//  Created by Enrique Barragán on 8/19/19.
//  Copyright © 2019 Enrique Barragán. All rights reserved.
//
// Challenge 3
// Enrique Barragán González A01370878
// Renata Saldívar González A00818538
// Lorraine Bichara Assad A01193063

//  https://www.codemiles.com/c-opengl-examples/draw-3d-cube-using-opengl-t9018.html?mobile=on
//  https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Introduction.html

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <fstream>
#include <math.h>
#include "figures.h"

#define PI 3.14159265

using namespace std;

/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

char title[] = "Challenge 3 - Llama";

// Define translation factors
float translation_factor_x = 0;
float translation_factor_y = 0;
float translation_factor_z = 0;

// Define scaling factors
float scaling_factor_x = 1;
float scaling_factor_y = 1;
float scaling_factor_z = 1;

// Define rotating factors
float rotating_factor_x = 0;
float rotating_factor_y = 0;
float rotating_factor_z = 0;
bool rotate_x = true;
bool rotate_y = false;
bool rotate_z = false;

void makeCheckImage(void)
{
   int i, j, c;

    //Generating Checker Patterm
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}
 
/* Initialize OpenGL Graphics */
void initGL() {
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    makeCheckImage();
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImage);
    
//   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//   glClearDepth(1.0f);                   // Set background depth to farthest
//   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//   glShadeModel(GL_SMOOTH);   // Enable smooth shading
//   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void render_cube(vector<vector<vector<float>>> sides, float factors[3][3], int cube_number) {
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
       // Top face (y = 1.0f)
       // Define vertices in counter-clockwise (CCW) order with normal pointing out
  
  // Assign a color to the cube
//  if(cube_number == 17 || cube_number == 18)
//  {
//      // White color for the eyes
//      glColor3f(1.0f, 1.0f, 1.0f);
//  }
//  else if(cube_number == 19 || cube_number == 20)
//  {
//      // Black color for the pupils
//      glColor3f(0.0f, 0.0f, 0.0f);
//  }
//  else if(cube_number == 23 || cube_number == 24)
//  {
//      // Dark gray for the T zone
//      glColor3f(0.5f, 0.5f, 0.5f);
//  }
//  else if(cube_number == 27 || cube_number == 28)
//  {
//      // Pink for the tongue
//      glColor3f(0.737255f, 0.560784f, 0.560784f);
//  }
//  else if(cube_number == 21 || cube_number == 22 || cube_number == 25 || cube_number == 26)
//  {
//      // Light gray for the mouth
//      glColor3f(0.8f, 0.8f, 0.8f);
//  }
//  else
//  {
//      // Random colors for the rest of the body
//      glColor3f(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)));
//  }
  glEnable(GL_TEXTURE_2D);
  for (int i = 0; i < sides.size(); i++) {
    vector<vector<float>> side = sides[i];
    for (int j = 0; j < side.size(); j++) {
      vector<float> coords = side[j];
      float x,y,z,cx,cy,cz,cos_t,sin_t;

      // Get x, y, and z
      cx = coords[0];
      cy = coords[1];
      cz = coords[2];
      
      // Rotate in Z
      cos_t = cos(factors[2][2] * PI / 180.0);
      sin_t = sin(factors[2][2] * PI / 180.0);
      x = (cx * cos_t) - (cy * sin_t);
      y = (cx * sin_t) + (cy * cos_t);
      z = cz;
      cx = x;
      cy = y;
      cz = z;
        
      // Rotate in Y
      cos_t = cos(factors[2][1] * PI / 180.0);
      sin_t = sin(factors[2][1] * PI / 180.0);
      x = (cz * sin_t) + (cx * cos_t);
      y = cy;
      z = (cz * cos_t) - (cx * sin_t);
      cx = x;
      cy = y;
      cz = z;
      
      // Rotate in X
      cos_t = cos(factors[2][0] * PI / 180.0);
      sin_t = sin(factors[2][0] * PI / 180.0);
      x = cx;
      y = (cy * cos_t) - (cz * sin_t);
      z = (cy * sin_t) + (cz * cos_t);
      
      glTexCoord2f(x, y);
      glVertex3f(
                 (x * factors[1][0]) + factors[0][0],
                 (y * factors[1][1]) + factors[0][1],
                 (z * factors[1][2]) + factors[0][2]);
    }
  }
  glEnd();  // End of drawing color-cube
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    gluLookAt(-15.0, 18.0, 10.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.); /* up is in positive Y direction */
    
    glEnable(GL_TEXTURE_2D);
 
   glTranslatef(0.0f, 0.0f, 0.0f);  // Move right and into the screen
  
  float factors[3][3] = {
    {translation_factor_x, translation_factor_y, translation_factor_z},
    {scaling_factor_x, scaling_factor_y, scaling_factor_z},
    {rotating_factor_x, rotating_factor_y, rotating_factor_z}
  };
  
  vector<vector<vector<vector<float>>>> figures = create_shapes();
  
  for (int i = 0; i < figures.size(); i++) {
    render_cube(figures[i], factors, i);
  }
  
  GLUquadricObj *quadric;
  quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricTexture(quadric, GL_TRUE);
  gluQuadricOrientation(quadric,GLU_INSIDE);
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
    glMatrixMode(GL_PROJECTION);     // To operate on model-view matrix
    glLoadIdentity();
    // Set the viewport to cover the new window
      glViewport(0, 0, width, height);
    // Enable perspective projection with fovy, aspect, zNear and zFar
    if (height == 0) height = 1;                // To prevent divide by 0
      GLfloat aspect = (GLfloat)width / (GLfloat)height;
    gluPerspective(90.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   glLoadIdentity();
    
   
//   // Set the aspect ratio of the clipping volume to match the viewport
//   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
//   glLoadIdentity();             // Reset

}

bool scaling = false;
bool translating = true;
bool rotating = false;

void move(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_UP:
      if (translating) {
        translation_factor_y += 10;
      } else if (scaling) {
        scaling_factor_y += 0.1;
      } else if (rotating) {
        if (rotate_x) {
          rotating_factor_x += 10;
        } else if (rotate_y) {
          rotating_factor_y += 10;
        } else {
          rotating_factor_z += 10;
        }
      }
      glutPostRedisplay();
      break;
    case GLUT_KEY_DOWN:
      if (translating) {
        translation_factor_y -= 10;
      } else if (scaling) {
        scaling_factor_y -= 0.1;
      } else if (rotating) {
        if (rotate_x) {
          rotating_factor_x -= 10;
        } else if (rotate_y) {
          rotating_factor_y -= 10;
        } else {
          rotating_factor_z -= 10;
        }
      }
      glutPostRedisplay();
      break;
    case GLUT_KEY_LEFT:
      if (translating) {
        translation_factor_x -= 10;
      } else if (scaling) {
        scaling_factor_x -= 0.1;
      } else if (rotating) {
        if (rotate_x) {
          rotating_factor_x -= 10;
        } else if (rotate_y) {
          rotating_factor_y -= 10;
        } else {
          rotating_factor_z -= 10;
        }
      }
      glutPostRedisplay();
      break;
    case GLUT_KEY_RIGHT:
      if (translating) {
        translation_factor_x += 10;
      } else if (scaling) {
        scaling_factor_x += 0.1;
      } else if (rotating) {
        if (rotate_x) {
          rotating_factor_x += 10;
        } else if (rotate_y) {
          rotating_factor_y += 10;
        } else {
          rotating_factor_z += 10;
        }
      }
      glutPostRedisplay();
      break;
    case 116: // t for translating
      cout << "Translating enabled." << endl;
      rotating = false;
      scaling = false;
      translating = true;
      break;
    case 115: // s for scaling
      cout << "Scaling enabled." << endl;
      rotating = false;
      scaling = true;
      translating = false;
      break;
    case 114: // r for rotating
      cout << "Rotating enabled." << endl;
      rotating = true;
      scaling = false;
      translating = false;
      break;
    case 120: // rotation in x
      if(rotating)
      {
        cout << "Rotating in x enabled." << endl;
        rotate_x = true;
        rotate_y = false;
        rotate_z = false;
      }
      break;
    case 121: // rotation in y
      if(rotating)
      {
        cout << "Rotating in y enabled." << endl;
        rotate_x = false;
        rotate_y = true;
        rotate_z = false;
      }
      break;
    case 122: // rotation in z
      if(rotating)
      {
        cout << "Rotating in z enabled." << endl;
        rotate_x = false;
        rotate_y = false;
        rotate_z = true;
      }
      break;
    default:
      break;
  }
}

// Print instructions to the console
void printInstructions()
{
    cout << "To translate: press t and use the arrow keys to move." << endl;
    cout << "To scale: press s and use the arrow keys to change size." << endl;
    cout << "To rotate: press r and then x, y, z depending on the axis you want to rotate on. Use the arrow keys to rotate." << endl;
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   initGL();                       // Our own OpenGL initialization
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   printInstructions();            // Function to print instructions
   glutSpecialFunc(move);          // Function that enables the keyboard to move the llama
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
