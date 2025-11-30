# ECOSYSTEMES
 Simulateur d'Écosystème — Conforme au cahier de charge

## Résumé
Projet C++17 implémentant un simulateur d'écosystème conforme au cahier de charge du professeur.
Architecture POO, séparation Core / Graphics, gestion mémoire RAII (`unique_ptr`), rendu via SDL3.

## Structure attendue

ecosystem_simulator/
├── include/
│   ├── Core/
│   │   ├── Structs.hpp
│   │   ├── Entity.hpp
│   │   └── Ecosystem.hpp
│   └── Graphics/
│       └── Window.hpp
├── src/
│   ├── Core/
│   │   ├── Time.hpp
│   │   ├── Time.cpp
│   │   ├── Entity.cpp
│   │   └── Ecosystem.cpp
│   ├── Graphics/
│   │   └── Window.cpp
│   └── main.cpp
├── CMakeLists.txt
└── README.md
Fonctionnalités implémentéeslantes; carnivores mangent herbivores.
- **Reproduction** : Conditions : énergie suffisante, âge minimal. Coût énergétique.
- **Comportement** : Mouvement aléatoire, recherche simple via distances.
- **Affichage SDL3** : Entités affichées en rectangles colorés, barre d'énergie, fond neutre.
- **Contrôles** : Espace (pause), R (reset), F (ajouter nourriture), ↑/↓ (vitesse), ESC (quitter).
- **Statistiques** : Affichage console.
- **Gestion mémoire** : `std::unique_ptr` pour entités, destructeurs corrects.

## Paramètres & équilibrage
- Herbivore energy consumption: `1.5` / s
- Carnivore energy consumption: `2.0` / s
- Plant energy generation: `0.5` / s
- Herbivore eat distance: `12.0`
- Carnivore eat distance: `18.0`

## Compilation
Prérequis : SDL3 dev libs, C++17 toolchain, CMake 3.16+

```bash
mkdir build
cd build
cmake ..
cmake --build .
./ecosystem_simulator

Controls

SPACE : Pause / Resume

R : Reset simulation

F : Spawn food (plants) at center

UP/DOWN : Simulation speed

ESC : Quit

- **Types d'entités** : Herbivores (bleu), Carnivores (rouge), Plantes (vert).
- **Système d'énergie** : Plantes génèrent, animaux dépensent. Mort si énergie <= 0.
- **Vieillissement** : Age et durée de vie maximale. Mort par vieillesse.
- **Alimentation** : Herbivores mangent p

Tests recommandés

Lancer la simulation 60–120s pour vérifier l'équilibre.

Vérifier avec Valgrind / ASAN pour les fuites.

Tester avec 100+ entités pour performance.


