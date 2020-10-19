#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
  assert(c.suit >= 0 && c.suit <= 3);
  assert(c.value >= 2 && c.value <= VALUE_ACE);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH\n";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND\n";
  case FULL_HOUSE: return "FULL_HOUSE\n";
  case FLUSH: return "FLUSH\n";
  case STRAIGHT: return "STRAIGHT\n";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND\n";
  case TWO_PAIR: return "TWO_PAIR\n";
  case PAIR: return "PAIR\n";
  case NOTHING: return "NOTHING\n";
  default: return "Not a valid ranking\n";
  }
}

char value_letter(card_t c) {
  char val = '0';
  if (c.value >= 2 && c.value < 10){
    val = '0'+c.value;
  }
  else if (c.value == VALUE_JACK){
    val = 'J';
  }
  else if (c.value == VALUE_QUEEN){
    val = 'Q';
  }
  else if (c.value == VALUE_KING){
    val = 'K';
  }
  else if (c.value == VALUE_ACE){
    val = 'A';
  }
  return val;
}

char suit_letter(card_t c) {
  char x;
  switch(c.suit){
  case SPADES: x ='s'; break;
  case HEARTS: x ='h'; break;
  case DIAMONDS: x ='d'; break;
  case CLUBS: x ='c'; break;
  case NUM_SUITS: printf("not a real suit"); break;
  }
  return x;
}

void print_card(card_t c) {
  printf("%c%c\n", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '0': temp.value = 10; break;
  case '2': temp.value = 2; break;
  case '3': temp.value = 3; break;
  case '4': temp.value = 4; break;
  case '5': temp.value = 5; break;
  case '6': temp.value = 6; break;
  case '7': temp.value = 7; break;
  case '8': temp.value = 8; break;
  case '9': temp.value = 9; break;
  case 'J': temp.value = VALUE_JACK; break;
  case 'Q': temp.value = VALUE_QUEEN; break;
  case 'K': temp.value = VALUE_KING; break;
  case 'A': temp.value = VALUE_ACE; break;
  default: perror("not a valid value\n");exit(EXIT_FAILURE);
  }
  switch(suit_let){
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'c': temp.suit = CLUBS; break;
  case 'd': temp.suit = DIAMONDS; break;
  default: perror("not a valid suit\n");exit(EXIT_FAILURE); 
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if(c>=0 && c<52){
    suit_t suits = c%4;
    temp.value = (c%13+2);
    temp.suit = suits;
  }
  else{
    perror("Not a vaild input. Please enter between 0-51\n");
    exit(EXIT_FAILURE);
  }
  return temp;
}
