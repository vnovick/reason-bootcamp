# Let binding definition

`let a = 123;`

`let basicFunction = (a,b) => a + b;`

Bindings are immutable

They can be muted only by using `ref` which is not actually mutating. You can read more [here](https://reasonml.github.io/docs/en/mutation)


## shadowing 

let a = "test";
let a = "other test";

## Mutation

```

let foo = ref(5);
let five = foo^;
foo := 6;
```

## Naming conventions
Everything is camel-cased


## Type annotation
You can annotate with a type

`let a: int = 12;`

# Types 

Types can be aliased in the following manner:

```
type test = int;
```



# Block Scope
```
let greeting = "Greeting";
let hello = {
  let greeting = "Hello";
  let world = "World"
  greeting ++ world;
};

print_string(hello);




