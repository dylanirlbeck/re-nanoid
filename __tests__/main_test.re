open Jest;
open NanoId;
open Url;

describe("Basic tests", () => {
  open! Expect.Operators;
  Expect.(
    test("nanoid works", () => {
      let test = nanoid();
      Js.log(test);
      let test2 = nanoid();
      Js.log(test2);
      expect(test) !== test2;
    })
  );
});

describe("Basic tests", () => {
  Expect.(
    test("url chars are correct", () =>
      expect(urlChars) |> toBe("-_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
    )
  )
});
