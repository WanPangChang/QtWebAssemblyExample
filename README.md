# Build
```shell
# Step 1
git clone https://github.com/WanPangChang/QtWebAssemblyExample.git

# Step 2: option 1
cd $HOME/QtWebAssemblyExample/WebTest
docker build -t wanpangchang/qt-webassembly-boost-opencv .

# Step 2: option 2
docker pull wanpangchang/qt-webassembly-boost-opencv

# Step 3
cd $HOME/QtWebAssemblyExample/WebTest
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost-opencv qmake
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost-opencv make -j8

# Step 4
python3 -m http.server
# open http://localhost:8000/WebTest.html
```

# Sample
1. https://wanpangchang.github.io/QtWebAssemblyExample/

# Reference
1. https://github.com/KnowledgePending/OpenCV-Static-WASM-Docker
2. https://github.com/Zebreus/qt-webassembly-docker
3. https://github.com/Zebreus/qt-webassembly-boost-docker
