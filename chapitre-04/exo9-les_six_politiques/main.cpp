#include <iostream>
#include <algorithm>

long long arrondiDiv(long long a, long long b) {
    return (2 * a + b) / (2 * b);
}

int main() {
    long long RW, RH, AW, AH, W, H;
    std::cin >> RW >> RH >> AW >> AH >> W >> H;

    bool ref = (RW > 0 && RH > 0);
    long long bandes = 0;

    auto emit = [&](const char* nom, long long vx, long long vy, long long vw, long long vh,
                     long long mw, long long mh) {
        std::cout << nom << " " << vx << " " << vy << " " << vw << " " << vh
                  << " " << mw << " " << mh << "\n";
        if (vw < W || vh < H) bandes++;
    };

    auto fitLetterbox = [&](long long &ovx, long long &ovy, long long &ovw, long long &ovh,
                             long long &omw, long long &omh) {
        if (!ref) { ovx = 0; ovy = 0; ovw = W; ovh = H; omw = W; omh = H; return; }
        omw = RW; omh = RH;
        if (W * RH <= H * RW) {
            ovw = W;
            ovh = arrondiDiv(RH * W, RW);
        } else {
            ovh = H;
            ovw = arrondiDiv(RW * H, RH);
        }
        ovx = (W - ovw) / 2;
        ovy = (H - ovh) / 2;
    };

    // FOLLOW_WINDOW
    emit("FOLLOW_WINDOW", 0, 0, W, H, W, H);

    // STRETCH
    if (ref) emit("STRETCH", 0, 0, W, H, RW, RH);
    else     emit("STRETCH", 0, 0, W, H, W, H);

    // FIT_LETTERBOX
    long long lx, ly, lw, lh, lmw, lmh;
    fitLetterbox(lx, ly, lw, lh, lmw, lmh);
    emit("FIT_LETTERBOX", lx, ly, lw, lh, lmw, lmh);

    // INTEGER_SCALE
    if (ref && W >= RW && H >= RH) {
        long long k = std::min(W / RW, H / RH);
        long long ivw = RW * k;
        long long ivh = RH * k;
        long long ivx = (W - ivw) / 2;
        long long ivy = (H - ivh) / 2;
        emit("INTEGER_SCALE", ivx, ivy, ivw, ivh, RW, RH);
    } else {
        long long fx, fy, fw, fh, fmw, fmh;
        fitLetterbox(fx, fy, fw, fh, fmw, fmh);
        emit("INTEGER_SCALE", fx, fy, fw, fh, fmw, fmh);
    }

    // FIT_CROP
    if (ref) {
        long long cmw, cmh;
        if (W * RH > H * RW) {
            cmw = RW;
            cmh = arrondiDiv(RW * H, W);
        } else {
            cmh = RH;
            cmw = arrondiDiv(RH * W, H);
        }
        emit("FIT_CROP", 0, 0, W, H, cmw, cmh);
    } else {
        emit("FIT_CROP", 0, 0, W, H, W, H);
    }

    // MANUAL
    emit("MANUAL", 0, 0, AW, AH, AW, AH);

    bool deformation = ref && (W * RH != H * RW);

    std::cout << "BANDES " << bandes << "\n";
    std::cout << "DEFORMATION " << (deformation ? "OUI" : "NON") << "\n";

    return 0;
}
