# Perspective

Why is algorithm analysis compeling? Few other design activities hold the
potential to reap savings factors of millions or billions, or more.

Also, as the scale of our computational power and out applications increases,
the gap between a fast algorithm and a slow one grows.

About using a computer effectively.

1. Decide on a complete and specific problem statement, including indentifying
   fundamental abstract operations that are intrinsic to the problem;
2. Develop a succint implementation for a straightforward algorithm;
3. Improve implementations through step-wise refinement, validating the efficacy
   of ideas through empirical analysis, mathematical analysis, or both;
4. Find high-level abstract representations of data structures or algorithms
   that enable effective high-level design of improved versions;
5. Strive for worst-case performance guarantees when possible, but accept good
   performance on actual data when available.

## Empirical analysis

On our use of *empirical analysis*: given two algorithms to solve the same
problem, we run them both to see which one takes longer. When empirical studies
start to consume a significant amount of time, mathematical analysis is called
for.

Challenges in empirical analysis:

* The first challenge in empirical analysis is to develop a correct and complete
  implementation;
* The second challenge in empirical analysis is to determine the nature of the
  input data and other factors that have direct influence on the experiments
  (actual data, random data or perverse data).

We strive to identify essential abstract operations, and start by comparing
algorithms on the basis of their use of such operations.

But, **we cannot run empirical tests for a program that is not yet written**.

## Other challenges

Perhaps the most common mistake in selecting an algorithm:

* To ignore performance characteristics.

Perhaps the second most common mistake:

* To pay too much attention to performance characteristics.

## The idealized world of the analyst

* To compare different algorithms for the same task;
* To predict performance in a new environment;
* To set values of algorithm parameters.

Identify the abstract operations on which the alhorithm is based, to
separate the analysis from the implementation: properties of the algorithm
versus properties of the computer.

The analysis amounts to determining the frequency of execution of a few
fundamental operations. First look for rough estimates of these quantities.

Study the data and model the input that might be presented to the algorithm. Two
approaches:

* *Average-case* performance: assume the input is random;
* *Worst-case* performance: look for perverse input.

The average case might be a methematical fiction, and the worst case might be a
bizarre construction.

# Growth of functions

A *primary parameter N*, most often directly proportional to the size of the
data set being processed. Examples:

* The degree of a polynomial;
* The size of a file to be sorted and searched;
* The number of characters in a text string;
* Some other abstract measure of the size of the problem.

If multiple, reduce the analysis to just one by expressing one as a function of
the other, or by considering one parameter at a time holding the others
constant.
