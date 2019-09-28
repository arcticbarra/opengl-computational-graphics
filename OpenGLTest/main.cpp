//
//  main.cpp
//  OpenGLTest
//
//  Created by Enrique Barragán on 8/19/19.
//  Copyright © 2019 Enrique Barragán. All rights reserved.
//
#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <fstream>

using namespace std;


char title[] = "3D Shapes";
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void render_cube(vector<vector<vector<float>>> sides, float factors[3][3]) {
  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
       // Top face (y = 1.0f)
       // Define vertices in counter-clockwise (CCW) order with normal pointing out
  for (int i = 0; i < sides.size(); i++) {
    vector<vector<float>> side = sides[i];
//    glColor3f(0.658824f, 0.658824f, 0.658824f);     // Light Gray
    // Random colors
    glColor3f(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)));
    for (int j = 0; j < side.size(); j++) {
      vector<float> coords = side[j];
      glVertex3f((coords[0] * factors[1][0]) + factors[0][0], (coords[1] * factors[1][1]) + factors[0][1], (coords[2] * factors[1][2]) + factors[0][2]);
    }
  }
  glEnd();  // End of drawing color-cube
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, 0.0f);  // Move right and into the screen
  vector<vector<vector<vector<float>>>> figures;
//
//  ifstream file;
//  file.open("output.txt");
//  char output[100];
//  if (file.is_open()) {
//    while (!file.eof()) {
//       file >> output;
//       cout<<output;
//    }
//  }
//
    // PAWS
    figures.push_back( // right_front_paw
    {
        {
            // front
            {0.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {1.3f, 1.0f, 0.0f},
            {1.3f, 0.0f, 0.0f}
        },
        {
            // back
            {0.0f, 0.0f, -3.0f},
            {0.0f, 1.0f, -3.0f},
            {1.3f, 1.0f, -3.0f},
            {1.3f, 0.0f, -3.0f}
        },
        {
            // left
            {0.0f, 0.0f, -3.0f},
            {0.0f, 1.0f, -3.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 0.0f}
        },
        {
            // top
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, -3.0f},
            {1.3f, 1.0f, -3.0f},
            {1.3f, 1.0f, 0.0f}
        },
        {
            // right
            {1.3f, 0.0f, 0.0f},
            {1.3f, 1.0f, 0.0f},
            {1.3f, 1.0f, -3.0f},
            {1.3f, 0.0f, -3.0f}
        },
        {
            // bottom
            {0.0f, 0.0f, 0.0f},
            {0.0f, 0.0f, -3.0f},
            {1.3f, 0.0f, -3.0f},
            {1.3f, 0.0f, 0.0f}
        }
    }
    );

    figures.push_back( // left_front_paw
    {
        {
            // front
            {3.3f, 0.0f, 0.0f},
            {3.3f, 1.0f, 0.0f},
            {4.6f, 1.0f, 0.0f},
            {4.6f, 0.0f, 0.0f}
        },
        {
            // back
            {3.3f, 0.0f, -3.0f},
            {3.3f, 1.0f, -3.0f},
            {4.6f, 1.0f, -3.0f},
            {4.6f, 0.0f, -3.0f}
        },
        {
            // left
            {3.3f, 0.0f, -3.0f},
            {3.3f, 1.0f, -3.0f},
            {3.3f, 1.0f, 0.0f},
            {3.3f, 0.0f, 0.0f}
        },
        {
            // top
            {3.3f, 1.0f, 0.0f},
            {3.3f, 1.0f, -3.0f},
            {4.6f, 1.0f, -3.0f},
            {4.6f, 1.0f, 0.0f}
        },
        {
            // right
            {4.6f, 0.0f, 0.0f},
            {4.6f, 1.0f, 0.0f},
            {4.6f, 1.0f, -3.0f},
            {4.6f, 0.0f, -3.0f}
        },
        {
            // bottom
            {3.3f, 0.0f, 0.0f},
            {3.3f, 0.0f, -3.0f},
            {4.6f, 0.0f, -3.0f},
            {4.6f, 0.0f, 0.0f}
        }
    }
    );

    figures.push_back( // right_back_paw
    {
        {
            // front
            {0.0f, 0.0f, -7.0f},
            {0.0f, 1.0f, -7.0f},
            {1.3f, 1.0f, -7.0f},
            {1.3f, 0.0f, -7.0f}
        },
        {
            // back
            {0.0f, 0.0f, -10.0f},
            {0.0f, 1.0f, -10.0f},
            {1.3f, 1.0f, -10.0f},
            {1.3f, 0.0f, -10.0f}
        },
        {
            // left
            {0.0f, 0.0f, -10.0f},
            {0.0f, 1.0f, -10.0f},
            {0.0f, 1.0f, -7.0f},
            {0.0f, 0.0f, -7.0f}
        },
        {
            // top
            {0.0f, 1.0f, -7.0f},
            {0.0f, 1.0f, -10.0f},
            {1.3f, 1.0f, -10.0f},
            {1.3f, 1.0f, -7.0f}
        },
        {
            // right
            {1.3f, 0.0f, -7.0f},
            {1.3f, 1.0f, -7.0f},
            {1.3f, 1.0f, -10.0f},
            {1.3f, 0.0f, -10.0f}
        },
        {
            // bottom
            {0.0f, 0.0f, -7.0f},
            {0.0f, 0.0f, -10.0f},
            {1.3f, 0.0f, -10.0f},
            {1.3f, 0.0f, -7.0f}
        }
    }
    );
    
    figures.push_back( // left_back_paw
    {
        {
            // front
            {3.3f, 0.0f, -7.0f},
            {3.3f, 1.0f, -7.0f},
            {4.6f, 1.0f, -7.0f},
            {4.6f, 0.0f, -7.0f}
        },
        {
            // back
            {3.3f, 0.0f, -10.0f},
            {3.3f, 1.0f, -10.0f},
            {4.6f, 1.0f, -10.0f},
            {4.6f, 0.0f, -10.0f}
        },
        {
            // left
            {3.3f, 0.0f, -10.0f},
            {3.3f, 1.0f, -10.0f},
            {3.3f, 1.0f, -7.0f},
            {3.3f, 0.0f, -7.0f}
        },
        {
            // top
            {3.3f, 1.0f, -7.0f},
            {3.3f, 1.0f, -10.0f},
            {4.6f, 1.0f, -10.0f},
            {4.6f, 1.0f, -7.0f}
        },
        {
            // right
            {4.6f, 0.0f, -7.0f},
            {4.6f, 1.0f, -7.0f},
            {4.6f, 1.0f, -10.0f},
            {4.6f, 0.0f, -10.0f}
        },
        {
            // bottom
            {3.3f, 0.0f, -7.0f},
            {3.3f, 0.0f, -10.0f},
            {4.6f, 0.0f, -10.0f},
            {4.6f, 0.0f, -7.0f}
        }
    }
    );
    
    // LOWER LEG
    figures.push_back( // right_front_lower_leg
    {
        {
            // front
            {0.0f, 1.0f, -1.5f},
            {0.0f, 3.5f, -1.5f},
            {1.3f, 3.5f, -1.5f},
            {1.3f, 1.0f, -1.5f}
        },
        {
            // back
            {0.0f, 1.0f, -3.0f},
            {0.0f, 3.5f, -3.0f},
            {1.3f, 3.5f, -3.0f},
            {1.3f, 1.0f, -3.0f}
        },
        {
            // left
            {0.0f, 1.0f, -3.0f},
            {0.0f, 3.5f, -3.0f},
            {0.0f, 3.5f, -1.5f},
            {0.0f, 1.0f, -1.5f}
        },
        {
            // top
            {0.0f, 3.5f, -1.5f},
            {0.0f, 3.5f, -3.0f},
            {1.3f, 3.5f, -3.0f},
            {1.3f, 3.5f, -1.5f}
        },
        {
            // right
            {1.3f, 1.0f, -1.5f},
            {1.3f, 3.5f, -1.5f},
            {1.3f, 3.5f, -3.0f},
            {1.3f, 1.0f, -3.0f}
        },
        {
            // bottom
            {0.0f, 1.0f, -1.5f},
            {0.0f, 1.0f, -3.0f},
            {1.3f, 1.0f, -3.0f},
            {1.3f, 1.0f, -1.5f}
        }
    }
    );
    
    figures.push_back( // left_front_lower_leg
    {
        {
            // front
            {3.3f, 1.0f, -1.5f},
            {3.3f, 3.5f, -1.5f},
            {4.6f, 3.5f, -1.5f},
            {4.6f, 1.0f, -1.5f}
        },
        {
            // back
            {3.3f, 1.0f, -3.0f},
            {3.3f, 3.5f, -3.0f},
            {4.6f, 3.5f, -3.0f},
            {4.6f, 1.0f, -3.0f}
        },
        {
            // left
            {3.3f, 1.0f, -3.0f},
            {3.3f, 3.5f, -3.0f},
            {3.3f, 3.5f, -1.5f},
            {3.3f, 1.0f, -1.5f}
        },
        {
            // top
            {3.3f, 3.5f, -1.5f},
            {3.3f, 3.5f, -3.0f},
            {4.6f, 3.5f, -3.0f},
            {4.6f, 3.5f, -1.5f}
        },
        {
            // right
            {4.6f, 1.0f, -1.5f},
            {4.6f, 3.5f, -1.5f},
            {4.6f, 3.5f, -3.0f},
            {4.6f, 1.0f, -3.0f}
        },
        {
            // bottom
            {3.3f, 1.0f, -1.5f},
            {3.3f, 1.0f, -3.0f},
            {4.6f, 1.0f, -3.0f},
            {4.6f, 1.0f, -1.5f}
        }
    }
    );

    figures.push_back( // right_back_lower_leg
    {
        {
            // front
            {0.0f, 1.0f, -8.5f},
            {0.0f, 3.5f, -8.5f},
            {1.3f, 3.5f, -8.5f},
            {1.3f, 1.0f, -8.5f}
        },
        {
            // back
            {0.0f, 1.0f, -10.0f},
            {0.0f, 3.5f, -10.0f},
            {1.3f, 3.5f, -10.0f},
            {1.3f, 1.0f, -10.0f}
        },
        {
            // left
            {0.0f, 1.0f, -10.0f},
            {0.0f, 3.5f, -10.0f},
            {0.0f, 3.5f, -8.5f},
            {0.0f, 1.0f, -8.5f}
        },
        {
            // top
            {0.0f, 3.5f, -8.5f},
            {0.0f, 3.5f, -10.0f},
            {1.3f, 3.5f, -10.0f},
            {1.3f, 3.5f, -8.5f}
        },
        {
            // right
            {1.3f, 1.0f, -8.5f},
            {1.3f, 3.5f, -8.5f},
            {1.3f, 3.5f, -10.0f},
            {1.3f, 1.0f, -10.0f}
        },
        {
            // bottom
            {0.0f, 1.0f, -8.5f},
            {0.0f, 1.0f, -10.0f},
            {1.3f, 1.0f, -10.0f},
            {1.3f, 1.0f, -8.5f}
        }
    }
    );
    
    figures.push_back( // left_back_lower_leg
    {
        {
            // front
            {3.3f, 1.0f, -8.5f},
            {3.3f, 3.5f, -8.5f},
            {4.6f, 3.5f, -8.5f},
            {4.6f, 1.0f, -8.5f}
        },
        {
            // back
            {3.3f, 1.0f, -10.0f},
            {3.3f, 3.5f, -10.0f},
            {4.6f, 3.5f, -10.0f},
            {4.6f, 1.0f, -10.0f}
        },
        {
            // left
            {3.3f, 1.0f, -10.0f},
            {3.3f, 3.5f, -10.0f},
            {3.3f, 3.5f, -8.5f},
            {3.3f, 1.0f, -8.5f}
        },
        {
            // top
            {3.3f, 3.5f, -8.5f},
            {3.3f, 3.5f, -10.0f},
            {4.6f, 3.5f, -10.0f},
            {4.6f, 3.5f, -8.5f}
        },
        {
            // right
            {4.6f, 1.0f, -8.5f},
            {4.6f, 3.5f, -8.5f},
            {4.6f, 3.5f, -10.0f},
            {4.6f, 1.0f, -10.0f}
        },
        {
            // bottom
            {3.3f, 1.0f, -8.5f},
            {3.3f, 1.0f, -10.0f},
            {4.6f, 1.0f, -10.0f},
            {4.6f, 1.0f, -8.5f}
        }
    }
    );
    
    // UPPER LEG
    figures.push_back( // right_front_upper_leg
    {
        {
            // front
            {-0.5f, 3.5f, -1.2f},
            {-0.5f, 5.0f, -1.2f},
            {1.8f, 5.0f, -1.2f},
            {1.8f, 3.5f, -1.2f}
        },
        {
            // back
            {-0.5f, 3.5f, -3.3f},
            {-0.5f, 5.0f, -3.3f},
            {1.8f, 5.0f, -3.3f},
            {1.8f, 3.5f, -3.3f}
        },
        {
            // left
            {-0.5f, 3.5f, -3.3f},
            {-0.5f, 5.0f, -3.3f},
            {-0.5f, 5.0f, -1.2f},
            {-0.5f, 3.5f, -1.2f}
        },
        {
            // top
            {-0.5f, 5.0f, -1.2f},
            {-0.5f, 5.0f, -3.3f},
            {1.8f, 5.0f, -3.3f},
            {1.8f, 5.0f, -1.2f}
        },
        {
            // right
            {1.8f, 3.5f, -1.2f},
            {1.8f, 5.0f, -1.2f},
            {1.8f, 5.0f, -3.3f},
            {1.8f, 3.5f, -3.3f}
        },
        {
            // bottom
            {-0.5f, 3.5f, -1.2f},
            {-0.5f, 3.5f, -3.3f},
            {1.8f, 3.5f, -3.3f},
            {1.8f, 3.5f, -1.2f}
        }
    }
    );
    
    figures.push_back( // left_front_upper_leg
    {
        {
            // front
            {2.8f, 3.5f, -1.2f},
            {2.8f, 5.0f, -1.2f},
            {5.1f, 5.0f, -1.2f},
            {5.1f, 3.5f, -1.2f}
        },
        {
            // back
            {2.8f, 3.5f, -3.3f},
            {2.8f, 5.0f, -3.3f},
            {5.1f, 5.0f, -3.3f},
            {5.1f, 3.5f, -3.3f}
        },
        {
            // left
            {2.8f, 3.5f, -3.3f},
            {2.8f, 5.0f, -3.3f},
            {2.8f, 5.0f, -1.2f},
            {2.8f, 3.5f, -1.2f}
        },
        {
            // top
            {2.8f, 5.0f, -1.2f},
            {2.8f, 5.0f, -3.3f},
            {5.1f, 5.0f, -3.3f},
            {5.1f, 5.0f, -1.2f}
        },
        {
            // right
            {5.1f, 3.5f, -1.2f},
            {5.1f, 5.0f, -1.2f},
            {5.1f, 5.0f, -3.3f},
            {5.1f, 3.5f, -3.3f}
        },
        {
            // bottom
            {2.8f, 3.5f, -1.2f},
            {2.8f, 3.5f, -3.3f},
            {5.1f, 3.5f, -3.3f},
            {5.1f, 3.5f, -1.2f}
        }
    }
    );

    figures.push_back( // right_back_upper_leg
    {
        {
            // front
            {-0.5f, 3.5f, -8.2f},
            {-0.5f, 5.0f, -8.2f},
            {1.8f, 5.0f, -8.2f},
            {1.8f, 3.5f, -8.2f}
        },
        {
            // back
            {-0.5f, 3.5f, -10.3f},
            {-0.5f, 5.0f, -10.3f},
            {1.8f, 5.0f, -10.3f},
            {1.8f, 3.5f, -10.3f}
        },
        {
            // left
            {-0.5f, 3.5f, -10.3f},
            {-0.5f, 5.0f, -10.3f},
            {-0.5f, 5.0f, -8.2f},
            {-0.5f, 3.5f, -8.2f}
        },
        {
            // top
            {-0.5f, 5.0f, -8.2f},
            {-0.5f, 5.0f, -10.3f},
            {1.8f, 5.0f, -10.3f},
            {1.8f, 5.0f, -8.2f}
        },
        {
            // right
            {1.8f, 3.5f, -8.2f},
            {1.8f, 5.0f, -8.2f},
            {1.8f, 5.0f, -10.3f},
            {1.8f, 3.5f, -10.3f}
        },
        {
            // bottom
            {-0.5f, 3.5f, -8.2f},
            {-0.5f, 3.5f, -10.3f},
            {1.8f, 3.5f, -10.3f},
            {1.8f, 3.5f, -8.2f}
        }
    }
    );
    
    figures.push_back( // left_back_lower_leg
    {
        {
            // front
            {2.8f, 3.5f, -8.2f},
            {2.8f, 5.0f, -8.2f},
            {5.1f, 5.0f, -8.2f},
            {5.1f, 3.5f, -8.2f}
        },
        {
            // back
            {2.8f, 3.5f, -10.3f},
            {2.8f, 5.0f, -10.3f},
            {5.1f, 5.0f, -10.3f},
            {5.1f, 3.5f, -10.3f}
        },
        {
            // left
            {2.8f, 3.5f, -10.3f},
            {2.8f, 5.0f, -10.3f},
            {2.8f, 5.0f, -8.2f},
            {2.8f, 3.5f, -8.2f}
        },
        {
            // top
            {2.8f, 5.0f, -8.2f},
            {2.8f, 5.0f, -10.3f},
            {5.1f, 5.0f, -10.3f},
            {5.1f, 5.0f, -8.2f}
        },
        {
            // right
            {5.1f, 3.5f, -8.2f},
            {5.1f, 5.0f, -8.2f},
            {5.1f, 5.0f, -10.3f},
            {5.1f, 3.5f, -10.3f}
        },
        {
            // bottom
            {2.8f, 3.5f, -8.2f},
            {2.8f, 3.5f, -10.3f},
            {5.1f, 3.5f, -10.3f},
            {5.1f, 3.5f, -8.2f}
        }
    }
    );
    
    // BODY
    figures.push_back(
    {
        {
            // front
            {-0.5f, 5.0f, -1.2f},
            {-0.5f, 11.0f, -1.2f},
            {5.1f, 11.0f, -1.2f},
            {5.1f, 5.0f, -1.2f}
        },
        {
            // back
            {5.1f, 5.0f, -10.3f},
            {5.1f, 11.0f, -10.3f},
            {-0.5f, 11.0f, -10.3f},
            {-0.5f, 5.0f, -10.3f}
        },
        {
            // left
            {-0.5f, 5.0f, -10.3f},
            {-0.5f, 11.0f, -10.3f},
            {-0.5f, 11.0f, -1.2f},
            {-0.5f, 5.0f, -1.2f}
        },
        {
            // top
            {-0.5f, 11.0f, -1.2f},
            {-0.5f, 11.0f, -10.3f},
            {5.1f, 11.0f, -10.3f},
            {5.1f, 11.0f, -1.2f}
        },
        {
            // right
            {5.1f, 5.0f, -1.2f},
            {5.1f, 11.0f, -1.2f},
            {5.1f, 11.0f, -10.3f},
            {5.1f, 5.0f, -10.3f}
        },
        {
            // bottom
            {5.1f, 5.0f, -1.2f},
            {5.1f, 5.0f, -10.3f},
            {-0.5f, 5.0f, -10.3f},
            {-0.5f, 5.0f, -1.2f}
        }
    }
    );
    
    // TAIL
    figures.push_back(
    {
        {
            // front
            {1.8f, 8.0f, -10.8f},
            {1.8f, 12.0f, -10.8f},
            {2.8f, 12.0f, -10.8f},
            {2.8f, 8.0f, -10.8f}
        },
        {
            // back
            {1.8f, 8.0f, -9.8f},
            {1.8f, 12.0f, -9.8f},
            {2.8f, 12.0f, -9.8f},
            {2.8f, 8.0f, -9.8f}
        },
        {
            // left
            {1.8f, 8.0f, -9.8f},
            {1.8f, 12.0f, -9.8f},
            {1.8f, 12.0f, -10.8f},
            {1.8f, 8.0f, -10.8f}
        },
        {
            // top
            {1.8f, 12.0f, -10.8f},
            {1.8f, 12.0f, -9.8f},
            {2.8f, 12.0f, -9.8f},
            {2.8f, 12.0f, -10.8f}
        },
        {
            // right
            {2.8f, 8.0f, -10.8f},
            {2.8f, 12.0f, -10.8f},
            {2.8f, 12.0f, -9.8f},
            {2.8f, 8.0f, -9.8f}
        },
        {
            // bottom
            {1.8f, 8.0f, -9.8f},
            {1.8f, 8.0f, -10.8f},
            {2.8f, 8.0f, -10.8f},
            {2.8f, 8.0f, -9.8f}
        }
    }
    );
    
    // NECK
    figures.push_back(
    {
        {
            // front
            {1.5f, 5.0f, 0.5f},
            {1.5f, 15.0f, 0.5f},
            {4.1f, 15.0f, 0.5f},
            {4.1f, 5.0f, 0.5f}
        },
        {
            // back
            {1.5f, 5.0f, -1.0f},
            {1.5f, 15.0f, -1.0f},
            {4.1f, 15.0f, -1.0f},
            {4.1f, 5.0f, -1.0f}
        },
        {
            // left (your left if you're seeing the llama from the front)
            {1.5f, 5.0f, -1.0f},
            {1.5f, 15.0f, -1.0f},
            {1.5f, 15.0f, 0.5f},
            {1.5f, 5.0f, 0.5f}
        },
        {
            // top
            {1.5f, 15.0f, 0.5f},
            {1.5f, 15.0f, -1.0f},
            {4.1f, 15.0f, -1.0f},
            {4.1f, 15.0f, 0.5f}
        },
        {
            // right
            {4.1f, 5.0f, 0.5f},
            {4.1f, 15.0f, 0.5f},
            {4.1f, 15.0f, -1.0f},
            {4.1f, 5.0f, -1.0f}
        },
        {
            // bottom
            {1.5f, 5.0f, -1.0f},
            {1.5f, 5.0f, 0.5f},
            {4.1f, 5.0f, 0.5f},
            {4.1f, 5.0f, -1.0f}
        }
    }
    );
    
    //EARS
    figures.push_back( // right
    {
        {
            // front
            {1.5f, 15.0f, -0.25f},
            {1.5f, 16.5f, -0.25f},
            {2.5f, 16.5f, -0.25f},
            {2.5f, 15.0f, -0.25f}
        },
        {
            // back
            {1.5f, 15.0f, -1.0f},
            {1.5f, 16.5f, -1.0f},
            {2.5f, 16.5f, -1.0f},
            {2.5f, 15.0f, -1.0f}
        },
        {
            // left (your left if you're seeing the llama from the front)
            {1.5f, 15.0f, -1.0f},
            {1.5f, 16.5f, -1.0f},
            {1.5f, 16.5f, -0.25f},
            {1.5f, 15.0f, -0.25f}
        },
        {
            // top
            {1.5f, 16.5f, -0.25f},
            {1.5f, 16.5f, -1.0f},
            {2.5f, 16.5f, -1.0f},
            {2.5f, 16.5f, -0.25f}
        },
        {
            // right
            {2.5f, 15.0f, -0.25f},
            {2.5f, 16.5f, -0.25f},
            {2.5f, 16.5f, -1.0f},
            {2.5f, 15.0f, -1.0f}
        },
        {
            // bottom
            {1.5f, 15.0f, -0.25f},
            {1.5f, 15.0f, -1.0f},
            {2.5f, 15.0f, -1.0f},
            {2.5f, 15.0f, -0.25f}
        }
    }
    );
    
    figures.push_back( // left
    {
        {
            // front
            {3.1f, 15.0f, -0.25f},
            {3.1f, 16.5f, -0.25f},
            {4.1f, 16.5f, -0.25f},
            {4.1f, 15.0f, -0.25f}
        },
        {
            // back
            {3.1f, 15.0f, -1.0f},
            {3.1f, 16.5f, -1.0f},
            {4.1f, 16.5f, -1.0f},
            {4.1f, 15.0f, -1.0f}
        },
        {
            // left (your left if you're seeing the llama from the front)
            {3.1f, 15.0f, -1.0f},
            {3.1f, 16.5f, -1.0f},
            {3.1f, 16.5f, -0.25f},
            {3.1f, 15.0f, -0.25f}
        },
        {
            // top
            {3.1f, 16.5f, -0.25f},
            {3.1f, 16.5f, -1.0f},
            {4.1f, 16.5f, -1.0f},
            {4.1f, 16.5f, -0.25f}
        },
        {
            // right
            {4.1f, 15.0f, -0.25f},
            {4.1f, 16.5f, -0.25f},
            {4.1f, 16.5f, -1.0f},
            {4.1f, 15.0f, -1.0f}
        },
        {
            // bottom
            {3.1f, 15.0f, -0.25f},
            {3.1f, 15.0f, -1.0f},
            {4.1f, 15.0f, -1.0f},
            {4.1f, 15.0f, -0.25f}
        }
    }
    );
    
    // EYES
    figures.push_back( // right
    {
        {
            // front
            {4.1f, 13.0f, 0.5f},
            {4.1f, 14.5f, 0.5f},
            {4.6f, 14.5f, 0.5f},
            {4.6f, 13.0f, 0.5f}
        },
        {
            // back
            {4.1f, 13.0f, -1.0f},
            {4.1f, 14.5f, -1.0f},
            {4.6f, 14.5f, -1.0f},
            {4.6f, 13.0f, -1.0f}
        },
        {
            // left (your left if you're seeing the llama from the front)
            {4.1f, 13.0f, -1.0f},
            {4.1f, 14.5f, -1.0f},
            {4.1f, 14.5f, 0.5f},
            {4.1f, 13.0f, 0.5f}
        },
        {
            // top
            {4.1f, 14.5f, 0.5f},
            {4.1f, 14.5f, -1.0f},
            {4.6f, 14.5f, -1.0f},
            {4.6f, 14.5f, 0.5f}
        },
        {
            // right
            {4.6f, 13.0f, 0.5f},
            {4.6f, 14.5f, 0.5f},
            {4.6f, 14.5f, -1.0f},
            {4.6f, 13.0f, -1.0f}
        },
        {
            // bottom
            {4.1f, 13.0f, 0.5f},
            {4.1f, 13.0f, -1.0f},
            {4.6f, 13.0f, -1.0f},
            {4.6f, 13.0f, 0.5f}
        }
    }
    );
    
    figures.push_back( // left
    {
        {
            // front
            {1.0f, 13.0f, 0.5f},
            {1.0f, 14.5f, 0.5f},
            {1.5f, 14.5f, 0.5f},
            {1.5f, 13.0f, 0.5f}
        },
        {
            // back
            {1.0f, 13.0f, -1.0f},
            {1.0f, 14.5f, -1.0f},
            {1.5f, 14.5f, -1.0f},
            {1.5f, 13.0f, -1.0f}
        },
        {
            // left (your left if you're seeing the llama from the front)
            {1.0f, 13.0f, -1.0f},
            {1.0f, 14.5f, -1.0f},
            {1.0f, 14.5f, 0.5f},
            {1.0f, 13.0f, 0.5f}
        },
        {
            // top
            {1.0f, 14.5f, 0.5f},
            {1.0f, 14.5f, -1.0f},
            {1.5f, 14.5f, -1.0f},
            {1.5f, 14.5f, 0.5f}
        },
        {
            // right
            {1.5f, 13.0f, 0.5f},
            {1.5f, 14.5f, 0.5f},
            {1.5f, 14.5f, -1.0f},
            {1.5f, 13.0f, -1.0f}
        },
        {
            // bottom
            {1.0f, 13.0f, 0.5f},
            {1.0f, 13.0f, -1.0f},
            {1.5f, 13.0f, -1.0f},
            {1.5f, 13.0f, 0.5f}
        }
    }
    );
    
    // PUPILS
    figures.push_back( // right
    {
        {
            // front
            {4.6f, 13.5f, 0.0f},
            {4.6f, 14.0f, 0.0f},
            {4.7f, 14.0f, 0.0f},
            {4.7f, 13.5f, 0.0f}
        },
        {
            // back
            {4.6f, 13.5f, -0.5f},
            {4.6f, 14.0f, -0.5f},
            {4.7f, 14.0f, -0.5f},
            {4.7f, 13.5f, -0.5f}
        },
        {
            // left (your left if you're seeing the llama from the front)
            {4.6f, 13.5f, -0.5f},
            {4.6f, 14.0f, -0.5f},
            {4.6f, 14.0f, 0.0f},
            {4.6f, 13.5f, 0.0f}
        },
        {
            // top
            {4.6f, 14.0f, 0.0f},
            {4.6f, 14.0f, -0.5f},
            {4.7f, 14.0f, -0.5f},
            {4.7f, 14.0f, 0.0f}
        },
        {
            // right
            {4.7f, 13.5f, 0.0f},
            {4.7f, 14.0f, 0.0f},
            {4.7f, 14.0f, -0.5f},
            {4.7f, 13.5f, -0.5f}
        },
        {
            // bottom
            {4.6f, 13.5f, 0.0f},
            {4.6f, 13.5f, -0.5f},
            {4.7f, 13.5f, -0.5f},
            {4.7f, 13.5f, 0.0f}
        }
    }
    );
  
  
  // CHANGE HERE TO TRANSLATE!!!
  float translation_factor_x = 0;
  float translation_factor_y = 0;
  float translation_factor_z = 0;
  
  // CHANGE HERE TO SCALE!!!
  float scaling_factor_x = 1;
  float scaling_factor_y = 1;
  float scaling_factor_z = 1;
  
  // CHANGE HERE TO ROTATE!!! (Not used for this first part)
  float rotating_factor_x = 0;
  float rotating_factor_y = 0;
  float rotating_factor_z = 0;
  
  float factors[3][3] = {
    {translation_factor_x, translation_factor_y, translation_factor_z},
    {scaling_factor_x, scaling_factor_y, scaling_factor_z},
    {rotating_factor_x, rotating_factor_y, rotating_factor_z}
  };
  
  for (int i = 0; i < figures.size(); i++) {
    render_cube(figures[i], factors);
  }
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(90.0f, aspect, 0.1f, 100.0f);
    gluLookAt(12.0, 20.0, 5.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.); /* up is in positive Y direction */
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
