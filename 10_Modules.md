# Modules

Every file is a module
Everything is exported from module

```
let greetings = (~hello="Hello", ~world="World", ()) =>
  Js.log({j|$hello $world|j});

```

## Submodules

```
module Math = {
  module Tools = {
    let times = (x, y) => x * y;
    let square = x => times(x, x);
  };
};
```

## Interface definitions
```
module type MathToolsInterface = {
  let times: (int, int) => int;
  let square: (int) => int;
};

module Math: MathToolsInterface = {
  let times = (x, y) => x * y;
  let square = x => times(x, x);
};

```

We can do that in rei files:

```
type t = string; /* A */

let make = (): t => "";
let logStr = (str: string, log: t): t => log ++ str ++ "\n";

let print = (log: t) => print_string(log);
```



## Abstract types: hiding internals

We can define abstract type in rei files:

```
type t;
let make: (unit) => t;
let logStr: (string, t) => t;
let print: (t) => unit;

```

## Using modules

- By qualified names
- Opening them (Belt, Js)
- Opening them locally
```
let () = Log.(
  make()
    |> logStr("Hello")
    |> logStr("everyone")
    |> print
);
```

## Including modules
```
module LogWithDate = {
  include Log;
  let logStrWithDate = (str: string, log: t) => {
    let dateStr = Js.Date.toISOString(Js.Date.make());
    logStr("[" ++ dateStr ++ "] " ++ str, log);
  };
};
let () = LogWithDate.(
  make()
    |> logStrWithDate("Hello")
    |> logStrWithDate("everyone")
    |> print
);
```

Disclaimer: 
Some examples taken from the following book [Exploring ReasonML](http://reasonmlhub.com/exploring-reasonml/index.html)
