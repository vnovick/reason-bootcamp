type rocketDestination = {
  destinationName: string,
  constellation: string,
  coordinates: celestialCoordinates,
}
and celestialCoordinates = {
  rA: (string, string, string),
  dEc: (string, string, string),
};

let reverseNum = num => {
  let (second, first) = (num mod 10, num / 10);
  second * 10 + first;
};

let tup = (1, 3);

let (_, _) = tup;

let a = 1;
let foo = ref(a);

foo := 5;

let crossProduct = (vector1, vector2) => {
  let (a1, a2, a3) = vector1;
  let (b1, b2, b3) = vector2;
  (a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1);
};

let addVectors = ((a1, a2, a3), (b1, b2, b3)) => (
  a1 + b1,
  a2 + b2,
  a3 + b3,
);

/*
 (x, y) matches (1,3)
 (1, y) matches (1,3)

 (x, 0) | (0, x)  matches (1,0)

 (8, x) as y matches (8, 3)


 */
/* let { coordinates } = marsDestination; */

type serverResponse =
  | Response
  | Error
  | Loading;

let result =
  switch (tup) {
  | (1, y) => "First " ++ string_of_int(y)
  | (x, 0)
  | (0, x) when true && false =>
    "Either first or second zero, X:" ++ string_of_int(x)
  | (8, x) as tup =>
    let (y, _) = tup;
    "Hey (" ++ string_of_int(y) ++ "," ++ string_of_int(x) ++ ")";
  | (x, y) => string_of_int(x + y)
  };

let cross = ((a1, a2, a3), (b1, b2, b3)) => (
  a2 * b3 - a3 * b2,
  a3 * b1 - a1 * b3,
  a1 * b2 - a2 * b1,
);

let addVectors = ((a1, a2, a3), (b1, b2, b3)) => (
  a1 + b1,
  a2 + b2,
  a3 + b3,
);

type binaryTree('a) =
  | Empty
  | Node(node('a))
and node('a) = {
  value: 'a,
  left: binaryTree('a),
  right: binaryTree('a),
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

type person = {
  name: string,
  age: int,
};

let isServerCode = code => code / 100 == 5;
let isClientCode = code => code / 100 == 5;
type request =
  | Loading
  | Error(string, int)
  | Sucess(person);

let emulateResponseResult = (response) => switch (response) {
| Loading => "Loading"
| Error(message, 444) => "No response" ++ message
| Error(message, 494 | 495 | 496 | 497 | 499) => "nginx error: " ++ message
| Error(message, code) when isServerCode(code) =>
  "Network Error: " ++ message
| Error(message, code) when isClientCode(code) => "Client Code:" ++ message
| Error(message, x) =>
  "Unknown code: " ++ string_of_int(x) ++ " message: " ++ message
| Sucess({name: "Vladimir Novick"}) => "Howdy Vladimir"
| Sucess(response) => response.name
};


let greetings = "Greetings";
let helloWorld = {j|$greetings, Vladimir|j};

/* Js.log(cellestialDestinationTree); */

Js.log(Modules.(Math.times(2, 3)));