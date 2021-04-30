```bash
git clone https://github.com/WanPangChang/QtWebAssemblyExample.git
docker pull wanpangchang/qt-webassembly
cd QtWebAssemblyExample/WebTest/
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly qmake
docker run --rm -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly make -j24
docker run --rm -p 8000:8000 -v $HOME/QtWebAssemblyExample/WebTest:/src/ wanpangchang/qt-webassembly python3 -m http.server
```
