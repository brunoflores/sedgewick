# Connectivity problem

A sequence of pairs of integers, where each integer represents an object of some
type and we are to interpret the pair `p-q` as meaning "p is connected to q".

We assume the relation "is connected" to be transitive.

Our goal is to write a program to filter out extraneous pairs from the set: When
the program inputs a pair `p-q`, it should output the pair only if the pairs it
has seen to that point do not imply that p is connected to q.

Our problem is to devise a program that can rememver sufficient information
about the pairs it has seen to be able to decide whether or not a new pair of
objects is connected.

Some applications:

1. Integers might represent computers in a network, and the pairs might
   represent connections in the network; then, our program might be used to
   determine whether we need to establish a new direct connection for p and q to
   be able to communicate;
2. Integers might represent contact points in an electrical network, and the
   pairs might represent wires connecting the points;
3. Programming environments: determine whether two given names are equivalent,
   after a sequence of aliasing declarations;
