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