open Jest;

describe("Chec Network Errors", () => {
  open Expect;
  open Demo;

  test("Loading State", () =>
    expect(emulateResponseResult(Loading)) |> toBe("Loading"))

  test("General Success State", () =>
    expect(emulateResponseResult(Success({ name: "John", age: 34}))) |> toBe("John"))

  test("Vladimir Success State", () =>
    expect(emulateResponseResult(Success({
      name: "Vladimir Novick",
      age: 34
    }))) |> toBe("Howdy Vladimir"))
});
