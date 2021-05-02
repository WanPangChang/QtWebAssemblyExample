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
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost-opencv make -j24
docker run --rm -p 8000:8000 -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly-boost-opencv python3 -m http.server
```
