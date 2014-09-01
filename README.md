OpenSMOKEppPostProcessor
========================

Graphical Post Processor for OpenSMOKE++ solvers (based on Qt 5.3)

COMPILATION
-----------
In order to compile the OpenSMOKEppPostProcessor the Qt Libraries (version 5.3 or higher) are needed.
The Qt libraries are available for free at the following web-address:
`http://qt-project.org/downloads`

1. Windows
   The `projects/Windows/OpenSMOKEppPostProcessor` provides a project for Microsoft Visual Studio

2. Linux
   Go to the `projects/Linux` folder and run the following instructions:
   ```
   qmake QtOpenSMOKE_PostProcessor.pro
   make clean
   make
   ```
