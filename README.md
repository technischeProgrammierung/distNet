# distNet

This project has the purpose of learning the language C, created for the module "technische Programmierung" of Hochschule Osnabrück.

## Exercise definition

There is a fictional distribution net defined by the locations of different shops/companies and one customer, also defined by its location.
It is the task of this program to check wether the customer is within the distribution net or not.

The net consists of an arbitrary number of points P1, P2, ..., Pn, each defined by x and y-coordinates in a 2-dimensional space. Every Point is
only connected to its preceding and its subsequent point through a line. A net is only valid if it has at least 3 points and if its lines do not
have any intersections. 
Therefore a **valid net** is mathemathically defined by a **non-self-intersecting polygon**.

Thus it is the exercise to check wether a point is placed within a polygon or not.

## Structure

The central struct of the project is the net defined in `/net`. A net consists of two linked lists `/pointList` and `/lineList`, both consisting
of items defined in `/lineItem` and `/pointItem`. These list-items wrap around the basic structs needed to describe the polygon: 2-dimensional
points and lines, defined in `/point` and `/line`.

A usage example is implemented in `test.c`

## Procedure

1. Enter the coordinates defining the points which form the net
2. Calculate the lines of the net
3. Check wether the net is valid
4. Enter the coordinates defining the point of the customer location
5. Check wether the point lays within the net or not





