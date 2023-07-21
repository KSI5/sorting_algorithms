#include "deck.h"
#include <stddef.h> /* For size_t */
#include <stdio.h> /* Include this for the print_deck function */

/**
 * _strcmp - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: 0 if the strings are different, 1 if they are equal.
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);

	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}

	return (str1[i] == '\0' && str2[i] == '\0');
}

/**
 * get_card_position - Get the position of the card in the deck.
 * @node: Pointer to the card node.
 *
 * Return: The position of the card.
 */
int get_card_position(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';

	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace"))
			value = 1;
		else if (_strcmp((*node).card->value, "10"))
			value = 10;
		else if (_strcmp((*node).card->value, "Jack"))
			value = 11;
		else if (_strcmp((*node).card->value, "Queen"))
			value = 12;
		else if (_strcmp((*node).card->value, "King"))
			value = 13;
	}

	value += (*node).card->kind * 13;
	return (value);
}

/**
 * swap_card - Swap a card with its previous one.
 * @card: Pointer to the card node.
 * @deck: Pointer to the deck.
 *
 * Return: Pointer to the card node after the swap.
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;

	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;

	return (current);
}

/**
 * insertion_sort_deck - Sort a doubly linked deck
 * of cards using Insertion Sort.
 * @deck: Double linked deck to sort.
 *
 * Description: This function sorts a deck of cards in ascending order
 * using the Insertion Sort algorithm.
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int value_prev, value_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;

	node = (*deck)->next;

	while (node)
	{
		if (node->prev)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
		}

		while (node->prev && value_prev > value_current)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
			node = swap_card(node, deck);
		}

		node = node->next;
	}
}

/**
 * sort_deck - Sort a deck of cards using insertion sort algorithm.
 * @deck: Pointer to the deck to be sorted.
 *
 * Description: This function sorts a deck of cards in ascending order
 * using the Insertion Sort algorithm.
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
