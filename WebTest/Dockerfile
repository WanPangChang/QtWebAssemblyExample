
FROM bryankp/opencv-static-wasm AS opencv-stage

FROM madmanfred/qt-webassembly-boost
COPY --from=opencv-stage /src/opencv/include/opencv2/ /emsdk_portable/sdk/system/include/opencv2/
COPY --from=opencv-stage /src/opencv/static_wasm/lib/ /opencv/static_wasm/lib/
