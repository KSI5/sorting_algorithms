#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Suit values for playing cards
 * @SPADE: Spades suit
 * @HEART: Hearts suit
 * @CLUB: Clubs suit
 * @DIAMOND: Diamonds suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card (Ace to King)
 * @kind: Suit of the card (SPADE, HEART, CLUB, or DIAMOND)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Doubly linked list node for a deck of cards
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the head of the doubly linked list of cards
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
