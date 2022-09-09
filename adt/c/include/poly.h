// Leave poly abstract.
typedef struct poly *Poly;

char *Poly_show(Poly);

Poly Poly_term(int, int);
Poly Poly_add(Poly, Poly);
Poly Poly_mult(Poly, Poly);

float Poly_eval(Poly, float);
