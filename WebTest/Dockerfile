FROM bryankp/opencv-static-wasm AS opencv-stage
RUN cd opencv && \
    cd static_wasm && \
    make install

FROM madmanfred/qt-webassembly AS boost-stage
MAINTAINER Lennart E.

#Install boost headers in emscripten directory
RUN mkdir -p /tmp/boost ;\
	cd /tmp/boost ;\
	wget -Oboost.tar.bz2 https://boostorg.jfrog.io/artifactory/main/release/1.66.0/source/boost_1_66_0.tar.bz2 ;\
	tar xjf boost.tar.bz2 ;\
	cd /tmp/boost/boost*/ ;\
	./bootstrap.sh ;\
	./b2 toolset=emscripten cxxflags=-std=c++17 system ;\
	mv /tmp/boost/boost_*/boost /boost/ ;\
	rm -rf /tmp/boost

FROM madmanfred/qt-webassembly
COPY --from=boost-stage /boost/ /emsdk_portable/sdk/system/include/boost/
COPY --from=opencv-stage /usr/local/include/opencv4/opencv2/ /emsdk_portable/sdk/system/include/opencv2/
COPY --from=opencv-stage /src/opencv/static_wasm/lib/ /opencv/static_wasm/lib/
