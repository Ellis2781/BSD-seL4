# Sel4-BSD
An attempt at creating a bsd like environment ontop of the sel4 microkernel

The BSD projects have all been known to keep their traditional sort of "style" in thier projects. This is what makes bsd an attractive option to many. 

# Building

To build this project, you must have google's repo installed. To build any sel4 based projects you must make sure your machine has the requried dependencies. Please refer to https://docs.sel4.systems/projects/buildsystem/host-dependencies.html

Now, create a new directory and run repo init to download the required dependencies for this project. Remember, don't worry if repo asks who you are.

```
mkdir Sel4-BSD
cd Sel4-BSD
repo init -u https://github.com/Ellis2781/Sel4-BSD
repo sync
```

Now that we have the required dependencies, it's time to build. Now create a build directory and run the build script. 

```
mkdir build
cd build
../init-build.sh -DPLATFORM=[PLATFORM] -DSIMULATION=TRUE
```

Obviously replace [PLATFORM] with your platform. This project is highly dependent on the rumpkernel so the only supported platforms are currently x86_64 and ia32.

# Future Plans

- Use newer drivers (rumpkernel drivers are quite old)
- VGA and HDMI support
- 3d and 2d graphics
