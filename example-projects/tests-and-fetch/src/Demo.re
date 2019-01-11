type person = {
  name: string,
  age: int,
};

let isServerCode = code => code / 100 == 5;
let isClientCode = code => code / 100 == 5;
type request =
  | Loading
  | Error(string, int)
  | Success(person);

let emulateResponseResult = (response) => switch (response) {
| Loading => "Loading"
| Error(message, 444) => "No response" ++ message
| Error(message, 494 | 495 | 496 | 497 | 499) => "nginx error: " ++ message
| Error(message, code) when isServerCode(code) =>
  "Network Error: " ++ message
| Error(message, code) when isClientCode(code) => "Client Code:" ++ message
| Error(message, x) =>
  "Unknown code: " ++ string_of_int(x) ++ " message: " ++ message
| Success({name: "Vladimir Novick"}) => "Howdy Vladimir"
| Success(response) => response.name
};