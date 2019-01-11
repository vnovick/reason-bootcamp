
#  Pattern matching (applies as well to destructuring)

Patterns are a programming mechanism that helps with processing data. They serve two purposes:

- Check what structure data has.
- Extract parts of data.

## How it works

We match patterns against data:
*Syntax of patterns match the syntax of processing data*


> Pseudo code below
x  matches 3 
:x = 3

(x, y) matches (1, 3)
:x = 1, y = 3

(1, y) matches (1, 4)
:y = 4

> End of pseudo code

So pattern matching is about matching data structure with actual data filling the missing pieces by creating bindings

If we don't want to create bindings, then instead of variable name we provide special name `_`

### Alternatives
> Pseudo code below

(x, 0) | (0, x) matches (1, 0) 
:x = 1

> end of pseudo code

### bind and match

`(8, x) as y` gives you ability to both pattern match and bind the pattern result

`let { coordinates: (x, y) as coordinates } = marsDestination;`

# Pattern Matching with let === destructuring 

# Pattern Matching with Switch 
match multiple patterns against data

> Pseudo code
switch «value» {
| «pattern1» => «result1»
| «pattern2» => «result2»
···
}
> end of pseudo code

```
let result = switch 1 {
 | 1 => "One"
 | 2 => "Two"
 | x => "Unknow result" 
};
```

using alternatives and as

```
let result = switch (1, 0)  {
 | (x, 0) | (0, x) => "Some X:" ++ string_of_int(x)
 | (3, 14) as test => "Almost pi"
 | (_, _) => "Unknown"
};
```

```
let somePoint: point = Point(7., 6.);

let circ = Circle(somePoint, 5.0);

 /* 1 arctan = π/4 rad */
 
 let pi = 4.0 *. atan(1.0);

let computeArea = (s: shape) =>
  switch s {
  | Rectangle(Point(x1, y1), Point(x2, y2)) =>
    let width = abs_float(x2 -. x1);
    let height = abs_float(y2 -. y1);
    width *. height;
  | Circle(_, radius) => pi *. (radius ** 2.0)
  };
 
 ```