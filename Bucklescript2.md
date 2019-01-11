# Bucklescript

## Leftovers

## Json

use bs-json with it's decoding or external JSON

```
[@bs.deriving abstract]
type data = {name: string};

[@bs.scope "JSON"] [@bs.val]
external parseIntoMyData : string => data = "parse";

let result = parseIntoMyData("{\"name\": \"Luke\"}");

let n = nameGet(result);
```

Stringify

```
Js.Json
```

Properly use JSON by recursively parse each field




### Pipe into variants

```
let result = name->preprocess->Some
```

turns into
```
let result = Some(preprocess(name))
```


# Debug Mode

## Printing flags:

NOT FOR PRODUCTION
```
- `"bsc-flags": ["-bs-g"]` - Pretty print variants, records etc
```


# Composing bs Attributes

bs attributes can be composed

# Functions

Modeling a function is like a value. [@bs.val]

## Object Method
- bs.send is used to annotate methods on JS objects
First argument is always an object

```
type math; /* abstract type for a document object */
[@bs.val] external math: math = "Math";
[@bs.send] external random: (math, int) => float = "";

let el = random(math, 23);
```

### Methods chaining

bs.send for example exist on JS array so how do we use it with external and chain to filter?

```
[@bs.send] external map : (array('a), 'a => 'b) => array('b) = "";
[@bs.send] external filter : (array('a), 'a => 'b) => array('b) = "";
```

```
let result = [|1, 2, 3|]
  ->map(a => a + 1)
  ->filter(a => a mod 2 === 0);
```

## Fast Pipe

```
a
->foo(b)
->bar
```

## Variadic Function arguments

Was previously bs.splice. It's used when number of arguments in external function is unknown

```
[@bs.val] [@bs.scope "global"] [@bs.variadic]
external draw : ([@bs.as "dog"] _, array(int)) => unit = "draw";

draw([|1, 2|]);
```

## Multiple externals
```
[@bs.module "Drawing"] external drawCat: unit => unit = "draw";
[@bs.module "Drawing"] external drawDog: (~giveName: string) => unit = "draw";
[@bs.module "Drawing"] external draw: (string, ~useRandomAnimal: bool) => unit = "draw";
```


