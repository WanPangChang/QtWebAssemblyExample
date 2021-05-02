
FROM bryankp/opencv-static-wasm AS opencv-stage

FROM madmanfred/qt-webassembly-boost
COPY --from=opencv-stage /src/opencv/include/ /opencv/include/
COPY --from=opencv-stage /src/opencv/modules/ /opencv/modules/
COPY --from=opencv-stage /src/opencv/static_wasm/lib/ /opencv/static_wasm/lib/
