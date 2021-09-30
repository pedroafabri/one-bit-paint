rm -rf ./build
mkdir ./build
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o build/onebitpaint.o main.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o build/onebitpaint.gb build/onebitpaint.o