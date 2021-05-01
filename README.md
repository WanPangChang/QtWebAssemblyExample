```shell
# Step 1
git clone https://github.com/WanPangChang/QtWebAssemblyExample.git

# Step 2: option 1
git clone https://github.com/Zebreus/qt-webassembly-boost-docker.git
cd $HOME/qt-webassembly-boost-docker
# In $HOME/qt-webassembly-boost-docker/Dockerfile,
# replace https://vorboss.dl.sourceforge.net/project/boost/boost/1.66.0/boost_1_66_0.tar.bz2
# with https://boostorg.jfrog.io/artifactory/main/release/1.66.0/source/boost_1_66_0.tar.bz2
# Concatenate $HOME/qt-webassembly-boost-docker/Dockerfile
# and https://github.com/KnowledgePending/OpenCV-Static-WASM-Docker/blob/master/Dockerfile
docker build -t wanpangchang/qt-webassembly-boost-opencv --build-arg QT_WASM_BASE=madmanfred/qt-webassembly .

# Step 2: option 2
docker pull wanpangchang/qt-webassembly-boost

# Step 3
cd $HOME/QtWebAssemblyExample/WebTest
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost qmake
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost make -j24
docker run --rm -p 8000:8000 -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost python3 -m http.server
```
