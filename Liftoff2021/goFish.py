# Import standard libraries here
import random

class GoFishAI:
    """
    This class will contain the logic of your gofish AI. The code is a minimum working example of a GoFishAI
    that randomly requests cards. Modify the code to improve the AI!

    GAME DESCRIPTION:
    Go-fish is an 4-player card game played with a standard deck of 52 cards. Each player starts with 5 cards. Each
    round, players take turns asking another player for a specific rank of card (A-K). The player asking for the rank
    (say, player A) must already own a card of that rank.

    If the player being asked (player B) has the requested rank, then they must give player A all of their cards
    matching that rank. Player A may then go again by choosing a player (possibly the same player) and asking for a
    rank.

    If player B does not have a card matching the requested rank, then player A must draw one card from the deck if the
    deck is not empty.

    If, after receiving or drawing a card, player A has all the cards of a rank (i.e. 4 Aces, 4 Tens, etc.), then player
    A removes those cards (called a ‘book’) from their hand and goes again. Otherwise, play continues to the next
    player.

    If a player runs out of cards, then they will draw 3 cards or however many is left in the deck, whichever is fewer.

    The objective of the game is to have the most number of books. The game ends after all 13 books have been taken out
    of play or an arbitrary maximum turn count. If two players have the same number of books, the player with the
    highest ranking book (Ace > King > Queen > … > 2) wins.

    ADDITIONAL COMMENTS:
     - You can debug your AI using print() statements. All standard output will be stored in a file and returned to you
       once your AI is done running.
     - You can see the history and results of a match by going to the Round History tab.
    """

    # DO NOT MODIFY METHOD SIGNATURE
    def __init__(self):
        """
        Here, you can create variables that persist throughout a match.
        """
        pass


    # DO NOT MODIFY METHOD SIGNATURE
    def poll(self, player_index, player_hand, hand_sizes, matches, deck_remaining, history):
        """
        Method poll() will be called every turn. It will be given the state of the current match and return the rank
        that the player requests and from who to request it. Note that poll() may be called consecutively if the player
        goes goes again due to a book or receives a card.

        :param player_index: An integer representing the unique index of YOUR player. Information about your player will
                             be at this index in hand_sizes, matches.
        :param player_hand: A list of integers representing the ranks of the cards in your hand. The range will be from
                            2 to 14, and J, Q, K, A are 11, 12, 13, 14 respectively.
                            Ex. [2, 4, 4, 6, 9]
        :param hand_sizes: A list of integers representing the number of cards in each player's hand. The order of the
                           players are consistent, and the size of a player's hand will appear at their player_index.
                           Ex. [5, 7, 3, 2]
        :param matches: A nested list containing lists of integers representing the books that a player has collected.
                        The order of the players are consistent, and a player's books will appear at their player_index.
                        Ex. [[2, 3], [11, 12, 14], [4], []]
        :param deck_remaining: An integer representing the number of cards remaining in the deck.
        :param history: A nested list containing lists ("events") that hold information about how you played the on your
                        last turn and how others played since. The list is sorted such that the oldest event is first.
                        Each event is a list that contains 5 items:
                         - player_index: integer index representing the current player whose turn it is
                         - to_who: integer index representing the player being asked for the card
                         - for_what: integer representing the requested rank of the card.
                         - cards_received: if player_index matches your index, then a list of integers representing the
                                           ranks of the cards that were received (either from to_who or the deck).
                                           Otherwise, an integer representing the number of cards that were received.
                         - go_fish: bool representing whether the player received no cards and therefore attempted to
                                    draw from the deck.
                        You can read the event as "[player_index] asked [to_who] for [for_what] and received
                                                   [cards_received] after [go_fish]."
                        Ex. [[3, 2, 14, [3, 2, 2], True], [4, 3, 2, 2, False], ...]
                        If a player has an empty hand and has to draw from the deck, then to_who, for_what = None;
                        card_received = the number of cards drawn; go_fish = FALSE.
        :return: Two integers (to_who, for_what) representing the index of the player being asked for the card and
                 the rank of the requested card.
        """

        to_who = random.randint(0, len(hand_sizes)-1)
        print("Sending To: " + str(to_who))
        
        while to_who == player_index:
            to_who = random.randint(0, len(hand_sizes)-1)

        for_what = random.choice(player_hand)

        return to_who, for_what