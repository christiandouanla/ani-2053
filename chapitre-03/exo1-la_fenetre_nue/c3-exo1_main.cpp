#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "MonTitre, etape 02";
    cfg.width = 720;
    cfg.height = 550;

    nkentseu::NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("Failed to create window");
        return -1;
    }

    while (window.IsOpen()) {
        while (nkentseu::NkEvent* event = nkentseu::NkEvents().PollEvent()) {
        if (event->Is<nkentseu::NkWindowCloseEvent>()) {
            window.Close();
        }
        }
    }
    return 0;
}
