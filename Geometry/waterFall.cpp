#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

// Definiciones iniciales.
typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

const Double INF = 1ll << 60;
const Double ERROR = 1e-9;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

// Punto en 2D.
struct Punto {
  Double x, y;
  Punto() : x(), y() {}
  Punto(Double X, Double Y) : x(X), y(Y) {}
  // Izquierda a derecha, abajo a arriba.
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }

  //Sumar los vectores actual y q.
  Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
  //Restar los vectores (o trasladarlos), tomando p como el origen.
  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
  //Obtener el vector opuesto.
  Punto operator -() const { return Punto(-x, -y); }
  //Obtener el vector por un escalar.
  Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
  //Obtener el vector dividido por un escalar.
  Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
  //Magnitud del vector.
  Double Abs() const { return hypot(x, y); }
  //Magnitud elevada al cuadrado del vector.
  Double Norm() const{ return x*x + y*y; }
  //Distancia entre el punto actual y q.
  Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
  //Distancia elevada al cuadrado entre el punto actual y q.
  Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
  //Producto punto entre el punto actual y q.
  Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
  //Producto cruz entre el punto actual y q.
  Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }

  //Rotar 90 grados en CCW.
  Punto rot90() const { return Punto(-y, x); }

  //Rotar t radianes en cw respecto al origen.
  Punto RotarCW(const Double& t) const {
    return Punto( x*cos(t) + y*sin(t),
            y*cos(t) - x*sin(t));
  }
  //Rotar t radianes en ccw respecto al origen.
  Punto RotarCCW(const Double& t) const {
    return Punto( x*cos(t) - y*sin(t), 
            y*cos(t) + x*sin(t));
  }
};

//Conversion de grados a radianes.
Double GradARad(Double grd) {
  return (grd * M_PI) / 180.0;
}

// Conversion de radianes a grados.
Double RadAGrad(Double rad) {
  return (rad * 180.0) / M_PI;
}

//Angulo mas chico formado por los puntos aob en radianes.
Double Angulo(const Punto& a, const Punto& o, const Punto& b){
  Punto u(a - o), v(b - o);
  return acos( u.Dot(v) / (u.Abs() * v.Abs()));
}

// Test de mano derecha: CCW = 1, CW = -1, Colineal = 0.
int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
  Double ccw = (p-o).Cruz(q-o);
  return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

// Linea en 2D.
struct Linea {
  Punto p, q;
  Double a, b, c;
  Linea() : p(), q(), a(), b(), c() {}
  Linea(Long A, Long B, Long C)
    : p(), q(), a(A), b(B), c(C) {
    if (EQ(a, 0)) {
      c /= -b; b = -1;
      p = Punto(0, c);
      q = Punto(1, c);
    } else if (EQ(b, 0)) {
      c /= -a; a = -1;
      p = Punto(c, 0);
      q = Punto(c, 1);
    } else {
      p = Punto(-c/a, 0);
      q = Punto(-(b+c)/a, 0);
    } if (q < p) swap(p, q);
  }
  bool isEntre(Punto punto){
	if(p.x <= punto.x && q.x >= punto.x ){
		return true;
	}
	return false;
  }
  Linea(const Punto& P, const Punto& Q)
    : p(P), q(Q), a(), b(), c() {
    // Asegura p como punto menor.
    if (q < p) swap(p, q);
    a = q.y - p.y;
    b = p.x - q.x;
    if (!a) c = p.y, b = -1;
    else if (!b) c = p.x, a = -1;
    else c = -a*p.x - b*p.y;
  }
  // PELIGRO! Ordena por ecuacion de recta.
  bool operator<(const Linea& cmp) const {
    if (!EQ(a, cmp.a)) return a < cmp.a;
    if (!EQ(b, cmp.b)) return b < cmp.b;
    return EQ(c, cmp.c)? false: c < cmp.c;
  }
};

// Saber si un punto p esta en la recta r.
bool PuntoEnRecta(const Punto& p, const Linea& r){
  return !ManoDerecha( r.p, r.q, p );
}
// Saber si un punto p esta en el segmento s.
bool PuntoEnSegmento(const Punto& p, const Linea& s) {
  return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}

// Saber si dos lineas l y m son paralelas.
bool LineasParalelas(const Linea& l, const Linea& m) {
  return EQ( 0, ( l.q - l.p ).Cruz( m.q - m.p ) );
}

// Saber si dos lineas l y m son iguales.
bool LineasIguales(const Linea& l, const Linea& m) {
  return LineasParalelas(l, m)
    && EQ( 0, ( l.p - l.q ).Cruz( l.p - m.q ) )
    && EQ( 0, ( m.q - m.p ).Cruz( m.q - l.p ) );
}
// Saber si dos lineas l y m son perpendiculares.
bool LineasPerpendiculares(const Linea& l, const Linea& m) {
  return EQ( 0, ( l.q - l.p ).Dot( m.q - m.p ) );
}

// Obtener una linea paralela a l que pase por p.
Linea ParalelaEnPunto(const Linea& l, const Punto& p) {
  return Linea(p, p + ( l.q - l.p ));
}

// Obtener una linea perpendicular a l que pase por p.
Linea PerpendicularEnPunto(const Linea& l, const Punto& p) {
  return Linea(p, p + ( l.q - l.p ).rot90());
}

// Saber si dos rectas r y s se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.
int InterseccionRectas(const Linea& r, const Linea& s) {
  if (LineasIguales(r, s)) return -1;
  return LineasParalelas(r, s)? 0: 1;
}

// Saber si una recta r y un segmento s se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.
int IntersecRectaSegmen(const Linea& r, const Linea& s) {
  if (LineasIguales(r, s)) return -1;
  if (LineasParalelas(r, s)) return 0;
  int t1 = ManoDerecha(r.p, r.q, s.p);
  int t2 = ManoDerecha(r.p, r.q, s.q);
  return (t1 != t2)? 1: 0;
}

// Saber si dos segmentos s y t se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.
int InterseccionSegmentos(const Linea& s, const Linea& t) {
  int t1 = ManoDerecha(s.p, s.q, t.p);
  int t2 = ManoDerecha(s.p, s.q, t.q);

  if (t1 == t2) return t1? 0:
    (PuntoEnSegmento(s.p, t) ||
     PuntoEnSegmento(s.q, t) ||
     PuntoEnSegmento(t.p, s) ||
     PuntoEnSegmento(t.q, s))? -1: 0;

  return (ManoDerecha(t.p, t.q, s.p) !=
      ManoDerecha(t.p, t.q, s.q))? 1: 0;
}

// Obtener punto de interseccion entre lineas l y m.
Punto PuntoInterseccion(const Linea& l, const Linea& m) {
  Punto a = l.p, b = l.q, c = m.p, d = m.q;
  b = b-a; d = c-d; c =c-a;
  assert( !LineasParalelas( l, m ) );
  return a + b*(c.Cruz( d )/b.Cruz( d ));
}
// Obtener proyeccion del vector v en la recta r.
Punto ProyeccionEnRecta(const Punto& v, const Linea& r) {
  return r.p + ( r.q - r.p ) * 
      (( v - r.p ).Dot( r.q - r.p )/( r.q  - r.p ).Norm());
}

// Distancia entre un punto p y una recta r.
Double DistanciaPuntoRecta(const Punto& p, const Linea& r) {
  return p.Dist(ProyeccionEnRecta(p, r));
}

// Distancia entre un punto p y un segmento s.
Double DistanciaPuntoSegmento(const Punto& p, const Linea& s) {
  Punto proy = ProyeccionEnRecta(p, s);
  if (proy < s.p) return p.Dist(s.p);
  if (s.q < proy) return p.Dist(s.q);
  return p.Dist(proy);
}

// Distancia entre dos lineas l y m.
Double DistanciaRectaRecta(const Linea& l, const Linea& m) {
  return LineasParalelas(l, m)? DistanciaPuntoRecta(l.p, m): 0;
}

// Distancia entre dos segmentos s y r.
Double DistanciaSegmenSegmen(const Linea& s, const Linea& r) {
  if (InterseccionSegmentos(s, r)) return 0;
  return min(min(DistanciaPuntoSegmento(s.p, r),
           DistanciaPuntoSegmento(s.q, r)),
         min(DistanciaPuntoSegmento(r.p, s),
           DistanciaPuntoSegmento(r.q, s)));
}

// Un poligono es una serie de
// vertices conectados por aristas.
// P = p1 -> p2 -> p3 -> ... -> pn -> p1.
typedef vector<Punto> Poligono;

// Saber si un punto esta en el perimetro de un poligono.
bool PuntoEnPerimetro(const Punto& p, const Poligono& P) {
  for (int i = 1; i < P.size(); ++i) {
    if( PuntoEnSegmento( p, Linea( P[i-1], P[i] ) ) ) return true;
  }
  return false;
}

// Punto en poligono concavo por ray casting.
// En el perimetro = -1, Fuera = 0, Dentro = 1.
/*int RayCasting(const Punto& p, const Poligono& P) {
  if (PuntoEnPerimetro(p, P)) return -1;
  Punto o = *min_element(P.begin(), P.end());
  Linea rayo(p, Punto(o.x - M_PI, o.y - M_E));
  int cruces = 0;
  for (int i = 1; i < P.size(); ++i)
    if (InterseccionSegmentos(rayo,
      Linea(P[i - 1], P[i]))) ++cruces;
  return cruces & 1;
}*/

// Area de un poligono.
Double Area(const Poligono& P) {
  Double area = 0;
  for (int i = 1; i < P.size(); ++i)
    area += P[i - 1].Cruz(P[i]);
  return fabs(area) / 2.0;
}
// Perimetro de un poligono.
Double Perimetro(const Poligono& P) {
  Double perimetro = 0;
  for (int i = 1; i < P.size(); ++i)
    perimetro += P[i].Dist(P[i - 1]);
  return perimetro;
}

// Cerco convexo de un conjunto de puntos.
template<class It> Poligono CercoConvexo(It lo, It hi) {
  int k = 0;
  if (hi - lo <= 1) return Poligono(lo, hi);    
  Poligono H(2 * (int)(hi - lo));
  sort(lo, hi);

  for (It it = lo; it != hi; ++it) {
    while (k >= 2 && ManoDerecha(H[k - 2], H[k - 1], *it) < 1) k--;
    H[k++] = *it;
  }
  int t = k + 1;
  for (It it = hi - 2; it != lo - 1; --it) {
    while (k >= t && ManoDerecha(H[k - 2], H[k - 1], *it) < 1) k--;
    H[k++] = *it;
  }
  H.resize(k);
  return H;
}
vector<Linea> lineas;
int t,l,s;
void backtrack(Punto punto){
	//cout << "Probando con " << punto.x << " " << punto.y << endl;
	bool status = false;
	Punto res;
	double distancia = 1000000;
	for(int i = 0; i < lineas.size(); i++){
		//cout << lineas[i].p.x << " " << lineas[i].p.y << " " << lineas[i].q.x << " " << lineas[i].q.y << "=" << ManoDerecha(lineas[i].p,lineas[i].q,punto) << endl;
		if (lineas[i].q < lineas[i].p) swap(lineas[i].p, lineas[i].q);
		if(ManoDerecha(lineas[i].p,lineas[i].q,punto) == 1 && lineas[i].isEntre(punto)){
			//cout << lineas[i].p.x << " " << lineas[i].p.y << " " << lineas[i].q.x << " " << lineas[i].q.y << endl;
			double d = DistanciaPuntoSegmento(punto,lineas[i]);
			status = true;
			if(d < distancia){
				distancia = d;
				//cout << distancia << endl;
				if(lineas[i].p.y  < lineas[i].q.y){
					res = lineas[i].p;
				}else{
					res = lineas[i].q;
				}
			}
		}
	}
	if(!status){
		cout << punto.x << endl;
	}else{
		backtrack(res);
	}
}

int main(){
  optimizar_io;
  cin >> t;
	while(t--){
		cin >> l;
		for(int i = 0; i < l; i++){
			Linea tmp;
			cin >> tmp.p.x >> tmp.p.y >> tmp.q.x >> tmp.q.y;
			lineas.push_back(tmp);
		}
		cin >> s;
		for(int i = 0; i < s; i++){
			Punto punto;
			cin >> punto.x >> punto.y;
			backtrack(punto);
		}
		/*Punto tmp1,tmp2;
		cin >> tmp1.x >> tmp1.y >> tmp2.x >> tmp2.y;
		Linea a(tmp1,tmp2);
		Punto b;
		cin >> b.x >> b.y;
		cout << DistanciaPuntoSegmento(b,a) << endl;*/
		if(t) cout << endl;
	}
}

