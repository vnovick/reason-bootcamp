# Values and expressions

Write result, then test in `rtop` and write down the real result.  Explain each of the statement results, grouping by groups in brackets.

For example: 
`1 + 2 * 3 + 4`
my result: `11` 
`1 + (2 * 3) + 4`
rtop result: 
`- : int = 11`

## Exercises

- `false != 0 && 3 <= 4`
> bool instead of int
- `1 < 5 mod 2 < 6`\
> bool instead of int
- `!(2 >= 1) || 3 = 4;`
> type error
- `1.5 *. 1e3 /. 5 `
> int instead of float
-  `2.5e3 <= 3000. && 2500 <= 1500 && false != true`
> false
- `12. /. 5. *. 4.`
> 9.6
- `1 <= 3.5 && 6 <= 4.5`
> float instrad of int
- `"Would you say: "I like this course?"!!!"`
> syntax error
-  `What replacement for the function f renders the expression f("3") < 1415 correct?`
>  let f =  int_of_string;
- `"baa" < "foo" && "baz" != "foo"`
> true
-  Make the following compile and use only block scope
```
print_string({
    a ++ b / c;
});
```
> Solution:
```
print_string({
let a = "Hello";
let b = 3;
let c = 2;
    a ++ string_of_int(b / c);
});


```
- `[1,2,3] === [1,2,3]`
> false
- `
    if ([1,2,3] == [1,2,3]) {
     "Hey"
    } else {
      3
    };
`
> int instead of string

# Bindings, Scopes and Types

- Give an example of global binding shadowing inside an anonymous block scope 
``` 
let a = "Hello
{
 let a = "Hi"
}
```
- create alias type for any of existing types
`let test = int`
- What's wrong with this type definition: `type A = int;`
> types names should be camelcase unless it's a module


# Tuples
- write a function that takes an integer x between 10 and 99 and returns an integer whose digits have been exchanged
exchange(73) = 37;	
```
let reverseNum = (num) => { 
  let (first, second) = (num mod 10, num / 10) ;
  first * 10 + second;
};
```

- write a function that takes two arguments of 3 dimensional vectors and multiply them 
It's also called cross product and is calculated as following

![crossProduct](https://wikimedia.org/api/rest_v1/media/math/render/svg/1e44fd23f788d2f589f26344245765511e522e5b)


```
let cross = ((a1, a2, a3), (b1, b2, b3)) => (
  a2 * b3 - a3 * b2,
  a3 * b1 - a1 * b3,
  a1 * b2 - a2 * b1,
);
```

- write an addVectors function that will take 2 3dimensional vectors with x,y,z coordinates and add them together. 
```
let addVectors = ((a1, a2, a3), (b1, b2, b3)) => (
  a1 + b1,
  a2 + b2,
  a3 + b3,
);
```
- what will be the value of `let (_, _) = (3,4,5);` and how can it be fixed
> wrong type


# Records, Variants and Pattern matching
- Create [Binary tree](https://en.wikipedia.org/wiki/Binary_tree) data structure using variants and recursive record types
```
type binarySearchTree('a) =
  | Empty
  | Node(node('a))
and node('a) = {
  value: 'a,
  left: binarySearchTree('a),
  right: binarySearchTree('a),
};

type rocketDestination = {
  destinationName: string,
  constellation: string,
  coordinates: celestialCoordinates,
}
and celestialCoordinates = {
  rA: (string, string, string),
  dEc: (string, string, string),
};


let cellestialDestinationTree =
  Node({
    value: {
      destinationName: "Mars",
      constellation: "Pisces",
      coordinates: {
        rA: ("20m", "14s", "00"),
        dEc: ("51deg", "34m", "12"),
      },
    },
    left:
      Node({
        value: {
          destinationName: "Mars",
          constellation: "Pisces",
          coordinates: {
            rA: ("20m", "14s", "00"),
            dEc: ("51deg", "34m", "12"),
          },
        },
        left:
          Node({
            value: {
              destinationName: "Mars",
              constellation: "Pisces",
              coordinates: {
                rA: ("20m", "14s", "00"),
                dEc: ("51deg", "34m", "12"),
              },
            },
            left: Empty,
            right: Empty,
          }),
        right: Empty,
      }),
    right:
      Node({
        value: {
          destinationName: "Mars",
          constellation: "Pisces",
          coordinates: {
            rA: ("20m", "14s", "00"),
            dEc: ("51deg", "34m", "12"),
          },
        },
        left: Empty,
        right:
          Node({
            value: {
              destinationName: "Mars",
              constellation: "Pisces",
              coordinates: {
                rA: ("20m", "14s", "00"),
                dEc: ("51deg", "34m", "12"),
              },
            },
            left: Empty,
            right: Empty,
          }),
      }),
  });
```

- Create a sample api response record containing fields `name`, `lastName`, `age`,  `aboutMe`, `twitterHandle`

- Create an response variant type that will return different request states. Loading, Error with error codes, response of api response type you've created earlier
- Pattern match on the api response and return different messages for different network errors
- If the name in response is yours, then print custom messages
```

type person = {
  name: string,
  age: int
}

let isServerCode = (code) => code / 100 == 5;
let isClientCode = (code) => code / 100 == 5;
type request = Loading | Error(string, int) | Sucess(person);
switch (Sucess({ name: "Vladimir Novick", age: 34 })) {
  | Loading => "Loading"
  | Error(message, 444) => "No response" ++ message
  | Error(message, 494 | 495 | 496 | 497 | 499) => "nginx error: " ++ message
  | Error(message, code) when isServerCode(code) => "Network Error: " ++ message
  | Error(message, code) when isClientCode(code) => "Client Code:" ++ message
  | Error(message, x) => "Unknown code: " ++ string_of_int(x) ++ " message: " ++ message
  | Sucess({ name: "Vladimir Novick" }) => "Howdy Vladimir"
  | Sucess(response) => response.name
};

```

