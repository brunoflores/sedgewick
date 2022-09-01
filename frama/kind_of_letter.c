enum Kind { VOWEL, CONSONANT };

/*@
  requires 'a' <= c <= 'z';
  assigns \nothing;

  behavior vowel:
    assumes c \in { 'a', 'e', 'i', 'o', 'u', 'y' };
    ensures \result == VOWEL;

  behavior consonant:
    assumes ! (c \in { 'a', 'e', 'i', 'o', 'u', 'y' });
    ensures \result == CONSONANT;

  complete behaviors;
  disjoint behaviors;
*/
enum Kind kind_of_letter(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
    return VOWEL;
  } else {
    return CONSONANT;
  }
}
