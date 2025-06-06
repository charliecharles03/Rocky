# Rocky  

**Rocky** is a OpenGL project to simulate real world physics

## 🛠 Prerequisites  

Make sure you have the following installed before building the project:  

- **CMake** (for generating build files)  
- **GCC** (modern version, preferably GCC 13 or later)  
- **GLFW3** (for window and input management)  
- **GLAD** (included in the project, but you can update or install it system-wide)  

> **Note**: You **don’t need to install GLAD separately**, as the required files are already included in the project. However, you can update it or install it globally if needed.  

## 🔧 Build Instructions  

To build and run **Rocky**, follow these steps:  

1. **Create a build directory** (to keep things tidy)  
    ```bash
    mkdir build
    cd build
    ```

2. **Run CMake** (to generate the Makefile)  
    ```bash
    cmake ..
    ```

3. **Compile the project**  
    ```bash
    make
    ```

4. **Run the executable**  
    ```bash
    ./OpenGLApp
    ```

## 📌 What Does It Do?  

- Opens an **OpenGL window** using GLFW.  
- Renders cubes 9 of them to be precise.
- gives you the ability to move around using w a s d and escape to close the window
- Displays the output in a **resizable window**.  

## 🚀 Future Improvements  

- Add **textures** and **shaders**.  
- Implement **keyboard controls**.  
- Support **3D transformations** with GLM.  

