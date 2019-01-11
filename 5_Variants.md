# Variants

> allows to express this or that
- Need explicit definition
- can be used as enums or data structures
- Variants constructors are always starting with uppercase letter and must be unique *within a scope*


## Variant can be used as enums

`type character = | Good | Bad | Ugly;`

> Tip: Don't forget camelCase naming

## Variants constructors 

Variant constructors can hold one or more values which are identified by position (similar to tupples)

```
type point = Point(float, float);
type shape = 
 | Rectangle(point, point)
 | Circle(point, float);
 
 ```
 
# Recursive variant types

```
type shapeBinaryTree =
  | Empty
  | Node(shape, shapeBinaryTree, shapeBinaryTree);
  
let shapeBinaryTree = Node(Rectangle(Point(2.0, 5.2), Point(2.1, 3.4)),
  Node(Circle(Point(2.0, 5.2), 3.4), Empty, Empty),
  Node(Rectangle(Point(4.0, 6.2), Point(2.1, 3.4)),
    Node(Rectangle(Point(66.0, 5.2), Point(2.1, 3.4)), Empty, Empty),
    Empty
  )
);
```
 

### Parametarised constructors

`type list('a) = Empty | Head('a, list('a));`



## option type
Used to express either Nothing or something. Outside of functional languages is called nullable types.
You can read more about option type in general [here](https://en.wikipedia.org/wiki/Option_type)

option type is a monad

`type option('a) = None | Some('a);`

