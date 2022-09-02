# Connectivity

Given a sequence of pairs of integers, where each integer represents an object
of some type, we are to interpret the pair `p-q` as meaning "p is connected to
q".

We assume the relation "is connected" to be transitive.

Our goal is to write a program to filter out extraneous pairs from the set: When
the program inputs a pair `p-q`, it should output the pair only if the pairs it
has seen to that point do not imply that p is connected to q.

This program will never output more than `N - 1` pairs, because once it has
output `N - 1` pairs, any pair it encounters from that point on will be
connected: A fundamental result from graph theory implies that all `N` objects
are connected if and only if the number of pairs output by the connectivity
algorithm is precisely `N -1`.

Our problem is to devise a program that can remember sufficient information
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

## Some terminology

The set of pairs in the input is called a *graph*, and the set of pairs output
is called a *spanning tree* for that graph, which connects all the objects.

## Fundamental operations

Each time we get a new pair:

1. Determine whether it represents a new connection;
2. Incorporate the information that the connection has been seen.

Encapsulate these two tasks as abstract operations by considering the integer
input values to represent elements in abstract sets, and then design algorithms
and data structures that can:

1. *Find* the set containing a given item;
2. Replace the sets containing two given items by their *union*.

The sets represent *connected components*: subsets of the objects with the
property that any two objects in a given component are connected.

This approach reduces the development of an algorithmic solution for
connectivity to the tasks of:

1. Defining a data structure representing the sets, and
2. Developing *union* and *find* algorithms that efficiently use that data
   strucuture.
