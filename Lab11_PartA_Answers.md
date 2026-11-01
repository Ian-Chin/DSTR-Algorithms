# Lab 11 - Part A Answers (Q1 and Q2)

## Q1. Binary Tree

Items inserted in the given order as a binary search tree (alphabetical: smaller to the left, larger to the right).

```
                 Monkey
               /        \
            Dog          Rat
           /   \        /    \
         Cat  Elephant Panda  Tiger
                             /     \
                         Salmon   Zebra
```

## Q2.

a) Path Monkey -> Panda: Monkey -> Rat -> Panda. Length = **2** (edges).

b) Height = **3** if counted in edges (longest path Monkey -> Rat -> Tiger -> Salmon/Zebra), or **4** if counted in levels/nodes (the convention used by the `height()` function in the C++ programs).

c) Degree of Rat = **2** (children: Panda, Tiger).

d) Degree of the tree = **2** (maximum degree of any node).

e) Traversals:

- Preorder: Monkey, Dog, Cat, Elephant, Rat, Panda, Tiger, Salmon, Zebra
- Inorder: Cat, Dog, Elephant, Monkey, Panda, Rat, Salmon, Tiger, Zebra
- Postorder: Cat, Elephant, Dog, Panda, Salmon, Zebra, Tiger, Rat, Monkey
- Level order: Monkey, Dog, Rat, Cat, Elephant, Panda, Tiger, Salmon, Zebra

## Part B tree (keyed by Car ID)

```
              Car0051
             /       \
        Car0024     Car0302
                   /       \
               Car0101   Car1001
                              \
                            Car5051
```
