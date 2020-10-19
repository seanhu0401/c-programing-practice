#include "cards.h"
#include <stdio.h>

int main(void) {
  printf("testing print_card\n");
  card_t c1;
  c1.value = 5;
  c1.suit = SPADES;
  card_t c2;
  c2.value = 14;
  c2.suit = HEARTS;
  card_t c3;
  c3.value = 12;
  c3.suit = CLUBS;
  card_t c4;
  c4.value = 13;
  c4.suit = HEARTS;
  card_t c5;
  c5.value = 2;
  c5.suit = HEARTS;
  card_t c6;
  c6.value = 12;
  c6.suit = DIAMONDS;
  card_t c7;
  c7.value = 5;
  c7.suit = DIAMONDS;
  card_t c8;
  c8.value = 9;
  c8.suit = DIAMONDS;

  assert_card_valid(c1);
  printf("expect:5d;get:");
  print_card(c1);
  assert_card_valid(c2);
  printf("expect:Ah;get:");
  print_card(c2);
  assert_card_valid(c3);
  printf("expect:Qc;get:");
  print_card(c3);
  assert_card_valid(c4);
  printf("expect:Kh;get:");
  print_card(c4);
  assert_card_valid(c5);
  printf("expect:2h;get:");
  print_card(c5);
  assert_card_valid(c6);
  printf("expect:Qd;get:");
  print_card(c6);
  assert_card_valid(c7);
  printf("expect:5d;get:");
  print_card(c7);
  assert_card_valid(c8);
  printf("expect:9d;get:");
  print_card(c8);

  printf("testing ranking_to_string\n");
  
  hand_ranking_t rank1 = FLUSH;
  hand_ranking_t rank2 = STRAIGHT_FLUSH;
  hand_ranking_t rank3 = FULL_HOUSE;

  printf("expect:FLUSH;get:");
  printf("%s",ranking_to_string(rank1));
  printf("expect:STRAIGHT_FLUSH;get:");
  printf("%s",ranking_to_string(rank2));
  printf("expect:FULL_HOUSE;get:");
  printf("%s",ranking_to_string(rank3));

  printf("testing card_from_num\n");
  card_t card1 = card_from_num(0);
  card_t card2 = card_from_num(1);
  card_t card3 = card_from_num(51);
  card_t card4 = card_from_num(12);
  card_t card5 = card_from_num(23);

  printf("expect:2s;get:");
  print_card(card1);
  printf("expect:3s;get:");
  print_card(card2);
  printf("expect:Ac;get:");
  print_card(card3);
  printf("expect:As;get:");
  print_card(card4);
  printf("expect:Qc;get:");
  print_card(card5);

  printf("testing card_from_letters\n");
  card_t card6 = card_from_letters('0','d');
  card_t card7 = card_from_letters('J','h');
  card_t card8 = card_from_letters('A','c');
  card_t card9 = card_from_letters('5','s');
  card_t card10 = card_from_letters('8','h');
  
  printf("expect:0d;get:");
  print_card(card6);
  printf("expect:Jh;get:");
  print_card(card7);
  printf("expect:Ac;get:");
  print_card(card8);
  printf("expect:5s;get:");
  print_card(card9);
  printf("expect:8h;get:");
  print_card(card10);

  return 0;
}
