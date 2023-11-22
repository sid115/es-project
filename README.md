# ES-Projekt

> Hinweis: Nutzt meine [GitHub-Anleitung](https://github.com/sid115/GitHubTutorial) als Hilfestellung. Eine Anleitung zur Syntax von Markdown findet ihr [hier](https://www.markdownguide.org/basic-syntax/).

## Beschreibung
Wir bauen ein Drohnen-Projekt.

## Arbeitspakete

### Hardware
1. Spannungsversorgung
1. Verdrahtung
1. Testaufbau
1. externe Platinen
    - Brücken
    - Spannungsversorgung
    - ...
1. Montage

### Software
1. Ansteuerung
    1. einzelne LEDs
    1. Panel (8x8 LEDs)
    1. Matrix  (3x5 Panele); mehr kaufen möglich?
    1. Implementierung in Schnittstelle
        - `set(R, G, B, x, y)`, `clear()`, `setup()`, ...
1. mit ULP3 fusionieren
1. Animation Drohne
1. Feld
    1. Generierung Labyrinth
    1. Brücken v mehr Panele

### Dokumentation
1. Allg. Beschreibung
1. Schaltplan
1. Bauplan
1. SA/RT-Modell

## Timeline

### Abgabefristen
Datum | Aufgabe
---|---
2023-12-12 | Abgabe ULP3
2023-12-20 | 2. Gruppebesprechung
2024-01-17 | Programm lauffähig
2024-01-24 | Abschluss: gemeinsames Inbetriebnehmen
2024-01-31 | Abgabe src und docs

### Aufgabenverteilung
![Gantt-Diagramm](./assets/gantt.png)
