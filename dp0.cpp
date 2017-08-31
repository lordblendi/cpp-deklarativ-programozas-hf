//segédfgv length_help(L,N) = N+L hossza, N-ben tárolom az addigi elemek számát
int length_help(list l, int n){
	if(nil == l) return n;
	return length_help(tl(l), n+1);
}

//length(L) = L lista hossza
int list_length(list l){
	return length_help(l, 0);
}

//insert_nth(L,N,E) L lista olyan másolata, amelyben az L lista n-edik és N+1-edik eleme közé be van szúrva az E elem (a lista számozása 0-tól kezdõdik)
list insert_nth(list l, int n, int e){
	if(n==0) return cons(e, l);
	return cons(hd(l), insert_nth(tl(l), n-1, e));
}

//number_to_base(n, b, l) az n számot visszaadja az l listában b számrendszerben
list number_to_base(int n, int b, list l){
	if(n<b) return cons(n, l);
	return number_to_base((n-n%b)/b, b, cons(n%b, l));
}
//number_to_base_ten(l,alap,szorzo,szam, i) az l listát visszadja számként 10-es számrendszerben. b a számrender, amiben a szám van, i  hanyadik elemnél tartok, szorzo az aktuális szorzó (=hatványai az alapnak), szam pedig hogy mennyi az aktuális összeg
int number_to_base_ten(list l, int alap, int szorzo, int szam, int i){
	if(i < 0) return szam;
	return szam + number_to_base_ten(l, alap, szorzo*alap, nth(l, i)* szorzo, i-1);

}

//nth(l,n) visszadja az l lista n-edik elemét. a számozás 0-tól kezdõdik
int nth(list l, int n){
	if(n==0) return hd(l);
	return nth(tl(l), n-1);
}

//split(l,r,n) r-ben visszaad minden második számot az l listából. n értékétõl függõen ez lehetnek páros vagy páratlan sorszámú elem
list split(list l, list r, int n){
	if(n > 1) return split(l, cons(nth(l,n),r),n-2);
	return cons(nth(l,n), r);
}

//paratlan(l) visszaadja az L lista páratlan helyiértéken álló elemeit -> megfelelõ n értékkel meghívja a splitet
list paratlan(list l){
	if((list_length(l) % 2) == 0) return split(l, nil, list_length(l)-2);
	return split(l, nil, list_length(l)-1);
}

//paros(l) visszaadja az L lista páros helyiértéken álló elemeit -> megfelelõ n értékkel meghívja a splitet
list paros(list l){
	if((list_length(l) % 2) == 0) return split(l, nil, list_length(l)-1);
	return split(l, nil, list_length(l)-2);
}

//páratlan listába a páros lista elemeit megfordítva beleszúrjuk
list beszur(list paratlan, list paros){
	return beszur_help(paratlan, paros, list_length(paros)-1, 1);

}

//beszur_help(paratlan, paros, n, i) segédfgv a beszúrhoz, beszúrja a paratlan lista minden 2. elemének a paros listát visszafelé. n és i tartják számon, hogy melyik listában hanyadik elemnél tartok
list beszur_help(list paratlan, list paros, int n, int i){
	if(n < 0) return paratlan;
	return beszur_help(insert_nth(paratlan, i, nth(paros,n)), paros, n-1, i+2);

}

/* osszekevert(S, A) == SK, ha SK az S szám A alapú összekevert
   változata (S>0, A>1 egész számok).
   Egy S szám A alapú összekevertjét úgy kapjuk meg, hogy az S számot felírjuk
   az A alapú számrendszerben, a számjegyeit egy listával ábrázoljuk, a
   listát a fentiek szerint átrendezzük, majd a kapott lista elemeit
   egy A alapú szám jegyeinek tekintve elõállítjuk a keresett értéket.

  ha a lista hossza <4, akkor felesleges cserélgetnünk, mert csak 1 párosodik szám van, és felesleges cserélgetni
*/
int osszekevert(const int S, const int A) {
 if(list_length(number_to_base(S,A,nil))<4) return S;
  return number_to_base_ten(beszur(paratlan(number_to_base(S,A,nil)), paros(number_to_base(S,A,nil)))  , A,1,0,list_length(beszur(paratlan(number_to_base(S,A,nil)), paros(number_to_base(S,A,nil))))-1);
}
