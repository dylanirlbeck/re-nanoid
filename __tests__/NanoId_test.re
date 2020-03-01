open Jest;
open NanoId;
open Url;
open Belt;

let rec constructSet = (~numIds, ~set: Set.String.t) => {
  switch (numIds, set) {
  | (0, _) => set
  | (_, set) =>
    let newId = nanoid();
    constructSet(~numIds=numIds - 1, ~set=Set.String.add(set, newId));
  };
};

let checkForDuplicates = (~numIds) => {
  let set = Set.String.empty;
  let newSet = constructSet(~numIds, ~set);
  Set.String.size(newSet);
};

describe("Basic tests", () => {
  open! Expect.Operators;
  Expect.(
    test("no collisions - 2", () => {
      let test = nanoid();
      let test2 = nanoid();
      expect(test) !== test2;
    })
  );

  Expect.(
    test("no collisions - one thousand", () => {
      let setLength = checkForDuplicates(~numIds=1000);
      expect(setLength) |> toBe(1000);
    })
  );

  Expect.(
    test("no collisions - one hundred thousand", () => {
      let setLength = checkForDuplicates(~numIds=100000);
      expect(setLength) |> toBe(100000);
    })
  );

  /*  Expect.(*/
  /*test("no collisions - one million", () => {*/
  /*let setLength = checkForDuplicates(~numIds=1000000);*/
  /*expect(setLength) |> toBe(1000000);*/
  /*})*/
  /*);*/

  Expect.(
    test("default id size is 21", () => {
      expect(String.length(nanoid())) |> toBe(21)
    })
  );

  Expect.(
    test("can modify id size", () => {
      expect(String.length(nanoid(~size=5, ()))) |> toBe(5)
    })
  );
});

describe("URL chars", () => {
  Expect.(
    test("url chars are correct", () =>
      expect(urlChars)
      |> toBe(
           "-_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
         )
    )
  )
});

describe("Custom alphabet", () => {
  open! Expect.Operators;
  Expect.(
    test("no collisions - 2", () => {
      let test = nanoid(~alphabet="0123456789", ());
      Js.log(test);
      let test2 = nanoid();
      Js.log(test2);
      expect(test) !== test2;
    })
  );
});
