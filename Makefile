# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1147/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1147/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cloud/OpticalTransmittanceBasedRouting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cloud/OpticalTransmittanceBasedRouting

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/1088/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/1147/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cloud/OpticalTransmittanceBasedRouting/CMakeFiles /home/cloud/OpticalTransmittanceBasedRouting//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cloud/OpticalTransmittanceBasedRouting/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named OpticalTransmittanceBasedRouting

# Build rule for target.
OpticalTransmittanceBasedRouting: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 OpticalTransmittanceBasedRouting
.PHONY : OpticalTransmittanceBasedRouting

# fast build rule for target.
OpticalTransmittanceBasedRouting/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/build
.PHONY : OpticalTransmittanceBasedRouting/fast

Algo/OpticalTransmittanceOptimizer.o: Algo/OpticalTransmittanceOptimizer.cpp.o
.PHONY : Algo/OpticalTransmittanceOptimizer.o

# target to build an object file
Algo/OpticalTransmittanceOptimizer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/OpticalTransmittanceOptimizer.cpp.o
.PHONY : Algo/OpticalTransmittanceOptimizer.cpp.o

Algo/OpticalTransmittanceOptimizer.i: Algo/OpticalTransmittanceOptimizer.cpp.i
.PHONY : Algo/OpticalTransmittanceOptimizer.i

# target to preprocess a source file
Algo/OpticalTransmittanceOptimizer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/OpticalTransmittanceOptimizer.cpp.i
.PHONY : Algo/OpticalTransmittanceOptimizer.cpp.i

Algo/OpticalTransmittanceOptimizer.s: Algo/OpticalTransmittanceOptimizer.cpp.s
.PHONY : Algo/OpticalTransmittanceOptimizer.s

# target to generate assembly for a file
Algo/OpticalTransmittanceOptimizer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/OpticalTransmittanceOptimizer.cpp.s
.PHONY : Algo/OpticalTransmittanceOptimizer.cpp.s

Algo/Path.o: Algo/Path.cpp.o
.PHONY : Algo/Path.o

# target to build an object file
Algo/Path.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/Path.cpp.o
.PHONY : Algo/Path.cpp.o

Algo/Path.i: Algo/Path.cpp.i
.PHONY : Algo/Path.i

# target to preprocess a source file
Algo/Path.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/Path.cpp.i
.PHONY : Algo/Path.cpp.i

Algo/Path.s: Algo/Path.cpp.s
.PHONY : Algo/Path.s

# target to generate assembly for a file
Algo/Path.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/Path.cpp.s
.PHONY : Algo/Path.cpp.s

Algo/ProxyEdge.o: Algo/ProxyEdge.cpp.o
.PHONY : Algo/ProxyEdge.o

# target to build an object file
Algo/ProxyEdge.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/ProxyEdge.cpp.o
.PHONY : Algo/ProxyEdge.cpp.o

Algo/ProxyEdge.i: Algo/ProxyEdge.cpp.i
.PHONY : Algo/ProxyEdge.i

# target to preprocess a source file
Algo/ProxyEdge.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/ProxyEdge.cpp.i
.PHONY : Algo/ProxyEdge.cpp.i

Algo/ProxyEdge.s: Algo/ProxyEdge.cpp.s
.PHONY : Algo/ProxyEdge.s

# target to generate assembly for a file
Algo/ProxyEdge.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Algo/ProxyEdge.cpp.s
.PHONY : Algo/ProxyEdge.cpp.s

SatData/Edge.o: SatData/Edge.cpp.o
.PHONY : SatData/Edge.o

# target to build an object file
SatData/Edge.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/Edge.cpp.o
.PHONY : SatData/Edge.cpp.o

SatData/Edge.i: SatData/Edge.cpp.i
.PHONY : SatData/Edge.i

# target to preprocess a source file
SatData/Edge.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/Edge.cpp.i
.PHONY : SatData/Edge.cpp.i

SatData/Edge.s: SatData/Edge.cpp.s
.PHONY : SatData/Edge.s

# target to generate assembly for a file
SatData/Edge.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/Edge.cpp.s
.PHONY : SatData/Edge.cpp.s

SatData/Network.o: SatData/Network.cpp.o
.PHONY : SatData/Network.o

# target to build an object file
SatData/Network.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/Network.cpp.o
.PHONY : SatData/Network.cpp.o

SatData/Network.i: SatData/Network.cpp.i
.PHONY : SatData/Network.i

# target to preprocess a source file
SatData/Network.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/Network.cpp.i
.PHONY : SatData/Network.cpp.i

SatData/Network.s: SatData/Network.cpp.s
.PHONY : SatData/Network.s

# target to generate assembly for a file
SatData/Network.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/Network.cpp.s
.PHONY : SatData/Network.cpp.s

SatData/SatelliteNode.o: SatData/SatelliteNode.cpp.o
.PHONY : SatData/SatelliteNode.o

# target to build an object file
SatData/SatelliteNode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/SatelliteNode.cpp.o
.PHONY : SatData/SatelliteNode.cpp.o

SatData/SatelliteNode.i: SatData/SatelliteNode.cpp.i
.PHONY : SatData/SatelliteNode.i

# target to preprocess a source file
SatData/SatelliteNode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/SatelliteNode.cpp.i
.PHONY : SatData/SatelliteNode.cpp.i

SatData/SatelliteNode.s: SatData/SatelliteNode.cpp.s
.PHONY : SatData/SatelliteNode.s

# target to generate assembly for a file
SatData/SatelliteNode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/SatData/SatelliteNode.cpp.s
.PHONY : SatData/SatelliteNode.cpp.s

Utility.o: Utility.cpp.o
.PHONY : Utility.o

# target to build an object file
Utility.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Utility.cpp.o
.PHONY : Utility.cpp.o

Utility.i: Utility.cpp.i
.PHONY : Utility.i

# target to preprocess a source file
Utility.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Utility.cpp.i
.PHONY : Utility.cpp.i

Utility.s: Utility.cpp.s
.PHONY : Utility.s

# target to generate assembly for a file
Utility.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/Utility.cpp.s
.PHONY : Utility.cpp.s

loadSats/LoadSat.o: loadSats/LoadSat.cpp.o
.PHONY : loadSats/LoadSat.o

# target to build an object file
loadSats/LoadSat.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/loadSats/LoadSat.cpp.o
.PHONY : loadSats/LoadSat.cpp.o

loadSats/LoadSat.i: loadSats/LoadSat.cpp.i
.PHONY : loadSats/LoadSat.i

# target to preprocess a source file
loadSats/LoadSat.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/loadSats/LoadSat.cpp.i
.PHONY : loadSats/LoadSat.cpp.i

loadSats/LoadSat.s: loadSats/LoadSat.cpp.s
.PHONY : loadSats/LoadSat.s

# target to generate assembly for a file
loadSats/LoadSat.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/loadSats/LoadSat.cpp.s
.PHONY : loadSats/LoadSat.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/OpticalTransmittanceBasedRouting.dir/build.make CMakeFiles/OpticalTransmittanceBasedRouting.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... OpticalTransmittanceBasedRouting"
	@echo "... Algo/OpticalTransmittanceOptimizer.o"
	@echo "... Algo/OpticalTransmittanceOptimizer.i"
	@echo "... Algo/OpticalTransmittanceOptimizer.s"
	@echo "... Algo/Path.o"
	@echo "... Algo/Path.i"
	@echo "... Algo/Path.s"
	@echo "... Algo/ProxyEdge.o"
	@echo "... Algo/ProxyEdge.i"
	@echo "... Algo/ProxyEdge.s"
	@echo "... SatData/Edge.o"
	@echo "... SatData/Edge.i"
	@echo "... SatData/Edge.s"
	@echo "... SatData/Network.o"
	@echo "... SatData/Network.i"
	@echo "... SatData/Network.s"
	@echo "... SatData/SatelliteNode.o"
	@echo "... SatData/SatelliteNode.i"
	@echo "... SatData/SatelliteNode.s"
	@echo "... Utility.o"
	@echo "... Utility.i"
	@echo "... Utility.s"
	@echo "... loadSats/LoadSat.o"
	@echo "... loadSats/LoadSat.i"
	@echo "... loadSats/LoadSat.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

