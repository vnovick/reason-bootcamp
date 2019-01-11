# Definition

- immutable
- ordered 
- fix-sized at creation time
- heterogeneous

# Creation

`let xyCoordinates = (23, 24)`

## return several values from the block 

let greetingsTupple = {
  let a = "Hello";
  let b = "World";
  (a, b);
};

fst(greetingsTupple) ++ snd(greetingsTupple);

[Pervasive](https://reasonml.github.io/api/Pervasives.html) is initially opened meaning you can use anything on this module without opening

> Tupples use structural typing

## Destructuring 

`let (x, y) = (1, 3);`
`let (x, _ , z) = (1,2,3);`
`let (_, _) = (1,2,3);`


