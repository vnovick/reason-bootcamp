// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';


var a = 1
;

function f (a,b){{return a + b}};

var expoFloat = (77.1234).toExponential();

var a = f(1, 2);

function personToJs(param) {
  return {
          name: param[/* name */0],
          age: param[/* age */1],
          lastName: param[/* lastName */2]
        };
}

function personFromJs(param) {
  return /* record */[
          /* name */param.name,
          /* age */param.age,
          /* lastName */param.lastName
        ];
}

var rcrd = {
  test: "Hey"
};

printTest(rcrd);

var pr = getPerson();

console.log(pr.name);

setTimeout((function (param) {
        window.alert(2);
        return /* () */0;
      }), 5000);

var date = new Date();

var el = Math.random(23);

console.log(el);

/* array */[
      1,
      2,
      3
    ].map((function (item) {
          return item;
        })).filter((function (item) {
        return item;
      }));

JSON.parse("{\"name\": \"Luke\"}");

var result = (function (prim) {
    return prim.name;
  });

global.draw("dog", 1, 2, 3, 5, 6);

exports.f = f;
exports.expoFloat = expoFloat;
exports.a = a;
exports.personToJs = personToJs;
exports.personFromJs = personFromJs;
exports.rcrd = rcrd;
exports.pr = pr;
exports.date = date;
exports.el = el;
exports.result = result;
/*  Not a pure module */
