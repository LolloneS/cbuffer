#include <string>
struct is_even {
    bool operator()(const int &n) const {
        return ((n % 2) == 0);
    }
};

struct greater_zero {
	bool operator()(const int &n) const {
		return n > 0;
	}
};

struct voce {
	std::string cognome; ///< cognome del contatto
	std::string nome; ///< nome del contatto
	std::string ntel; ///< numero telefonico del contatto
	
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
	int x; ///< coordinata x del punto
  	int y; ///< coordinata y del punto
  	point(int xx, int yy) : x(xx), y(yy) { }
};


std::ostream &operator<<(std::ostream &os, const point &p) {
	os << "(" << p.x << ", " << p.y << ")";
  	return os;
}