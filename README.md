# Deklaratív programozás Cékla (C++) házi

Ezt a Cékla (C++) házit a Deklaratív programozás tantárgyhoz készítettem a BME-s tanulmányaim során a 2013/2014/1. félévben.

## A feladat

Egy S>0 egész szám A>1 alapú összekevert változatát a következőképpen definiáljuk:

  - Írjuk fel az S számot A alapú számrendszerben. A kapott számjegyeket jelölje S<sub>1</sub>, ..., S<sub>k</sub>. Az átíráskor nem használhatunk vezető nullákat, azaz S<sub>1</sub> ≠ 0.
  - A számjegysorozatot rendezzük át úgy, hogy
    - a páratlan indexű számjegyek a maradjanak helyükön;
    - a páros indexű számjegyek sorrendje forduljon meg, azaz S<sub>2</sub> és az utolsó páros indexű számjegy cseréljen helyet, éppúgy mint S<sub>4</sub> és és utolsó előtti páros indexű számjegy sít.

    Pontosítva és formalizálva:
      - ha k páros, akkor az eredmény S<sub>1</sub>, S<sub>k</sub>, S<sub>3</sub>, S<sub>k-2</sub>, ..., S<sub>4</sub>, S<sub>k-1</sub>, S<sub>2</sub> legyen;
      - ha k páratlan, akkor az eredmény S<sub>1</sub>, S<sub>k-1</sub>, S<sub>3</sub>, S<sub>k-3</sub>, ..., S<sub>4</sub>, S<sub>k-2</sub>, S<sub>2</sub>, S<sub>k</sub> legyen.

  - Az átrendezett számjegysorozatot tekintsük A alapú számrendszerben felírt számnak. Az így kapott szám értékét nevezzük az S szám A alapú összekevert változatának.


Például az 1234 szám 10-es alapú összekevert változata 1432, az 1234567 szám 10-es alapú összekevert változata pedig 1634527.

Írjon olyan programot Cékla nyelven (a C++ nyelv egy deklaratív résznyelvén), amelynek fő függvénye az `int osszekevert(const int S, const int A){...}` függvény.

``` cpp
/* osszekevert(S, A) == SK, ha SK az S szám A alapú összekevert
   változata (S>0, A>1 egész számok).
   Egy S szám A alapú összekevertjét úgy kapjuk meg, hogy az S számot felírjuk
   az A alapú számrendszerben, a számjegyeit egy listával ábrázoljuk, a
   listát a fentiek szerint átrendezzük, majd a kapott lista elemeit
   egy A alapú szám jegyeinek tekintve előállítjuk a keresett értéket.
*/
int osszekevert(const int S, const int A) {
  ...
}
```
A jobbrekurzív függvények kevesebb memóriát használnak, mint az egyéb rekurzív függvények, ezért a használatukat ajánljuk, azonban a pontozáskor csak azt vizsgáljuk, hogy a program a megadott (néhány másodperces) időkorláton belül előállítja-e a helyes megoldást.

### Mintamegoldás speciális esetre

Az alábbi mintamegoldás csak akkor működik helyesen, ha S < A<sup>4</sup>:

```cpp
int osszekevert(const int S, const int A) {
  if (S<A*A*A) return S;
  return ((S/A/A/A*A+S%A)*A+S/A%A)*A+S/A/A%A;
}
```
### Gyakorló feladatok

A házi feladat megoldásának előkészítésére a következő kisebb gyakorló feladatok megoldását javasoljuk.
  - Lista szeletének (i. és j. sorszámú elemek közötti részének) előállítása.
  - Sorfolytonosan, illetve oszlopfolytonosan tárolt mátrix i. sorának előallítása.
  - Sorfolytonosan, illetve oszlopfolytonosan tárolt mátrix j. oszlopának előállítása.
  - Sorok listájaként tárolt mátrix sorfolytonosan, illetve oszlopfolytonosan tárolt változatának előállítása.
  - Sorfolytonosan, illetve oszlopfolytonosan tárolt mátrix sorok listájaként tárolt változatának előállítása.

### Példák

```cpp
|* osszekevert(1234, 10);
1432
|* osszekevert(12345, 10);
14325
|*
1011
|* osszekevert(12, 2);
9 // mert 122 = 1 1 0 0 és 92 = 1 0 0 1
|* osszekevert(1023, 10);
1320
|* osszekevert(38, 3);
46 // mert 383 = 1 1 0 2, és 463 = 1 2 0 1
|* osszekevert(46, 3);
38
|* osszekevert(183654729, 10);
123456789
|* osszekevert(18365472, 10);
12345678
|*
```
