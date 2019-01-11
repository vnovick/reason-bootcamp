# Bucklescript

# Data types
https://bucklescript.github.io/docs/en/common-data-types

Js primitives:
https://bucklescript.github.io/bucklescript/api/Js

## String
Same as Stdlib

### Interpolation

```
let world = "World";
let helloWorld = {j|Hello，$world|j};
```

## Float
Float are numbers in JS
(Js.Float)[https://bucklescript.github.io/bucklescript/api/Js.Float.html]

```let expoFloat = Js.Float.toExponential(77.1234);```

## Int
[Js.Int](https://bucklescript.github.io/bucklescript/api/Js.Int.html)

```let expoInt = Js.Int.toExponential(77.1234);```

## Array

dynamic sized array
[Js.Array](https://bucklescript.github.io/bucklescript/api/Js.Array.html#VALdefault)


# Tuple
Compiled to JS arrays

# Bool
Compiles to JS boolean

# Record, variant, object are not shared
Converting to JS objects
https://bucklescript.github.io/docs/en/generate-converters-accessors


# Installing libraries

```
{
  "dependencies": {
    "bs-jest": "^0.1.5"
  }
}
```

```
{
  "bs-dependencies": [
    "bs-jest"
  ],
  ···
}
```


