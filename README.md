Math
====

**Math** is a C++ library designed to extend the functionality of the [UtilsCPP](https://github.com/Thomas-Chqt/UtilsCPP.git) library for projects that require efficient linear algebra operations. It provides essential tools for handling vectors and matrices, making it ideal for graphics programming. 

The library is still under active development and is being built alongside other projects, with new functionality added as needed to meet evolving project requirements.

Features
--------

This library includes various structures for vectors and matrices:

- **Vectors**
  - `vec2f` : 2D vector of floats
  - `vec3f` : 3D vector of floats
  - `vec4f` : 4D vector of floats
- **Matrices**
  - `mat3x3` : 3x3 matrix of floats
  - `mat4x4` : 4x4 matrix of floats

In addition to basic arithmetic operations such as vector addition and subtraction or matrix multiplications, **Math** also supports more advanced features:

- Matrix determinant and inversion functions
- Generation of rotation, translation, and scale matrices

The types in this library are fully compatible with Apple's Metal graphics API in terms of size and alignment, ensuring smooth integration with Metal Shading Language (MSL) for graphics programming.

Build
-----

CMake is used as the build system. The recommended way to use the library is to clone the repository inside your project and use `add_subdirectory`.

Alternatively, the library can be built separately using CMake.

```sh
mkdir build
cmake -S . -B build
cmake --build build
```

| CMake Option          | Default Value | Description                |
|-----------------------|---------------|----------------------------|
| `BUILD_SHARED_LIBS`   | OFF           | Build as shared library    |
| `MATH_BUILD_TESTS`    | OFF           | Build the test executable  |
| `MATH_INSTALL`        | ON            | Enable the install command |

Learning
--------

Writing this Math library helped me deepen my understanding of several key concepts.  
One of the biggest challenges was learning linear algebra, as I hadn't studied it formally beyond basic vectors. I had to teach myself how to perform operations like matrix multiplication.  
Additionally, this project improved my knowledge of C++ templates, particularly template specialization.  
Ensuring compatibility with Apple's Metal API also presented a challenge, as I initially faced issues with memory alignment. After consulting the Metal Shading Language documentation, I successfully resolved these problems using `alignas()`.