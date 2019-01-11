type alert;

%raw
"var a = 1";

let f: (int, int) => int = [%raw (a, b) => "{return a + b}"];

let expoFloat = Js.Float.toExponential(77.1234);

type timeout;
[@bs.val] external setTimeout: (unit => unit, int) => timeout = "";
[@bs.val] external clearTimeout: timeout => unit = "";

[@bs.val] [@bs.scope "window"] external alert: 'a => unit = "";

[@bs.val] [@bs.scope ("window", "location", "ancestorOrigins")]
external length: int = "length";

let a = f(1, 2);

/* [@bs.val] external peopleAge: Js.Dict.t(int) = "";
   switch (Js.Dict.get(peopleAge, "Vladimir")) {
   | None => Js.log("Vladimir can't be found")
   | Some(age) => Js.log("Vladimir is " ++ string_of_int(age))
   }; */

[@bs.deriving jsConverter]
type person = {
  name: string,
  age: int,
  lastName: string,
};

[@bs.val] external getPerson: unit => 'a = "getPerson";

[@bs.deriving abstract]
type testRecord = {
  test: string,
  [@bs.optional]
  test2: string,
};

[@bs.val] external printTest: testRecord => unit = "printTest";

let rcrd = testRecord(~test="Hey", ());
printTest(rcrd);
let pr = getPerson();

Js.log(pr##name);

setTimeout(() => alert(2), 5000);

type t;
[@bs.new] external createDate: unit => t = "Date";

let date = createDate();

type math; /* abstract type for a document object */
[@bs.val] external math: math = "Math";
[@bs.send] external random: (math, int) => float = "";

let el = random(math, 23);

Js.log(el);



[@bs.send] external map : (array('a), 'a => 'b) => array('b) = "";
[@bs.send] external filter : (array('a), 'a => 'b) => array('b) = "";


let result = [|1,2,3|] -> map(item => item) -> filter(item => item);

[@bs.deriving abstract]
type data = {
  name: string
};

[@bs.scope "JSON"] [@bs.val] external parseIntoMyData: string => data = "parse";


let result = parseIntoMyData("{\"name\": \"Luke\"}");


let result = name -> Some;

[@bs.val] [@bs.scope "global"] [@bs.variadic] external draw: ([@bs.as "dog"] _, array(int)) => unit = "draw";

draw([|1,2,3,5,6|])


