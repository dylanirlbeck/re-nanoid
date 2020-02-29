open Jest;
open NanoId;

describe("Basic tests", () => {
  Expect.(
    test("nanoid can be called", () =>
      expect(nanoid()) |> toBe("test")
    )
  )
});
