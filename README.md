# Sel4-BSD

Status: In the working

An attempt at creating a bsd like environment ontop of the sel4 microkernel

The BSD projects have all been known to keep their traditional sort of style in their projects. This is what makes bsd an attractive option to many. 

# Building

To build any sel4 based projects you must make sure your machine has the requried dependencies. Please refer to https://docs.sel4.systems/projects/buildsystem/host-dependencies.html. See the Python and Base Build Dependencies sections.

Now, clone this directory and run init.sh to fetch external sources.

```
cd Sel4-BSD
./init.sh
```

This will clone all of the submodules in this repo.

Now that we have the required dependencies, it's time to build. Now create a build directory and run the build script. 

```
mkdir build
cd build
../init-build.sh -DPLATFORM=[PLATFORM] -DSIMULATION=TRUE
```

Obviously, replace [PLATFORM] with your platform. 

# Future Plans

- Use netbsd drivers
- VGA and HDMI support
- 3d and 2d graphics
- UFS file system support 
- Some posix programs
- USB Keyboard support
- Interactable command line
