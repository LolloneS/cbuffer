#include <string>

/**
	@brief Funtore per sapere se un numero è pari
	@param n Intero da testare
	@return boolean True se è vero che il numero è pari
**/
struct is_even {
    bool operator()(const int &n) const {
        return ((n % 2) == 0);
    }
};

/**
	@brief Funtore per sapere se un numero è positivo
	@param n Double da testare
	@return boolean True se è vero che il numero è positivo
**/
struct greater_zero {
	bool operator()(const double &n) const {
		return n > 0;
	}
};


struct voce {
	std::string cognome; 
	std::string nome; 
	std::string ntel; 
	
	voce() {}
	
	voce(const std::string &c, 
			const std::string &n, 
			const std::string &t) : 
			cognome(c), nome(n), ntel(t){} 
};

std::ostream &operator<<(std::ostream &os, const voce &v) {
	os << v.cognome << " " << v.nome << " " << v.ntel;
	return os;
}



struct point {
	int x;
  	int y;
  	point(int xx, int yy) : x(xx), y(yy) { }
};


std::ostream &operator<<(std::ostream &os, const point &p) {
	os << "(" << p.x << ", " << p.y << ")";
  	return os;
}

/**
	@brief Funtore per sapere se un punto appartiene alla retta y = x
	@param p Punto da testare
	@return boolean True se è vero che il punto giace sulla retta y = x
**/
struct x_equals_y {
	bool operator()(const point &p) const {
		return (p.x == p.y);
	}
};
