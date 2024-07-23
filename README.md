# FdF
This project is about representing a landscape as a 3D object
> Note: I'll refactor this project soon.

---

## ***Clone the project***
```link
git clone git@github.com:0bvim/FdF.git
```

## ***Go to FdF repository and download MLX42 from codam***
```
$ cd FdF
$ git clone https://github.com/codam-coding-college/MLX42.git
```

### ***Now you need to build MLX with cmake and back to FdF directory***
```
$ cd MLX42
$ cmake -B build
$ cmake --build build -j4 # or do make -C build -j4
$ cd ../
```
> Ps: If you are in 42 school machine, you need to change update your cmake to `3.18` or above.
> If you can't update, change version requirement in file inside of MLX42 directory:
```
$ cd MLX42/
$ vim CMakeLists.txt

In following line change version to 3.16 or your cmake version (cmake --version):
cmake_minimum_required (VERSION 3.18.0) --> cmake_minimum_required (VERSION 3.16.0)
```
 
### Build FdF executable and run program
```
$ make or make bonus
$ ./fdf maps/42.fdf
```

> Mandatory part and bonus are separeted, so if you run `make` and then `make bonus` you'll see only bonus part.

### Mandatory 
* Mandatory part is basicaly print pixels in a windows and make it take Isometric Projection. * (My mandatory handle bonus too, except color)
### Bonus
* `Rotation, Translaction, Zoom In/Out, Extra Projection (like perspective)` and one bonus of your choice.*
