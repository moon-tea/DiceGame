# DiceGame
========

C++ - The Dice game Pig played against a non-trivial computer opponent
```cpp
////////////////////////////////////
// ___   ___   ___
//|   | |   | |   |
//| P | | I | | G |      A Program By:
//|___| |___| |___|      Monte Nichols
////////////////////////////////////
```
* **Display The Rules:**
**Goal:**
  - Be the first player to reach 30 points!

**Gameplay:**
  - On a turn, a player rolls the die repeatedly until either:
    - A 1 is rolled
    - The player chooses to hold (stop rolling)

If a 1 is rolled, that player's turn ends and no points are earned.
If the player chooses to hold, all of the points rolled during that turn are
added to his or her score.

At the end of a game you gain not only all of the money you put up ($30) but
also all the money the opponent was betting.

Try to have a close game with the opponent so you have the chance to earn more.
Be careful though, the closer the scores, the more likely your opponent will win.

====

## Example output

Let's roll to see who goes first.

(type r to roll) //[[INPUT TO ROLL]]

//We decide who goes first by roll, for example if you go first:

You go first!

Press r to roll some dice.

(type r to roll) //[[INPUT TO ROLL]]

You roll calling your turn function [[see myTurn();]]

After, the computer does the same   [[see cpTurn();]]

If either of you go past the winning score value you gain or lose money and might play another round
