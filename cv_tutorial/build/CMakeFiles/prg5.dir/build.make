# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/p82maavd/Desktop/fsiv/cv_tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/p82maavd/Desktop/fsiv/cv_tutorial/build

# Include any dependencies generated for this target.
include CMakeFiles/prg5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prg5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prg5.dir/flags.make

CMakeFiles/prg5.dir/prg5.cpp.o: CMakeFiles/prg5.dir/flags.make
CMakeFiles/prg5.dir/prg5.cpp.o: ../prg5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/p82maavd/Desktop/fsiv/cv_tutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prg5.dir/prg5.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prg5.dir/prg5.cpp.o -c /home/p82maavd/Desktop/fsiv/cv_tutorial/prg5.cpp

CMakeFiles/prg5.dir/prg5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prg5.dir/prg5.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/p82maavd/Desktop/fsiv/cv_tutorial/prg5.cpp > CMakeFiles/prg5.dir/prg5.cpp.i

CMakeFiles/prg5.dir/prg5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prg5.dir/prg5.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/p82maavd/Desktop/fsiv/cv_tutorial/prg5.cpp -o CMakeFiles/prg5.dir/prg5.cpp.s

# Object files for target prg5
prg5_OBJECTS = \
"CMakeFiles/prg5.dir/prg5.cpp.o"

# External object files for target prg5
prg5_EXTERNAL_OBJECTS =

prg5: CMakeFiles/prg5.dir/prg5.cpp.o
prg5: CMakeFiles/prg5.dir/build.make
prg5: /usr/local/lib/libopencv_stitching.so.3.4.7
prg5: /usr/local/lib/libopencv_superres.so.3.4.7
prg5: /usr/local/lib/libopencv_videostab.so.3.4.7
prg5: /usr/local/lib/libopencv_aruco.so.3.4.7
prg5: /usr/local/lib/libopencv_bgsegm.so.3.4.7
prg5: /usr/local/lib/libopencv_bioinspired.so.3.4.7
prg5: /usr/local/lib/libopencv_ccalib.so.3.4.7
prg5: /usr/local/lib/libopencv_dnn_objdetect.so.3.4.7
prg5: /usr/local/lib/libopencv_dpm.so.3.4.7
prg5: /usr/local/lib/libopencv_face.so.3.4.7
prg5: /usr/local/lib/libopencv_freetype.so.3.4.7
prg5: /usr/local/lib/libopencv_fuzzy.so.3.4.7
prg5: /usr/local/lib/libopencv_hfs.so.3.4.7
prg5: /usr/local/lib/libopencv_img_hash.so.3.4.7
prg5: /usr/local/lib/libopencv_line_descriptor.so.3.4.7
prg5: /usr/local/lib/libopencv_optflow.so.3.4.7
prg5: /usr/local/lib/libopencv_reg.so.3.4.7
prg5: /usr/local/lib/libopencv_rgbd.so.3.4.7
prg5: /usr/local/lib/libopencv_saliency.so.3.4.7
prg5: /usr/local/lib/libopencv_stereo.so.3.4.7
prg5: /usr/local/lib/libopencv_structured_light.so.3.4.7
prg5: /usr/local/lib/libopencv_surface_matching.so.3.4.7
prg5: /usr/local/lib/libopencv_tracking.so.3.4.7
prg5: /usr/local/lib/libopencv_xfeatures2d.so.3.4.7
prg5: /usr/local/lib/libopencv_ximgproc.so.3.4.7
prg5: /usr/local/lib/libopencv_xobjdetect.so.3.4.7
prg5: /usr/local/lib/libopencv_xphoto.so.3.4.7
prg5: /usr/local/lib/libopencv_shape.so.3.4.7
prg5: /usr/local/lib/libopencv_phase_unwrapping.so.3.4.7
prg5: /usr/local/lib/libopencv_video.so.3.4.7
prg5: /usr/local/lib/libopencv_datasets.so.3.4.7
prg5: /usr/local/lib/libopencv_plot.so.3.4.7
prg5: /usr/local/lib/libopencv_text.so.3.4.7
prg5: /usr/local/lib/libopencv_dnn.so.3.4.7
prg5: /usr/local/lib/libopencv_highgui.so.3.4.7
prg5: /usr/local/lib/libopencv_ml.so.3.4.7
prg5: /usr/local/lib/libopencv_videoio.so.3.4.7
prg5: /usr/local/lib/libopencv_imgcodecs.so.3.4.7
prg5: /usr/local/lib/libopencv_objdetect.so.3.4.7
prg5: /usr/local/lib/libopencv_calib3d.so.3.4.7
prg5: /usr/local/lib/libopencv_features2d.so.3.4.7
prg5: /usr/local/lib/libopencv_flann.so.3.4.7
prg5: /usr/local/lib/libopencv_photo.so.3.4.7
prg5: /usr/local/lib/libopencv_imgproc.so.3.4.7
prg5: /usr/local/lib/libopencv_core.so.3.4.7
prg5: CMakeFiles/prg5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/p82maavd/Desktop/fsiv/cv_tutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prg5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prg5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prg5.dir/build: prg5

.PHONY : CMakeFiles/prg5.dir/build

CMakeFiles/prg5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prg5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prg5.dir/clean

CMakeFiles/prg5.dir/depend:
	cd /home/p82maavd/Desktop/fsiv/cv_tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/p82maavd/Desktop/fsiv/cv_tutorial /home/p82maavd/Desktop/fsiv/cv_tutorial /home/p82maavd/Desktop/fsiv/cv_tutorial/build /home/p82maavd/Desktop/fsiv/cv_tutorial/build /home/p82maavd/Desktop/fsiv/cv_tutorial/build/CMakeFiles/prg5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prg5.dir/depend

