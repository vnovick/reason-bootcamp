# Functions

## Definition

`let a => a + b;`

## Higher order functions

`List.map((a) => a + 1, [7, 23, 8, 4]);`

## Functions with blocks scope

```
let (a,b) => {
  a + b 
};
```

## Recursive functions

### Self recursive

```
let rec factorial = x =>
  switch x {
    | x when x <= 2 => x
    | x => x * factorial(x - 1) 
  };
```

### first-order functions

```
let add = (a,b) => a + b;
```

### higher order

```
let f = (b: ('a) => 'a) => b(1 + 2);
let f = (b: ('a) => 'a) => b();
```

## No nullary functions

due to partial applications there are no nullary functions. Any function without arguments is a shorhand for one argument () of type unit

## Destructuring in function parenthesis

Any function parenthesis can be pattern matched (destructured) with similar destructuring syntax

```
let cross = ((a1, a2, a3), (b1, b2, b3)) => (
  a2 * b3 - a3 * b2,
  a3 * b1 - a1 * b3,
  a1 * b2 - a2 * b1,
);
```

## Labeled parameters

`let computation = (~x, ~y, ~z) => x + y / z;`

### Destructuring labeled params

```
let cross = (~vector1 as (a1, a2, a3), ~vector2 as (b1, b2, b3)) => (
  a2 * b3 - a3 * b2,
  a3 * b1 - a1 * b3,
  a1 * b2 - a2 * b1,
);
```

## Optional params 

```
let add = (~x=?, ~y=?, ()) =>
  switch (x, y) {
  | (Some(x'), Some(y')) => x' + y'
  | (Some(x'), None) => x'
  | (None, Some(y')) => y'
  | (None, None) => 0
  };
```

## Defaults

```
let add = (~x=0, ~y=0, ()) => x + y;
let add = (~x: int=0, ~y: int=0, ()) => x + y;

```

> With optional parameters, you need at least one positional parameter

## Explicitly passed optional

```
let someFn = (a: option('a)) => a
let result2 = None
add(~x=?someFn(Some(12)),~y=?result2)
```


## Currying and Partial application

```
let add = (a,b) => a + b
add(2)(3)
```


## reverse-application operator

`|>` let's you chain functions 

```
[4, 2, 1, 3, 5]
|> List.map(x => x + 1)
|> List.filter(x => x < 5)
|> List.sort(compare);

```
## unary functions pattern matching 

```
let divTuple = (tuple) =>
  switch tuple {
  | (_, 0) => (-1)
  | (x, y) => x / y
  };
  
  
let divTuple =
  fun
  | (_, 0) => (-1)
  | (x, y) => x / y;
```

## Designing your own operators

operators are just functions

```
(+)(8, 1);

```

###  infix operators 

These charachters can be used:
- First charachter: `! $ % & * + - . / : < = > ? @ ^ | ~` followed by 0+
- First charachter: `#` followed by 1+

You can read more about it here: 
[2ality blog](http://2ality.com/2017/12/functions-reasonml.html#advanced)

[Ocaml manual](https://caml.inria.fr/pub/docs/manual-ocaml/lex.html#infix-symbol)

Expressions:
[Ocaml manual](https://caml.inria.fr/pub/docs/manual-ocaml/expr.html)




