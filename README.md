# Prolog++
## Summary
Some subset of Prolog written in modern C++.
## Building
```
cmake -S . -B ninjabuilddebug -G Ninja \ 
  -DCMAKE_BUILD_TYPE=debug \
  -DVCPKG_TARGET_TRIPLET=x64-osx \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```
