# A267263
A program to calculate this sequence (http://oeis.org/A267263). Written in `C`.

## Building
Run:
```
git clone https://github.com/ChemicalDevelopment/A267263.git
cd A267263
make
./A267263.o
```
And you are running it.

## Explanation
Primorial base is similar to most bases. We use base 10, computers use base 2.
Every place value is the last multiplied by 10
100 = 10 * 10 (you add 0)
(100)_(2) = (10)_(2) * (10)_(2) In base 2
But, in primorial base, the place value is multiplied by the next prime.
So, it looks like this:
...(2*3*5's place)(2*3's place)(2's place)(1's place)
This sequence is the number of places where the value is not 0.

For example, (5)_(10) = (21)_(#)
(6)_(10) = (100)_(#)
And A267363_6 = 1, because (100)_(#) has 1 nonzero digit
