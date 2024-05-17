#include <stdio.h>
#include "Include/gif_lib.h"

int main() {
    int error;
    GifFileType *gif = DGifOpenFileName("Textures/miairl.gif", &error);
    if (gif == NULL) {
        fprintf(stderr, "Could not open GIF file: %s\n", GifErrorString(error));
        return 1;
    }

    if (DGifSlurp(gif) == GIF_ERROR) {
        fprintf(stderr, "Could not read GIF file: %s\n", GifErrorString(gif->Error));
        DGifCloseFile(gif, &error);
        return 1;
    }

    // Process the GIF as needed, for example, display it frame by frame
    // ...

    DGifCloseFile(gif, &error);
    return 0;
}
