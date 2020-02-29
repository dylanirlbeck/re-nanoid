open Jest;
open NanoId;
open Url;

describe("Basic tests", () => {
  Expect.(
    test("nanoid can be called", () =>
      expect(nanoid()) |> toBe("test")
    )
  )
});

describe("Basic tests", () => {
  Expect.(
    test("url chars are correct", () =>
      expect(urlChars) |> toBe("-_0123456789abcABC")
    )
  )
});
