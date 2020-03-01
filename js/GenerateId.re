open Random;

// ~bytes should be of type Buffer.t, that's why this module is in js/
let rec generateIdRec =
        (~size, ~alphabet, ~currId: string, ~bytes: array('a)) => {
  switch (size) {
  | 0 => currId
  | _ =>
    generateIdRec(
      ~size=size - 1,
      ~alphabet,
      ~currId=currId ++ String.make(1, alphabet.[bytes[size - 1] land 63]),
      ~bytes,
    )
  };
};

let generateId = (~size, ~alphabet) => {
  let bytes = random(~bytes=size);
  generateIdRec(~size, ~alphabet, ~currId="", ~bytes);
};

let rec helperRec = (~i, ~size, ~step, ~alphabet, ~bytes, ~mask, ~currId) =>
  if (String.length(currId) === size || i >= step) {
    currId;
  } else {
    let offset = bytes[i] land mask;
    offset > String.length(alphabet)
      ? helperRec(~i=i + 1, ~size, ~step, ~alphabet, ~bytes, ~mask, ~currId)
      : helperRec(
          ~i=i + 1,
          ~size,
          ~step,
          ~alphabet,
          ~bytes,
          ~mask,
          ~currId=currId ++ String.make(1, alphabet.[bytes[i] land mask]),
        );
  };

let rec generateIdWithCustomRec =
        (~size, ~alphabet, ~mask, ~step, ~currId: string) => {
  let bytes = random(step);
  let newId =
    helperRec(~i=0, ~size, ~step, ~alphabet, ~bytes, ~mask, ~currId);
  Js.log("ID");
  Js.log(newId);
  String.length(newId) === size
    ? currId
    : generateIdWithCustomRec(~size, ~alphabet, ~mask, ~step, ~currId=newId);
};

let generateIdWithCustom = (~size, ~alphabet) => {
  let mask =
    2 lsl (31 - Js.Math.clz32((String.length(alphabet) - 1) lor 1)) - 1;
  let maskFloat = float_of_int(mask);

  let step =
    Js.Math.ceil(
      1.6
      *. maskFloat
      *. float_of_int(size)
      /. float_of_int(String.length(alphabet)),
    );
  generateIdWithCustomRec(~size, ~alphabet, ~step, ~mask, ~currId="");
};
