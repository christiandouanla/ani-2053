#include "NKWindow/NKMain.h"
#include "NKCanvas/App/NkCanvasApp.h"
using namespace nkentseu ;
using namespace nkentseu::renderer ;

class FenetreNue : public NkCanvasApp {
public:
    FenetreNue() {
        Config().title      = "Fenetre nue";
        Config().width      = 800;
        Config().height     = 600;
        Config().clearColor = NkColor2D(30, 30, 40, 255);
    }
};

int nkmain(const NkEntryState &state) {
    return NkCanvasApp::Run<FenetreNue>(state);
}
