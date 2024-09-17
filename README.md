**On a Comet - OpenGL Animation**

This project is an OpenGL-based animation simulating a simplified solar system. It features a rotating sun and a planet orbiting around it, demonstrating the use of basic 3D transformations and animations in OpenGL. The planet also has a white axis pole to represent its spinning motion.

**Features**

Sun (Yellow Sphere): A stationary sphere at the center of the scene, representing the sun.
Planet (Blue Sphere): A rotating and revolving planet that orbits around the sun.
Planet Axis (White Line): A visual representation of the planet's rotation axis.

**Libraries Used**

OpenGL (via GLUT) for rendering the 3D objects and handling window management.
GLUT for managing the display, reshaping, and timer functions.
Setup and Installation

To run this project, you will need the following installed:

OpenGL (via GLUT)
A C++ compiler (e.g., GCC)
On Linux / macOS

Install OpenGL libraries:
command
 sudo apt-get install freeglut3 freeglut3-dev  # On Ubuntu

**Compile and run the program:**

g++ -o comet comet.cpp -lGL -lGLU -lglut
./comet
On Windows
Install the necessary OpenGL libraries.
Compile the code using a suitable compiler (e.g., MinGW or Visual Studio).
Running the Program
After successfully compiling, run the program. You will see:

A yellow sphere at the center representing the sun.
A blue sphere orbiting the sun representing the planet, with a rotating motion on its axis.
The camera revolves around the objects to give a dynamic view of the scene.

Project Structure
main.cpp: Contains the OpenGL logic for rendering the sun, planet, and handling animations.
Wireframe Spheres: Used to represent both the sun and the planet, rendered with glutWireSphere.
Transformations: Applied using glRotatef, glTranslatef, and matrix stack functions.
Controls and Animation
Sun: Fixed at the center, rendered as a yellow wireframe sphere.
Planet: Revolves around the sun and rotates around its own axis.
Camera: Moves along a circular trajectory around the scene, offering different perspectives.
Known Issues
Some older or unsupported OpenGL functions may not work on modern systems. Ensure that the appropriate OpenGL and GLUT libraries are installed and up-to-date.
Check the accompanying README for more details on specific versions of libraries used.
Future Improvements
Add textures to the sun and planet for a more realistic effect.
Enhance the camera movement and introduce user controls for better interaction.
Add additional planets or moons to extend the simulation.
License
This project is open-source and available under the MIT License.
