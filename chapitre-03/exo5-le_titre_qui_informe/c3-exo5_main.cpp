#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include <sstream>  
#include <string>   

// AJOUTE : fonction qui construit le titre a partir de l'etat courant et l'applique
static void majTitre(nkentseu::NkWindow &window, const std::string &nomDocument, bool modifie) {
    auto taille = window.GetSize();
    std::ostringstream titre;
    titre << nomDocument << (modifie ? "*" : "") << " - " << taille.x << "x" << taille.y;
    window.SetTitle(titre.str().c_str());
}

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title  = "MonTitre, etape 02";
    cfg.width  = 800;  
    cfg.height = 600;   
    nkentseu::NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("Failed to create window");
        return -1;
    }

    std::string nomDocument = "MonTitre, etape 02"; 
    bool modifie = false;                            
    majTitre(window, nomDocument, modifie);           

    while (window.IsOpen()) {
        while (nkentseu::NkEvent* event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }

            if (event->Is<nkentseu::NkWindowResizeEvent>()) {
                majTitre(window, nomDocument, modifie);
            }

            
            if (event->Is<nkentseu::NkKeyPressEvent>()) {
                modifie = true;
                majTitre(window, nomDocument, modifie);
            }
        }
    }
    return 0;
}