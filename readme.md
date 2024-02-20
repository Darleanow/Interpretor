## Interpretor
---

#### How to build

Generate a build folder using this command, you can edit the generator
```cmake
cmake -S . -B build -G "Visual Studio 17 2022"
```

Then cd into the `build` folder:
```sh
cd build
```

Finally, build the relase:
```cmake
cmake --build . --config Release
```

The .exe will be at build/Release/

---
Enjoy !
---