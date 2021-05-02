FROM bryankp/opencv-static-wasm AS opencv-stage
RUN cd opencv && \
    cd static_wasm && \
    make install

FROM madmanfred/qt-webassembly-boost AS boost-stage

FROM madmanfred/qt-webassembly
COPY --from=boost-stage /boost/ /emsdk_portable/sdk/system/include/boost/
COPY --from=opencv-stage /usr/local/include/opencv4/opencv2/ /emsdk_portable/sdk/system/include/opencv2/
COPY --from=opencv-stage /src/opencv/static_wasm/lib/ /opencv/static_wasm/lib/
