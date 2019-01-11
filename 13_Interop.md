# JS Interop

# Raw dumping of Javascript

Wrap with 
```
[%bs.raw {| 
//  Your code
|}]
```

Top level:

`[%%raw "var a = 1"];`

or 

```
%raw
"var a = 1";
```

```
let alert = [%bs.raw {| function(a) {
  window.alert(a)
} |}];

```
```
let f: (int, int) => int = [%raw (a, b) => "{return a + b}"];
```

# Externals

`external` is a keyword for declaring a value in BuckleScript/OCaml/Reason:

It's like let *but the body is a string*

Depending on the context it has specific meaning

- native OCaml, it usually points to a C function of that name.
- Bucklescript they are decorated with [@bs.blala]

Escape hatch NOT TO DO `external myShadyConversion : foo => bar = "%identity";`

converts foo type to bar


## Globals

[@bs.val] external bindingToBeCalledInReason: typeSignature = "functionNameOnGlobalScope"

`[@bs.val] external setTimeout: (unit => unit, int) => float = "";`
`[@bs.val] external clearTimeout : float => unit = "";`

### Abstract Type

```
type timeout;
[@bs.val] external setTimeout: (unit => unit, int) => timeout = "";
[@bs.val] external clearTimeout: timeout => unit = "";
```

### Global Modules
`[@bs.scope scopeName]` - Adding scope from left side or from right side will interop with function on this scope
`[@bs.scope (scope, nestedFn, nestedFn)] [@bs.val]` - Passing tupple lets you get deeper into module

```
[@bs.scope "window"] [@bs.val] external alert: 'a => unit = "";
```


## Null, Undefined, Option

(Js.Nullable)[https://bucklescript.github.io/docs/en/null-undefined-option]


If you're receiving, for example, a JS string that can be null and undefined, type it as:

```
[@bs.module "MyConstant"] external myId: Js.Nullable.t(string) = "myId"
```

To pass nullable string to a module

```
[@bs.module "MyIdValidator"] external validate: Js.Nullable.t(string) => bool = "validate";
let personId: Js.Nullable.t(string) = Js.Nullable.return("abc123");

let result = validate(personId);
```

`Js.Nullable.fromOption` converts from a option to `Js.Nullable.t`. `Js.Nullable.toOption` does the opposite.

## Objects

JS.Objects used as
- hash map (dictionary) with dynamic add, remove functionality
- As a record with fixed fields

### Hash Maps

[Js.Dict](https://bucklescript.github.io/bucklescript/api/Js.Dict.html)

- Create a Js Object
```
let jsMap = Js.Dict.empty();
```
- Get Js Object
```
[@bs.val] external peopleAge: Js.Dict.t(int) = "";
switch (Js.Dict.get(peopleAge, "Vladimir")) {
| None => Js.log("Vladimir can't be found")
| Some(age) => Js.log("Vladimir is " ++ string_of_int(age))
};
```

Getting and accessing Javascript object from Reason side

```
type person = Js.t({
  .
  name: string,
  age: int,
  job: string
});

[@bs.val] external getPerson: unit => person = "getPerson";
Js.log(getPerson()##name)
```

As a record

Passing record to JS side:

```
[@bs.deriving abstract]
type testRecord = {
  test: string,
  test2: string,
};

[@bs.val] external printTest: testRecord => unit = "printTest";

let rcrd = testRecord(~test="Hey", ~test2="Hello");
printTest(rcrd);
```

creation through named arguments

```
let joe = person(~name="Joe", ~age=20, ~job="teacher")
```

### Renaming fields

Use `@bs.as`

```
[@bs.deriving abstract]
type data = {
  [@bs.as "type"] type_: string,
  [@bs.as "aria-label"] ariaLabel: string,
};

let d = data(~type_="message", ~ariaLabel="hello");
```

### Optional fields

```
[@bs.deriving abstract]
type testRecord = {
  test: string,
  [@bs.optional]
  test2: string,
};

[@bs.val] external printTest: testRecord => unit = "printTest";

let rcrd = testRecord(~test="Hey", ());
printTest(rcrd);
```


## JS Classes


```
type t;
[@bs.new] external createDate : unit => t = "Date";

let date = createDate();
```

```
class type _rect =
  [@bs]
  {
    [@bs.set] pub height: int;
    [@bs.set] pub width: int;
    pub draw: unit => unit
  };

type rect = Js.t(_rect);
```

## Functions

- bs.send is used to annotate methods on JS objects
First argument is always an object

```
type math; /* abstract type for a document object */
[@bs.val] external math: math = "Math";
[@bs.send] external random: (math, int) => float = "";

let el = random(math, 23);
```

## Import Exports

same as bs.val only accepts string with path.
without 

```
[@bs.module "path"] external dirname : string => string = "dirname";
```

Default imports
```
[@bs.module "./student"] external studentName : string = "default";
```

## Exceptions

Js.Exn

## JSON

use bs-json

## Fast Pipe

## Converters/Helpers

Converting from Js.t to Record

```
[@bs.deriving jsConverter]
type person = {
  name: string,
  age: int,
  lastName: string,
};

[@bs.val] external getPerson: unit => 'a = "getPerson";

```

Converting to abstract type
```
[@bs.deriving {jsConverter: newType}]
type person = {
  name: string,
  age: int,
  lastName: string,
};

[@bs.val] external getPerson: unit => abs_person = "getPerson";

let pr = personFromJs(getPerson());

Js.log(personFromJs);
```

